#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

// Statistics contains helper functions for error counting and BER calculation.
class Statistics {
public:
    static int countErrors(
        const std::vector<int>& original,
        const std::vector<int>& received
    );

    static double computeBER(
        const std::vector<int>& original,
        const std::vector<int>& received
    );
};

#endif