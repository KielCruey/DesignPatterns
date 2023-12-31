#include <iostream>

// =========== Abstract Target ===========
class AbstractPlug
{
private:
    int VoltageRating;
    int FrequencyRating;

public:
    AbstractPlug(int VoltageRating, int FrequencyRating)
    {
        this->VoltageRating = VoltageRating;
        this->FrequencyRating = FrequencyRating;

        std::cout << "AbstractPlug Created" << std::endl;
    }

    virtual ~AbstractPlug()
    {
        std::cout << "AbstractPlug deleted" << std::endl;
    }

    virtual bool HasRoundPins();
    virtual int GetNumberOfPins();

    // =========== general functions ===========
    int GetVoltageRating()
    {
        return this->VoltageRating;
    }

    int GetFrequencyRating()
    {
        return this->FrequencyRating;
    }
};

// =========== Concrete Target ===========
class AmericanPlug : public AbstractPlug
{
private:
    const bool RoundPins = false;
    int NumberOfPins;

public:
    // =========== special class functions ===========
    AmericanPlug(int VoltageRating, int FrequencyRating, int NumberOfPins) : 
        AbstractPlug(VoltageRating, FrequencyRating)
    {
        this->NumberOfPins = NumberOfPins;

        std::cout << "AmericanPlug Created" << std::endl;
    }

    ~AmericanPlug() override 
    {
        std::cout << "AmericanPlug deleted" << std::endl;
    }

    // =========== general functions ===========
    bool HasRoundPins() override
    {
        return this->RoundPins;
    }

    int GetNumberOfPins() override
    {
        return this->NumberOfPins;
    }
};

class UKPlug : public AbstractPlug
{
public:
    const bool RoundPins = false;
    int NumberOfPins;

public:
    // =========== special class functions ===========
    UKPlug(int VoltageRating, int FrequencyRating, int NumberOfPins) : 
        AbstractPlug(VoltageRating, FrequencyRating)
    {
        this->NumberOfPins = NumberOfPins;

        std::cout << "UKPlug created" << std::endl;
    }

    ~UKPlug() override 
    {
        std::cout << "UKPlug deleted" << std::endl;
    };

    // =========== general functions ===========
    bool HasRoundPins() override
    {
        return this->RoundPins;
    }

    int GetNumberOfPins() override
    {
        return this->NumberOfPins;
    }
};

class JapanesePlug : public AbstractPlug
{
private:
    const bool RoundPins = true;
    int NumberOfPins;

public:
    // =========== special class functions ===========
    JapanesePlug(int VoltageRating, int FrequencyRating, int NumberOfPins) :
        AbstractPlug(VoltageRating, FrequencyRating)
    {
        this->NumberOfPins = NumberOfPins;

        std::cout << "JapanesePlug created" << std::endl;
    }

    ~JapanesePlug() override
    {
        std::cout << "JapanesePlug deleted" << std::endl;
    }

    // =========== general functions ===========
    bool HasRoundPins() override
    {
        return this->RoundPins;
    }

    int GetNumberOfPins() override
    {
        return this->NumberOfPins;
    }
};

// =========== Adaptee ===========
class Outlet
{
private:
    bool AcceptsFlatPins;
    int PinCount;
    int Voltage;
    int Frequency;

public:
    virtual bool GetAcceptsRoundPins();
    virtual int GetPinCount();

    // =========== special class functions ===========
    Outlet(int Voltage, int Frequency)
    {
        this->Voltage = Voltage;
        this->Frequency = Frequency;

        std::cout << "Outlet created" << std::endl;
    }

    ~Outlet()
    {
        std::cout << "Outlet deleted" << std::endl;
    }

    // =========== general function ===========
    bool GetAcceptsRoundPins()
    {
        return this->AcceptsFlatPins;
    }

    int GetPinCount()
    {
        return this->PinCount;
    }

    int GetVoltage()
    {
        return this->Voltage;
    }

    int GetFrequency()
    {
        return this->Frequency;
    }
};

// =========== Adapter ===========
class PlugAdapter : public AbstractPlug
{
private:
    Outlet * pOutlet;

public:
    // =========== special class functions ===========
    PlugAdapter(Outlet * pOutlet)
    {
        SetOutlet(pOutlet);
    }

    // =========== general functions ===========
    // now the point of the adapter class is to call the target's AbstractPlug virtual functions
    bool HasRoundPins() override
    {
        return pOutlet->GetAcceptsRoundPins();
    }

    // now the point of the adapter class is to call the target's AbstractPlug virtual functions
    int GetNumberOfPins() override
    {
        return pOutlet->GetPinCount();
    }
    
    // =========== getters/setters ===========
    void SetOutlet(Outlet * pOutlet)
    {
        this->pOutlet = pOutlet;
    }

    Outlet * GetOutlet()
    {
        return this->pOutlet;
    }
};

// =========== MAIN code ===========
int main()
{
    return 0;
}