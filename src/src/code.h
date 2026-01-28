#ifndef CODE_H
#define CODE_H

#include <vector>

class Code {
private:
    std::vector<int> digits;
    int n;
    int m;

public:
    Code(int n, int m);

    // fill with random digits from 0 to m-1
    void initializeRandom();

    // right digit + right position
    int checkCorrect(const Code& guess) const;

    // right digit but wrong position (don't double count)
    int checkIncorrect(const Code& guess) const;

    // helper for testing (lets us set a guess easily)
    void setDigits(const std::vector<int>& v);

    void print() const;
};

#endif
