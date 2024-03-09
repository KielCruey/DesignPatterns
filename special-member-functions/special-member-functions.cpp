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
	model(model)
{
	// allocating memory
	this->serialNumber = new int;

	// setting class memeber variables
	setSerialNumber(serialNumber);

	printToConsole("Motorcycle created");
}

// The destructo is responsible for the necessary cleanup needed by a class when its lifetime ends.
// Essentially, deletes or releases any dynamic mememory when parameters in the class are on the heap.
Motorcycle::~Motorcycle() {
	delete serialNumber; // dynamically allocated int

	printToConsole("Motorcycle deleted");
}

// opy constructor
Motorcycle::Motorcycle(const Motorcycle& motorcycle) {

}

// copy assignment
Motorcycle& Motorcycle::operator= (const Motorcycle&) {
	return;
}

// move constructor
Motorcycle::Motorcycle(Motorcycle&&) {

}

// move assigment
Motorcycle& Motorcycle::operator= (Motorcycle&&) {
	return;
}

// ========= Main =========
int main() {
	return 0;
}