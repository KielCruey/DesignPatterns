#include <string>
#include <iostream>
#include <iomanip> // setprecision
#include <chrono>


// ========== Helper Classes ==========
class CreditCardData
{
public:
	CreditCardData(bool isPaymentAuthenticated = NULL,
					int validMonth = NULL,
					int validYear = NULL,
					int securityCode = NULL,
					int cardNumber = NULL,
					std::string firstName = nullptr,
					std::string lastName = nullptr,
					std::string companyName = nullptr);
	~CreditCardData();

	inline bool GetisPaymentAuthenticated() const;
	inline int GetValidMonth() const;
	inline int GetValidYear() const;
	inline int GetSecurityCode() const;
	inline int GetCardNumber() const;
	inline std::string GetFirstName() const;
	inline std::string GetLastName() const;
	inline std::string GetCompany() const;

	inline void SetisPaymentAuthenticated(bool isPaymentAuthenticated);
	inline void SetValidMonth(int validMonth);
	inline void SetValidYear(int validYear);
	inline void SetSecurityCode(int securityCode);
	inline void SetCardNumber(int cardNumber);
	inline void SetFirstName(std::string firstName);
	inline void SetLastName(std::string lastName);
	inline void SetCompany(std::string companyName);

private:
	bool isPaymentAuthenticated;
	int validMonth;
	int validYear;
	int securityCode;
	int cardNumber;
	std::string firstName;
	std::string lastName;
	std::string companyName;
};

// ======= Subject =======
class PaymentType
{
public:
	virtual ~PaymentType() {};
	virtual double CheckBalance() = 0;
	virtual double PayAmount(double payment) = 0;
};

// ======= Real Subject =======
class Cash : public PaymentType
{
public:
	Cash(double paymentBalance = NULL, 
			double paymentTotal = NULL);
	~Cash() override;

	double CheckBalance() override;
	double PayAmount(double payment) override;

	inline double GetPaymentBalance() const;
	inline double GetPaymentTotal() const;
	inline void SetPaymentBalance(double paymentBalance);
	inline void SetPaymentTotal(double paymentTotal);

private:
	double paymentBalance;
	double paymentTotal;
};

// ======= Proxy =======
class CreditCard : public PaymentType
{
public:
	CreditCard(Cash * cash = nullptr, 
				CreditCardData * creditCardData = nullptr);
	~CreditCard() override;

	double CheckBalance() override;
	double PayAmount(double payment) override;

	bool CheckPaymentAuthentication(CreditCardData* creditCardData);

	bool CheckValidMonth(CreditCardData* creditCardData);
	bool CheckValidYear(CreditCardData* creditCardData);
	bool CheckSecurityCode(CreditCardData* creditCardData);
	bool CheckCardNumber(CreditCardData* creditCardData);
	bool CheckFirstName(CreditCardData* creditCardData);
	bool CheckLastName(CreditCardData* creditCardData);
	bool CheckCompanyName(CreditCardData* creditCardData);

	Cash * GetCash() const;
	CreditCardData* GetCreditCardData() const;
	void SetCash(Cash * cash);
	void SetCreditCardData(CreditCardData * creditCardData);

private:
	Cash * cash; // credit card is used to pay cash as payment
	CreditCardData * creditCardData;
};


#include "proxy.inl"