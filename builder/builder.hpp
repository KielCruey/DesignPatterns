#include <iostream>

// ============ THE PRODUCT ============
// acts like a normal class, define everything that your "product" has

class Car
{
private:
    std::string make;
    std::string model;

public:
    Car();
    Car(std::string make, std::string model);
    ~Car();

    // ============ printing functions ============
    void printMake();
    void printModel();

    // ============ setters ============
    void SetMake(std::string make);
    void SetModel(std::string model);

    // ============ getters ============
    std::string GetMake();
    std::string GetModel();
};

// ============ THE ABSTRACT BUILDER -- INTERFACE ============
class CarBuilder
{
public:
    virtual ~CarBuilder(){}
    virtual void ProduceEngine() = 0;
    virtual void ProduceChassis() = 0;
    virtual void ProduceTransmission() = 0;
};

// ============ THE CONCRETE BUILDER ============
class ConcreteCarBuilder : public CarBuilder
{
private:
    Car * car;

public:
    ConcreteCarBuilder();
    ConcreteCarBuilder(std::string make, std::string model);
    ~ConcreteCarBuilder();

    // ============ car constructors ============
    void CreateCar();
    void CreateCar(std::string make, std::string model);

    // ============ car components builds ============
    void ProduceEngine();
    void ProduceChassis();
    void ProduceTransmission();

    // ============ getters ============
    Car * GetCar();
};

// ============ Director ============
class CarDirector
{
private:
    CarBuilder * carBuilder;

public:
    void SetBuilder(CarBuilder * carBuilder);

    // ============ construction functions ============
    // functions that help create a "recipe" for the director to trigger the builder
    void BuildMinimalViableCar();
    void BuildMaximumViableCar();
};