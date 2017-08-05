#include "mathpp.h"
#include <cmath>
#include <iostream>

namespace mathpp {

    unsigned long long int hyper (
        unsigned int order, unsigned int a, unsigned int b) {
        // Gives the result of a hyperoperation of order specified. Only accepts
        // unsigned integers as order and operand values.
        if (order == 0) {
            return b + 1;
        }
        else if (order == 1 && b == 0) {
            return a;
        }
        else if (order == 2 && b == 0) {
            return 0;
        }
        else if (order > 2 && b == 0) {
            return 1;
        }
        else {
            return hyper (order-1, a, hyper(order, a, b-1));
        }
    }
    bool pythagorean(double a, double b, double c) {
        // Returns whether a, b, and c are a Pythagorean triple. Works for any
        // ordering of the values given.
        double sides[3] = {a, b, c};
        std::sort(sides, sides+3);
        return hypot(sides[0], sides[1]) == sides[2];
    }
    long long int fib (int n) {
        // Formulaic function for generation of members of the Fibonacci
        // sequence. Note that all results may not be 100% correct, due to
        // rounding.
        double phi = (sqrt(5) + 1) / 2;
        double lowerphi = phi - 1;
        double fibval = (pow(phi, n) - pow(-lowerphi, n)) / sqrt(5);
        return round(fibval);

    }
    long long int recurfib (int n) {
        // Recursive function for generation of members of the Fibonacci
        // sequence.
        if (n < 0) {
            return pow(-1, n+1) * recurfib (-n);
        }
        else if (n == 0) {return 0;}
        else if (n == 1) {return 1;}
        else if (n > 1) {
            return recurfib(n-1) + recurfib(n-2);
        }
    }
    unsigned int hcf(unsigned int a, unsigned int b) {
        // Returns the highest common factor of a and b.
        int i = a;
        while (a%i || b%i) {
            i--;
        }
        return i;
    }
}
