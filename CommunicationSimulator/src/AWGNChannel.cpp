#include "AWGNChannel.h"
#include <random>
#include <cmath>

// Converts SNR in dB into noise standard deviation.
// Higher SNR means smaller noise.
double AWGNChannel::computeNoiseStdDev(double snrDb) const {
    double snrLinear = std::pow(10.0, snrDb / 10.0);

    // Assuming signal power is approximately 1
    double noiseVariance = 1.0 / (2.0 * snrLinear);

    return std::sqrt(noiseVariance);
}

// Adds Gaussian noise to every transmitted signal sample
std::vector<double> AWGNChannel::transmit(
    const std::vector<double>& signal,
    double snrDb
) const {
    std::vector<double> received;

    std::random_device rd;
    std::default_random_engine gen(rd());

    double sigma = computeNoiseStdDev(snrDb);

    // Gaussian noise with mean 0 and standard deviation sigma
    std::normal_distribution<double> noise(0.0, sigma);

    for (double sample : signal) {
        double noisySample = sample + noise(gen);
        received.push_back(noisySample);
    }

    return received;
}