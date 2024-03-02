#include <iostream>
#include "CrazyPrinter.hpp"

CrazyPrinter::CrazyPrinter() 
{ }

void CrazyPrinter::print(DoubleWrapper * val)
{
    std::cout << val->getValue() << std::endl;
}