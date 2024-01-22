#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <cmath>
#include <iostream>

template<typename T>
class ComplexNumber {
private:
    T real;
    T imaginary;

public:
    ComplexNumber();

    ComplexNumber(T real, T imaginary);

    T getReal() const;

    void setReal(T real);

    T getImaginary() const;

    void setImaginary(T imaginary);

    ComplexNumber<T> add(const ComplexNumber<T> &other) const;

    ComplexNumber<T> subtract(const ComplexNumber<T> &other) const;

    ComplexNumber<T> multiply(const ComplexNumber<T> &other) const;

    ComplexNumber<T> divide(const ComplexNumber<T> &other) const;

    bool isEqual(const ComplexNumber<T> &other) const;

    bool isEqualToReal(T value) const;

    ComplexNumber<T> power(int exponent) const;

    double getModulus() const;

    void print() const;

    explicit operator int() const;
    explicit operator float() const;
    operator std::string() const;
};


#endif
