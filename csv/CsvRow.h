#pragma once

#include <string>

// Represents a valid, cleaned CSV row
struct CsvRow {
    int id;
    int score;
};

// Status after validating a raw CSV row
enum class RowStatus {
    VALID,
    INVALID_MISSING_FIELD,
    INVALID_FORMAT
};
// Validates and cleans a raw CSV row