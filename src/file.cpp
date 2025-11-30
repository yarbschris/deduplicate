#include "file.h"
#include <filesystem>
#include <iostream>

void iterateThroughDirectory(std::string dir) {
    for (auto const &dirEntry : std::filesystem::recursive_directory_iterator(
             dir, std::filesystem::directory_options::skip_permission_denied)) {
        std::cout << dirEntry << '\n';
    }
}

void validateDirectory(std::string dir) {
    if (!std::filesystem::is_directory(dir)) {
        std::cerr << "Error: " << dir << " is not a directory.\n";
        exit(EXIT_FAILURE);
    }
}
