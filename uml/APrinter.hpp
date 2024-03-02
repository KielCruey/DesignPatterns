#include "DoubleWrapper.hpp"

class APrinter
{
public:
    APrinter(DoubleWrapper * value) ;
    ~APrinter();
    void print();
    void update(DoubleWrapper * doubleValue);

protected:
    APrinter() = default;

private:
    DoubleWrapper * doubleValue;
};
