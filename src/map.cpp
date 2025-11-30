#include "map.h"
#include "file.h"
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <unordered_map>

std::unordered_map<std::uintmax_t, std::vector<std::filesystem::path>> fileMap;

void addToFileMap(std::filesystem::directory_entry file) {
    if (isRegularFile(file)) {
        uintmax_t fileSize = file.file_size();
        // Lookup if key is already in map, append if so
        if (fileMap.count(fileSize) != 0) {
            fileMap.at(fileSize).push_back(file.path());
        }
        // Else create a new entry
        else {
            fileMap.insert_or_assign(
                fileSize, std::vector<std::filesystem::path>{file.path()});
        }
    }
}

void printFileMap() {
    std::unordered_map<std::uintmax_t,
                       std::vector<std::filesystem::path>>::iterator it =
        fileMap.begin();

    while (it != fileMap.end()) {
        std::cout << it->first << ": ";
        for (auto i : it->second) {
            std::cout << i << " | ";
        }
        std::cout << '\n';

        it++;
    }
}
