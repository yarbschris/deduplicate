#include "cli.h"
#include "file.h"
#include <cstdlib>

int main(int argc, char *argv[]) {

    std::string pathToRoot = parseCLI(argc, argv);
    if (!validateDirectory(pathToRoot)) {
        std::cout << "Error: " << pathToRoot << " is not a directory." << '\n';
        exit(EXIT_FAILURE);
    }
    iterateThroughDirectory(pathToRoot);

    // Recursively Walk Filesystem
    // Calculate SHA256 hash for each file
    // Find Duplicates
    // Optionally delete files

    return 0;
}
