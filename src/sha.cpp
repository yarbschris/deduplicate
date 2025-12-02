#include "sha.h"
#include <cstdint>
#include <iostream>
#include <vector>

SHA256::SHA256() { reset(); }

void SHA256::reset() {
    // Initialize hash value
    H[0] = 0x6a09e667; // A
    H[1] = 0xbb67ae85; // B
    H[2] = 0x3c6ef372; // C
    H[3] = 0xa54ff53a; // D
    H[4] = 0x510e527f; // E
    H[5] = 0x9b05688c; // F
    H[6] = 0x1f83d9ab; // G
    H[7] = 0x5be0cd19; // H
};

void SHA256::calculateHash(std::vector<uint8_t> bits) {
    pad(&bits);
    process(bits);
};

std::vector<uint32_t> SHA256::getHashVector() {
    return std::vector<uint32_t>{H[0], H[1], H[2], H[3],
                                 H[4], H[5], H[6], H[7]};
}

void SHA256::printHash() {
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << H[i];
    }
    std::cout << '\n';
}

// Functions needed for SHA-256
uint32_t SHA256::Ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t SHA256::Maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t SHA256::SHR(uint32_t x, int n) { return x >> n; }

uint32_t SHA256::ROTR(uint32_t x, int n) { return (x >> n) | (x << (32 - n)); }

uint32_t SHA256::ep0(uint32_t x) {
    return ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22);
}

uint32_t SHA256::ep1(uint32_t x) {
    return ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25);
}

uint32_t SHA256::sig0(uint32_t x) {
    return ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3);
}

uint32_t SHA256::sig1(uint32_t x) {
    return ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10);
}

// Constants for SHA-256

// Preprocessing Steps
// Pad: Ensure message length is a multiple of 512 with last 64 bits
// encoding the original message length
void SHA256::pad(std::vector<uint8_t> *bits) {
    int64_t originalLength = bits->size() * 8;

    // Append '1' bit
    bits->push_back(0x80);

    // Append '0' bits until we have 64 bits left with which to encode our
    // original length (mod by 64 (512 bits), result will be 56 (448 bits)
    // if we have 64 bits remaining)

    while (bits->size() % 64 != 56) {
        bits->push_back(0x0);
    }

    // Encode original length as 64 bits and append it to our vector
    for (int i = 7; i >= 0; i--) {
        bits->push_back((originalLength >> (i * 8)) & 0xFF);
    }
}

// Process Step: Parse message into 512 bit blocks
// Each chunk will point to the start of a 512 bit block
void SHA256::process(std::vector<uint8_t> &padded) {
    for (size_t offset = 0; offset < padded.size(); offset += 64) {
        const uint8_t *chunk = &padded[offset];
        processChunk(chunk);
    }
}

// Process Each Chunk
void SHA256::processChunk(const uint8_t *chunk) {
    // Prepare Message Schedule
    uint32_t W[64];

    // First 16 words of message schdule are just the first 16 32 bit words
    for (int i = 0; i < 16; i++) {
        int j = i * 4;
        W[i] = (static_cast<uint32_t>(chunk[j]) << 24) |
               (static_cast<uint32_t>(chunk[j + 1]) << 16) |
               (static_cast<uint32_t>(chunk[j + 2]) << 8) |
               (static_cast<uint32_t>(chunk[j + 3]));
    }

    // Next 48 words calculated by this formula from paper
    for (int i = 16; i < 64; i++) {
        W[i] = sig1(W[i - 2]) + W[i - 7] + sig0(W[i - 15]) + W[i - 16];
    }

    // Initialize working variables
    uint32_t a = H[0];
    uint32_t b = H[1];
    uint32_t c = H[2];
    uint32_t d = H[3];
    uint32_t e = H[4];
    uint32_t f = H[5];
    uint32_t g = H[6];
    uint32_t h = H[7];

    // Update function for working variables from message schedule
    for (int i = 0; i < 64; i++) {
        uint32_t T1 = h + ep1(e) + Ch(e, f, g) + K[i] + W[i];
        uint32_t T2 = ep0(a) + Maj(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }

    // After this is done, update hash values
    H[0] += a;
    H[1] += b;
    H[2] += c;
    H[3] += d;
    H[4] += e;
    H[5] += f;
    H[6] += g;
    H[7] += h;
};
}
;
