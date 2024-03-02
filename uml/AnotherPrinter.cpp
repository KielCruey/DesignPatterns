#include <iostream>
#include "AnotherPrinter.hpp"

using namespace std;

AnotherPrinter::AnotherPrinter(RobustDoubleWrapper * value) {
    // cannot use initialiser list owning to dereferncing needed
    doubleValue = *value;
}

void AnotherPrinter::print() {
    // no condition needed −− double Value is on the stack
    // also note the use of . instead of −> to call the function
    cout << doubleValue.getValue() << endl;
}

void AnotherPrinter::update(RobustDoubleWrapper * value) {
    // dereference value before assigning
    doubleValue = *value;
}

AnotherPrinter::~AnotherPrinter() {}
// doubleValue is on the stack and is automatically released