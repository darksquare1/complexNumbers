#include "ComplexNumber.h"
#include <iostream>
#include <cmath>

constexpr double EPSILON = 1e-9;

ComplexNumber::ComplexNumber() : real(0), imaginary(0) {}

ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {}

double ComplexNumber::getReal() const {
    return real;
}

void ComplexNumber::setReal(double real) {
    this->real = real;
}

double ComplexNumber::getImaginary() const {
    return imaginary;
}

void ComplexNumber::setImaginary(double imaginary) {
    this->imaginary = imaginary;
}

ComplexNumber ComplexNumber::add(const ComplexNumber &other) const {
    return ComplexNumber(real + other.real, imaginary + other.imaginary);
}

ComplexNumber ComplexNumber::subtract(const ComplexNumber &other) const {
    return ComplexNumber(real - other.real, imaginary - other.imaginary);
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber &other) const {
    return ComplexNumber(
            real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real
    );
}

ComplexNumber ComplexNumber::divide(const ComplexNumber &other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    return ComplexNumber(
            (real * other.real + imaginary * other.imaginary) / denominator,
            (imaginary * other.real - real * other.imaginary) / denominator
    );
}

bool ComplexNumber::isEqual(const ComplexNumber &other) const {
    return (std::abs(real - other.real) < EPSILON) && (std::abs(imaginary - other.imaginary) < EPSILON);
}

bool ComplexNumber::isEqualToReal(double value) const {
    return (std::abs(real - value) < EPSILON) && (std::abs(imaginary) < EPSILON);
}

ComplexNumber ComplexNumber::power(int exponent) const {
    double r = pow(getModulus(), exponent);
    double theta = atan2(imaginary, real);
    double newReal = r * cos(exponent * theta);
    double newImaginary = r * sin(exponent * theta);
    return ComplexNumber(newReal, newImaginary);
}

double ComplexNumber::getModulus() const {
    return sqrt(real * real + imaginary * imaginary);
}

void ComplexNumber::print() const {
    std::cout << "(" << real << " + " << imaginary << "i)" << std::endl;
}
