#include "file.h"
#include <cstdint>
#include <filesystem>

bool isRegularFile(std::filesystem::directory_entry file) {
    return file.is_regular_file();
}

std::uintmax_t getFileSize(std::filesystem::directory_entry file) {
    return file.file_size();
}
