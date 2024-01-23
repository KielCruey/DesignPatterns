#include <iostream>
#include <memory>

// =========== Abstract Target ===========
class Outlet
{
private: 
    bool HasRoundHoles;
    int NumberOfHoles;

public:
    Outlet(bool RoundHoles, int NumberOfHoles);
    virtual ~Outlet();

    // =========== getters/setters ===========
    bool GetHasRoundHoles();
    int GetNumberOfHoles();
};

// =========== Concrete Target ===========
class AmericanOutlet : public Outlet
{
private:
    const int FrequencyRating = 60;
    int VoltageRating;

public:
    // =========== special class functions ===========
    // if voltage isn't defined, assumes stander non-industrial voltage
    AmericanOutlet(int VoltageRating = 120);
    ~AmericanOutlet();

    // =========== general functions ===========
    int GetFrequencyRating();
    int GetVoltageRating();
};

class UKOutlet : public Outlet
{
public:
    int FrequencyRating;
    int VoltageRating;
    
public:
    // =========== special class functions ===========
    UKOutlet(int VoltageRating = 230, int FrequencyRating = 50);
    ~UKOutlet();

    // =========== general functions ===========
    int GetFrequencyRating();
    int GetVoltageRating();
};

class JapaneseOutlet : public Outlet
{
private:
    int FrequencyRating;
    int VoltageRating;
    
public:
    // =========== special class functions ===========
    JapaneseOutlet(int FrequencyRating, int VoltageRating = 100);
    ~JapaneseOutlet();

    // =========== general functions ===========
    int GetFrequencyRating();
    int GetVoltageRating();
};

// =========== Adaptee ===========
class Plug
{
private:
    bool HasRoundPins;
    int PinCount;

public:
    // =========== special class functions ===========
    Plug(int PinCount, bool HasRoundPins);
    ~Plug();

    // =========== general function ===========
    bool GetHasRoundPins();
    int GetPinCount();
};

// =========== Adapter ===========
class Adapter : public Outlet
{
private:
    Plug * pPlug;

public:
    // =========== special class functions ===========
    Adapter(Plug * pPlug, Outlet * pOutlet);
    ~Adapter();

    // =========== general functions ===========
    std::string WhatTypeOfOutletAdapter(Outlet * pOutlet); // determines if an adapter is needed
    bool CheckOutletCompatibility(Outlet * pOutlet); // logic -- plug/outlet needs an adapter

    // =========== getters/setters ===========
    void SetPlug(Plug * pPlug);
    Plug * GetPlug();
};
