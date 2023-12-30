
// =========== Abstract Target ===========
class AbstractPlug
{
public:
    int VoltageRating;
    int FrequencyRating;

public:
    virtual ~AbstractPlug();
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
    AmericanPlug(int NumberOfPins)
    {
        this->NumberOfPins = NumberOfPins;
    }

    ~AmericanPlug() override = default;

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
    UKPlug(int NumberOfPins)
    {
        this->NumberOfPins = NumberOfPins;
    }

    ~UKPlug() override = default;

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
    JapanesePlug(int NumberOfPins)
    {
        this->NumberOfPins = NumberOfPins;
    }

    ~JapanesePlug() override = default;

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
    virtual bool GetAcceptsFlatPins();
    virtual int GetPinCount();

    // =========== special class functions ===========
    Outlet(int Voltage, int Frequency)
    {
        this->Voltage = Voltage;
        this->Frequency = Frequency;
    }

    ~Outlet() {};

    // =========== general function ===========
    bool GetAcceptsFlatPins()
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
    void SetOutlet(Outlet * pOutlet)
    {
        this->pOutlet = pOutlet;
    }

    Outlet * GetOutlet()
    {
        return this->pOutlet;
    }
};