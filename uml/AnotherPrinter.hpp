#include "RobustDoubleWrapper.hpp"
class AnotherPrinter
{
public:
    AnotherPrinter(RobustDoubleWrapper * doubleValue);
    ~AnotherPrinter();
    void print();
    void update(RobustDoubleWrapper * doubleValue);

protected:
    AnotherPrinter();
    
private:
    RobustDoubleWrapper doubleValue;
};
