#include "state.hpp"

// ======== Boss ========
Boss::Boss(Mood * mood) :
	mood(mood)
{
	this->TransitionMood(mood);
}

Boss::~Boss() {
	delete mood;
}

void Boss::helpMe() {
	getMood()->helpMe();
}

void Boss::directMe() {
	getMood()->directMe();
}

void Boss::TransitionMood(Mood * mood) {
	if (this->getMood() != nullptr) {
		delete this->mood;
	}

	setMood(mood);
}

// ======== Mood ========
Mood::Mood() {

}

Mood::~Mood() {

}

// ======== BadMood ========
void BadMood::helpMe() {

}

void BadMood::directMe() {

}

// ======== OkMood ========
void OkMood::helpMe() {

}

void OkMood::directMe() {

}

// ======== GoodMood ========
void GoodMood::helpMe() {

}

void GoodMood::directMe() {

}

// ======== Main ========
int main() {
	Boss * boss;

	return 0;
}