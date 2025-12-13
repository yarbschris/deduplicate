#ifndef MAP_H
#define MAP_H

#include <filesystem>
#include <unordered_map>

extern std::unordered_map<std::uintmax_t, std::vector<struct file>> fileMap;

void addToFileMap(std::filesystem::directory_entry file);
void removeFileMapSingleEntries();

void printFileMap();

void computeHashes();

#endif
