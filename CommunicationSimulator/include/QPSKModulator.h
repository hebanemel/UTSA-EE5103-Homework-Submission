#ifndef QPSKMODULATOR_H
#define QPSKMODULATOR_H

#include "Modulator.h"

// QPSKModulator implements a simplified QPSK-style modulation.
// Note: This is not full complex IQ QPSK. It is a simplified version.
class QPSKModulator : public Modulator {
public:
    std::vector<double> modulate(const std::vector<int>& bits) const override;
    std::vector<int> demodulate(const std::vector<double>& received) const override;
    std::string getName() const override;
};

#endif