
// =========== Abstract Target ===========
class AbstractPlug
{
public:
    virtual ~AbstractPlug();

    virtual bool HasRoundPins();
    virtual int GetNumberOfPins();
    virtual int GetVoltageRating();
    virtual int GetFrequencyRating();
};

// =========== Concrete Target ===========
class AmericanPlug : public AbstractPlug
{
private:
    const bool RoundPins = false;
    
    int NumberOfPins;
    int VoltageRating;
    int FrequencyRating;

public:
    // =========== special class functions ===========
    AmericanPlug(int NumberOfPins, int VoltageRating, int FrequencyRating)
    {
        this->NumberOfPins = NumberOfPins;
        this->VoltageRating = VoltageRating;
        this->FrequencyRating = FrequencyRating;
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
    
    int GetVoltageRating() override
    {
        return this->VoltageRating;
    }

    int GetFrequencyRating() override
    {
        return this->FrequencyRating;
    }
};

class UKPlug : public AbstractPlug
{
public:
    const bool RoundPins = false;
    
    int NumberOfPins;
    int VoltageRating;
    int FrequencyRating;

public:
    // =========== special class functions ===========
    UKPlug(int NumberOfPins, int VoltageRating, int FrequencyRating)
    {
        this->NumberOfPins = NumberOfPins;
        this->VoltageRating = VoltageRating;
        this->FrequencyRating = FrequencyRating;
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
    
    int GetVoltageRating() override
    {
        return this->VoltageRating;
    }

    int GetFrequencyRating() override
    {
        return this->FrequencyRating;
    }
};

class JapanesePlug : public AbstractPlug
{
private:
    const bool RoundPins = false;
    
    int NumberOfPins;
    int VoltageRating;
    int FrequencyRating;

public:
    // =========== special class functions ===========
    JapanesePlug(int NumberOfPins, int VoltageRating, int FrequencyRating)
    {
        this->NumberOfPins = NumberOfPins;
        this->VoltageRating = VoltageRating;
        this->FrequencyRating = FrequencyRating;
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
    
    int GetVoltageRating() override
    {
        return this->VoltageRating;
    }

    int GetFrequencyRating() override
    {
        return this->FrequencyRating;
    }
};