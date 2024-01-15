#include "casting.hpp"

// ================ Base ================
Base::Base() : 
    baseVariable(0)
{
    std::cout << "Base object created" << std::endl;
}

Base::~Base() 
{  
    std::cout << "Base object destroyed" << std::endl;
}

void Base::SomeFunction()
{

}

void Base::PrintBaseVariable()
{
    std::cout << "Base Variable: " << this->baseVariable << std::endl;
}

int Base::GetBaseVariable()
{ 
    return this->baseVariable; 
}

void Base::SetBaseVariable(int baseVariable)
{
    this->baseVariable = baseVariable;
}

// ================ Derived ================
Derived::Derived() :
    derivedVariable(1)
{
    std::cout << "Derived object created" << std::endl;
}

Derived::~Derived() 
{
    std::cout << "Derived object destroyed" << std::endl;
}

void Derived::SomeFunction()
{
    std::cout << "SomeFunction()" << std::endl;
}

void Derived::DerivedFunction()
{
    std::cout << "DerivedFunction()" << std::endl;
}  

void Derived::PrintDerivedVariable()
{
    std::cout << "Derived Variable: " << this->derivedVariable << std::endl;
}

int Derived::GetDerivedVariable()
{
    return this->derivedVariable;
}

void Derived::SetDerivedVariable(int derivedVariable)
{
    this->derivedVariable = derivedVariable;
}

// ================ Client Code ================
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

// ================ Main ================
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