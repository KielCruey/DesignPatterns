#include <iostream>
#include "RobustDoubleWrapper.hpp"
using namespace std ;

RobustDoubleWrapper::RobustDoubleWrapper() : 
    value(0) 
{ }

RobustDoubleWrapper::RobustDoubleWrapper (const RobustDoubleWrapper& c)
{
    if (value != 0) {
        delete value;
    }

    value = new double (*(c.value));
}

RobustDoubleWrapper::RobustDoubleWrapper(double v) {
    value = new double(v);
}

RobustDoubleWrapper::~RobustDoubleWrapper() {
    if (value != 0) {
        delete value;
        value = 0;
    }
}

RobustDoubleWrapper& RobustDoubleWrapper::operator= (const RobustDoubleWrapper& s ) {
    if (value != 0) {
        delete value;
    }

    value = new double (*(s.value));
    return *this;
}

void RobustDoubleWrapper::setValue(double v) {
    if (value != 0) {
        delete value;
    }

    value = new double(v);
}

double RobustDoubleWrapper::getValue()
{
    if (value != 0) {
        return *value;
    }

    return -1;
}