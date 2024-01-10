// ============ Product ============
class AbstractAnimal
{
public:
    virtual ~AbstractAnimal();

    // functions concrete classes must have
    virtual std::string SoundsOfYourPeople() = 0;
    virtual void Sleeps() = 0;
    virtual void Eats() = 0;
};

// ============ Concrete Products ============
class Cow : public AbstractAnimal
{
private:
    std::string name;

public:
    // ======= special class functions =======
    Cow();
    Cow(std::string name);
    ~Cow();

    // ======= overriding base class's functions =======
    std::string SoundsOfYourPeople() override;
    void Sleeps() override;
    void Eats () override;

    // ======= getters/setters =======
    std::string GetName();
    void SetName(std::string name);
};

class Sheep : public AbstractAnimal
{
private:
    std::string name;

public:
    // ======= special class functions =======
    Sheep();
    Sheep(std::string name);
    ~Sheep();

    // ======= overriding base class's functions =======
    std::string SoundsOfYourPeople() override;
    void Sleeps() override;
    void Eats () override;

    // ======= getters/setters =======
    std::string GetName();
    void SetName(std::string name);
};

class Pig : public AbstractAnimal
{
private:
    std::string name;

public:
    // ======= special class functions =======
    Pig();
    Pig(std::string name);
    ~Pig();

    // ======= overriding base class's functions =======
    std::string SoundsOfYourPeople() override;
    void Sleeps() override;
    void Eats () override;

    // ======= getters/setters =======
    std::string GetName();
    void SetName(std::string name);
};

// ============ Creator ============
// the point of the creator is to not create products, but to call the FactoryMethod() function which then creates the subclass objects we need
class AnimalCreator
{
public:
    // functions that can be overriden by derived class
    virtual ~AnimalCreator();

    // virtual functions that must be override by derived class
    virtual AbstractAnimal * FactoryMethod() = 0;
    virtual AbstractAnimal * FactoryMethod(std::string name) = 0;

    // non-virtual function to call the virtual FactoryMethod(), which will be overwritten by the subclass "products"
    // the subclasses will use the new keyword to create their own object
    AbstractAnimal * CreateAnimal();
    AbstractAnimal * CreateAnimal(std::string name);
};

// ============ Concrete Creators ============
// only need these subclasses to override the virtual FactoryMethod() function
// they are all using the default constructor/destructor 
class ConcreteCowCreator : public AnimalCreator
{
public: 
    ~ConcreteCowCreator();

    AbstractAnimal * FactoryMethod() override;
    AbstractAnimal * FactoryMethod(std::string name) override;
};

class ConcreteSheepCreator : public AnimalCreator
{
public: 
    ~ConcreteSheepCreator();

    AbstractAnimal * FactoryMethod() override;
    AbstractAnimal * FactoryMethod(std::string name) override;
};

class ConcretePigCreator : public AnimalCreator
{
public: 
    ~ConcretePigCreator();

    AbstractAnimal* FactoryMethod() override;
    AbstractAnimal * FactoryMethod(std::string name) override;
};