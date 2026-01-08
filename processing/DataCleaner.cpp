#include "DataCleaner.h"

CleaningResult DataCleaner::clean(const std::vector<RawCsvRow>& rawRows) {
    CleaningResult result;

    for (const auto& raw : rawRows) {
        if (raw.status == RowStatus::INVALID_MISSING_FIELD) {
            result.invalidMissingFieldCount++;
            continue;
        }

        if (raw.status == RowStatus::INVALID_FORMAT) {
            result.invalidFormatCount++;
            continue;
        }

        // Row is valid → convert to CsvRow
        CsvRow row;
        row.id = std::stoi(raw.fields[0]);
        row.score = std::stoi(raw.fields[1]);

        result.cleanRows.push_back(row);
    }

    return result;
}
