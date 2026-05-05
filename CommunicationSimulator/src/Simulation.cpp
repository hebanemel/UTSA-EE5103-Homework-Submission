#include "Simulation.h"
#include "BitStream.h"
#include "Statistics.h"
#include <iostream>

// Constructor initializes simulation parameters
Simulation::Simulation(
    int numBits,
    double snrDb,
    const Modulator& modulator,
    const Channel& channel
)
    : numBits_(numBits),
      snrDb_(snrDb),
      modulator_(modulator),
      channel_(channel) {}

// Runs the full digital communication simulation
void Simulation::run() const {
    // 1. Generate random bits
    BitStream source(numBits_);
    const std::vector<int>& originalBits = source.getBits();

    // 2. Modulate bits into signal symbols
    std::vector<double> transmittedSignal = modulator_.modulate(originalBits);

    // 3. Pass signal through noisy AWGN channel
    std::vector<double> receivedSignal = channel_.transmit(transmittedSignal, snrDb_);

    // 4. Demodulate noisy signal back into bits
    std::vector<int> receivedBits = modulator_.demodulate(receivedSignal);

    // 5. Count errors and compute BER
    int errors = Statistics::countErrors(originalBits, receivedBits);
    double ber = Statistics::computeBER(originalBits, receivedBits);

    // 6. Print results
    std::cout << "\n===== Simulation Results =====\n";
    std::cout << "Modulation: " << modulator_.getName() << std::endl;
    std::cout << "SNR (dB): " << snrDb_ << std::endl;
    std::cout << "Bits transmitted: " << numBits_ << std::endl;
    std::cout << "Errors: " << errors << std::endl;
    std::cout << "BER: " << ber << std::endl;
}