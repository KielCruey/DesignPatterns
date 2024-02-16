// For the prototype design pattern, the use of the copy constructs is a must.
// That's the mechanism that clones the same instance of already initialized object.
// It appears that using the 'rule of three' would be good enough for the prototype design pattern.

// The use of deep copy is important, because creating a new object with own independent member variables.
// This is true if you use pointers for your member variables, deep copy is required.
// https://stackoverflow.com/questions/33142935/prototype-design-pattern-example-c

#include <iostream>
#include <string>
#include <unordered_map>

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
    RobotPrototype(int serialNumber = 0);
    virtual ~RobotPrototype(); // not required for derived classes to override but can

    // =========== virtual functions ===========
    virtual void PrintInfo();

    // =========== pure virtual functions ===========
    virtual RobotPrototype * Clone() const = 0;
    virtual int GetRobotType() = 0;

    // =========== getters/setters ===========
    void SetSerialNumber(int serialNumber);
    int GetSerialNumber() const;
};

// ============== Concrete Product ==============
class ConcreteCivilianRobotPrototype : public RobotPrototype
{
private:
    std::string name;

public:
    ConcreteCivilianRobotPrototype(int serialNumber, std::string name);
    ~ConcreteCivilianRobotPrototype() override;

    // =========== virtual functions ===========
    void PrintInfo() override;

    // =========== pure virtual functions ===========
    RobotPrototype * Clone() const override;

    // ============== getters/setters ==============
    void SetName(std::string name);
    std::string GetName();
    int GetRobotType();
};

class ConcreteMilitaryRobotPrototype : public RobotPrototype
{
private:
    std::string rank;

public:
    ConcreteMilitaryRobotPrototype(int serialNumber, std::string rank);
    ~ConcreteMilitaryRobotPrototype() override;

    // =========== virtual functions ===========
    void PrintInfo() override;

    // =========== pure virtual functions ===========
    RobotPrototype * Clone() const override;

    // ============== getters/setters ==============
    void SetRank(std::string rank);
    std::string GetRank();
    int GetRobotType();
};

// ============== Factory ==============
class PrototypeFactory
{
private:
    std::unordered_map<RobotTypes, RobotPrototype *> robotMap;

public:
    PrototypeFactory();
    ~PrototypeFactory();

    RobotPrototype * CreatePrototype(RobotTypes rType);
};
