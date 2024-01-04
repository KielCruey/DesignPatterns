#include <iostream>
#include <string>
#include <vector>

// ============ Product ============
class AbstractAnimal
{
public:
    virtual ~AbstractAnimal() 
    {
        std::cout << "Abstract Animal destroyed" << std::endl;   
    };

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
        std::cout << "I'm a sheep, and my name is " + name + "!" << std::endl; 
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
        std::cout << "I'm a pig, and my name is " + name + "!" << std::endl; 
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
    virtual AbstractAnimal * FactoryMethod(std::string name) = 0;

    // non-virtual function to call the virtual FactoryMethod(), which will be overwritten by the subclass "products"
    // the subclasses will use the new keyword to create their own object
    AbstractAnimal * CreateAnimal()
    {
        AbstractAnimal * animal = this->FactoryMethod();
        return animal;
    }

    AbstractAnimal * CreateAnimal(std::string name)
    {
        AbstractAnimal * animal = this->FactoryMethod(name);
        return animal;
    }
};

// ============ Concrete Creators ============
// only need these subclasses to override the virtual FactoryMethod() function
// they are all using the default constructor/destructor 
class ConcreteCowCreator : public AnimalCreator
{
public: 
    AbstractAnimal * FactoryMethod() override
    {
        return new Cow();
    }

    AbstractAnimal * FactoryMethod(std::string name)
    {
        return new Cow(name);
    }
};

class ConcreteSheepCreator : public AnimalCreator
{
public: 
    AbstractAnimal * FactoryMethod() override
    {
        return new Sheep();
    }

    AbstractAnimal * FactoryMethod(std::string name)
    {
        return new Sheep(name);
    }
};

class ConcretePigCreator : public AnimalCreator
{
public: 
    AbstractAnimal* FactoryMethod() override
    {
        return new Pig();
    }

    AbstractAnimal * FactoryMethod(std::string name)
    {
        return new Pig(name);
    }
};

// ============ Client Code ============
// AnimalCreator knows to create the concrete animals because creator is of type ConcreteCowCreator's "FactoryMethod"
std::vector<AbstractAnimal *> CreateOneOfEachAnimals_NoNames(AnimalCreator * pAnimalCreator)
{
    std::vector<AbstractAnimal *> vAnimals;

    pAnimalCreator = new ConcreteCowCreator();  
    AbstractAnimal * cow = pAnimalCreator->CreateAnimal(); // creates Cow object -- calls the Cow() constructor
    vAnimals.push_back(cow);

    pAnimalCreator = new ConcreteSheepCreator();
    AbstractAnimal * sheep = pAnimalCreator->FactoryMethod(); // creates a sheep -- calls the Sheep() constructor
    vAnimals.push_back(sheep);

    pAnimalCreator = new ConcretePigCreator();
    AbstractAnimal * pig = pAnimalCreator->CreateAnimal(); // creates a pig -- calls the Pig() constructor
    vAnimals.push_back(pig);

    return vAnimals;
}

void PrintAnimalSounds(std::vector<AbstractAnimal *> v)
{
    for(int i = 0; i <= (v.size() - 1); i++)
    {
        std::cout << v[i]->SoundsOfYourPeople() << std::endl;
    }
}


std::vector<AbstractAnimal *> CreateOneOfEachAnimals_Names(AnimalCreator * pAnimalCreator)
{
    std::vector<AbstractAnimal *> vAnimals;

    pAnimalCreator = new ConcreteCowCreator(); 
    AbstractAnimal * cow = pAnimalCreator->CreateAnimal("Daisy"); // creates Cow object -- calls the Cow() constructor
    vAnimals.push_back(cow); 

    pAnimalCreator = new ConcreteSheepCreator();
    AbstractAnimal * sheep = pAnimalCreator->FactoryMethod("Grant"); // creates a sheep -- calls the Sheep() constructor
    vAnimals.push_back(sheep);

    pAnimalCreator = new ConcretePigCreator();
    AbstractAnimal * pig = pAnimalCreator->CreateAnimal("Luigi"); // creates a pig -- calls the Pig() constructor
    vAnimals.push_back(pig);

    return vAnimals;
}

// ============ Main ============
int main()
{
    AnimalCreator * animalCreator;
    std::vector<AbstractAnimal *> animals_NoNames;
    std::vector<AbstractAnimal *> animals_Names;

    // vector of each farm animals -- with no names
    animals_NoNames = CreateOneOfEachAnimals_NoNames(animalCreator);
    PrintAnimalSounds(animals_NoNames);

    // vector of each farm animals -- with names 
    animals_Names = CreateOneOfEachAnimals_Names(animalCreator);
    PrintAnimalSounds(animals_Names);

    return 0;
}