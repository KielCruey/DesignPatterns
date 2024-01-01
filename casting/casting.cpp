#include <iostream>

class Base
{
private:
    int baseVariable;

public:
    // ======== special class functions ========
    Base() : baseVariable(0)
    {
        std::cout << "Base object created" << std::endl;
    }

    virtual ~Base() 
    {  
        std::cout << "Base object destroyed" << std::endl;
    }

    // ======== virtual functions ========
    virtual void SomeFunction() {}

    // ======== getters/setters ========
    int GetBaseVariable()
    { 
        return this->baseVariable; 
    }

    void SetBaseVariable(int baseVariable)
    {
        this->baseVariable = baseVariable;
    }

    void printBaseVariable()
    {
        std::cout << "Base Variable: " + this->baseVariable << std::endl;
    }
};

class Derived : public Base
{
private:
    int derivedVariable;

public:
    // ======== special class functions ========
    Derived() : derivedVariable(1)
    {
        std::cout << "Derived object created" << std::endl;
    }

    ~Derived() override
    {
        std::cout << "Derived object destroyed" << std::endl;
    }

// ======== virtual functions ========
    virtual void SomeFunction() override
    {
        std::cout << "SomeFunction()" << std::endl;
    }

    // ======== general functions ========
    void DerivedFunction()
    {
        std::cout << "DerivedFunction()" << std::endl;
    }  

    // ======== getters/setters ========
    int GetDerivedVariable()
    {
        return this->derivedVariable;
    }

    void SetDerivedVariable(int derivedVariable)
    {
        this->derivedVariable = derivedVariable;
    }
};

Derived * DownCasting(Base * pBase)
{
    Derived * derived = dynamic_cast<Derived *>(pBase);
    return derived;
}

Base * UpCasting(Derived * pDerived)
{
    Base * base = dynamic_cast<Base *>(pDerived);
    return base;
}

int main()
{
    Base * base = new Base();
    base->printBaseVariable();
    
    Derived * derived = DownCasting(base); // downcasting
    base = UpCasting(derived); // upcasting

    return 0;
}