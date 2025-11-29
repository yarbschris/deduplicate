#include "cli.h"

int main(int argc, char *argv[]) {

    std::string pathToRoot = parseCLI(argc, argv);
    // Recursively Walk Filesystem
    // Calculate SHA256 hash for each file
    // Find Duplicates
    // Optionally delete files

    return 0;
}
