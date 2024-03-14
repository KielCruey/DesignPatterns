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
BeverageMaker::BeverageMaker() {
	setExtras(new Extras());
	setTeas(new Teas());
	setCoffees(new Coffees());
	setCups(MAX_CUPS);
	setWaterAmount(MAX_WATER_AMOUNT);
}

BeverageMaker::BeverageMaker(Extras* extras,
							Teas* teas,
							Coffees* coffees,
							int cups,
							double waterAmount) :
	extras(new Extras(*extras)),
	teas(new Teas(*teas)),
	coffees(new Coffees(*coffees)),
	cups(cups),
	waterAmount(waterAmount)
{
	printToConsole("BeverageMaker created");
}

BeverageMaker::~BeverageMaker() {
	delete extras;
	delete teas;
	delete coffees;

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
					Coffees* coffees,
					int cups,
					double waterAmount) :
	BeverageMaker(extras, teas, coffees, cups, waterAmount)
{ }

TeaMaker::~TeaMaker() {

}

void TeaMaker::brew() {

}

void TeaMaker::addExtras() {

}

// =========== CoffeeMaker ===========
CoffeeMaker::CoffeeMaker(Extras* extras,
						Teas* teas,
						Coffees* coffees,
						int cups,
						double waterAmount) :
	BeverageMaker(extras, teas, coffees, cups, waterAmount)
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

		TeaMaker * teaMaker = new TeaMaker(extras, teas, coffees);

		delete extras;
		delete teas;
		delete coffees;
	}

	return 0;
}