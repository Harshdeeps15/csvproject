#pragma once

#include <string>
#include <vector>
#include "CsvRow.h"

// Represents a raw CSV row before cleaning
struct RawCsvRow {
    std::vector<std::string> fields;
    RowStatus status;
};

class CsvReader {
public:
    explicit CsvReader(const std::string& filePath);

    // Reads and parses all rows except header
    std::vector<RawCsvRow> readAll();

private:
    std::string filePath_;

    RawCsvRow parseLine(const std::string& line);
};
