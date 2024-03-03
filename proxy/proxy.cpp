#include "proxy.hpp"

// =======  =======
static void printToConsole(std::string toConsole) {
	std::cout << toConsole << std::endl;
}

// ======= Time =======
Time::Time() {
	const std::chrono::time_point now{ std::chrono::system_clock::now() };
	const std::chrono::year_month_day ymd{ std::chrono::floor<std::chrono::days>(now) };

	SetDay(static_cast<unsigned>(ymd.day()));
	SetMonth(static_cast<unsigned>(ymd.month()));
	SetYear(static_cast<int>(ymd.year()));

	printToConsole("Time created");
}

Time::~Time() {
	printToConsole("Time destroyed");
}

// ======= CreditCardOwnerData =======
CreditCardOwnerData::CreditCardOwnerData(int securityCode,
										 int cardNumber,
										 std::string firstName,
										 std::string lastName,
										 std::string companyName) :
	securityCode(securityCode),
	cardNumber(cardNumber),
	firstName(firstName),
	lastName(lastName),
	companyName(companyName)
{
	printToConsole("CreditCardOwnerData created");
}

CreditCardOwnerData::~CreditCardOwnerData() {
	printToConsole("CreditCardOwnerData destroyed");
}

// ======= CreditCardData =======
CreditCardData::CreditCardData(bool isPaymentAuthenticated,
								int validMonth,
								int validYear,
								int securityCode,
								int cardNumber,
								std::string firstName,
								std::string lastName,
								std::string companyName) :
	isPaymentAuthenticated(isPaymentAuthenticated),
	validMonth(validMonth),
	validYear(validYear),
	securityCode(securityCode),
	cardNumber(cardNumber),
	firstName(firstName),
	lastName(lastName),
	companyName(companyName)
{
	printToConsole("Credit Card Data created");
}

CreditCardData::~CreditCardData() {
	printToConsole("Credit Card Data destroyed");
}

// ======= Cash =======
Cash::Cash(double paymentBalance, double paymentTotal) :
	paymentBalance(paymentBalance),
	paymentTotal(paymentTotal)
{
	printToConsole("Cash created");
}

Cash::~Cash() {
	printToConsole("Cash destroyed");
}

double Cash::CheckBalance() {
	std::cout << "Balance: " << GetPaymentBalance() << std::endl;
	return this->paymentBalance;
}

double Cash::PayAmount(double payment, Time * time) {
	double newBalance = GetPaymentBalance() - payment;

	// checks for overpayment, returns overplayment else return no overplayment value
	if (newBalance < 0) {
		newBalance = abs(newBalance);
		SetPaymentBalance(0);
		std::cout << "Over payment! Returning $" << std::setprecision(2) << newBalance << "!" << std::endl;
	}
	else {
		SetPaymentBalance(newBalance);
		printToConsole("Payment received");
	}

	return newBalance;
}

// ======= Credit Card =======
CreditCard::CreditCard(Cash * cash, 
						CreditCardData * creditCardData, 
						Time * time) :
	cash(new Cash(*cash)),
	creditCardData(creditCardData),
	time(time)
{
	printToConsole("CreditCard created");
}

CreditCard::~CreditCard() {
	delete cash;

	printToConsole("CreditCard destroyed");
}

double CreditCard::CheckBalance() {
	return GetCash()->CheckBalance();
}

double CreditCard::PayAmount(double payment, Time * time) {
	double results;

	if (CheckPaymentAuthentication(GetCreditCardData(), time)) {
		results = GetCash()->PayAmount(payment, time);
		GetCash()->SetPaymentBalance(results);
		std::cout << "Payment authenticated and processing..." << std::endl;
	}
	else {
		results = 0;
		printToConsole("Payment failed to autenticate!");
	}

	return results;
}

bool CreditCard::CheckPaymentAuthentication(CreditCardData * creditCardData, Time * time) {
	if (CheckValidMonth(creditCardData, time) &&
		CheckValidYear(creditCardData, time) &&
		CheckSecurityCode(creditCardData) &&
		CheckCardNumber(creditCardData) &&
		CheckFirstName(creditCardData) &&
		CheckLastName(creditCardData) &&
		CheckCompanyName(creditCardData))
	{
		return true;
	}
	else 
		return false;
}

bool CreditCard::CheckValidMonth(CreditCardData* creditCardData, Time* time) {
	if (1 <= creditCardData->GetValidMonth() &&
		creditCardData->GetValidMonth() <= 12)
	{
		return true;
	}
	else 
		return false;
}

bool CreditCard::CheckValidYear(CreditCardData* creditCardData, Time * time) {

	if (time->GetYear() <= creditCardData->GetValidYear()) 
		return true;
	else 
		return false;
}

bool CreditCard::CheckSecurityCode(CreditCardData* creditCardData) {
	if (0 <= creditCardData->GetSecurityCode() &&
		creditCardData->GetSecurityCode() <= 999)
	{
		return true;
	}
	else 
		return false;
}

bool CreditCard::CheckCardNumber(CreditCardData* creditCardData) {
	return true;
}

bool CreditCard::CheckFirstName(CreditCardData* creditCardData) {
	return true;
}

bool CreditCard::CheckLastName(CreditCardData* creditCardData) {
	return true;
}

bool CreditCard::CheckCompanyName(CreditCardData* creditCardData) {
	return true;
}

// ======= Client Code =======
static double RequestCheckBalance(PaymentType * paymentType) {
	return paymentType->CheckBalance();
}

static double PayBill(PaymentType* paymentType, double amount, Time * time, CreditCardOwnerData* creditCardOwnerData) {
	return paymentType->PayAmount(amount, time);
}

// overloading function to differentiate if cash is used for payment
static double PayBill(Cash* paymentType, double amount, Time * time, CreditCardOwnerData* creditCardOwnerData) {
	return paymentType->PayAmount(amount, time);
}


// ======= Main =======
int main() {
	Time * time = new Time();

	Cash * cash = new Cash(100.00, 500.00);
	CreditCardOwnerData * creditCardOwnerData = new CreditCardOwnerData(420, 123456, "John", "Doe", "Capital One");
	CreditCardData * creditCardData = new CreditCardData(false, 9, 2026, 420, 123456, "John", "Doe", "Capital One");
	CreditCard * creditCard = new CreditCard(cash, creditCardData, time);

	auto creditCardBalance_precheck = RequestCheckBalance(creditCard);
	auto paymentLeft = PayBill(creditCard, 30.00, time, creditCardOwnerData);
	auto creditCardBalance_check = RequestCheckBalance(creditCard);
	auto paymentRemainding = PayBill(creditCard, 60.00, time, creditCardOwnerData);
	auto creditCardBalance_postcheck = RequestCheckBalance(creditCard);

	delete time;
	delete creditCard;

	return 0;
}