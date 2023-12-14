#include <iostream>
#include <string>

// ============ Product ============
class AbstractAnimal
{
public:
    virtual ~AbstractAnimal() {};

    // functions concrete classes must have
    virtual std::string SoundsOfYourPeople() = 0;
    virtual void Sleeps() = 0;
    virtual void Eats() = 0;
};

// ============ Concrete Product ============
class Cow : public AbstractAnimal
{
public:
    // ======= special class functions =======
    Cow() { std::cout << "I'm a cow!" << std::endl; }
    Cow(std::string name) { std::cout <<"I'm a cow, and my name is " + name + "!" << std::endl; }
    ~Cow() { std::cout << "No more cow!" << std::endl; }

    // ======= overriding base class's functions =======
    std::string SoundsOfYourPeople() override { return "Moo!"; }
    void Sleeps() override { std::cout << "zzzzZZZZZzzzzz." << std::endl; }
    void Eats () override { std::cout << "Starts to eat hay." << std::endl; }

    // ======= getters/setters =======
    std::string GetName() { return this->name; }
    void SetName(std::string name) { this->name = name; }

private:
    std::string name;
};

class Sheep : public AbstractAnimal
{
public:
    // ======= special class functions =======
    Sheep() { std::cout << "I'm a sheep!" << std::endl; }
    Sheep( std::string name) { std::cout << "I'm a sheep and my name is " + name + "!" << std::endl; } 
    ~Sheep() { std::cout << "No more sheep!" << std::endl; }

    // ======= overriding base class's functions =======
    std::string SoundsOfYourPeople() override { return "Baa!"; }
    void Sleeps() override { std::cout << "zzzzZzzzz." << std::endl; }
    void Eats () override { std::cout << "Starts to eat grass." << std::endl; }

    // ======= getters/setters =======
    std::string GetName() { return this->name; }
    void SetName(std::string name) { this->name = name; }

private:
    std::string name;
};

class Pig : public AbstractAnimal
{
public:
    // ======= special class functions =======
    Pig() { std::cout << "I'm a pig!" << std::endl; }
    Pig(std::string name) { std::cout << "I'm a pig and my name is " + name + "!" << std::endl; }
    ~Pig() { std::cout << "No more pig!" << std::endl; }

    // ======= overriding base class's functions =======
    std::string SoundsOfYourPeople() override { return "Oink!"; }
    void Sleeps() override { std::cout << "zzZZZzz." << std::endl; }
    void Eats () override { std::cout << "Starts to eat slop." << std::endl; }

    // ======= getters/setters =======
    std::string GetName() { return this->name; }
    void SetName(std::string name) { this->name = name; }

private:
    std::string name;
};

// ============ Creator ============

// the point of the creator is to not create products,
// but to call the FactoryMethod() function which then creates the objects we need
class Creator
{
public:
    virtual ~Creator() {};
    virtual AbstractAnimal * FactoryMethod() = 0;

    // non-virtual function to call the virtual FactoryMethod()
    std::string CallFactoryMethod()
    {
        AbstractAnimal * animal = this->FactoryMethod();
        std::string results = "Creator: called the AbstractAnimal's SoundsOfYourPeople() function: " + animal->SoundsOfYourPeople();
        
        delete animal;
        return results;
    }
};

class ConcreteCowCreator : public Creator
{
public:
    ConcreteCowCreator();
    ~ConcreteCowCreator();
};

// ============ Main ============
int main()
{
    std::cout << "Hello World" << std::endl;
    return 0;
}