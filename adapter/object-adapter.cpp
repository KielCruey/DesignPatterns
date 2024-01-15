#include <iostream>
#include <memory>

// =========== Abstract Target ===========
class Outlet
{
private: 
    bool RoundHoles;
    int NumberOfHoles;

public:
    Outlet(bool RoundHoles, int NumberOfHoles)
    {
        this->RoundHoles = RoundHoles;
        this->NumberOfHoles = NumberOfHoles;

        std::cout << "Outlet Created" << std::endl;
    }

    virtual ~Outlet()
    {
        std::cout << "Outlet deleted" << std::endl;
    }

    // =========== getters/setters ===========
    bool GetRoundHoles()
    {
        return this->RoundHoles;
    }

    int GetNumberOfHoles()
    {
        return this->NumberOfHoles;
    }
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
    AmericanOutlet(int VoltageRating = 120) :
        Outlet(false, 3)
    {
        this->VoltageRating = VoltageRating;

        std::cout << "AmericanOutlet Created" << std::endl;
    }

    ~AmericanOutlet() 
    {
        std::cout << "AmericanOutlet deleted" << std::endl;
    }

    // =========== general functions ===========
    int GetFrequencyRating()
    {
        return this->FrequencyRating;
    }

    int GetVoltageRating()
    {
        return this->VoltageRating;
    }
};

class UKOutlet : public Outlet
{
public:
    int FrequencyRating;
    int VoltageRating;
    
public:
    // =========== special class functions ===========
    UKOutlet(int VoltageRating, int FrequencyRating) :
        Outlet(false, 3)
    {
        std::cout << "UKOutlet created" << std::endl;
    }

    ~UKOutlet()
    {
        std::cout << "UKOutlet deleted" << std::endl;
    };

    // =========== general functions ===========
    int GetFrequencyRating()
    {
        return this->FrequencyRating;
    }

    int GetVoltageRating()
    {
        return this->VoltageRating;
    }
};

class JapaneseOutlet : public Outlet
{
private:
    int FrequencyRating;
    int VoltageRating;
    
public:
    // =========== special class functions ===========
    JapaneseOutlet(int VoltageRating, int FrequencyRating) :
        Outlet(true, 50)
    {
        std::cout << "JapaneseOutlet created" << std::endl;
    }

    ~JapaneseOutlet()
    {
        std::cout << "JapaneseOutlet deleted" << std::endl;
    }

    // =========== general functions ===========
    int GetFrequencyRating()
    {
        return this->FrequencyRating;
    }

    int GetVoltageRating()
    {
        return this->VoltageRating;
    }
};

// =========== Adaptee ===========
class Plug
{
private:
    bool HasRoundPins;
    int PinCount;

public:
    // =========== special class functions ===========
    Plug(int PinCount, bool HasRoundPins)
    {
        this->HasRoundPins = HasRoundPins;
        this->PinCount = PinCount;

        std::cout << "Plug created" << std::endl;
    }

    ~Plug()
    {
        std::cout << "Plug deleted" << std::endl;
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
};

// =========== Adapter ===========
class Adapter : public Outlet
{
private:
    Plug * pPlug;

public:
    // =========== special class functions ===========
    Adapter(Outlet * pOutlet, Plug * pPlug) :
        Outlet(pOutlet->GetRoundHoles(), pOutlet->GetNumberOfHoles())
    {
        this->pPlug = pPlug;

        std::cout << "Adapter created" << std::endl;
    }
    
    ~Adapter()
    {
        std::cout << "Adapter deleted" << std::endl;
    }

    // =========== general functions ===========
    std::string WhatTypeOfOutletAdapter(Outlet * pOutlet)
    {
        if(CheckOutletCompatibility(pOutlet))
        {
            return "No Adapter Needed!";
        }
        else{
            return "Adapter Needed!";
        }

    }

    bool CheckOutletCompatibility(Outlet * pOutlet)
    {
        if( pPlug->GetHasRoundPins() == pOutlet->GetRoundHoles() 
            && pPlug->GetPinCount() <= pOutlet->GetNumberOfHoles())
        {
            return true;
        }
        else
            return false;
    }

    // =========== getters/setters ===========
    void SetPlug(Plug * pPlug)
    {
        this->pPlug = pPlug;
    }

    Plug * GetPlug()
    {
        return this->pPlug;
    }
};

// =========== Client code ===========


// =========== MAIN code ===========
int main()
{
    Plug * pAmericanPlug = new Plug(2, false);
    AmericanOutlet * pAmericanOutlet = new AmericanOutlet();

    // checks if adapter and fit into plug
    Adapter * pAdapter = new Adapter(pAmericanOutlet, pAmericanPlug);
    std::string WhatAdapter = pAdapter->WhatTypeOfOutletAdapter(pAmericanOutlet);
    std::cout << WhatAdapter << std::endl;

    return 0;
}