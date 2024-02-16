#include <queue>

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
    void ServesCustomers();
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
    void OrderReady();
    void WashesDishes();
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
    void SeatsGuests(int number);
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
    void CallsWaiter();

private:
    Chef * chef;
};

class Customer
{
public:
    Customer();
    ~Customer();

    void CallsForReservation();
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

    void ChecksForReservation(Customer* customer);
    void SeatsCustomers(int number);
    void RequestsCustomersOrder(Customer* customer);
    void CreateOrder();
    void CustomerConsumes(Customer* customer);
    void CustomerCheckout(Customer* customer);
    void ThankCustomers(Customer* customer);

    FrontOfHouse * GetFrontOfHouse() const;
    BackOfHouse * GetBackOfHouse() const;

    void SetFrontOfHouse(FrontOfHouse* frontOfHouse);
    void SetBackOfHouse(BackOfHouse* backOfHouse);

    void AddCustomer(Customer * customer);
    void RemoveCustomer();

protected:
    FrontOfHouse * frontOfHouse;
    BackOfHouse * backOfHouse;

    std::queue<Customer*> customerQueue;
};