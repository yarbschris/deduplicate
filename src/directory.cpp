#include "directory.h"
#include "encrypt.h"
#include "file.h"
#include "map.h"
#include <filesystem>
#include <iostream>

void iterateThroughDirectory(std::string dir) {
    // Recursively Iterate Through Directory, Ignore entires where permission is
    // denied
    for (auto const &dirEntry : std::filesystem::recursive_directory_iterator(
             dir, std::filesystem::directory_options::skip_permission_denied)) {
        addToFileMap(dirEntry);
    }
}

void validateDirectory(std::string dir) {
    if (!std::filesystem::is_directory(dir)) {
        std::cerr << "Error: " << dir << " is not a directory.\n";
        exit(EXIT_FAILURE);
    }
}
