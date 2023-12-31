#include <iostream>
#include <memory>

// =========== Abstract Target ===========
class AbstractPlug
{
private:
    int VoltageRating;
    int FrequencyRating;

public:
    AbstractPlug()
    {
        this->VoltageRating = 0;
        this->FrequencyRating = 0;

        std::cout << "AbstractPlug Created" << std::endl;
    }

    AbstractPlug(int VoltageRating, int FrequencyRating)
    {
        this->VoltageRating = VoltageRating;
        this->FrequencyRating = FrequencyRating;

        std::cout << "AbstractPlug Created" << std::endl;
    }

    ~AbstractPlug()
    {
        std::cout << "AbstractPlug deleted" << std::endl;
    }

    virtual bool HasRoundPins() = 0;
    virtual int GetNumberOfPins() = 0;

    // =========== general functions ===========
    int GetVoltageRating()
    {
        return this->VoltageRating;
    }

    int GetFrequencyRating()
    {
        return this->FrequencyRating;
    }

    void SetVoltageRating(int VoltageRating)
    {
        this->VoltageRating = VoltageRating;
    }

    void SetFrequencyRating(int FrequencyRating)
    {
        this->FrequencyRating = FrequencyRating;
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

    ~AmericanPlug() 
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

    ~UKPlug()
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

    ~JapanesePlug()
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
    bool HasRoundPins;
    int PinCount;
    int Voltage;
    int Frequency;

public:
    // =========== special class functions ===========
    Outlet(bool HasRoundPins, int PinCount, int Voltage, int Frequency)
    {
        this->HasRoundPins = HasRoundPins;
        this->PinCount = PinCount;
        this->Voltage = Voltage;
        this->Frequency = Frequency;

        std::cout << "Outlet created" << std::endl;
    }

    ~Outlet()
    {
        std::cout << "Outlet deleted" << std::endl;
    }

    // =========== general function ===========
    bool GetHasRoundPins()
    {
        return this->HasRoundPins;
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
    PlugAdapter(Outlet * pOutlet, int VoltageRating, int FrequencyRating) 
    {
        SetOutlet(pOutlet); // setting class variable
        
        SetVoltageRating(VoltageRating);
        SetFrequencyRating(FrequencyRating);
    }

    // =========== general functions ===========
    // now the point of the adapter class is to call the target's AbstractPlug virtual functions
    bool HasRoundPins()
    {
        return pOutlet->GetHasRoundPins();
    }

    // now the point of the adapter class is to call the target's AbstractPlug virtual functions
    int GetNumberOfPins()
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

// =========== Client code ===========
void PrintPlugData(AbstractPlug * plug)
{
    std::cout << "voltage rating: " + plug->GetVoltageRating() << std::endl;
    std::cout << "frequency rating: " + plug->GetFrequencyRating() << std::endl;
}

// =========== MAIN code ===========
int main()
{
    AmericanPlug * plug = new AmericanPlug(120, 60, 2);
    int temp = plug->GetNumberOfPins();
    std::cout << "Pins are round: " + plug->HasRoundPins() << std::endl;
    std::cout << "number of pins: " + temp << std::endl;

    Outlet * outlet = new Outlet(false, 3, 120, 60);
    AbstractPlug * adapter = new PlugAdapter(outlet, 120, 60);
    
    return 0;
}