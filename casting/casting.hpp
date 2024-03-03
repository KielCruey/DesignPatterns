#include <iostream>
#include <typeinfo>

class Base
{
public:
    Base(int baseVariable = 10);
    virtual ~Base();

    virtual void SomeFunction();

    void PrintBaseVariable() const;

    int GetBaseVariable() const;
    void SetBaseVariable(int baseVariable);

private:
    int baseVariable;
};

class Derived : public Base
{
public:
    Derived(int derivedVariable = 100);
    ~Derived() override;

    void SomeFunction() override;

    void DerivedFunction();
    void PrintDerivedVariable() const;

    int GetDerivedVariable() const;
    void SetDerivedVariable(int derivedVariable);

private:
    int derivedVariable;
};