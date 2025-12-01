#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <filesystem>
#include <fstream>

bool outputBinary(std::filesystem::path filePath);
std::vector<char> readBinary(std::filesystem::path filePath);

#endif
