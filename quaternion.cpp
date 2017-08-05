#include <ostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <complex>
#include <cmath>
#include "mathpp.h"

namespace mathpp {

    Quaternion::Quaternion() {
    	a = 0.0;
    	b = 0.0;
    	c = 0.0;
    	d = 0.0;
    }

    Quaternion::Quaternion(double part1) {
    	a = part1;
    	b = 0.0;
    	c = 0.0;
    	d = 0.0;
    }

    Quaternion::Quaternion(double part1, double part2) {
    	a = part1;
    	b = part2;
    	c = 0.0;
    	d = 0.0;
    }

    Quaternion::Quaternion(double part1, double part2, double part3) {
    	a = part1;
    	b = part2;
    	c = part3;
    	d = 0.0;
    }

    Quaternion::Quaternion(double part1, double part2, double part3, double part4) {
    	a = part1;
    	b = part2;
    	c = part3;
    	d = part4;
    }

    Quaternion::Quaternion(std::complex<double> part1) {
    	a = part1.real();
    	b = part1.imag();
    	c = 0.0;
    	d = 0.0;
    }

    Quaternion Quaternion::operator+ (const Quaternion& other) {
    	Quaternion result;
    	result.a = a + other.a;
    	result.b = b + other.b;
    	result.c = c + other.c;
    	result.d = d + other.d;
    	return result;
    }

    Quaternion Quaternion::operator+ (const double& other) {
    	Quaternion qother (other);
    	Quaternion result;
    	result.a = a + qother.a;
    	result.b = b + qother.b;
    	result.c = c + qother.c;
    	result.d = d + qother.d;
    	return result;
    }

    Quaternion Quaternion::operator+ (const std::complex<double>& other) {
    	Quaternion qother(other);
    	Quaternion result;
    	result.a = a + qother.a;
    	result.b = b + qother.b;
    	result.c = c + qother.c;
    	result.d = d + qother.d;
    	return result;
    }

    Quaternion Quaternion::operator- (const Quaternion& other) {
    	Quaternion result;
    	result.a = a - other.a;
    	result.b = b - other.b;
    	result.c = c - other.c;
    	result.d = d - other.d;
    	return result;
    }

    Quaternion Quaternion::operator- (const double& other) {
    	Quaternion qother(other);
    	Quaternion result;
    	result.a = a - qother.a;
    	result.b = b - qother.b;
    	result.c = c - qother.c;
    	result.d = d - qother.d;
    	return result;
    }

    Quaternion Quaternion::operator- (const std::complex<double>& other) {
    	Quaternion qother(other);
    	Quaternion result;
    	result.a = a - qother.a;
    	result.b = b - qother.b;
    	result.c = c - qother.c;
    	result.d = d - qother.d;
    	return result;
    }

    Quaternion Quaternion::operator* (const Quaternion& other) {
    	float atotal = ((a * other.a) - (b * other.b)
    		- (c * other.c)- (d * other.d));
    	float btotal = ((a * other.b) + (b * other.a)
    		+ (c * other.d) - (d * other.c));
    	float ctotal = ((a * other.c) - (b * other.d)
    		+ (c * other.a) + (d * other.b));
    	float dtotal = ((a * other.d) + (b * other.c)
    		- (c * other.b) + (d * other.a));
    	Quaternion result(atotal, btotal, ctotal, dtotal);
    	return result;
    }

    Quaternion Quaternion::operator* (const double& other) {
    	Quaternion qother(other);
    	float atotal = ((a * qother.a) - (b * qother.b)
    		- (c * qother.c) - (d * qother.d));
    	float btotal = ((a * qother.b) + (b * qother.a)
    		+ (c * qother.d) - (d * qother.c));
    	float ctotal = ((a * qother.c) - (b * qother.d)
    		+ (c * qother.a) + (d * qother.b));
    	float dtotal = ((a * qother.d) + (b * qother.c)
    		- (c * qother.b) + (d * qother.a));
    	Quaternion result(atotal, btotal, ctotal, dtotal);
    	return result;
    }

    Quaternion Quaternion::operator* (const std::complex<double>& other) {
    	Quaternion qother(other);
    	float atotal = ((a * qother.a) - (b * qother.b)
    		- (c * qother.c) - (d * qother.d));
    	float btotal = ((a * qother.b) + (b * qother.a)
    		+ (c * qother.d) - (d * qother.c));
    	float ctotal = ((a * qother.c) - (b * qother.d)
    		+ (c * qother.a) + (d * qother.b));
    	float dtotal = ((a * qother.d) + (b * qother.c)
    		- (c * qother.b) + (d * qother.a));
    	Quaternion result(atotal, btotal, ctotal, dtotal);
    	return result;
    }

    Quaternion Quaternion::operator/ (const Quaternion& other) {
    	float denominator = (pow(other.a, 2) + pow(other.b, 2)
    		+ pow(other.c, 2) + pow(other.d, 2));
    	float atotal = ((a * other.a) + (b * other.b)
    		+ (c * other.c) + (d * other.d)) / denominator;
    	float btotal = ((b * other.a) - (a * other.b)
    		- (d * other.c) + (c * other.d)) / denominator;
    	float ctotal = ((c * other.a) + (d * other.b)
    		- (a * other.c) - (b * other.d)) / denominator;
    	float dtotal = ((d * other.a) - (c * other.b)
    		+ (b * other.c) - (a * other.d)) / denominator;
    	Quaternion result(atotal, btotal, ctotal, dtotal);
    	return result;
    }

    Quaternion Quaternion::operator/ (const double& other) {
    	Quaternion qother(other);
    	float denominator = (pow(qother.a, 2) + pow(qother.b, 2)
    		+ pow(qother.c, 2) + pow(qother.d, 2));
    	float atotal = ((a * qother.a) + (b * qother.b)
    		+ (c * qother.c) + (d * qother.d)) / denominator;
    	float btotal = ((b * qother.a) - (a * qother.b)
    		- (d * qother.c) + (c * qother.d)) / denominator;
    	float ctotal = ((c * qother.a) + (d * qother.b)
    		- (a * qother.c) - (b * qother.d)) / denominator;
    	float dtotal = ((d * qother.a) - (c * qother.b)
    		+ (b * qother.c) - (a * qother.d)) / denominator;
    	Quaternion result(atotal, btotal, ctotal, dtotal);
    	return result;
    }

    Quaternion Quaternion::operator/ (const std::complex<double>& other) {
    	Quaternion qother(other);
    	float denominator = (pow(qother.a, 2) + pow(qother.b, 2) + pow(qother.c, 2) + pow(qother.d, 2));
    	float atotal = ((a * qother.a) + (b * qother.b)
    		+ (c * qother.c) + (d * qother.d)) / denominator;
    	float btotal = ((b * qother.a) - (a * qother.b)
    		- (d * qother.c) + (c * qother.d)) / denominator;
    	float ctotal = ((c * qother.a) + (d * qother.b)
    		- (a * qother.c) - (b * qother.d)) / denominator;
    	float dtotal = ((d * qother.a) - (c * qother.b)
    		+ (b * qother.c) - (a * qother.d)) / denominator;
    	Quaternion result(atotal, btotal, ctotal, dtotal);
    	return result;
    }

    Quaternion operator+ (const double& other, const Quaternion& qua) {
    	Quaternion qother(other);
    	return qother + qua;
    }

    Quaternion operator+ (const std::complex<double>& other, const Quaternion& qua) {
    	Quaternion qother(other);
    	return qother + qua;
    }

    Quaternion operator- (const double& other, const Quaternion& qua) {
    	Quaternion qother(other);
    	return qother - qua;
    }

    Quaternion operator- (const std::complex<double>& other, const Quaternion& qua) {
    	Quaternion qother(other);
    	return qother - qua;
    }

    Quaternion operator* (const double& other, const Quaternion& qua) {
    	Quaternion qother(other);
    	return qother * qua;
    }

    Quaternion operator/ (const std::complex<double>& other, const Quaternion& qua) {
    	Quaternion qother(other);
    	return qother / qua;
    }

    Quaternion::operator std::string() const {
    	std::stringstream stream;
    	stream << a << " + " << b << "i + " << c << "j + " << d << "k";
    	return stream.str();
    }

    Quaternion::operator std::complex<double>() {
    	std::complex<double> com(a, b);
    	return com;
    }

    Quaternion::operator std::complex<float>() {
    	std::complex<float> com(a, b);
    	return com;
    }

    Quaternion::operator std::complex<int>() {
    	std::complex<int> com(a, b);
    	return com;
    }

    Quaternion::operator double() const {
    	return a;
    }

    Quaternion::operator float() const {
    	return a;
    }

    Quaternion::operator int() const {
    	return a;
    }

    std::ostream& operator<<(std::ostream& stream, const Quaternion& qua) {
    	stream << (std::string)qua;
    	return stream;

    }
}
