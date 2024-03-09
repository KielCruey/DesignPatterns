#include <string>
#include <iostream>

class Motorcycle
{
public:
	Motorcycle(std::string make = "N/A", 
			   std::string model = "N/A",
			   int * serialNumber = nullptr); // constructor
	~Motorcycle(); // destructor
	Motorcycle(const Motorcycle& motorcycle); // copy constructor
	Motorcycle& operator= (const Motorcycle&); // copy assignment
	Motorcycle(Motorcycle&&); // move constructor
	Motorcycle& operator= (Motorcycle&&); // move assigment

	inline int * getSerialNumber();
	inline void setSerialNumber(int * serialNumber);

private:
	std::string make;
	std::string model;
	int * serialNumber;
};

#include "special-member-functions.inl"