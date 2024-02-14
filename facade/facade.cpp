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
    std::cout << "Waiter cleans tables" << std::endl;
}

void Waiter::PlacesUtensils() {
    std::cout << "Waiter places utensils down" << std::endl;
}

void Waiter::GivesMenu() {
    std::cout << "Waiter gives menus to guests" << std::endl;
}

void Waiter::ReceivesCustomerOrders() {
    std::cout << "Waiter receives food orders from guests" << std::endl;
}

void Waiter::WritesOrder() {
    std::cout << "Waiter writes down orders" << std::endl;
}

void Waiter::SendsOrderToKitchen() {
    std::cout << "Waiter sends ticket to kitchen" << std::endl;
}

void Waiter::ServesCustomers() {
    std::cout << "Waiter serves customer" << std::endl;
}

void Waiter::GivesBill() {
    std::cout << "Waiter gives bill to guests" << std::endl;
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
    std::cout << "Chef prepares food" << std::endl;
}

void Chef::CutsFood() {
    std::cout << "Chef cuts food" << std::endl;
}

void Chef::CooksFood() {
    std::cout << "Chef cooks food" << std::endl;
}

void Chef::PlatesFood() {
    std::cout << "Chef plates food" << std::endl;
}

void Chef::OrderReady() {
    std::cout << "'Order is Ready' the Chef yells" << std::endl;
}

void Chef::WashesDishes() {
    std::cout << "Chef washes dishes" << std::endl;
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

void FrontOfHouse::SeatsGuests(int number) {
    for (int i = 0; i < number; i++) {
        std::cout << "Guest seated" << std::endl;
    }
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
    std::cout << "Customer enters restaurant and wait for a table" << std::endl;
}

void Customer::GoesToTable() {
    std::cout << "Customer is seated" << std::endl;
}

void Customer::PlacesFoodOrder() {
    std::cout << "Customer places order" << std::endl;
}

void Customer::StartsEating() {
    std::cout << "Customer eats food" << std::endl;
}

void Customer::FinishesEating() {
    std::cout << "Customer finishes eating" << std::endl;
}

void Customer::PaysBill() {
    std::cout << "Customer pays bill" << std::endl;
}

void Customer::LeavesTable() {
    std::cout << "Customer leaves table" << std::endl;
}

void Customer::LeavesRestaurant() {
    std::cout << "Customer leaves restaurant" << std::endl;
}

void Customer::RatesRestaurantReview() {
    std::cout << "Customer reviews restaurant" << std::endl;
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

void RestaurantFacade::SeatsCustomers(int number) {
    // removes people from waiting queue
    for (int i = 0; i < number; i++) {
        customerQueue.front()->GoesToTable();
        RemoveCustomer();
    }

    GetFrontOfHouse()->SeatsGuests(number);
    GetFrontOfHouse()->GetWaiter()->PlacesUtensils();
    GetFrontOfHouse()->GetWaiter()->GivesMenu();
}

void RestaurantFacade::RequestsCustomersOrder(Customer * customer) {
    customer->PlacesFoodOrder();
    GetFrontOfHouse()->GetWaiter()->ReceivesCustomerOrders();
}

void RestaurantFacade::CreateOrder() {
    GetBackOfHouse()->GetChef();
    GetFrontOfHouse()->GetWaiter()->SendsOrderToKitchen();
    GetBackOfHouse()->GetChef()->PreparesFood();
    GetBackOfHouse()->GetChef()->CutsFood();
    GetBackOfHouse()->GetChef()->CooksFood();
    GetBackOfHouse()->GetChef()->PlatesFood();
    GetBackOfHouse()->GetChef()->OrderReady();
    GetFrontOfHouse()->GetWaiter()->ServesCustomers();
}

void RestaurantFacade::CustomerConsumes(Customer* customer) {
    customer->StartsEating();
    customer->FinishesEating();
    
}

void RestaurantFacade::CustomerCheckout(Customer* customer) {
    GetFrontOfHouse()->GetWaiter()->GivesBill();
    customer->PaysBill();

}

void RestaurantFacade::ThanksCustomers(Customer* customer) {
    customer->LeavesTable();
    customer->LeavesRestaurant();
    GetFrontOfHouse()->GetWaiter()->CleansTable();
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

void RestaurantFacade::AddCustomer(Customer* customer) {
    customerQueue.push(customer);
}

void RestaurantFacade::RemoveCustomer() {
    customerQueue.pop();
}

// ========== Client Code ==========
Waiter * CreateWaiter() {
    WashCloth* washCloth = new WashCloth();
    NotePad* notePad = new NotePad();
    Pen* pen = new Pen();
    Menu* menu = new Menu();

    return new Waiter(washCloth, notePad, pen, menu);;
}

Chef * CreateChef() {
    WashCloth* washCloth = new WashCloth();
    Plate* plate = new Plate();
    Pan* pan = new Pan();
    Knife* knife = new Knife();

    return new Chef(washCloth, plate, pan, knife);
}

Customer* CreateCustomer() {
    return new Customer();
}

// ======== Main ========
int main()
{
    Waiter * waiter = CreateWaiter();
    Chef * chef = CreateChef();

    Customer * girlfriend = CreateCustomer();
    Customer * boyfriend = CreateCustomer();

    FrontOfHouse * frontOfHouse = new FrontOfHouse(waiter);
    BackOfHouse * backOfHouse = new BackOfHouse(chef);

    RestaurantFacade * restaurant = new RestaurantFacade(frontOfHouse, backOfHouse);
    restaurant->AddCustomer(girlfriend);
    restaurant->AddCustomer(boyfriend);

    restaurant->SeatsCustomers(2);
    restaurant->RequestsCustomersOrder(girlfriend);
    restaurant->RequestsCustomersOrder(boyfriend);
    restaurant->CreateOrder();
    restaurant->CustomerConsumes(girlfriend);
    restaurant->CustomerConsumes(boyfriend);
    restaurant->CustomerCheckout(girlfriend);
    restaurant->CustomerCheckout(boyfriend);


    return 0;
}