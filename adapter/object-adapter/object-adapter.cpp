#include "object-adapter.hpp"

// =========== Outlet ===========
Outlet::Outlet(bool HasRoundHoles, int NumberOfHoles) :
    HasRoundHoles(HasRoundHoles),
    NumberOfHoles(NumberOfHoles)
{
    std::cout << "Outlet Created" << std::endl;
}

Outlet::~Outlet() {
    std::cout << "Outlet deleted" << std::endl;
}

bool Outlet::GetHasRoundHoles() const {
    return this->HasRoundHoles;
}

int Outlet::GetNumberOfHoles() const {
    return this->NumberOfHoles;
}

// =========== AmericanOutlet ===========
AmericanOutlet::AmericanOutlet(int VoltageRating, 
                                int FrequencyRating, 
                                bool HasRoundHoles, 
                                int NumberOfHoles) :
    Outlet(HasRoundHoles, NumberOfHoles),
    VoltageRating(VoltageRating),
    FrequencyRating(FrequencyRating)
{
    std::cout << "AmericanOutlet Created" << std::endl;
}

AmericanOutlet::~AmericanOutlet() {
    std::cout << "AmericanOutlet deleted" << std::endl;
}

int AmericanOutlet::GetFrequencyRating() const {
    return this->FrequencyRating;
}

int AmericanOutlet::GetVoltageRating() const {
    return this->VoltageRating;
}

// =========== UKOutlet ===========
UKOutlet::UKOutlet(int VoltageRating, 
                    int FrequencyRating,
                    bool HasRoundHoles,
                    int NumberOfHoles) :
    Outlet(HasRoundHoles, NumberOfHoles),
    VoltageRating(VoltageRating),
    FrequencyRating(FrequencyRating)
{
    std::cout << "UKOutlet created" << std::endl;
}

UKOutlet::~UKOutlet() {
    std::cout << "UKOutlet deleted" << std::endl;
};

int UKOutlet::GetFrequencyRating() const {
    return this->FrequencyRating;
}

int UKOutlet::GetVoltageRating() const {
    return this->VoltageRating;
}

// =========== JapaneseOutlet ===========
JapaneseOutlet::JapaneseOutlet(int VoltageRating, 
                                int FrequencyRating,
                                bool HasRoundHoles,
                                int NumberOfHoles) :
    Outlet(HasRoundHoles, NumberOfHoles),
    FrequencyRating(FrequencyRating),
    VoltageRating(VoltageRating)
{
    std::cout << "JapaneseOutlet created" << std::endl;
}

JapaneseOutlet::~JapaneseOutlet() {
    std::cout << "JapaneseOutlet deleted" << std::endl;
}

int JapaneseOutlet::GetFrequencyRating() const {
    return this->FrequencyRating;
}

int JapaneseOutlet::GetVoltageRating() const {
    return this->VoltageRating;
}

// =========== Plug ===========
Plug::Plug(int PinCount, bool HasRoundPins) :
    PinCount(PinCount),
    HasRoundPins(HasRoundPins)
{
    std::cout << "Plug created" << std::endl;
}

Plug::~Plug() {
    std::cout << "Plug deleted" << std::endl;
}

bool Plug::GetHasRoundPins() const {
    return this->HasRoundPins;
}

int Plug::GetPinCount() const {
    return this->PinCount;
}

// =========== AmericanPlug ===========
AmericanPlug::AmericanPlug(int VoltageRating, 
                           int FrequencyRating, 
                           int PinCount, 
                           bool HasRoundPins) :
    VoltageRating(VoltageRating),
    FrequencyRating(FrequencyRating),
    Plug(PinCount, HasRoundPins)
{
    std::cout << "American plug created" << std::endl;
}

AmericanPlug::~AmericanPlug() {
    std::cout << "American plug destroyed" << std::endl;
}

int AmericanPlug::GetVoltageRating() const {
    return this->VoltageRating;
}

int AmericanPlug::GetFrequencyRating() const {
    return this->FrequencyRating;
}

// =========== UKPlug ===========
UKPlug::UKPlug(int VoltageRating, 
               int FrequencyRating, 
               int PinCount, 
               bool HasRoundPins) :
    VoltageRating(VoltageRating),
    FrequencyRating(FrequencyRating),
    Plug(PinCount, HasRoundPins)
{
    std::cout << "UK plug created" << std::endl;
}

UKPlug::~UKPlug() {
    std::cout << "UK plug destroyed" << std::endl;
}

int UKPlug::GetVoltageRating() const {
    return this->VoltageRating;
}

int UKPlug::GetFrequencyRating() const {
    return this->FrequencyRating;
}

// =========== JapanesePlug ===========
JapanesePlug::JapanesePlug(int VoltageRating, 
                           int FrequencyRating, 
                           int PinCount,
                           bool HasRoundPins) :
    VoltageRating(VoltageRating),
    FrequencyRating(FrequencyRating),
    Plug(PinCount, HasRoundPins)
{
    std::cout << "Japanese plug created" << std::endl;
}

JapanesePlug::~JapanesePlug() {
    std::cout << "Japanese plug destroyed" << std::endl;
}

int JapanesePlug::GetVoltageRating() const {
    return this->VoltageRating;
}

int JapanesePlug::GetFrequencyRating() const {
    return this->FrequencyRating;
}

// =========== Adapter ===========
Adapter::Adapter(Plug * pPlug, Outlet * pOutlet) :
    pPlug(pPlug),
    Outlet(pOutlet->GetHasRoundHoles(), pOutlet->GetNumberOfHoles())
{
    std::cout << "Adapter created" << std::endl;
}

Adapter::~Adapter() {
    std::cout << "Adapter deleted" << std::endl;
}

bool Adapter::CheckNeedsAdapter(Outlet * pOutlet) {
    if(CheckOutletCompatibility(pOutlet)) {
        std::cout << "No Adapter Needed!" << std::endl;
        return false;
    }
    else {
        std::cout << "Adapter Needed!" << std::endl;
        return true;
    }
}

bool Adapter::CheckOutletCompatibility(Outlet * pOutlet) {
    // logic -- checking plug and outlet needs an adapter
    if(pPlug->GetHasRoundPins() == pOutlet->GetHasRoundHoles() 
        && pPlug->GetPinCount() <= pOutlet->GetNumberOfHoles())
    {
        return true;
    }
    else
        return false;
}

void Adapter::SetPlug(Plug * pPlug) {
    this->pPlug = pPlug;
}

Plug * Adapter::GetPlug() {
    return this->pPlug;
}

// =========== Client code ===========
static void CheckPlugAndOutlet(Plug & pPlug, Outlet & pOutlet) {
    // checks if adapter is needed
    Adapter * pAdapter = new Adapter(&pPlug, &pOutlet);
    bool temp = pAdapter->CheckOutletCompatibility(&pOutlet);
    bool WhatAdapter = pAdapter->CheckNeedsAdapter(&pOutlet);
    std::cout << WhatAdapter << std::endl;
}

// =========== Main code ===========
int main() {
    Plug * pAmericanPlug = new Plug(2, false);
    Plug * pUKPlug = new Plug(3, false);
    Plug * pJapanesePlug = new Plug(2, true);
    
    AmericanOutlet * pAmericanOutlet = new AmericanOutlet();
    UKOutlet * pUKOutlet = new UKOutlet();
    JapaneseOutlet * pJapaneseOutlet = new JapaneseOutlet(60);

    CheckPlugAndOutlet(*pAmericanPlug, *pAmericanOutlet);
    CheckPlugAndOutlet(*pAmericanPlug, *pUKOutlet);

    return 0;
}