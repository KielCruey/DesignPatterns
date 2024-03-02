class RobustDoubleWrapper
{
public:
    RobustDoubleWrapper ( ) ;
    
    // copy constructor added
    RobustDoubleWrapper(const RobustDoubleWrapper &);
    RobustDoubleWrapper(double);
    ~RobustDoubleWrapper();

    // assignment operator added
    RobustDoubleWrapper& operator = (const RobustDoubleWrapper &);
    void setValue(double);
    double getValue();

private:
    double * value;
};