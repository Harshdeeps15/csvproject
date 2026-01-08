#pragma once

#include <vector>
#include "CsvRow.h"
#include "CsvReader.h"

// Result after cleaning raw CSV data
struct CleaningResult {
    std::vector<CsvRow> cleanRows;
    int invalidMissingFieldCount = 0;
    int invalidFormatCount = 0;
};

class DataCleaner {
public:
    CleaningResult clean(const std::vector<RawCsvRow>& rawRows);
};
