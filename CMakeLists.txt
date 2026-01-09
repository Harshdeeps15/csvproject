cmake_minimum_required(VERSION 3.15)
project(csvproject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(csvproject
    main/main.cpp

    csv/CsvReader.cpp

    processing/DataCleaner.cpp
    processing/CsvAnalyzer.cpp

    utils/FileHasher.cpp
)

target_include_directories(csvproject PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/csv
    ${CMAKE_CURRENT_SOURCE_DIR}/processing
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)