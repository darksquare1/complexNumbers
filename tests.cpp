#include "ComplexNumber.h"
#include <cassert>
#include <iostream>
#include <cmath>

int main() {

    // Double precision tests
    ComplexNumber<double> c1(2, 3);
    ComplexNumber<double> c2(1, -2);
    ComplexNumber<double> c3(5, 0);
    ComplexNumber<double> c5(0, 0);

    // Test addition
    assert(c1.add(c2).isEqual(ComplexNumber<double>(3, 1)));

    // Test subtraction
    assert(c1.subtract(c2).isEqual(ComplexNumber<double>(1, 5)));

    // Test multiplication
    assert(c1.multiply(c2).isEqual(ComplexNumber<double>(8, -1)));

    // Test division
    assert(c1.divide(c2).isEqual(ComplexNumber<double>(-0.8, 1.4)));

    // Test equality to real number
    assert(c3.isEqualToReal(5));
    assert(!c1.isEqualToReal(2));

    // Test power
    assert(c1.power(2).isEqual(ComplexNumber<double>(-5, 12)));

    // Test modulus
    assert(std::abs(c1.getModulus() - std::sqrt(13.0)) < 10e-9);

    // Test division by zero
    try {
        c5.divide(c5);
        assert(false);
    } catch (const std::runtime_error &e) {
        assert(std::string(e.what()) == "Division by zero");
    }

    // Integer precision tests
    ComplexNumber<int> c6(2, 3);
    ComplexNumber<int> c7(1, -2);
    ComplexNumber<int> c8(5, 0);
    ComplexNumber<int> c10(0, 0);

    // Test addition
    assert(c6.add(c7).isEqual(ComplexNumber<int>(3, 1)));

    // Test subtraction
    assert(c6.subtract(c7).isEqual(ComplexNumber<int>(1, 5)));

    // Test multiplication
    assert(c6.multiply(c7).isEqual(ComplexNumber<int>(8, -1)));

    // Test division
    assert(c6.divide(c7).isEqual(ComplexNumber<int>(0, 1)));

    // Test equality to real number
    assert(c8.isEqualToReal(5));
    assert(!c6.isEqualToReal(2));

    // Test power
    assert(c6.power(2).isEqual(ComplexNumber<int>(-5, 12)));

    // Test modulus
    assert(std::abs(c6.getModulus() - std::sqrt(13.0)) < 1e-10);

    // Test division by zero
    try {
        c10.divide(c10);
        assert(false);
    } catch (const std::runtime_error &e) {
        assert(std::string(e.what()) == "Division by zero");
    }

    // Double precision tests
    ComplexNumber<double> c11(2.5, 3.7);

    // Test cast to int
    int intValue = static_cast<int>(c11);
    assert(intValue == 2);

    // Test cast to float
    float floatValue = static_cast<float>(c11);
    assert(std::abs(floatValue - 2.5) < 10e-9);

    // Test cast to string
    std::string stringValue = static_cast<std::string>(c11);
    std::cout << "stringValue: " << stringValue << std::endl;
    assert(stringValue == "(2.5 + 3.7i)");

    // Integer precision tests
    ComplexNumber<int> c12(2, 3);

    // Test cast to int
    int intValue2 = static_cast<int>(c12);
    assert(intValue2 == 2);

    // Test cast to float
    float floatValue2 = static_cast<float>(c12);
    assert(std::abs(floatValue2 - 2) < 10e-9);

    // Test cast to float
    std::string stringValue2 = static_cast<std::string>(c12);
    assert(stringValue2 == "(2 + 3i)");

    std::cout << "All tests passed" << std::endl;

    return 0;
}
