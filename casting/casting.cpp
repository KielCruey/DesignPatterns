#include "casting.hpp"

// ================ Base ================
Base::Base(int baseVariable) : 
    baseVariable(baseVariable)
{
    std::cout << "Base object created" << std::endl;
}

Base::~Base() {  
    std::cout << "Base object destroyed" << std::endl;
}

void Base::SomeFunction() {
    std::cout << "Base -- SomeFunction" << std::endl;
}

void Base::PrintBaseVariable() {
    std::cout << "Base Variable: " << this->baseVariable << std::endl;
}

int Base::GetBaseVariable() { 
    return this->baseVariable; 
}

void Base::SetBaseVariable(int baseVariable) {
    this->baseVariable = baseVariable;
}

// ================ Derived ================
Derived::Derived(int derivedVariable) :
    Base(),
    derivedVariable(derivedVariable)
{
    std::cout << "Derived object created" << std::endl;
}

Derived::~Derived() {
    std::cout << "Derived object destroyed" << std::endl;
}

void Derived::SomeFunction() {
    std::cout << "Derived -- SomeFunction" << std::endl;
}

void Derived::DerivedFunction() {
    std::cout << "Derived -- DerivedFunction" << std::endl;
}  

void Derived::PrintDerivedVariable() {
    std::cout << "Derived Variable: " << this->derivedVariable << std::endl;
}

int Derived::GetDerivedVariable() {
    return this->derivedVariable;
}

void Derived::SetDerivedVariable(int derivedVariable) {
    this->derivedVariable = derivedVariable;
}

// ================ Client Code ================
Derived * DownCasting(Base * pBase) {
    Derived * derived = dynamic_cast<Derived *>(pBase);

    // there's a chance that downcasting can cause a nullptr
    if(derived) {
        return derived;
    }
    else return nullptr;
}

Base * UpCasting(Derived * pDerived) {
    Base * base = dynamic_cast<Base *>(pDerived);
    return base;
}

// example will cast nullptr because the definition of the created
// base doesn't know about the derived part of the hierachy
static void NullCasingExample() {
    Base * base = new Base();

    // will return nullptr
    Derived * derived = DownCasting(base);

    // checks nullptr
    if (!derived) {
        delete derived;
        delete base;
    }
    else delete base;
}

static void SuccessfulDownCasting() {
    Base * base = new Derived(); // possible -- derived class is a base class

    // successful case
    Derived * derived = DownCasting(base);

    // checks nullptr
    if (!derived) {
        delete derived;
        delete base;
    }
    else delete base;
}

// ================ Main ================
int main()
{  
    // example of failed cast
    NullCasingExample();

    SuccessfulDownCasting();

    return 0;
}