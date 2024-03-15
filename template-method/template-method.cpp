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
BeverageMaker::BeverageMaker(Extras * extras,
							Teas * teas,
							Coffees * coffees,
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

// calls template methods
void BeverageMaker::makeBeverage() {
	placeCup();
	boilWater();
	brew();
	pourInCup();
	addExtras();
}

void BeverageMaker::restockExtras() {
	getExtras()->setSugarShot(MAX_EXTRAS_AMOUNT);
	getExtras()->setCreamShot(MAX_EXTRAS_AMOUNT);
	getExtras()->setMilkShot(MAX_EXTRAS_AMOUNT);
	getExtras()->setChocolateShot(MAX_EXTRAS_AMOUNT);

	printToConsole("Restocked extras");
}

void BeverageMaker::restockTeas() {
	getTeas()->setGreenTea(MAX_BEVERAGE_AMOUNT);
	getTeas()->setBlackTea(MAX_BEVERAGE_AMOUNT);
	getTeas()->setChiaTea(MAX_BEVERAGE_AMOUNT);

	printToConsole("Restocked teas");
}

void BeverageMaker::restockCoffees() {
	getCoffees()->setLightRoast(MAX_BEVERAGE_AMOUNT);
	getCoffees()->setMediumRoast(MAX_BEVERAGE_AMOUNT);
	getCoffees()->setDarkRoast(MAX_BEVERAGE_AMOUNT);

	printToConsole("Restocked coffees");
}

void BeverageMaker::placeCup() {
	setCups(getCups() - 1);

	printToConsole("Cup placed");
}

void BeverageMaker::boilWater() {
	printToConsole("Water boiled");
}

void BeverageMaker::pourInCup() {
	setWaterAmount(getWaterAmount() - BEVERAGE_WATER);

	printToConsole("Beverage poured in cup");
}

// =========== TeaMaker ===========
TeaMaker::TeaMaker(Extras* extras,
					Teas* teas,
					int cups,
					double waterAmount) :
	BeverageMaker(extras, teas, nullptr, cups, waterAmount)
{ }

TeaMaker::~TeaMaker() {
	printToConsole("TeaMaker deleted");
}

void TeaMaker::brew() {
	printToConsole("Brewing tea");
}

void TeaMaker::addExtras() {
	printToConsole("Tea extras added");
}

// =========== CoffeeMaker ===========
CoffeeMaker::CoffeeMaker(Extras* extras,
						Coffees* coffees,
						int cups,
						double waterAmount) :
	BeverageMaker(extras, nullptr, coffees, cups, waterAmount)
{ }

CoffeeMaker::~CoffeeMaker() {
	printToConsole("CoffeeMaker deleted");
}

void CoffeeMaker::brew() {
	printToConsole("Brewing coffee");
}

void CoffeeMaker::addExtras() {
	printToConsole("Coffee extras added");
}

// =========== Main ===========
int main() {



	Extras* extras = new Extras();
	Teas* teas = new Teas();
	Coffees* coffees = new Coffees();

	TeaMaker * teaMaker = new TeaMaker(extras, teas);
	CoffeeMaker* coffeeMaker = new CoffeeMaker(extras, coffees);

	delete extras;
	delete teas;
	delete coffees;

	teaMaker->makeBeverage();
	coffeeMaker->makeBeverage();





	return 0;
}