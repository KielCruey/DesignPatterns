#include <iostream>

#include "APrinter.hpp"
using namespace std;

APrinter::APrinter(DoubleWrapper * value) :
    doubleValue(value)
{ }

void APrinter::print() {
    if (doubleValue != 0) {
        cout << doubleValue->getValue() << endl;
    }
    else {
        cout << "undefined" << endl;
    }
}

void APrinter::update(DoubleWrapper * doubleValue) {
    this->doubleValue = doubleValue;
}

APrinter::~APrinter() {
    doubleValue = 0;
}
