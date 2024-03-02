class DoubleWrapper
{
public:
    DoubleWrapper();
    DoubleWrapper(double v);
    ~DoubleWrapper();
    void setValue(double v) ;
    double getValue();
private:
    double * value;
} ;