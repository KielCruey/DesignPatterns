#include <iostream>
#include <string>

#include "UMLArrowsComposition.hpp"


static void printToConsole(std::string toConsole) {
	std::cout << toConsole << std::endl;
}

// =========== Engine ===========
Engine::Engine() {
	printToConsole("Engine created!");
}

Engine::~Engine() {
	printToConsole("Engine destroyed!");
}

void Engine::StartEngine() {
	printToConsole("Engine Started");
}

void Engine::StopEngine() {
	printToConsole("Engine Stoped");
}

// =========== Car ===========
Car::Car() :
	engine(new Engine())
{
	printToConsole("Car created");
}

Car::~Car() {
	printToConsole("Car destroyed");
	delete engine;
}

void Car::Start() {
	engine->StartEngine();
}

void Car::Stop() {
	engine->StopEngine();
}

// =========== Main ===========
int main() {
	Car* car = new Car();

	car->Start();
	car->Stop();

	delete car;

	return 0;
}