#include <iostream>

// ============ ABSTRACT PRODUCT ============
class AbstractPerson
{
public:
    virtual ~AbstractPerson() {};
    virtual void Attack() = 0;
    virtual void CheckHealth() = 0;
};

// ============ CONCRETE PRODUCTS -- will be created by concrete factories ============
class ConcreteSoldier : public AbstractPerson
{ 
public:
    ConcreteSoldier() { std::cout << "Soldier Created" << std::endl; }
    ~ConcreteSoldier() { std::cout << "Soldier Destroyed" << std::endl; }

    // ============ concrete functions -- getting overridden ============
    void Attack() { std::cout << "Soldier Attacked" << std::endl; }
    void CheckHealth() { std::cout << "Soldier Checked Health" << std::endl; }
};

class ConcreteArcher : public AbstractPerson
{
public:
    ConcreteArcher() { std::cout << "Archer Created" << std::endl; }
    ~ConcreteArcher () { std::cout << "Archer Destroyed" << std::endl; }

    // ============ concrete functions -- getting overridden ============
    void Attack() override { std::cout << "Archer Attacked" << std::endl; }
    void CheckHealth() override { std::cout << "Archer Checked Health" << std::endl; }
};

class ConcreteCalvary : public AbstractPerson
{
public:
    ConcreteCalvary() { std::cout << "Calvary Created" << std::endl; }
    ~ConcreteCalvary() { std::cout << "Calvary Destroyed" << std::endl; }

    // ============ concrete functions -- getting overridden ============
    void Attack() override { std::cout << "Calvary Attacked" << std::endl; }
    void CheckHealth() override { std::cout << "Calvary Checked Health" << std::endl; }
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
class ConcreteHumanFactory : public AbstractRaceFactory
{
public:
    ConcreteHumanFactory() { std::cout << "Human Factory Created" << std::endl; }
    ~ConcreteHumanFactory() { std::cout << "Human Factory Destroyed" << std::endl; }

    AbstractPerson * MakeSoldier()
    {
        return new ConcreteSoldier();
    }

    AbstractPerson * MakeArcher()
    {
        return new ConcreteArcher();
    }
    
    AbstractPerson * MakeCalvary() 
    {
        return new ConcreteCalvary();
    }
};

class ConcreteOrcFactory : public AbstractRaceFactory
{
public:
    ConcreteOrcFactory() { std::cout << "Orc Factory Created" << std::endl; }
    ~ConcreteOrcFactory() { std::cout << "Orc Factory Destroyed" << std::endl; }

    AbstractPerson * MakeSoldier()
    {
        return new ConcreteSoldier();
    }

    AbstractPerson * MakeArcher()
    {
        return new ConcreteArcher();
    }
    
    AbstractPerson * MakeCalvary() 
    {
        return new ConcreteCalvary();
    }
};

// ============ CLIENT CODE ============ 
void CreateHumanArmy(AbstractRaceFactory & factory)
{
    AbstractPerson * humanSoldier = factory.MakeSoldier(); 
    AbstractPerson * humanArcher = factory.MakeArcher();
    AbstractPerson * humanCalvary = factory.MakeCalvary();
}

void CreateOrcArmy(AbstractRaceFactory & factory)
{
    AbstractPerson * orcSoldier = factory.MakeSoldier(); 
    AbstractPerson * orcArcher = factory.MakeArcher();
    AbstractPerson * orcCalvary = factory.MakeCalvary();
}

// ============ MAIN ============
int main()
{
    // factory creating humans
    ConcreteHumanFactory * humanFactory = new ConcreteHumanFactory();
    CreateHumanArmy(*humanFactory);
    delete humanFactory;

    // factory creating humans
    ConcreteOrcFactory * orcFactory = new ConcreteOrcFactory();
    CreateHumanArmy(*orcFactory);
    delete orcFactory;
}