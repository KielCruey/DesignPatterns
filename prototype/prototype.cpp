#include <iostream>
#include <string>

// For the prototype design pattern, the use of the copy constructs is a must.
// That's the mechanism that clones the same instance of already initialized object.
// It appears that using the 'rule of three' would be good enough for the prototype design pattern.

// The use of deep copy is important, because creating a new object with own independent member variables.
// This is true if you use pointers for your member variables, deep copy is required.
// https://stackoverflow.com/questions/33142935/prototype-design-pattern-example-c



enum RobotTypes {
    MILITARY = 0,
    CIVILIAN
};

// ============== Abstract Product ==============
class RobotPrototype
{
private:
    int serialNumber;

public:
    // =========== class special functions ===========
    RobotPrototype()
    {
        std::cout << "Robot Prototype created" << std::endl;
    }

    RobotPrototype(int serialNumber) :
        serialNumber(serialNumber)
    { 
        std::cout << "Robot Prototype created with serial number" << std::endl;
    }

    virtual ~RobotPrototype()
    {
        std::cout << "Robot Prototype destroyed" << std::endl;
    }

    // =========== virtual functions ===========
    virtual void PrintInfo()
    {
        std::cout << "Robot's serial number: " + GetSerialNumber() << std::endl;
    }

    // =========== pure virtual functions ===========
    virtual RobotPrototype * Clone() const = 0;
    virtual int GetRobotType() = 0;

    // =========== getters/setters ===========
    void SetSerialNumber(int serialNumber)
    {
        this->serialNumber = serialNumber;
    }

    int GetSerialNumber()
    {
        return this->serialNumber;
    }
};

// ============== Concrete Product ==============
class ConcreteCivilianRobotPrototype : public RobotPrototype
{
private:
    std::string name;

public:
    ConcreteCivilianRobotPrototype(int serialNumber, std::string name) :
        RobotPrototype(serialNumber), 
        name(name)
    {
        std::cout << "Concrete Civilian Robot created" << std::endl;
    }

    ~ConcreteCivilianRobotPrototype()
    {
        std::cout << "Concrete Civilian Robot destroyed" << std::endl;
    }

    // =========== virtual functions ===========
    void PrintInfo() override
    {
        std::cout << "Concrete Civilian Robot is named " + GetName() + " with the serial number " << GetSerialNumber() << "." << std::endl;
    }

    // =========== pure virtual functions ===========
    RobotPrototype * Clone() const override 
    {
        return new ConcreteCivilianRobotPrototype(*this); // calling default copy constructor -- shallow copy only
    }

    // ============== getters/setters ==============
    void SetName(std::string name)
    {
        this->name = name;
    }

    std::string GetName()
    {
        return this->name;
    }

    int GetRobotType()
    {
        return RobotTypes::CIVILIAN;
    }
};

class ConcreteMilitaryRobotPrototype : public RobotPrototype
{
private:
    std::string rank;

public:
    ConcreteMilitaryRobotPrototype(int serialNumber, std::string rank) :
        RobotPrototype(serialNumber),
        rank(rank)
    {
        std::cout << "Concrete Military Robot created" << std::endl;
    }

    ~ConcreteMilitaryRobotPrototype()
    {
        std::cout << "Concrete Military Robot destroyed" << std::endl;
    }

    // =========== virtual functions ===========
    void PrintInfo() override
    {
        std::cout << "Concrete Military Robot rank is " + GetRank() + " with the serial number " << GetSerialNumber() << "." << std::endl;
    }

    // =========== pure virtual functions ===========
    RobotPrototype * Clone() const override 
    {
        return new ConcreteMilitaryRobotPrototype(*this); // calling default copy constructor -- shallow copy only
    }

    // ============== getters/setters ==============
    void SetRank(std::string rank)
    {
        this->rank = rank;
    }

    std::string GetRank()
    {
        return this->rank;
    }

    int GetRobotType()
    {
        return RobotTypes::MILITARY;
    }
};

class PrototypeFactory
{
public:
    PrototypeFactory();
    ~PrototypeFactory();
};

// ============== client code ==============
RobotPrototype * CloneAndPrintMilitaryRobot(ConcreteMilitaryRobotPrototype * mRobot)
{
    // cloning miliary robot
    RobotPrototype * protoMilitary = mRobot->Clone();
    // printing out member variables
    protoMilitary->PrintInfo();

    return protoMilitary;
}

void SimpleMiliaryClone()
{
    ConcreteMilitaryRobotPrototype * mRobot = new ConcreteMilitaryRobotPrototype(123, "Private");
    mRobot->PrintInfo();

    // cloning
    RobotPrototype * milRobot = CloneAndPrintMilitaryRobot(mRobot);

    delete mRobot;
    delete milRobot;
}

RobotPrototype * CloneAndPrintCivilianRobot(ConcreteCivilianRobotPrototype * cRobot) 
{
    // cloning civilian robot
    RobotPrototype * protoCivilian = cRobot->Clone();
    // printing out member variables
    cRobot->PrintInfo();

    return cRobot;
}

void SimpleCivilianClone()
{
    ConcreteCivilianRobotPrototype * cRobot = new ConcreteCivilianRobotPrototype(321, "Dawn");
    cRobot->PrintInfo();

    // cloning
    RobotPrototype * civRobot = CloneAndPrintCivilianRobot(cRobot);

    delete cRobot;
    delete civRobot;
}

// ============== main ==============
int main()
{
    ConcreteCivilianRobotPrototype * rJim = new ConcreteCivilianRobotPrototype(9, "Jim");
    if(rJim->GetRobotType() == RobotTypes::CIVILIAN)
    {
        std::cout << "Jim is a robot" << std::endl;
    }
    else
    {
        std::cout << "Jim is NOT a robot" << std::endl;
    }

    // cloning military robot without a factory
    SimpleMiliaryClone();

    // cloning civilian robot without a factory
    SimpleCivilianClone();

    return 0;
}