
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