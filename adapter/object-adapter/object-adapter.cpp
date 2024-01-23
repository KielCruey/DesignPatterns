#include "object-adapter.hpp"

// =========== Outlet ===========
Outlet::Outlet(bool HasRoundHoles, int NumberOfHoles)
{
    this->HasRoundHoles = HasRoundHoles;
    this->NumberOfHoles = NumberOfHoles;

    std::cout << "Outlet Created" << std::endl;
}

Outlet::~Outlet()
{
    std::cout << "Outlet deleted" << std::endl;
}

bool Outlet::GetHasRoundHoles()
{
    return this->HasRoundHoles;
}

int Outlet::GetNumberOfHoles()
{
    return this->NumberOfHoles;
}

// =========== AmericanOutlet ===========
AmericanOutlet::AmericanOutlet(int VoltageRating) :
    Outlet(false, 3)
{
    this->VoltageRating = VoltageRating;

    std::cout << "AmericanOutlet Created" << std::endl;
}

AmericanOutlet::~AmericanOutlet() 
{
    std::cout << "AmericanOutlet deleted" << std::endl;
}

int AmericanOutlet::GetFrequencyRating()
{
    return this->FrequencyRating;
}

int AmericanOutlet::GetVoltageRating()
{
    return this->VoltageRating;
}

// =========== UKOutlet ===========
UKOutlet::UKOutlet(int VoltageRating, int FrequencyRating) :
    Outlet(false, 3)
{
    std::cout << "UKOutlet created" << std::endl;
}

UKOutlet::~UKOutlet()
{
    std::cout << "UKOutlet deleted" << std::endl;
};

int UKOutlet::GetFrequencyRating()
{
    return this->FrequencyRating;
}

int UKOutlet::GetVoltageRating()
{
    return this->VoltageRating;
}

// =========== JapaneseOutlet ===========
JapaneseOutlet::JapaneseOutlet(int FrequencyRating, int VoltageRating) :
    Outlet(true, 50)
{
    std::cout << "JapaneseOutlet created" << std::endl;
}

JapaneseOutlet::~JapaneseOutlet()
{
    std::cout << "JapaneseOutlet deleted" << std::endl;
}

int JapaneseOutlet::GetFrequencyRating()
{
    return this->FrequencyRating;
}

int JapaneseOutlet::GetVoltageRating()
{
    return this->VoltageRating;
}

// =========== Plug ===========
Plug::Plug(int PinCount, bool HasRoundPins)
{
    this->HasRoundPins = HasRoundPins;
    this->PinCount = PinCount;

    std::cout << "Plug created" << std::endl;
}

Plug::~Plug()
{
    std::cout << "Plug deleted" << std::endl;
}

bool Plug::GetHasRoundPins()
{
    return this->HasRoundPins;
}

int Plug::GetPinCount()
{
    return this->PinCount;
}

// =========== Adapter ===========
Adapter::Adapter(Plug * pPlug, Outlet * pOutlet) :
    Outlet(pOutlet->GetHasRoundHoles(), pOutlet->GetNumberOfHoles())
{
    this->pPlug = pPlug;

    std::cout << "Adapter created" << std::endl;
}

Adapter::~Adapter()
{
    std::cout << "Adapter deleted" << std::endl;
}

std::string Adapter::WhatTypeOfOutletAdapter(Outlet * pOutlet)
{
    if(CheckOutletCompatibility(pOutlet))
    {
        return "No Adapter Needed!";
    }
    else{
        return "Adapter Needed!";
    }
}

bool Adapter::CheckOutletCompatibility(Outlet * pOutlet)
{
    // logic -- checking plug and outlet needs an adapter
    if(pPlug->GetHasRoundPins() == pOutlet->GetHasRoundHoles() 
        && pPlug->GetPinCount() <= pOutlet->GetNumberOfHoles())
    {
        return true;
    }
    else
        return false;
}

void Adapter::SetPlug(Plug * pPlug)
{
    this->pPlug = pPlug;
}

Plug * Adapter::GetPlug()
{
    return this->pPlug;
}

// =========== Client code ===========
void CheckPlugAndOutlet(Plug * pPlug, Outlet * pOutlet)
{
    // checks if adapter is needed
    Adapter * pAdapter = new Adapter(pPlug, pOutlet);
    bool temp = pAdapter->CheckOutletCompatibility(pOutlet);
    std::string WhatAdapter = pAdapter->WhatTypeOfOutletAdapter(pOutlet);
    std::cout << WhatAdapter << std::endl;
}

// =========== MAIN code ===========
int main()
{
    Plug * pAmericanPlug = new Plug(2, false);
    Plug * pUKPlug = new Plug(3, false);
    Plug * pJapanesePlug = new Plug(2, true);
    
    AmericanOutlet * pAmericanOutlet = new AmericanOutlet();
    UKOutlet * pUKOutlet = new UKOutlet();
    JapaneseOutlet * pJapaneseOutlet = new JapaneseOutlet(60);

    CheckPlugAndOutlet(pAmericanPlug, pAmericanOutlet);
    CheckPlugAndOutlet(pAmericanPlug, pUKOutlet);

    return 0;
}