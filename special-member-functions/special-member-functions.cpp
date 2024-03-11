#include "special-member-functions.hpp"

static void printToConsole(std::string toConsole) {
	std::cout << toConsole << std::endl;
}

// ========= Motorcycle =========
// The constructor just allows the objects of a class to be declared and will initialize any variables in the class.
// Upon creation of the object, the constructor requires parameter and initializes those values.
// The constructor can create stack or heap memory, which is determined by the constructor.
Motorcycle::Motorcycle(std::string make,
					   std::string model, 
					   int * serialNumber) :
	make(make),
	model(model),
	serialNumber(new int(*serialNumber))
{
	printToConsole("Motorcycle created");
}

// The destructor is responsible for the necessary cleanup needed by a class when its lifetime ends.
// Essentially, deletes or releases any dynamic mememory when parameters in the class are on the heap.
Motorcycle::~Motorcycle() {
	delete serialNumber; // dynamically allocated int

	printToConsole("Motorcycle deleted");
}

// The default copy constructor is a shallow copy of the variables.
// This copy constructor deep copies member variables.
// Deep copying is only needed for pointers, because copys only the address of the dynamic memory.
// It also needs to create a new block of memory as well during the copy.
Motorcycle::Motorcycle(const Motorcycle& motorcycle) :
	make(motorcycle.make),
	model(motorcycle.model),
	serialNumber(new int(*motorcycle.serialNumber))
{
	printToConsole("Motorcycle deep copy");
}

/*
// The copy assignment operator allows the member variables to be copied.
// This assumes that both objects are created and by using the = operator, member variables get copied.
Motorcycle& Motorcycle::operator= (const Motorcycle& rhs) {

	return *this;
}


// move constructor
Motorcycle::Motorcycle(Motorcycle&&) {

}

// move assigment
Motorcycle& Motorcycle::operator= (Motorcycle&&) {
	return;
}
*/

// ========= Main =========
int main() {
	// constructor/destructor example
	Motorcycle * motorcycle = new Motorcycle("Yamaha", "Sport Touring", new int(98765)); // constructor
	delete motorcycle; //destructor

	// copy constructor example
	Motorcycle motor = Motorcycle("Harlely-Davison", "Nightster", new int(12345));
	Motorcycle cycle = motor;

	// chaning 'motor' object doesn't change 'cycle' object because of deep copy
	motor.setMake("Honda");
	motor.setModel("Roadster");
	motor.setSerialNumber(new int(11111));

	return 0;
}