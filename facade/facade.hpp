#include <queue>

// =========== Waiter/Chef objects ===========
class WashCloth
{
public:
    WashCloth();
    ~WashCloth();
};
class NotePad
{
public:
    NotePad();
    ~NotePad();
};

class Pen
{
public:
    Pen();
    ~Pen();
};

class Menu
{
public:
    Menu();
    ~Menu();
};

class Knife
{
public:
    Knife();
    ~Knife();
};

class Plate
{
public:
    Plate();
    ~Plate();
};

class Pan
{
public:
    Pan();
    ~Pan();
};

// =========== Subsystem Helper Classes ===========
class Waiter
{
public:
    Waiter(WashCloth * washCloth = nullptr,
            NotePad * notePad = nullptr,
            Pen * pen = nullptr,
            Menu * menu = nullptr);
    ~Waiter();

    void CleansTable();
    void PlacesUtensils();
    void GivesMenu();
    void ReceivesCustomerOrders();
    void WritesOrder();
    void SendsOrderToKitchen();
    void GivesBill();    

private:
    WashCloth * washCloth;
    NotePad * notePad;
    Pen * pen;
    Menu * menu;
};

class Chef
{
public:
    Chef(WashCloth * washCloth = nullptr,
            Plate * plate = nullptr,
            Pan * pan = nullptr,
            Knife * knife = nullptr);
    ~Chef();

    void PreparesFood();
    void CutsFood();
    void CooksFood();
    void PlatesFood();
    void WashesDishes();

private:
    WashCloth* washCloth;
    Plate* plate;
    Pan* pan;
    Knife* knife;
};

// =========== Subsystem(s) ===========
class FrontOfHouse
{   
public:
    FrontOfHouse(Waiter * waiter = nullptr);
    ~FrontOfHouse();

    Waiter * GetWaiter() const;
    void SetWaiter(Waiter * waiter);

    void WritesReserveTime();
    void SeatsGuests();
    void ReceivesBill();

private:
    Waiter * waiter;
};

class BackOfHouse
{
public:
    BackOfHouse(Chef * chef = nullptr);
    ~BackOfHouse();

    Chef * GetChef() const;
    void SetChef(Chef * chef);

    void ReceivesOrder();
    void CompletesOrder();
    void CallsWaiter();

private:
    Chef * chef;
};

class Customer
{
public:
    Customer();
    ~Customer();

    void EntersRestaurant();
    void GoesToTable();
    void PlacesFoodOrder();
    void StartsEating();
    void FinishesEating();
    void PaysBill();
    void LeavesTable();
    void LeavesRestaurant();
    void RatesRestaurantReview();
};

// =========== Facade ===========
class RestaurantFacade
{
public:
    RestaurantFacade(FrontOfHouse * frontOfHouse = nullptr,
                        BackOfHouse * backOfHouse = nullptr);
    ~RestaurantFacade();

    void AskForReservation();
    void SeatsCustomers();

    FrontOfHouse * GetFrontOfHouse() const;
    BackOfHouse * GetBackOfHouse() const;

    void SetFrontOfHouse(FrontOfHouse* frontOfHouse);
    void SetBackOfHouse(BackOfHouse* backOfHouse);

protected:
    FrontOfHouse * frontOfHouse;
    BackOfHouse * backOfHouse;

    std::queue<Customer*> customerQueue;
};