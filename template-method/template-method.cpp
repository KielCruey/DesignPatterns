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
TeaMaker::TeaMaker(BeverageMaker * beverageMaker) :
	BeverageMaker(beverageMaker->getExtras(),
		beverageMaker->getTeas(),
		beverageMaker->getCoffees(),
		beverageMaker->getCups(),
		beverageMaker->getWaterAmount())
{ }

void TeaMaker::brew() {

}

void TeaMaker::addExtras() {

}

// =========== CoffeeMaker ===========
CoffeeMaker::CoffeeMaker(BeverageMaker * beverageMaker) :
	BeverageMaker(beverageMaker->getExtras(),
		beverageMaker->getTeas(),
		beverageMaker->getCoffees(),
		beverageMaker->getCups(),
		beverageMaker->getWaterAmount()) 
{ }

void CoffeeMaker::brew() {

}

void CoffeeMaker::addExtras() {

}

// =========== Main ===========
int main() {

	return 0;
}