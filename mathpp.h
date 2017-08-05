#ifndef MATHPP_H
#define MATHPP_H

#include <ostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <complex>

namespace mathpp {

    class Quaternion {
        // Represents a four-dimensional quaternion number. Defined are methods
        // to deal with simple arithmetic (addition, subtraction,
        // multiplication, and division). Conversion methods also exist for int,
        // float, double, std::string, and std::complex types.
    public:
        double a;
        double b;
        double c;
        double d;
        Quaternion();
        Quaternion(double part1);
        Quaternion(double part1, double part2);
        Quaternion(double part1, double part2, double part3);
        Quaternion(double part1, double part2, double part3, double part4);
        Quaternion(std::complex<double> part1);
        Quaternion operator+ (const Quaternion& other);
        Quaternion operator+ (const double& other);
        Quaternion operator+ (const std::complex<double>& other);
        Quaternion operator- (const Quaternion& other);
        Quaternion operator- (const double& other);
        Quaternion operator- (const std::complex<double>& other);
        Quaternion operator* (const Quaternion& other);
        Quaternion operator* (const double& other);
        Quaternion operator* (const std::complex<double>& other);
        Quaternion operator/ (const Quaternion& other);
        Quaternion operator/ (const double& other);
        Quaternion operator/ (const std::complex<double>& other);
        operator std::string() const;
        operator std::complex<double>();
        operator std::complex<float>();
        operator std::complex<int>();
        operator double() const;
        operator float() const;
        operator int() const;
        friend std::ostream& operator<<(std::ostream& stream, const Quaternion& qua);
    };

    Quaternion operator+ (const double& other, const Quaternion& qua);
    Quaternion operator+ (const std::complex<double>& other, const Quaternion& qua);
    Quaternion operator- (const double& other, const Quaternion& qua);
    Quaternion operator- (const std::complex<double>& other, const Quaternion& qua);
    Quaternion operator* (const double& other, const Quaternion& qua);
    Quaternion operator/ (const std::complex<double>& other, const Quaternion& qua);

    class Fraction {
        int numerator;
        int denominator;
    public:
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(double decimal);
        Fraction operator+ (const Fraction& other);
        Fraction operator+ (const double& other);
        Fraction operator- (const Fraction& other);
        Fraction operator- (const double& other);
        Fraction operator* (const Fraction& other);
        Fraction operator* (const double& other);
        Fraction operator/ (const Fraction& other);
        Fraction operator/ (const double& other);
        operator std::string() const;
        friend std::ostream& operator<<(std::ostream& stream, const Fraction& fra);
    };

    Fraction operator+ (const double& other, const Fraction& qua);
    Fraction operator- (const double& other, const Fraction& qua);
    Fraction operator* (const double& other, const Fraction& qua);
    Fraction operator/ (const double& other, const Fraction& qua);

    unsigned long long int hyper (
        unsigned int order, unsigned int a, unsigned int b);
    bool pythagorean(double a, double b, double c);
    long long int fib (int n);
    long long int recurfib (int n);
    unsigned int hcf(unsigned int a, unsigned int b);
}

#endif
