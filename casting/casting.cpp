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

int main()
{
    Base * base = new Base();
    int tempBaseVariable = base->GetBaseVariable(); 
    std::cout << "temp Base Variable: " + tempBaseVariable << std::endl;

    // downcasting
    Derived * derived = DownCasting(base);

    return 0;
}