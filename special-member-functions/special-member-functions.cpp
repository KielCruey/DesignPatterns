#include "special-member-functions.hpp"

static void printToConsole(std::string toConsole) {
	std::cout << toConsole << std::endl;
}

// ========= Motorcycle =========
Motorcycle::Motorcycle(std::string make, std::string model) :
	make(make),
	model(model)
{
	printToConsole("Motorcycle created");
}

Motorcycle::~Motorcycle() {
	printToConsole("Motorcycle deleted");
}

// copy constructor
Motorcycle::Motorcycle(const Motorcycle& motorcycle) {

}

// copy assignment
Motorcycle& Motorcycle::operator= (const Motorcycle&) {

}

// move constructor
Motorcycle::Motorcycle(Motorcycle&&) {

}

// move assigment
Motorcycle& Motorcycle::operator= (Motorcycle&&) {

}

// ========= Main =========
int main() {
	return 0;
}