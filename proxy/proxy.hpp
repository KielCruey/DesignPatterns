#include <string>
#include <iostream>
#include <iomanip> // setprecision
#include <chrono>

class Time {
public:
	Time();
	~Time();

	inline int GetDay() const;
	inline int GetMonth() const;
	inline int GetYear() const;
	inline void SetDay(int day);
	inline void SetMonth(int month);
	inline void SetYear(int year);

private:
	int day;
	int month;
	int year;
};

class CreditCardOwnerData
{
public:
	CreditCardOwnerData(int validMonth = NULL,
						int validYear = NULL,
						int securityCode = NULL,
						int cardNumber = NULL,
						std::string firstName = nullptr,
						std::string lastName = nullptr,
						std::string companyName = nullptr);
	~CreditCardOwnerData();

	inline int GetValidMonth() const;
	inline int GetValidYear() const;
	inline int GetSecurityCode() const;
	inline int GetCardNumber() const;
	inline std::string GetFirstName() const;
	inline std::string GetLastName() const;
	inline std::string GetCompany() const;

	inline void SetValidMonth(int validMonth);
	inline void SetValidYear(int validYear);
	inline void SetSecurityCode(int securityCode);
	inline void SetCardNumber(int cardNumber);
	inline void SetFirstName(std::string firstName);
	inline void SetLastName(std::string lastName);
	inline void SetCompany(std::string companyName);

private: 
	int validMonth;
	int validYear;
	int securityCode;
	int cardNumber;
	std::string firstName;
	std::string lastName;
	std::string companyName; // what company the credit card was issued from
};

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
	std::string companyName; // what company the credit card was issued from
};

// ======= Subject =======
class PaymentType
{
public:
	virtual ~PaymentType() {};
	virtual double CheckBalance() = 0;
	virtual double PayAmount(double payment, Time * time) = 0;
};

// ======= Real Subject =======
class Cash : public PaymentType
{
public:
	Cash(double paymentBalance = NULL, 
			double paymentTotal = NULL);
	~Cash() override;

	double CheckBalance() override;
	double PayAmount(double payment, Time * time) override;

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
				CreditCardData * creditCardData = nullptr,
				Time * time = nullptr);
	~CreditCard() override;

	double CheckBalance() override;
	double PayAmount(double payment, Time * time) override;

	bool CheckPaymentAuthentication(CreditCardData* creditCardData, Time * time);
	bool CheckValidMonth(CreditCardData* creditCardData, Time * time);
	bool CheckValidYear(CreditCardData* creditCardData, Time * time);
	bool CheckSecurityCode(CreditCardData* creditCardData);
	bool CheckCardNumber(CreditCardData* creditCardData);
	bool CheckFirstName(CreditCardData* creditCardData);
	bool CheckLastName(CreditCardData* creditCardData);
	bool CheckCompanyName(CreditCardData* creditCardData);

	inline Cash * GetCash() const;
	inline CreditCardData * GetCreditCardData() const;
	inline Time * GetTime();

	inline void SetCash(Cash * cash);
	inline void SetCreditCardData(CreditCardData * creditCardData);
	inline void SetTime(Time * time);

protected:
	Cash * cash; // credit card is used to pay cash as payment
	CreditCardData * creditCardData;
	Time * time; // 
};

#include "proxy.inl"