#include <iostream>

#include "CsvReader.h"
#include "DataCleaner.h"
#include "CsvAnalyzer.h"
#include "FileHasher.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: csvproject <csv_file_path>\n";
        return 1;
    }

    std::string filePath = argv[1];

    // 1. Integrity check
    unsigned long checksum = FileHasher::computeChecksum(filePath);
    if (checksum == 0) {
        std::cout << "Failed to open file or file is empty.\n";
        return 1;
    }

    std::cout << "File checksum: " << checksum << "\n";

    // 2. Read CSV
    CsvReader reader(filePath);
    auto rawRows = reader.readAll();

    if (rawRows.empty()) {
        std::cout << "No data rows found.\n";
        return 0;
    }

    // 3. Clean data
    DataCleaner cleaner;
    auto cleaningResult = cleaner.clean(rawRows);

    // 4. Analyze clean data
    CsvAnalyzer analyzer;
    auto analysis = analyzer.analyze(cleaningResult.cleanRows);

    // 5. Print report
    std::cout << "\nCSV Analysis Report\n";
    std::cout << "-------------------\n";
    std::cout << "Total rows read: " << rawRows.size() << "\n";
    std::cout << "Valid rows: " << cleaningResult.cleanRows.size() << "\n";
    std::cout << "Invalid rows (missing fields): "
              << cleaningResult.invalidMissingFieldCount << "\n";
    std::cout << "Invalid rows (format errors): "
              << cleaningResult.invalidFormatCount << "\n";

    if (analysis.totalRows > 0) {
        std::cout << "Min score: " << analysis.minScore << "\n";
        std::cout << "Max score: " << analysis.maxScore << "\n";
        std::cout << "Average score: " << analysis.averageScore << "\n";
    } else {
        std::cout << "No valid data available for analysis.\n";
    }

    return 0;
}
