#include "map.h"
#include "file.h"
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <unordered_map>

// Map: File Size -> Vector of paths
// Global, used to group files by size so that we only calculate hashes for
// files of the same size
std::unordered_map<std::uintmax_t, std::vector<struct file>> fileMap;

void addToFileMap(std::filesystem::directory_entry file) {
    if (isRegularFile(file)) {
        uintmax_t fileSize = file.file_size();
        std::filesystem::path filePath = file.path();

        struct file curr;
        curr.path = filePath;

        // Lookup if key is already in map, append to vector if so
        if (fileMap.count(fileSize) != 0) {
            fileMap.at(fileSize).push_back(curr);
        }
        // Else create a new entry
        else {
            fileMap.insert_or_assign(fileSize, std::vector<struct file>{curr});
        }
    }
}

void removeFileMapSingleEntries() {
    std::unordered_map<std::uintmax_t, std::vector<struct file>>::iterator it =
        fileMap.begin();

    while (it != fileMap.end()) {
        if (it->second.size() < 2) {
            it = fileMap.erase(it);
            continue;
        }
        it++;
    }
}

void printFileMap() {
    std::unordered_map<std::uintmax_t, std::vector<struct file>>::iterator it =
        fileMap.begin();

    while (it != fileMap.end()) {
        std::cout << it->first << ": ";
        for (auto file : it->second) {
            std::cout << file.path << " | ";
        }
        std::cout << '\n';

        it++;
    }
}
