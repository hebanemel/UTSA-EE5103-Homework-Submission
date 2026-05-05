#ifndef AWGNCHANNEL_H
#define AWGNCHANNEL_H

#include "Channel.h"

// AWGNChannel models Additive White Gaussian Noise.
// Received signal:
// r = s + n
class AWGNChannel : public Channel {
public:
    std::vector<double> transmit(
        const std::vector<double>& signal,
        double snrDb
    ) const override;

private:
    double computeNoiseStdDev(double snrDb) const;
};

#endif