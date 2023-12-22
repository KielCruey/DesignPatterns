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

// ============ Concrete Products ============
class Cow : public AbstractAnimal
{
public:
    // ======= special class functions =======
    Cow() 
    {
        std::cout << "I'm a cow!" << std::endl; 
    }

    Cow(std::string name)
    { 
        std::cout << "I'm a cow, and my name is " + name + "!" << std::endl; 
    }

    ~Cow() 
    { 
        std::cout << "No more cow!" << std::endl; 
    }

    // ======= overriding base class's functions =======
    std::string SoundsOfYourPeople() override 
    { 
        return "Moo!"; 
    }

    void Sleeps() override 
    { 
        std::cout << "zzZZzz. Counting cows." << std::endl; 
    }

    void Eats () override 
    { 
        std::cout << "Starts to eat hay." << std::endl; 
    }

    // ======= getters/setters =======
    std::string GetName() 
    { 
        return this->name; 
    }

    void SetName(std::string name) 
    { 
        this->name = name; 
    }

private:
    std::string name;
};

class Sheep : public AbstractAnimal
{
public:
    // ======= special class functions =======
    Sheep() 
    { 
        std::cout << "I'm a sheep!" << std::endl; 
    }

    Sheep( std::string name) 
    { 
        std::cout << "I'm a sheep and my name is " + name + "!" << std::endl; 
    } 

    ~Sheep() 
    { 
        std::cout << "No more sheep!" << std::endl; 
    }

    // ======= overriding base class's functions =======
    std::string SoundsOfYourPeople() override 
    { 
        return "Baa!"; 
    }

    void Sleeps() override 
    { 
        std::cout << "zzZZzz. Counting Sheep." << std::endl; 
    }

    void Eats () override 
    { 
        std::cout << "Starts to eat grass." << std::endl; 
    }

    // ======= getters/setters =======
    std::string GetName() 
    { 
        return this->name; 
    }

    void SetName(std::string name) 
    { 
        this->name = name; 
    }

private:
    std::string name;
};

class Pig : public AbstractAnimal
{
public:
    // ======= special class functions =======
    Pig() 
    { 
        std::cout << "I'm a pig!" << std::endl; 
    }

    Pig(std::string name) 
    { 
        std::cout << "I'm a pig and my name is " + name + "!" << std::endl; 
    }

    ~Pig() 
    { 
        std::cout << "No more pig!" << std::endl; 
    }

    // ======= overriding base class's functions =======
    std::string SoundsOfYourPeople() override 
    { 
        return "Oink!"; 
    }

    void Sleeps() override 
    { 
        std::cout << "zzZZZzz. Counting pigs." << std::endl; 
    }

    void Eats () override 
    { 
        std::cout << "Starts to eat slop." << std::endl; 
    }

    // ======= getters/setters =======
    std::string GetName() 
    { 
        return this->name; 
    }
    void SetName(std::string name) 
    { 
        this->name = name; 
    }

private:
    std::string name;
};

// ============ Creator ============
// the point of the creator is to not create products, but to call the FactoryMethod() function which then creates the subclass objects we need
class AnimalCreator
{
public:
    virtual ~AnimalCreator() {};
    virtual AbstractAnimal * FactoryMethod() = 0;

    // non-virtual function to call the virtual FactoryMethod(), which will be overwritten by the subclass "products"
    // the subclasses will use the new keyword to create their own object
    std::string CreateAnimal()
    {
        AbstractAnimal * animal = this->FactoryMethod();
    }
};

// ============ Concrete Creators ============
// only need these subclasses to override the virtual FactoryMethod() function
// they are all using the default constructor/destructor 
class ConcreteCowCreator : public AnimalCreator
{
private: 
    AbstractAnimal * FactoryMethod() override
    {
        return new Cow();
    }
};

class ConcreteSheepCreator : public AnimalCreator
{
private: 
    AbstractAnimal * FactoryMethod() override
    {
        return new Sheep();
    }
};

class ConcretePigCreator : public AnimalCreator
{
private: 
    AbstractAnimal* FactoryMethod() override
    {
        return new Pig();
    }
};

// ============ Main ============
int main()
{
    std::cout << "Hello World" << std::endl;
    return 0;
}