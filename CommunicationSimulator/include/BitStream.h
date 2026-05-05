#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <vector>

// BitStream is responsible for creating and storing random binary bits.
class BitStream {
private:
    std::vector<int> bits_; // Stores the generated bits: 0s and 1s

public:
    BitStream();                 // Default constructor
    explicit BitStream(int size); // Constructor that generates bits immediately

    void generateRandomBits(int size);        // Generates random bits
    const std::vector<int>& getBits() const;  // Returns the bit vector
};

#endif