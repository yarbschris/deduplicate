#include "cli.h"

std::string parseCLI(int argc, char *argv[]) {
    std::string dirPath{};

    switch (argc) {
    case 1: // Use cwd
        dirPath = ".";
        break;

    case 2: // Use argv[1]
        dirPath = argv[1];
        break;

    default:
        std::cout << "Error, deduplicate only takes one (optional) "
                     "argument.\nCorrect usage: "
                     "\"deduplicate <directory>\"\n"
                  << "To deduplicate cwd: \"deduplicate\"" << '\n';
        exit(EXIT_FAILURE);
    }

    std::cout << "Path to deduplicate: " << dirPath << '\n';

    return dirPath;
}
