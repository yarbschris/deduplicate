#include "map.h"
#include "file.h"
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <unordered_map>

// Map: File Size -> Vector of paths
// Global, used to group files by size so that we only calculate hashes for
// files of the same size
std::unordered_map<std::uintmax_t, std::vector<std::filesystem::path>> fileMap;

void addToFileMap(std::filesystem::directory_entry file) {
    if (isRegularFile(file)) {
        uintmax_t fileSize = file.file_size();
        std::filesystem::path filePath = file.path();

        // Lookup if key is already in map, append to vector if so
        if (fileMap.count(fileSize) != 0) {
            fileMap.at(fileSize).push_back(filePath);
        }
        // Else create a new entry
        else {
            fileMap.insert_or_assign(
                fileSize, std::vector<std::filesystem::path>{filePath});
        }
    }
}

void printFileMap() {
    // Create Iterator for unordered_map
    std::unordered_map<std::uintmax_t,
                       std::vector<std::filesystem::path>>::iterator it =
        fileMap.begin();

    // Iterate through map, print size: (path vector contents)
    while (it != fileMap.end()) {
        std::cout << it->first << ": ";
        for (auto i : it->second) {
            std::cout << i << " | ";
        }
        std::cout << '\n';

        it++;
    }
}
