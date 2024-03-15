#include "template-method.hpp"

static void printToConsole(std::string toConsole) {
	std::cout << toConsole << std::endl;
}

// =========== Extras ===========
Extras::Extras(int sugarShot,
				int creamShot,
				int milkShot,
				int chocolateShot) :
	sugarShot(sugarShot),
	creamShot(creamShot),
	milkShot(milkShot),
	chocolateShot(chocolateShot)
{ }

// =========== Teas ===========
Teas::Teas(int greenTea,
			int blackTea,
			int chiaTea) :
	greenTea(greenTea),
	blackTea(blackTea),
	chiaTea(chiaTea)
{ }

// =========== Coffees ===========
Coffees::Coffees(int lightRoast,
		int mediumRoast,
		int darkRoast) :
	lightRoast(lightRoast),
	mediumRoast(mediumRoast),
	darkRoast(darkRoast)
{ }

// =========== BeverageMaker ===========
BeverageMaker::BeverageMaker(Extras* extras,
							Teas* teas,
							Coffees* coffees,
							int cups,
							double waterAmount) :
	extras(new Extras(*extras)),
	cups(cups),
	waterAmount(waterAmount)
{
	if (teas != nullptr) {
		this->teas = new Teas(*teas);
	}

	if (coffees != nullptr) {
		this->coffees = new Coffees(*coffees);
	}

	printToConsole("BeverageMaker created");
}

BeverageMaker::~BeverageMaker() {
	delete extras;

	// only TeaMaker class needs to delete
	if (this->teas != nullptr) {
		delete teas;
	}

	if (this->coffees != nullptr) {
		delete coffees;
	}

	printToConsole("BeverageMaker deleted");
}

void BeverageMaker::makeBeverage() {

}

void BeverageMaker::restockExtras() {

}

void BeverageMaker::restockTeas() {

}

void BeverageMaker::restockCoffees() {

}

void BeverageMaker::placeCup() {

}

void BeverageMaker::boilWater() {

}

void BeverageMaker::pourInCup() {

}

// =========== TeaMaker ===========
TeaMaker::TeaMaker(Extras* extras,
					Teas* teas,
					int cups,
					double waterAmount) :
	BeverageMaker(extras, teas, nullptr, cups, waterAmount)
{ }

TeaMaker::~TeaMaker() {

}

void TeaMaker::brew() {

}

void TeaMaker::addExtras() {

}

// =========== CoffeeMaker ===========
CoffeeMaker::CoffeeMaker(Extras* extras,
						Coffees* coffees,
						int cups,
						double waterAmount) :
	BeverageMaker(extras, nullptr, coffees, cups, waterAmount)
{ }

CoffeeMaker::~CoffeeMaker() {

}

void CoffeeMaker::brew() {

}

void CoffeeMaker::addExtras() {

}

// =========== Main ===========
int main() {

	// a little test
	{
		Extras* extras = new Extras();
		Teas* teas = new Teas();
		Coffees* coffees = new Coffees();

		TeaMaker * teaMaker = new TeaMaker(extras, teas);
		CoffeeMaker* coffeeMaker = new CoffeeMaker(extras, coffees);

		delete extras;
		delete teas;
		delete coffees;

		delete teaMaker;
		delete coffeeMaker;
	}

	return 0;
}