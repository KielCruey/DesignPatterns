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

// =========== Subsystem(s) ===========
class FrontOfHouse
{   
public:
    FrontOfHouse();
    ~FrontOfHouse();

    void WritesReserveTime();
    void SeatsGuests();
    void ReceivesBill();

private:
    Waiter * waiter;
};

class BackOfHouse
{
public:
    BackOfHouse();
    ~BackOfHouse();

    void ReceivesOrder();
    void CompletesOrder();
    void CallsWaiter();

private:
    Chef * chef;
};

// =========== Facade ===========
class RestaurantFacade
{
    void AskForReservation();
    void SeatsCustomers();
};