#include "BPSKModulator.h"

// Converts each bit into a BPSK signal value
std::vector<double> BPSKModulator::modulate(const std::vector<int>& bits) const {
    std::vector<double> symbols;

    for (int bit : bits) {
        if (bit == 1) {
            symbols.push_back(1.0);
        } else {
            symbols.push_back(-1.0);
        }
    }

    return symbols;
}

// Converts received BPSK signal values back into bits
std::vector<int> BPSKModulator::demodulate(const std::vector<double>& received) const {
    std::vector<int> bits;

    for (double sample : received) {
        if (sample >= 0) {
            bits.push_back(1);
        } else {
            bits.push_back(0);
        }
    }

    return bits;
}

// Returns modulation name
std::string BPSKModulator::getName() const {
    return "BPSK";
}