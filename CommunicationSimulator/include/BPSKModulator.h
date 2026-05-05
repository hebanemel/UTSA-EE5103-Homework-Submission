#ifndef BPSKMODULATOR_H
#define BPSKMODULATOR_H

#include "Modulator.h"

// BPSKModulator implements Binary Phase Shift Keying.
// Mapping:
// bit 0 -> -1
// bit 1 -> +1
class BPSKModulator : public Modulator {
public:
    std::vector<double> modulate(const std::vector<int>& bits) const override;
    std::vector<int> demodulate(const std::vector<double>& received) const override;
    std::string getName() const override;
};

#endif