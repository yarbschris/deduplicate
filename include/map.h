#ifndef MAP_H
#define MAP_H

#include <filesystem>
#include <unordered_map>

extern std::unordered_map<std::uintmax_t, std::vector<std::filesystem::path>>
    fileMap;

void addToFileMap(std::filesystem::directory_entry file);
void printFileMap();

#endif
