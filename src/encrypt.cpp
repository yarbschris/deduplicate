#include "encrypt.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

void outputBinary(std::filesystem::path filePath) {
    std::ifstream infile(filePath);
    if (infile.is_open()) {
        std::cout << std::ios::binary << infile.rdbuf();
    }

    infile.close();
}
