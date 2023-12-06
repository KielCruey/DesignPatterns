#include <iostream>

// ============ ABSTRACT PRODUCT ============
class AbstractPerson
{
public:
    virtual ~AbstractPerson() {}
    virtual void Attack() = 0;
    virtual void CheckHealth() = 0;
};

// ============ CONCRETE PRODUCTS ============
class Soldier : public AbstractPerson
{ 
public:
    Soldier() { std::cout << "Soldier Created" << std::endl; }
    ~Soldier() { std::cout << "Soldier Destroyed" << std::endl; }

    // ============ concrete functions -- getting overridden ============
    void Attack() { std::cout << "Soldier Attacked" << std::endl; }
    void CheckHealth() { std::cout << "Soldier Checked Health" << std::endl; }
};

class Archer : public AbstractPerson
{
public:
    Archer() { std::cout << "Archer Created" << std::endl; }
    ~Archer () { std::cout << "Archer Destroyed" << std::endl; }

    // ============ concrete functions -- getting overridden ============
    void Attack() { std::cout << "Archer Attacked" << std::endl; }
    void CheckHealth() { std::cout << "Archer Checked Health" << std::endl; }
};

class Calvary : public AbstractPerson
{
public:
    Calvary() { std::cout << "Calvary Created" << std::endl; }
    ~Calvary() { std::cout << "Calvary Destroyed" << std::endl; }

    // ============ concrete functions -- getting overridden ============
    void Attack() { std::cout << "Calvary Attacked" << std::endl; }
    void CheckHealth() { std::cout << "Calvary Checked Health" << std::endl; }
};

// ============ ABSTRACT FACTORY ============
class AbstractRaceFactory
{
public:
    virtual ~AbstractRaceFactory() {};

    // ============ creational objects ============
    virtual AbstractPerson * MakeSoldier() = 0;
    virtual AbstractPerson * MakeArcher() = 0;
    virtual AbstractPerson * MakeCalvary() = 0;
};

// ============ CONCRETE FACTORIES ============
class HumanFactory : public AbstractRaceFactory
{
public:
    HumanFactory() { std::cout << "Human Factory Created" << std::endl; }

    ~HumanFactory() { std::cout << "Human Factory Destroyed" << std::endl; }

    AbstractPerson * MakeSoldier()
    {
        return new Soldier();
    }

    AbstractPerson * MakeArcher()
    {
        return new Archer();
    }
    
    AbstractPerson * MakeCalvary() 
    {
        return new Calvary();
    }
};

class OrcFactory : public AbstractRaceFactory
{
public:
    OrcFactory() { std::cout << "Orc Factory Created" << std::endl; }

    ~OrcFactory() { std::cout << "Orc Factory Destroyed" << std::endl; }

    AbstractPerson * MakeSoldier()
    {
        return new Soldier();
    }

    AbstractPerson * MakeArcher()
    {
        return new Archer();
    }
    
    AbstractPerson * MakeCalvary() 
    {
        return new Calvary();
    }
};

// ============ CLIENT CODE ============ 
void CreateHumanArmy(AbstractRaceFactory & factory)
{
    AbstractPerson * humanSoldier = factory.MakeSoldier(); 
}

// ============ MAIN ============
int main()
{
    HumanFactory * factory = new HumanFactory();
    CreateHumanArmy(*factory);

    // appears the solder isn't deleted, MEMORY LEAK

    delete factory;
}