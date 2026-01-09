# CSV Data Quality & Analysis Tool (C++)

A lightweight C++ command-line tool that verifies CSV file integrity, performs rule-based data cleaning, and generates analytical summaries from validated data.

This project was built to practice real-world C++ fundamentals such as file I/O, defensive parsing, data validation, and clean separation of responsibilities.

---

## Features

- File integrity check using checksum
- CSV parsing with header handling
- Validation of required fields and numeric formats
- Rule-based data cleaning
- Statistical analysis (min, max, average)
- Clear and readable console output

---

## Project Structure

csvproject/
 main/ (Application entry point)
 csv/ (CSV reading and parsing)
 processing/ (Data cleaning and analysis)
 utils/ (Utility components (file hashing))

 sample.csv (Sample input data)
 CMakeLists.txt
 README.md

---

## How It Works

1. Computes a checksum to verify file integrity
2. Reads and parses CSV rows
3. Validates each row (missing fields, invalid formats)
4. Cleans invalid data
5. Analyzes valid rows
6. Prints a summary report

---

## Example Input ('sample.csv')

sample.csv file
id,score
1,85
2,
3,abc
4,90
5,70
