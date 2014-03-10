#include <iostream>

#ifndef SEED
// Pseudo random numbers generator's seed.
// Pick any number, I dare you, I double dare you.
const int SEED = 0;
#endif

// Computes Pi value at compile time.

// Number of loop iterations
// Putting a too damn high number here can kill your compiler
const int n = 20000;

// Linear Congruent Generator
// a is the multiplicative coefficient
// b is the additive coefficient
const int a = 1103515245, b = 12345;

template<int A>
struct LCG
{
    enum { v = a * LCG<A-1>::v + b };
};

template<>
struct LCG<0>
{
    enum { v = SEED };
};

// Radius of the circle
// Should be small enough so that radius * radius doesn't overflow.
const int radius = 10000;

// Generates two random numbers
template<int i>
struct Try
{
    enum {
        a = LCG<2 * i>::v % radius,
        b = LCG<2 * i + 1>::v % radius
    };
};

template<int i>
struct IsInCircle
{
    enum { is = ( Try<i>::a * Try<i>::a + Try<i>::b * Try<i>::b ) < radius * radius };
};

// Pick (a,b) in a square of size radius * radius.
// Probability " (a,b) in the circle "
//      = num(points in the circle) / num(total)        // empirically
//      = area(circle) / area(square)                   // theoritically
//      = pi * r * r / (2 * r * 2 * r)
//      = pi / 4
template<int n>
struct Loop
{
    enum { v = Loop<n-1>::v + IsInCircle<n>::is };
};

template<>
struct Loop<-1>
{
    enum { v = 0 };
};

int main()
{
    double pi = 0.;
    pi = 4 * Loop<n>::v / double(n);
    std::cout << "The answer is " << pi << std::endl;
    return 0;
}

