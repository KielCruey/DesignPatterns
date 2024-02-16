#include <iostream>
#include <memory>

enum NumberOfPinholes { One = 1, Two, Three };
enum HasRoundPinholes { False = 0, True };

const int AMERICAN_HERTS = 60;
const int UK_HERTS = 50;

// =========== Abstract Target ===========
class Outlet
{
public:
    Outlet(bool RoundHoles = HasRoundPinholes::False, 
            int NumberOfHoles = NumberOfPinholes::Two);
    virtual ~Outlet();

    bool GetHasRoundHoles() const;
    int GetNumberOfHoles() const;

private:
    bool HasRoundHoles;
    int NumberOfHoles;
};

// =========== Concrete Target ===========
class AmericanOutlet : public Outlet
{
public:
    enum AmericanVoltage { Residential = 120, Commercial = 240 };

    AmericanOutlet(int VoltageRating = AmericanVoltage::Residential, 
                    int FrequencyRating = AMERICAN_HERTS,
                    bool HasRoundHoles = HasRoundPinholes::False,
                    int NumberOfHoles = NumberOfPinholes::Two);
    ~AmericanOutlet();

    int GetVoltageRating() const;
    int GetFrequencyRating() const;

private:
    int VoltageRating;
    int FrequencyRating;
};

class UKOutlet : public Outlet
{
public:
    enum UKVoltage { Residential = 230, Commercial = 415 };

    UKOutlet(int VoltageRating = UKVoltage::Residential, 
                int FrequencyRating = UK_HERTS,
                bool HasRoundHoles = HasRoundPinholes::False,
                int NumberOfHoles = NumberOfPinholes::Three);
    ~UKOutlet();

    int GetFrequencyRating() const;
    int GetVoltageRating() const;

public:
    int FrequencyRating;
    int VoltageRating;
};

class JapaneseOutlet : public Outlet
{
public:
    enum JapaneseVoltage { Residential = 100, Commercial = 200 };
    enum JapaneseHerts { Eastern = 50, Western = 60 };

    JapaneseOutlet(int VoltageRating = JapaneseVoltage::Residential, 
                    int FrequencyRating = JapaneseHerts::Eastern,
                    bool HasRoundHoles = HasRoundPinholes::True,
                    int NumberOfHoles = NumberOfPinholes::Two);
    ~JapaneseOutlet();

    int GetVoltageRating() const;
    int GetFrequencyRating() const;

private:
    int VoltageRating;
    int FrequencyRating;
};

// =========== Adaptee ===========
class Plug
{
public:
    Plug(int PinCount, bool HasRoundPins);
    ~Plug();

    bool GetHasRoundPins() const;
    int GetPinCount() const;

private:
    bool HasRoundPins;
    int PinCount;
};

// =========== Adapter ===========
class Adapter : public Outlet
{
public:
    Adapter(Plug * pPlug = nullptr, Outlet * pOutlet = nullptr);
    ~Adapter();

    bool CheckNeedsAdapter(Outlet * pOutlet); // determines if an adapter is needed
    bool CheckOutletCompatibility(Outlet * pOutlet); // logic -- plug/outlet needs an adapter

    void SetPlug(Plug * pPlug);
    Plug * GetPlug();

private:
    Plug * pPlug;
};
