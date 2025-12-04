#include "cli.h"
#include "directory.h"
#include "map.h"
#include <cstdlib>

int main(int argc, char *argv[]) {

    std::string pathToRoot = parseCLI(argc, argv);
    validateDirectory(pathToRoot);
    iterateThroughDirectory(pathToRoot);
    removeFileMapSingleEntries();
    printFileMap();

    // Calculate SHA256 hash for each file
    // Compare Hashes in each group with 2+ to find duplicates
    // Optionally delete files

    return 0;
}
