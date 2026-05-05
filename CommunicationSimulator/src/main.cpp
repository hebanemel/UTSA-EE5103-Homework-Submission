#include "Simulation.h"
#include "BPSKModulator.h"
#include "QPSKModulator.h"
#include "AWGNChannel.h"
#include <iostream>

int main() {
    int numBits;
    double snrDb;
    int choice;

    std::cout << "Enter number of bits: ";
    std::cin >> numBits;

    std::cout << "Enter SNR (dB): ";
    std::cin >> snrDb;

    std::cout << "Select Modulation:\n";
    std::cout << "1. BPSK\n";
    std::cout << "2. QPSK\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;


   // Pointer to base class (polymorphism)
    Modulator* mod = nullptr;  // Invalid choice -> default to BPSK
 if (choice != 1 && choice != 2) {
    std::cout << "Invalid choice. Defaulting to BPSK.\n";
    mod = new BPSKModulator();
}
   

    if (choice == 2) {
        mod = new QPSKModulator();
    } else {
        mod = new BPSKModulator();
    }

    AWGNChannel channel;

    // Pass selected modulator
    Simulation sim(numBits, snrDb, *mod, channel);
    sim.run();

    delete mod; // avoid memory leak

    return 0;
}