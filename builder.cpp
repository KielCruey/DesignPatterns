#include <iostream>

// the "product" in the builder design pattern
class Car
{
private:
    std::string make;
    std::string model;

public:
    Car() 
    { 
        this->make = "N/A";
        this->model = "N/A";
        std::cout << "Constructor -- Car" << std::endl; 
    }

    Car(std::string make, std::string model)
    {
        this->make = make;
        this->model = model;
    }

    ~Car() { std::cout << "Deconstructor -- Car" << std::endl; }

    // ============ printing functions ============
    void printMake()
    {
        std::cout << "Make: " + this->make << std::endl;
    }

    void printModel()
    {
        std::cout << "Model: " + this->model << std::endl;
    }

    // ============ setters ============
    void SetMake(std::string make)
    {
        this->make = make;
    }

    void SetModel(std::string model)
    {
        this->model = model;
    }

    // ============ getters ============
    std::string GetMake()
    {
        return this->make;
    }

    std::string GetModel()
    {
        return this->model;
    }
};


// "abstract builder" for the builder design pattern.
class CarBuilder
{
public:
    virtual ~CarBuilder(){}
    virtual void ProduceEngine() = 0;
    virtual void ProduceChassis() = 0;
    virtual void ProduceTransmission() = 0;
};

class ConcreteCarBuilder : public CarBuilder
{
private:
    Car * car;
public:
    ConcreteCarBuilder()
    {
        this->CreateCar();
    }

    ~ConcreteCarBuilder()
    {
        delete this->car;
    }

    void CreateCar()
    {
        this->car = new Car();
    }

    // ============ car components builds ============
    void ProduceEngine()
    { 
        std::cout << "Engine Created! -- Car" << std::endl;
    }

    void ProduceChassis()
    {
        std::cout << "Chassis Created! -- Car" << std::endl;
    }

    void ProduceTransmission()
    {
        std::cout << "Transmission Created! -- Car" << std::endl;
    }

    // ============ getters ============
    Car * GetCar()
    {
        Car * result = this->car;
        this->CreateCar();
        return result;
    }
};

class CarDirector
{
private:
    CarBuilder * carBuilder;

public:
    void SetBuilder(CarBuilder * carBuilder)
    {
        this->carBuilder = carBuilder;
    }

    // ============ construction functions ============
    void BuildMinimalViableCar()
    {
        this->carBuilder->ProduceChassis();
    }

    void BuildMaximumViableCar()
    {
        this->carBuilder->ProduceEngine();
        this->carBuilder->ProduceTransmission();
        this->carBuilder->ProduceChassis();
    }
};

// implemented with the CarDirector class
void SeasonalProjectCars(CarDirector & carDirector)
{
    ConcreteCarBuilder * builder = new ConcreteCarBuilder();
    carDirector.SetBuilder(builder);

    // director creating a new "winter" build
    std::cout << "Winter Project Car Built!" << std::endl;
    carDirector.BuildMinimalViableCar(); // carDirctor created a Car object

    Car * winterCar = builder->GetCar();
    winterCar->printMake();
    winterCar->printModel();
    delete winterCar;

    // director creating a new "summer" build
    std::cout << "Summer Project Car Built!" << std::endl;
    carDirector.BuildMaximumViableCar(); // carDirctor created a Car object

    Car * summerCar = builder->GetCar();
    winterCar->printMake();
    winterCar->printModel();
    delete summerCar;

    delete builder;
}

// used without the CarDirector class
void ProjectCars(CarDirector & director)
{
    ConcreteCarBuilder * builder = new ConcreteCarBuilder();
    director.SetBuilder(builder);

    // now created "products" that car will have
    std::cout << "Spring Project Car Built!" << std::endl;
    builder->ProduceEngine();
    builder->ProduceChassis();

    // creating an Car object then populating that object via ConcreteCarBuilder
    Car * springCar = builder->GetCar();
    springCar->printMake();
    springCar->printModel();
    delete builder;
}


int main()
{
    CarDirector * director = new CarDirector();
    SeasonalProjectCars(*director);
    
    ProjectCars(*director);

    delete director;
    return 0;
}
