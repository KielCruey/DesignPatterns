// =========== Subsystem Helper Classes ===========
class Waiter
{
public:
    Waiter();
    ~Waiter();

    void CleansTable();
    void PlacesUtensils();
    void GivesMenu();
    void ReceivesCustomerOrders();
    void WritesOrder();
    void SendsOrderToKitchen();
    void GivesBill();
};

class Chef
{
public:
    Chef();
    ~Chef();

    void PreparesFood();
    void CutsFood();
    void CooksFood();
    void PlatesFood();
    void WashesDishes();
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

// =========== Subsystem ===========
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

// =========== Subsystem ===========
class RestaurantFacade
{
    void AskForReservation();
    void SeatsCustomers();
};