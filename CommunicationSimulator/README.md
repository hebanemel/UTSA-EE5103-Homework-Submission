# UTSA-EE5103-Project-Submission
Submission for Engineering programming Project (C++)

Name: Tosan Ine, Hebane Guehi
Course: EE5103 (Engineering Programming)
Instructions: I used VScode with gcc as compiler.

# Digital Communication System Simulator (C++)

## Overview

This project is a simple simulation of a digital communication system built in C++. The goal is to model how data is transmitted over a noisy channel and to observe how noise affects the accuracy of the received signal.

The simulator follows the basic communication pipeline:
- Generate binary data
- Modulate the data (BPSK or QPSK)
- Transmit through a noisy channel (AWGN)
- Demodulate the received signal
- Compute the Bit Error Rate (BER)

This project was developed as part of an engineering programming course to demonstrate object-oriented design and the use of modern C++ features.


## Features

- Supports **BPSK and QPSK modulation**
- Simulates **Additive White Gaussian Noise (AWGN)**
- Computes **Bit Error Rate (BER)**
- User can choose:
  - Number of bits
  - Signal-to-Noise Ratio (SNR)
  - Modulation type
- Modular and extensible design using C++ classes


Key classes:
- `BitStream` → Generates random bits
- `Modulator` → Base class for modulation
- `BPSKModulator`, `QPSKModulator` → Modulation implementations
- `Channel` → Base class for channel model
- `AWGNChannel` → Adds noise to the signal
- `Simulation` → Controls the full pipeline
- `Statistics` → Computes BER


## How to Compile and Run (Using g++ (Windows / PowerShell))

# Compile
g++ src/main.cpp src/BitStream.cpp src/BPSKModulator.cpp src/QPSKModulator.cpp src/AWGNChannel.cpp src/Statistics.cpp src/Simulation.cpp -Iinclude -std=c++17 -Wall -o sim.exe

# Run
.\sim.exe