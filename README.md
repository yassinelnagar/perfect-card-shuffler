# Perfect Card Shuffler

This project explores the simulation and analysis of realistic card shuffling using mathematical models. It implements a probabilistic riffle shuffle in C++ as a proof of concept and aims to evaluate shuffle randomness, with future plans for robot design and research publication.

## Project Goals

- Implement a shuffle algorithm based on the Gilbert–Shannon–Reeds model
- Use true random numbers to simulate realistic cuts and interleaving
- Validate randomness using statistical tests (e.g., total variation distance)
- Eventually design a mechanical system to physically shuffle cards
- Write a technical paper covering methods, code, and findings

## Current Features

- C++ deck and card classes
- Normal-distribution-based riffle shuffling
- Pseudo-random interleaving of packets
- Console output of original and shuffled deck
  
Dependencies
C++17 or later

Standard Template Library (<deque>, <queue>, <random>, etc.)

Future Work
Implement true random number sources

Add shuffle quality testing tools (TVD, Monte Carlo)

Design and simulate a physical robot mechanism

Prepare for academic submission or publication

License
This project is licensed under the MIT License.

References
Persi Diaconis et al., "Trailing the Dovetail Shuffle to Its Lair"

Bayer & Diaconis, "Shuffling Cards and Stopping Times"

Fulman, "Carries, Shuffling, and Symmetric Functions"

## Usage
You are free to use this code in personal, academic, or commercial projects without requesting permission. However, if it is used in a major or widely distributed project, credit to the original author is appreciated. 
### Compile and Run
```bash
g++ -std=c++17 -o shuffle main.cpp
./shuffle
