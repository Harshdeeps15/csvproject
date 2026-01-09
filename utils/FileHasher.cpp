#include "FileHasher.h"

#include <fstream>

unsigned long FileHasher::computeChecksum(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        return 0;
    }

    unsigned long checksum = 0;
    char byte;

    while (file.get(byte)) {
        checksum += static_cast<unsigned char>(byte);
    }

    return checksum;
}
