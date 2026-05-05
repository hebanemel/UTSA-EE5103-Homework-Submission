#ifndef CHANNEL_H
#define CHANNEL_H

#include <vector>

// Abstract base class for channel models.
// A channel takes transmitted symbols and returns received noisy symbols.
class Channel {
public:
    virtual ~Channel() = default;

    virtual std::vector<double> transmit(
        const std::vector<double>& signal,
        double snrDb
    ) const = 0;
};

#endif