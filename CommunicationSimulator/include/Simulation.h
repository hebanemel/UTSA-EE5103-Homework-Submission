#ifndef SIMULATION_H
#define SIMULATION_H

#include "Modulator.h"
#include "Channel.h"

// Simulation controls the full communication process.
class Simulation {
private:
    int numBits_;                 // Number of bits to transmit
    double snrDb_;                // Signal-to-noise ratio in dB
    const Modulator& modulator_;  // Selected modulation scheme
    const Channel& channel_;      // Selected channel model

public:
    Simulation(
        int numBits,
        double snrDb,
        const Modulator& modulator,
        const Channel& channel
    );

    void run() const;
};

#endif