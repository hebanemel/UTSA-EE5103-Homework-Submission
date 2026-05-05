#ifndef MODULATOR_H
#define MODULATOR_H

#include <vector>
#include <string>

// Abstract base class for all modulation schemes.
// Any modulation class must implement these functions.
class Modulator {
public:
    virtual ~Modulator() = default;

    // Converts bits into signal symbols
    virtual std::vector<double> modulate(const std::vector<int>& bits) const = 0;

    // Converts received signal symbols back into bits
    virtual std::vector<int> demodulate(const std::vector<double>& received) const = 0;

    // Returns the modulation name
    virtual std::string getName() const = 0;
};

#endif