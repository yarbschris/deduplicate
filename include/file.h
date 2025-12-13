#ifndef FILE_H
#define FILE_H

#include <cstdint>
#include <filesystem>

struct file {
    std::filesystem::path path;
    std::vector<uint32_t> hash;
};

bool isRegularFile(std::filesystem::directory_entry file);

std::uintmax_t getFileSize(std::filesystem::directory_entry file);
#endif
