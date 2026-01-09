#include "CsvAnalyzer.h"

AnalysisResult CsvAnalyzer::analyze(const std::vector<CsvRow>& rows) {
    AnalysisResult result;

    if (rows.empty()) {
        return result;
    }

    result.totalRows = static_cast<int>(rows.size());
    result.minScore = rows[0].score;
    result.maxScore = rows[0].score;

    int sum = 0;

    for (const auto& row : rows) {
        sum += row.score;

        if (row.score < result.minScore) {
            result.minScore = row.score;
        }

        if (row.score > result.maxScore) {
            result.maxScore = row.score;
        }
    }

    result.averageScore = static_cast<double>(sum) / result.totalRows;
    return result;
}
