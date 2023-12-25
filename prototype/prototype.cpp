#include <string>

// ============== Abstract Product ==============
class AbstractRobot
{
public:
    virtual ~AbstractRobot();
    virtual AbstractRobot * Clone() = 0;
};

// ============== Concrete Product ==============
class ConcreteWorkerRobot : public AbstractRobot
{
public:
    ConcreteWorkerRobot()
    {

    }

    ~ConcreteWorkerRobot()
    {

    }

private:
    std::string name;
    int serialNumber;
};

class ConcreteArmyRobot : public AbstractRobot
{
public:
    ConcreteArmyRobot()
    {

    }

    ~ConcreteArmyRobot()
    {

    }
};