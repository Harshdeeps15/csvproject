#pragma once

#include <vector>
#include "CsvRow.h"

// Result of CSV data analysis
struct AnalysisResult {
    int totalRows = 0;
    int minScore = 0;
    int maxScore = 0;
    double averageScore = 0.0;
};

class CsvAnalyzer {
public:
    AnalysisResult analyze(const std::vector<CsvRow>& rows);
};
