#include "file.h"
#include "sha.h"
#include <cstdint>
#include <filesystem>
#include <fstream>

bool isRegularFile(std::filesystem::directory_entry file) {
    return file.is_regular_file();
}

std::uintmax_t getFileSize(std::filesystem::directory_entry file) {
    return file.file_size();
}

void file::computeHash() {
    std::fstream stream{entry.path(), std::ios::in};
    std::vector<uint8_t> contents;

    while (stream.peek() != EOF) {
        contents.push_back(stream.get());
    }

    sha.calculateHash(contents);
    hash = sha.getHashVector();
    std::cout << entry.path() << ": ";
    sha.printHash();
    sha.reset();
}
