class Engine
{
public:
    Engine();
    ~Engine();

    void StartEngine();
    void StopEngine();
};

// a car is composed of an engine, 
// and the car overlooks the engines common lifecycle
class Car
{
public:
    Car(); // creates a dynamic engine
    ~Car();

    void Start();
    void Stop();

private:
    // the car contains a reference to the engine, but most importantly,
    // the car controls the creation and deletion of the engine instance
    Engine * engine; 
};