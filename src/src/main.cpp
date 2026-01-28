#include "code.h"
#include <iostream>
#include <cstdlib>

Code::Code(int n, int m) : n(n), m(m), digits(n, 0) {}

void Code::initializeRandom() {
    for (int i = 0; i < n; i++) {
        digits[i] = rand() % m;
    }
}

void Code::setDigits(const std::vector<int>& v) {
    digits = v;
}

int Code::checkCorrect(const Code& guess) const {
    int correct = 0;

    for (int i = 0; i < n; i++) {
        if (digits[i] == guess.digits[i]) {
            correct++;
        }
    }

    return correct;
}

int Code::checkIncorrect(const Code& guess) const {
    // mark stuff we already matched so it doesn't count twice
    std::vector<bool> usedSecret(n, false);
    std::vector<bool> usedGuess(n, false);

    int wrongSpot = 0;

    // first, lock in the exact matches
    for (int i = 0; i < n; i++) {
        if (digits[i] == guess.digits[i]) {
            usedSecret[i] = true;
            usedGuess[i] = true;
        }
    }

    // now count digits that exist but are in the wrong spot
    for (int i = 0; i < n; i++) {
        if (usedGuess[i]) continue;

        for (int j = 0; j < n; j++) {
            if (!usedSecret[j] && guess.digits[i] == digits[j]) {
                wrongSpot++;
                usedSecret[j] = true;
                break;
            }
        }
    }

    return wrongSpot;
}

void Code::print() const {
    for (int i = 0; i < n; i++) {
        std::cout << digits[i];
        if (i != n - 1) std::cout << " ";
    }
    std::cout << std::endl;
}
