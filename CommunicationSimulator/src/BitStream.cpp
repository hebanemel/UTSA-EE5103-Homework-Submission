#include "BitStream.h"
#include <random>

// Default constructor
BitStream::BitStream() {}

// Constructor that creates a bit stream of the given size
BitStream::BitStream(int size) {
    generateRandomBits(size);
}

// Generates random bits using a uniform distribution between 0 and 1
void BitStream::generateRandomBits(int size) {
    bits_.clear();

    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    for (int i = 0; i < size; ++i) {
        bits_.push_back(dist(gen));
    }
}

// Returns the generated bits without copying them
const std::vector<int>& BitStream::getBits() const {
    return bits_;
}