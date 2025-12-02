#include "sha.cpp"
int main(int argc, char *argv[]) {
    SHA256 sha = SHA256();
    sha.reset();
    std::vector<uint8_t> bits = {static_cast<uint8_t>(0x80)};
    sha.calculateHash(bits);
    sha.getHash();
    return 0;
}
