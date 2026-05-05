#include "QPSKModulator.h"
#include <cmath>

// Simplified QPSK-style modulation.
// It takes two bits at a time and maps them into one signal value.
std::vector<double> QPSKModulator::modulate(const std::vector<int>& bits) const {
    std::vector<double> symbols;

    for (size_t i = 0; i < bits.size(); i += 2) {
        int b1 = bits[i];

        // If the number of bits is odd, pad the last missing bit with 0
        int b2 = (i + 1 < bits.size()) ? bits[i + 1] : 0;

        // Convert bit pair into a value from 0 to 3
        int pairValue = b1 * 2 + b2;

        // Simplified mapping to four signal levels
        // 00 -> -1.0
        // 01 -> -0.33
        // 10 ->  0.33
        // 11 ->  1.0
        double symbol;

        if (pairValue == 0) {
            symbol = -1.0;
        } else if (pairValue == 1) {
            symbol = -0.33;
        } else if (pairValue == 2) {
            symbol = 0.33;
        } else {
            symbol = 1.0;
        }

        symbols.push_back(symbol);
    }

    return symbols;
}

// Simplified QPSK-style demodulation.
// Finds the closest of the four possible signal levels.
std::vector<int> QPSKModulator::demodulate(const std::vector<double>& received) const {
    std::vector<int> bits;

    for (double sample : received) {
        int pairValue;

        if (sample < -0.665) {
            pairValue = 0; // 00
        } else if (sample < 0.0) {
            pairValue = 1; // 01
        } else if (sample < 0.665) {
            pairValue = 2; // 10
        } else {
            pairValue = 3; // 11
        }

        // Convert pairValue back into two bits
        int b1 = pairValue / 2;
        int b2 = pairValue % 2;

        bits.push_back(b1);
        bits.push_back(b2);
    }

    return bits;
}

// Returns modulation name
std::string QPSKModulator::getName() const {
    return "QPSK";
}