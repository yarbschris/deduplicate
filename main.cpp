#include <filesystem>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error, deduplicate only takes one argument.\nCorrect usage: "
                 "\"deduplicate <directory>\n";
    exit(EXIT_FAILURE);
  }
  std::string dirPath = argv[1];

  std::cout << "Path to deduplicate: " << dirPath << '\n';
  return 0;
}
