#include <iostream>

#include "memento.hpp"

static void printToConsole(std::string toConsole) {
	std::cout << toConsole << std::endl;
}

// ======== Memento ========
Memento::Memento(std::string date,
				 std::string time,
				 std::string name,
				 std::string specialization,
				 std::string state,
				 int level,
				 int health,
				 int mana) :
	date(date),
	time(time),
	name(name),
	specialization(specialization),
	state(state),
	level(level),
	health(health),
	mana(mana)
{
	printToConsole("Memento created");
}

Memento::~Memento() {
	printToConsole("Memento deleted");
}

// ======== Originator ========
Originator::Originator(std::string name,
					   std::string specialization,
					   std::string state,
					   int level,
					   int health,
					   int mana) :
	name(name),
	specialization(specialization),
	state(state),
	level(level),
	health(health),
	mana(mana)
{
	printToConsole("Originator created");
}

Originator::~Originator() {
	printToConsole("Originator deleted");
}

void Originator::changeName() {

}

void Originator::changeSpecialization() {

}

void Originator::changeState() {

}

void Originator::levelUp() {

}

void Originator::levelDown() {

}

void Originator::healUp() {

}

void Originator::healDown() {

}

void Originator::manaUp() {

}

void Originator::manaDown() {

}

Memento * Originator::save() {
	return nullptr;
}

void Originator::restore(Memento* memento) {

}

// ======== Caretaker ========
Caretaker::Caretaker(Originator * originator) :
	originator(originator)
{

}

Caretaker::~Caretaker() {

}

void Caretaker::backup() {

}

void Caretaker::undo() {

}

void Caretaker::showHistory() {

}

// ======== Main ========
int main() {
	return 0;
}