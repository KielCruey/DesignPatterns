#include <iostream>
#include <typeinfo>

class Base
{
private:
    int baseVariable;

public:
    // ======== special class functions ========
    Base();
    virtual ~Base();

    // ======== virtual functions ========
    virtual void SomeFunction();

    // ======== general functions ========
    void PrintBaseVariable();

    // ======== getters/setters ========
    int GetBaseVariable();
    void SetBaseVariable(int baseVariable);
};

class Derived : public Base
{
private:
    int derivedVariable;

public:
    // ======== special class functions ========
    Derived();
    ~Derived() override;

    // ======== virtual functions ========
    virtual void SomeFunction() override;

    // ======== general functions ========
    void DerivedFunction();

    // ======== general functions ========
    void PrintDerivedVariable();

    // ======== getters/setters ========
    int GetDerivedVariable();
    void SetDerivedVariable(int derivedVariable);
};