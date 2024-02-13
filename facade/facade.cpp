#include <iostream>

#include "facade.hpp"

// ==== WashCloth ====
WashCloth::WashCloth() {
    std::cout << "WashCloth created" << std::endl;
}

WashCloth::~WashCloth() {
    std::cout << "WashCloth destroyed" << std::endl;
}

// ==== NotePad ====
NotePad::NotePad() {
    std::cout << "NotePad created" << std::endl;
}

NotePad::~NotePad() {
    std::cout << "NotePad destroyed" << std::endl;
}

// ==== Pen ====
Pen::Pen() {
    std::cout << "Pen created" << std::endl;
}

Pen::~Pen() {
    std::cout << "Pen destroyed" << std::endl;
}

// ==== Menu ====
Menu::Menu() {
    std::cout << "Menu created" << std::endl;
}

Menu::~Menu() {
    std::cout << "Menu destroyed" << std::endl;
}

// ==== Knife ====
Knife::Knife() {
    std::cout << "Knife created" << std::endl;
}

Knife::~Knife() {
    std::cout << "Knife destroyed" << std::endl;
}

// ==== Plate ====
Plate::Plate() {
    std::cout << "Plate created" << std::endl;
}

Plate::~Plate() {
    std::cout << "Plate destroyed" << std::endl;
}

// ==== Pan ====
Pan::Pan() {
    std::cout << "Pan created" << std::endl;
}

Pan::~Pan() {
    std::cout << "Pan destroyed" << std::endl;
}

// ======== Waiter ========
Waiter::Waiter(WashCloth * washCloth,
                NotePad * notePad,
                Pen * pen,
                Menu * menu) :
    washCloth(washCloth),
    notePad(notePad),
    pen(pen),
    menu(menu)
{
    std::cout << "Waiter created" << std::endl;
}

Waiter::~Waiter() {
    std::cout << "Waiter destroyed" << std::endl;
}

void Waiter::CleansTable() {

}

void Waiter::PlacesUtensils() {

}

void Waiter::GivesMenu() {

}

void Waiter::ReceivesCustomerOrders() {

}

void Waiter::WritesOrder() {

}

void Waiter::SendsOrderToKitchen() {

}

void Waiter::GivesBill() {

}

// ======== Chef ========
Chef::Chef(WashCloth* washCloth,
            Plate* plate,
            Pan* pan,
            Knife* knife) :
    washCloth(washCloth),
    plate(plate),
    pan(pan),
    knife(knife)
{
    std::cout << "Chef created" << std::endl;
}

Chef::~Chef() {
    std::cout << "Chef destroyed" << std::endl;
}

void Chef::PreparesFood() {

}

void Chef::CutsFood() {

}

void Chef::CooksFood() {

}

void Chef::PlatesFood() {

}

void Chef::WashesDishes() {

}

// ======== FrontOfHouse ========
FrontOfHouse::FrontOfHouse(Waiter* waiter) :
    waiter(waiter)
{
    std::cout << "FrontOfHouse created" << std::endl;
}

FrontOfHouse::~FrontOfHouse() {
    std::cout << "FrontOfHouse destroyed" << std::endl;
}

Waiter* FrontOfHouse::GetWaiter() const {
    return this->waiter;
}

void FrontOfHouse::SetWaiter(Waiter* waiter) {
    this->waiter = waiter;
}

void FrontOfHouse::WritesReserveTime() {

}

void FrontOfHouse::SeatsGuests() {

}

void FrontOfHouse::ReceivesBill() {

}

// ======== BackOfHouse ========
BackOfHouse::BackOfHouse(Chef * chef) :
    chef(chef)
{
    std::cout << "BackOfHouse created" << std::endl;
}

BackOfHouse::~BackOfHouse() {
    std::cout << "BackOfHouse destroyed" << std::endl;
}

Chef * BackOfHouse::GetChef() const {
    return this->chef;
}

void BackOfHouse::SetChef(Chef * chef) {
    this->chef = chef;
}

void BackOfHouse::ReceivesOrder() {

}

void BackOfHouse::CompletesOrder() {

}

void BackOfHouse::CallsWaiter() {

}

// ======== Customer ========
Customer::Customer() {
    std::cout << "Customer created" << std::endl;
}

Customer::~Customer() {
    std::cout << "Customer destroyed" << std::endl;
}

void Customer::EntersRestaurant() {

}

void Customer::GoesToTable() {

}

void Customer::PlacesFoodOrder() {

}

void Customer::StartsEating() {

}

void Customer::FinishesEating() {

}

void Customer::PaysBill() {

}

void Customer::LeavesTable() {

}

void Customer::LeavesRestaurant() {

}

void Customer::RatesRestaurantReview() {

}

// ======== RestaurantFacade ========
RestaurantFacade::RestaurantFacade(FrontOfHouse* frontOfHouse,
                    BackOfHouse* backOfHouse) :
    frontOfHouse(frontOfHouse),
    backOfHouse(backOfHouse)
{
    std::cout << "RestaurantFacade created" << std::endl;
}

RestaurantFacade::~RestaurantFacade() {
    std::cout << "RestaurantFacade destroyed" << std::endl;
}

void RestaurantFacade::AskForReservation() {

}

void RestaurantFacade::SeatsCustomers() {

}

FrontOfHouse* RestaurantFacade::GetFrontOfHouse() const {
    return this->frontOfHouse;
}

BackOfHouse* RestaurantFacade::GetBackOfHouse() const {
    return this->backOfHouse;
}

void RestaurantFacade::SetFrontOfHouse(FrontOfHouse* frontOfHouse) {

}

void RestaurantFacade::SetBackOfHouse(BackOfHouse* backOfHouse) {

}

// ======== Main ========
int main()
{
    WashCloth* washCloth = new WashCloth();
    NotePad * notePad = new NotePad();
    Pen * pen = new Pen();
    Menu * menu = new Menu();        
    Plate * plate = new Plate();
    Pan * pan = new Pan();
    Knife * knife = new Knife();

    Waiter * waiter = new Waiter(washCloth, notePad, pen, menu);

    return 0;
}