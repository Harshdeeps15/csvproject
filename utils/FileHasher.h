#pragma once

#include <string>

class FileHasher {
public:
    // Computes a simple checksum for a file
    static unsigned long computeChecksum(const std::string& filePath);
};
