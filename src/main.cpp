#include "cli.h"
#include "file.h"
#include <cstdlib>

int main(int argc, char *argv[]) {

    std::string pathToRoot = parseCLI(argc, argv);
    validateDirectory(pathToRoot);
    iterateThroughDirectory(pathToRoot);

    // Calculate SHA256 hash for each file
    // Find Duplicates
    // Optionally delete files

    return 0;
}
