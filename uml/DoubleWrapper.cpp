#include <iostream>
#include "DoubleWrapper.hpp"
using namespace std;

DoubleWrapper::DoubleWrapper() : 
    value(0) 
{ }

DoubleWrapper::DoubleWrapper(double v) {
    value = new double (v);
}

void DoubleWrapper::setValue (double v) {
    if (value != 0) {
        delete value;
    }

    value = new double(v);
}

double DoubleWrapper::getValue() {
    if (value != 0) {
        return * value;
    }

    return -1;
}

DoubleWrapper::~DoubleWrapper ( )
{
    if (value != 0) {
        delete value;
        value = 0;
    }
}
