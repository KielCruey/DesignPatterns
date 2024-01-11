#include <iostream>
#include <typeinfo>

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

    // ======== general functions ========
    void PrintBaseVariable()
    {
        std::cout << "Base Variable: " << this->baseVariable << std::endl;
    }

    // ======== getters/setters ========
    int GetBaseVariable()
    { 
        return this->baseVariable; 
    }

    void SetBaseVariable(int baseVariable)
    {
        this->baseVariable = baseVariable;
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

    // ======== general functions ========
    void PrintDerivedVariable()
    {
        std::cout << "Derived Variable: " << this->derivedVariable << std::endl;
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

void CheckSameTypes(void * class1, void * class2)
{
    if(typeid(class1).name() == typeid(class2).name())
    {
        std::cout << "Same types" << std::endl;
    }
    else
    {
        std::cout << "Different types" << std::endl;
    }
}

// ======== Main ========
int main()
{
    /*
    Base * base = new Base();
    base->PrintBaseVariable();
    Derived * derived = DownCasting(base); // downcasting
    derived->PrintDerivedVariable();
    base = UpCasting(derived); // upcasting
    */

    Base * base = new Base();

    Derived * derived = new Derived();
    derived->PrintDerivedVariable();
    derived->PrintBaseVariable();

    std::cout << typeid(base).name() << std::endl;
    std::cout << typeid(derived).name() << std::endl;

    return 0;
}