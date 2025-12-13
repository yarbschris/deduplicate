#include "file.h"
#include <cstdint>
#include <filesystem>

struct file {
    std::filesystem::path path;
    std::vector<uint32_t> hash;
};

bool isRegularFile(std::filesystem::directory_entry file) {
    return file.is_regular_file();
}

std::uintmax_t getFileSize(std::filesystem::directory_entry file) {
    return file.file_size();
}
