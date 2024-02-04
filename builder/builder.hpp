#include <iostream>

// ============ THE PRODUCT ============
// acts like a normal class, define everything that your "product" has
class Car
{
public:
    Car(std::string make = "N/A", std::string model = "N/A");
    ~Car();

    // ============ printing functions ============
    void printMake();
    void printModel();

    // ============ setters ============
    void SetMake(std::string make);
    void SetModel(std::string model);

    // ============ getters ============
    std::string GetMake() const;
    std::string GetModel() const;

private:
    std::string make;
    std::string model;
};

// ============ THE ABSTRACT BUILDER -- INTERFACE ============
class CarBuilder
{
public:
    virtual ~CarBuilder() = default;
    virtual void ProduceEngine() = 0;
    virtual void ProduceChassis() = 0;
    virtual void ProduceTransmission() = 0;
};

// ============ THE CONCRETE BUILDER ============
class ConcreteCarBuilder : public CarBuilder
{
public:
    ConcreteCarBuilder(std::string make = "N/A", std::string model = "N/A");
    ~ConcreteCarBuilder();

    // ============ car constructors ============
    void CreateCar(std::string make = "N/A", std::string model = "N/A");

    // ============ car components builds ============
    void ProduceEngine();
    void ProduceChassis();
    void ProduceTransmission();

    // ============ getters/setters ============
    void SetCar(Car * car);
    Car * GetCar();
    
private:
    Car * car;
};

// ============ Director ============
class CarDirector
{
public:
    void SetBuilder(CarBuilder * carBuilder);

    // ============ construction functions ============
    // functions that help create a "recipe" for the director to trigger the builder
    void BuildMinimalViableCar();
    void BuildMaximumViableCar();

private:
    CarBuilder * carBuilder;
};