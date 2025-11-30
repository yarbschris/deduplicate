#include "file.h"
#include <filesystem>
#include <iostream>

void iterateThroughDirectory(std::string path) {
    for (auto const &dirEntry :
         std::filesystem::recursive_directory_iterator(path)) {
        std::cout << dirEntry << '\n';
    }
}

bool validateDirectory(std::string path) {
    if (!std::filesystem::is_directory(path))
        return false;

    return true;
}
