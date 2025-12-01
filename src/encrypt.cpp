#include "encrypt.h"
#include <filesystem>
#include <fstream>
#include <iostream>

bool outputBinary(std::filesystem::path filePath) {
    std::cout << filePath << ": \n";
    std::vector<char> bits{readBinary(filePath)};

    for (unsigned char bit : bits) {
        std::cout << bit;
    }
    return true;
}

std::vector<char> readBinary(std::filesystem::path filePath) {
    // Create input stream in binary mode
    std::ifstream file(filePath, std::ios::binary);

    if (!file) {
        std::cerr << "Error: Could not open " << filePath << '\n';
    }
    // Find end to get size, then reset
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    // Allocate buffer
    std::vector<char> buffer(size);

    // Read file content into buffer
    file.read(buffer.data(), size);

    return buffer;
}
