#include "proxy.hpp"

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
	std::cout << "Credit Card Data created" << std::endl;
}

CreditCardData::~CreditCardData() {
	std::cout << "Credit Card Data destroyed" << std::endl;
}

// ======= Cash =======
Cash::Cash(double paymentBalance, double paymentTotal) :
	paymentBalance(paymentBalance),
	paymentTotal(paymentTotal)
{
	std::cout << "Cash created" << std::endl;
}

Cash::~Cash() {
	std::cout << "Cash destroyed" << std::endl;
}

double Cash::CheckBalance() {
	std::cout << "Balance: " << GetPaymentBalance() << std::endl;
	return this->paymentBalance;
}

double Cash::PayAmount(double payment) {
	double leftoverCash = GetPaymentBalance() - payment;

	// checks for overpayment, returns overplayment else return no overplayment value
	if (leftoverCash < 0) {
		leftoverCash = abs(leftoverCash);
		std::cout << "Over payment! Returning $" << std::setprecision(2) << leftoverCash << "!" << std::endl;
	}
	else {
		std::cout << "Payment received" << std::endl;
	}

	return leftoverCash;
}

double Cash::GetPaymentBalance() const {
	return this->paymentBalance;
}

double Cash::GetPaymentTotal() const {
	return this->paymentTotal;
}

void Cash::SetPaymentBalance(double paymentBalance) {
	this->paymentBalance = paymentBalance;
}

void Cash::SetPaymentTotal(double paymentTotal) {
	this->paymentTotal = paymentTotal;
}

// ======= Credit Card =======
CreditCard::CreditCard(Cash* cash, CreditCardData* creditCardData) :
	cash(new Cash(*cash)),
	creditCardData(creditCardData)
{
	std::cout << "CreditCard created" << std::endl;
}

CreditCard::~CreditCard() {
	delete cash;
	std::cout << "CreditCard destroyed" << std::endl;
}

double CreditCard::CheckBalance() {
	return GetCash()->CheckBalance();
}

double CreditCard::PayAmount(double payment) {
	double results;

	if (CheckPaymentAuthentication(GetCreditCardData())) {
		results = GetCash()->PayAmount(payment);
		GetCash()->SetPaymentBalance(results);
		std::cout << "Payment authenticated and processing..." << std::endl;
	}
	else {
		results = 0;
		std::cout << "Payment failed to autenticate!" << std::endl;
	}

	return results;
}

bool CreditCard::CheckPaymentAuthentication(CreditCardData* creditCardData) {
	bool results;

	if (CheckValidMonth(creditCardData) &&
		CheckValidYear(creditCardData) &&
		CheckSecurityCode(creditCardData) &&
		CheckCardNumber(creditCardData) &&
		CheckFirstName(creditCardData) &&
		CheckLastName(creditCardData) &&
		CheckCompanyName(creditCardData))
	{
		results = true;
	}
	else results = false;

	return results;
}

bool CreditCard::CheckValidMonth(CreditCardData* creditCardData) {
	bool results;

	if (1 <= creditCardData->GetValidMonth() &&
		creditCardData->GetValidMonth() <= 12)
	{
		results = true;
	}
	else results = false;

	return results;
}

bool CreditCard::CheckValidYear(CreditCardData* creditCardData) {
	return true;
}

bool CreditCard::CheckSecurityCode(CreditCardData* creditCardData) {
	bool results;

	if (0 <= creditCardData->GetSecurityCode() &&
		creditCardData->GetSecurityCode() <= 999)
	{
		results = true;
	}
	else results = false;
	
	return results;
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

Cash * CreditCard::GetCash() const {
	return this->cash;
}

CreditCardData * CreditCard::GetCreditCardData() const {
	return this->creditCardData;
}

void CreditCard::SetCash(Cash* cash) {
	this->cash = cash;
}

void CreditCard::SetCreditCardData(CreditCardData* creditCardData) {
	this->creditCardData = creditCardData;
}

// ======= Client Code =======
static double RequestCheckBalance(PaymentType * paymentType) {
	return paymentType->CheckBalance();
}

static double PayBill(PaymentType* paymentType, double amount) {
	return paymentType->PayAmount(amount);
}

// ======= Main =======
int main() {
	Cash * cash = new Cash(100.00, 500.00);
	CreditCardData * creditCardData = new CreditCardData(false, 9, 10, 420, 666999, "John", "Doe", "Capital One");
	CreditCard * creditCard = new CreditCard(cash, creditCardData);

	auto creditCardBalance_precheck = RequestCheckBalance(creditCard);
	auto paymentLeft = PayBill(creditCard, 30.00);
	auto creditCardBalance_check = RequestCheckBalance(creditCard);
	auto paymentRemainding = PayBill(creditCard, 30.00);
	auto creditCardBalance_postcheck = RequestCheckBalance(creditCard);

	return 0;
}