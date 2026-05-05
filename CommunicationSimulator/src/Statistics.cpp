#include "Statistics.h"
#include <algorithm>

// Counts how many bits are different between original and received data
int Statistics::countErrors(
    const std::vector<int>& original,
    const std::vector<int>& received
) {
    int errors = 0;

    // Use the smaller size to avoid out-of-range errors
    size_t length = std::min(original.size(), received.size());

    for (size_t i = 0; i < length; ++i) {
        if (original[i] != received[i]) {
            errors++;
        }
    }

    return errors;
}

// Computes BER = number of errors / number of transmitted bits
double Statistics::computeBER(
    const std::vector<int>& original,
    const std::vector<int>& received
) {
    if (original.empty()) {
        return 0.0;
    }

    int errors = countErrors(original, received);

    return static_cast<double>(errors) / original.size();
}