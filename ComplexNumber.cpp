#include <cmath>
#include <iostream>
#include "ComplexNumber.h"

constexpr double EPSILON = 1e-9;

template<typename T>
ComplexNumber<T>::ComplexNumber() : real(0), imaginary(0) {}

template<typename T>
ComplexNumber<T>::ComplexNumber(T real, T imaginary) : real(real), imaginary(imaginary) {
}

template<typename T>
T ComplexNumber<T>::getReal() const {
    return real;
}

template<typename T>
void ComplexNumber<T>::setReal(T real) {
    this->real = real;
}

template<typename T>
T ComplexNumber<T>::getImaginary() const {
    return imaginary;
}

template<typename T>
void ComplexNumber<T>::setImaginary(T imaginary) {
    this->imaginary = imaginary;
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::add(const ComplexNumber<T> &other) const {
    return ComplexNumber<T>(real + other.real, imaginary + other.imaginary);
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::subtract(const ComplexNumber<T> &other) const {
    return ComplexNumber<T>(real - other.real, imaginary - other.imaginary);
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::multiply(const ComplexNumber<T> &other) const {
    return ComplexNumber<T>(
            real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real
    );
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::divide(const ComplexNumber<T> &other) const {
    T denominator = other.real * other.real + other.imaginary * other.imaginary;


    if (std::abs(denominator) < EPSILON) {
        throw std::runtime_error("Division by zero");
    }

    return ComplexNumber<T>(
            (real * other.real + imaginary * other.imaginary) / denominator,
            (imaginary * other.real - real * other.imaginary) / denominator
    );
}

template<typename T>
bool ComplexNumber<T>::isEqual(const ComplexNumber<T> &other) const {
    return (std::abs(real - other.real) < EPSILON) && (std::abs(imaginary - other.imaginary) < EPSILON);
}

template<typename T>
bool ComplexNumber<T>::isEqualToReal(T value) const {
    return (std::abs(real - value) < EPSILON) && (std::abs(imaginary) < EPSILON);
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::power(int exponent) const {

    if (exponent == 0) {
        return ComplexNumber<T>(1, 0);
    }

    ComplexNumber<T> result = *this;
    for (int i = 1; i < exponent; ++i) {
        result = result.multiply(*this);
    }

    return result;
}


template<typename T>
double ComplexNumber<T>::getModulus() const {
    return sqrt(real * real + imaginary * imaginary);
}


template<typename T>
void ComplexNumber<T>::print() const {
    std::cout << "(" << real << " + " << imaginary << "i)" << std::endl;
}

template
class ComplexNumber<double>;

template
class ComplexNumber<int>;
