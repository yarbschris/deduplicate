#ifndef FILE_H
#define FILE_H

#include <cstdint>
#include <filesystem>

bool isRegularFile(std::filesystem::directory_entry file);

std::uintmax_t getFileSize(std::filesystem::directory_entry file);
#endif
