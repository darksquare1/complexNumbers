#include "ComplexNumber.h"
#include <cassert>
#include <iostream>
#include <cmath>

int main() {
    ComplexNumber c1(2, 3);
    ComplexNumber c2(1, -2);
    ComplexNumber c3(5, 0);

    assert(c1.add(c2).isEqual(ComplexNumber(3, 1)));
    assert(c1.subtract(c2).isEqual(ComplexNumber(1, 5)));
    assert(c1.multiply(c2).isEqual(ComplexNumber(8, -1)));
    assert(c1.divide(c2).isEqual(ComplexNumber(-0.8, 1.4)));

    assert(c3.isEqualToReal(5));
    assert(!c1.isEqualToReal(2));

    assert(c1.power(2).isEqual(ComplexNumber(-5, 12)));

    assert(std::abs(c1.getModulus() - sqrt(13)) < 10e-9);

    c1.print();
    c2.print();
    c3.print();

    std::cout << "Tests passed" << std::endl;

    return 0;
}
