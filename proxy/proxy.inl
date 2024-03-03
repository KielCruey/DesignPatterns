// ======= CreditCardData =======
inline bool CreditCardData::GetisPaymentAuthenticated() const { 
	return isPaymentAuthenticated; 
}

inline int CreditCardData::GetValidMonth() const { 
	return validMonth; 
}

inline int CreditCardData::GetValidYear() const { 
	return validYear; 
}

inline int CreditCardData::GetSecurityCode() const { 
	return securityCode; 
}

inline int CreditCardData::GetCardNumber() const { 
	return cardNumber; 
}

inline std::string CreditCardData::GetFirstName() const { 
	return firstName; 
}

inline std::string CreditCardData::GetLastName() const { 
	return lastName; 
}

inline std::string CreditCardData::GetCompany() const { 
	return companyName; 
}

inline void CreditCardData::SetisPaymentAuthenticated(bool isPaymentAuthenticated) { 
	this->isPaymentAuthenticated = isPaymentAuthenticated; 
}

inline void CreditCardData::SetValidMonth(int validMonth) { 
	this->validMonth = validMonth; 
}

inline void CreditCardData::SetValidYear(int validYear) { 
	this->validYear = validYear; 
}

inline void CreditCardData::SetSecurityCode(int securityCode) { 
	this->securityCode = securityCode; 
}

inline void CreditCardData::SetCardNumber(int cardNumber) { 
	this->cardNumber = cardNumber; 
}

inline void CreditCardData::SetFirstName(std::string firstName) { 
	this->firstName = firstName; 
}

inline void CreditCardData::SetLastName(std::string lastName) { 
	this->lastName = lastName; 
}

inline void CreditCardData::SetCompany(std::string companyName) {
	this->companyName = companyName; 
}

// ======= Cash =======
inline double Cash::GetPaymentBalance() const {
	return this->paymentBalance;
}

inline double Cash::GetPaymentTotal() const {
	return this->paymentTotal;
}

inline void Cash::SetPaymentBalance(double paymentBalance) {
	this->paymentBalance = paymentBalance;
}

inline void Cash::SetPaymentTotal(double paymentTotal) {
	this->paymentTotal = paymentTotal;
}

// ======= Credit Card =======
inline Cash* CreditCard::GetCash() const {
	return this->cash;
}

inline CreditCardData* CreditCard::GetCreditCardData() const {
	return this->creditCardData;
}

inline void CreditCard::SetCash(Cash* cash) {
	this->cash = cash;
}

inline void CreditCard::SetCreditCardData(CreditCardData* creditCardData) {
	this->creditCardData = creditCardData;
}