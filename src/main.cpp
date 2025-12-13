#include "cli.h"
#include "directory.h"
#include "map.h"
#include <cstdint>
#include <cstdlib>

int main(int argc, char *argv[]) {

    std::string pathToRoot = parseCLI(argc, argv);
    validateDirectory(pathToRoot);
    iterateThroughDirectory(pathToRoot);
    removeFileMapSingleEntries();
    computeHashes();

    // For Each Group (Vector in remaining file map):
    //      Convert File Contents into vector of uint8_t
    //      Compute File Hashes
    //      Compare Hashes to detect duplicates
    //
    // Report Duplicates
    // Optionally delete files

    return 0;
}
