#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber();
    ComplexNumber(double real, double imaginary);

    double getReal() const;
    void setReal(double real);
    double getImaginary() const;
    void setImaginary(double imaginary);

    ComplexNumber add(const ComplexNumber &other) const;
    ComplexNumber subtract(const ComplexNumber &other) const;
    ComplexNumber multiply(const ComplexNumber &other) const;
    ComplexNumber divide(const ComplexNumber &other) const;

    bool isEqual(const ComplexNumber &other) const;
    bool isEqualToReal(double value) const;
    ComplexNumber power(int exponent) const;

    double getModulus() const;

    void print() const;
};

#endif
