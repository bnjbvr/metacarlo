#include <iostream>

#ifndef SEED
// Pseudo random numbers generator's seed.
// Pick any number, I dare you, I double dare you.
const int SEED = 0;
#endif

// Computes Pi value at compile time.

// Number of loop iterations
// Putting a too damn high number here can slow down compilation.
#ifndef ITER
const unsigned ITER = 10000000;
#endif

// Linear Congruent Generator
// a is the multiplicative coefficient
// b is the additive coefficient
const long long unsigned a = 1103515245, b = 12345;

// Radius of the circle
// Should be small enough so that radius * radius doesn't overflow.
const int radius = 10000;

struct LCG {
    int prev;
    constexpr LCG(int seed) : prev(seed) {}
    constexpr int next() {
        int ret = prev;
        prev = a * prev + b;
        return ret;
    }
};

// Pick (a,b) in a square of size radius * radius.
// Probability " (a,b) in the circle "
//      = num(points in the circle) / num(total)        // empirically
//      = area(circle) / area(square)                   // theoritically
//      = pi * r * r / (2 * r * 2 * r)
//      = pi / 4
constexpr unsigned loop(int n) {
    int count = 0;
    LCG lcg{SEED};
    for (unsigned i = 0; i < n; i++) {
        int a = lcg.next() % radius;
        int b = lcg.next() % radius;
        if ((a * a + b * b) < radius * radius)
            ++count;
    }
    return count;
}

int main()
{
    constexpr double pi = 4 * loop(ITER) / double(ITER);
    printf("The answer is %.10f\n", pi);
    return 0;
}
