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
	if (serialNumber == nullptr) { this->serialNumber = 0; }
	else { this->serialNumber = new int(*serialNumber);	}

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

// An assignment operator is used to replace the data of a previously initialized object with some other object's data.
// This assumes that both objects are created and by using the = operator, member variables get copied.
Motorcycle& Motorcycle::operator= (const Motorcycle& motorcyle){
	// transfering data to newly created object
	this->make = motorcyle.make;
	this->model = motorcyle.model;

	if (motorcyle.serialNumber == nullptr) { this->serialNumber = 0; }
	else { this->serialNumber = new int(*motorcyle.serialNumber); }

	return *this;
}

// For the move constructor and move assigment functions, the && means a r-value, which is of type unnamed temporary object.
// The concept of moving is most useful for objects that manage the storage they use, such as objects that allocate storage with new and delete.

// For the move constructor, the content is actually transferred from one object (the source) to the other (the destination).
// This moving only happens when the source of the value is an unnamed object.
// Unnamed objects are objects that are temporary in nature, and thus haven't even been given a name. Typical examples of unnamed objects are return values of functions or type-casts.
Motorcycle::Motorcycle(Motorcycle&& motorcycle) :
	make(motorcycle.make),
	model(motorcycle.model)
{
	// when transfering the data from one object to another, must delete the object that's being moved dynamic memory 
	if (motorcycle.serialNumber == nullptr) { this->serialNumber = 0; }
	else { this->serialNumber = new int (*motorcycle.serialNumber); }

	// for all dynamic memory, need to set the values to nullptr to prevent a dandling pointer
	// the memory will be cleared up my the destructor, however need to 'erase' the pointer.
	motorcycle.serialNumber = nullptr; // 
}

// The move assignment operator = is used for transferring a temporary object to an existing object.
Motorcycle& Motorcycle::operator= (Motorcycle&& motorcycle) noexcept
{
	// transfering data to newly created object
	this->make = motorcycle.make;
	this->model = motorcycle.model;
	
	if (motorcycle.serialNumber == nullptr) { this->serialNumber = 0; }
	else { this->serialNumber = new int(*motorcycle.serialNumber); }

	motorcycle.serialNumber = nullptr;

	return motorcycle;
}

// ========= Client Code =========
static void constructorDestructorExample() {
	Motorcycle* motorcycle = new Motorcycle("Yamaha", "Sport Touring", new int(98765)); // constructor
	delete motorcycle; //destructor
}

static void copyConstructorExample() {
	Motorcycle motor = Motorcycle("Harlely-Davison", "Nightster", new int(12345));
	Motorcycle cycle = motor;

	// changing 'motor' object doesn't change 'cycle' object because of deep copy
	motor.setMake("Honda");
	motor.setModel("Roadster");
	motor.setSerialNumber(new int(11111));
}

static void copyAssignmentOperator() {
	Motorcycle mCycle = Motorcycle("Honda", "Roadster", new int(44444));
	Motorcycle bike;
	bike = mCycle;

	// chaning 'bike' object doesn't change 'mCycle' object
	bike.setMake("BMW");
	bike.setModel("Sidecar");
	bike.setSerialNumber(new int(99999));
}

static void moveConstructorExample() {
	std::vector<Motorcycle> vMotorcycle;

	// calls the move constructor because the Motorcycle is an unnamed object as the vector's parameter
	vMotorcycle.push_back( Motorcycle("Indian", "Roadster", new int(22222)) );
}

static void moveAssignmentExample() {
	Motorcycle motorcycle;

	// move assignment invoked because created a unnamed object, which is a rvalue
	motorcycle = Motorcycle("Unbranded", "Monster", new int(414)); 
}

// ========= Main =========
int main() {
	constructorDestructorExample();
	copyConstructorExample();
	copyAssignmentOperator();
	moveConstructorExample();
	moveAssignmentExample();

	return 0;
}