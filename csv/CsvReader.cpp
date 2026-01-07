#include "CsvReader.h"

#include <fstream>
#include <sstream>

CsvReader::CsvReader(const std::string& filePath)
    : filePath_(filePath) {}

std::vector<RawCsvRow> CsvReader::readAll() 
{
    std::vector<RawCsvRow> rows;
    std::ifstream file(filePath_);

    if (!file.is_open()) {
        return rows; // empty result if file can't be opened
    }

    std::string line;

    // Skip header
    if (!std::getline(file, line)) {
        return rows;
    }

    // Read remaining lines
    while (std::getline(file, line)) {
        rows.push_back(parseLine(line));
    }

    return rows;
}

RawCsvRow CsvReader::parseLine(const std::string& line) {
    RawCsvRow row;
    row.status = RowStatus::VALID;

    std::stringstream ss(line);
    std::string field;

    while (std::getline(ss, field, ',')) {
        row.fields.push_back(field);
    }

    // Expecting exactly 2 columns: id, score
    if (row.fields.size() != 2) {
        row.status = RowStatus::INVALID_MISSING_FIELD;
        return row;
    }

    // Validate numeric format
    try {
        std::stoi(row.fields[0]);
        std::stoi(row.fields[1]);
    } catch (...) {
        row.status = RowStatus::INVALID_FORMAT;
    }

    return row;
}
