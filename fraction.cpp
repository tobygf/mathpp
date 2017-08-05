#include "mathpp.h"
#include <iostream>
#include <stdexcept>
#include <cmath>


namespace mathpp {
    Fraction::Fraction() {
        numerator = 1;
        denominator = 1;
    }
    Fraction::Fraction(int num, int den) {
        if (den < 0) {
            den = -den;
            num = -num;
        }
        if (den) {
            int i = hcf(abs(num), den);
            numerator = num/i;
            denominator = den/i;
        }
        else {
            throw std::invalid_argument("Denominator must not be 0");
        }
    }

    Fraction::Fraction(double decimal) {
        int i = 1;
        while (decimal*i != floor(decimal*i)) {
            i++;
        }
        numerator = decimal*i;
        denominator = i;
    }


    Fraction Fraction::operator+ (const Fraction& other) {
        int den = denominator * other.denominator;
        int num1 = numerator * other.denominator;
        int num2 = other.numerator * denominator;
        Fraction result (num1+num2, den);
        return result;
    }




    Fraction::operator std::string() const {
    	std::stringstream stream;
    	stream << numerator << "/" << denominator;
    	return stream.str();
    }
    std::ostream& operator<<(std::ostream& stream, const Fraction& fra) {
    	stream << (std::string)fra;
    	return stream;
    }
}