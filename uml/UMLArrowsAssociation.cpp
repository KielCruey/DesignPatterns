#include "UMLArrowsAssociation.hpp"

// =========== Player ===========
Player::Player() {
	healthBar = new HealthBar();
}

Player::~Player() {
	delete healthBar;
}

// =========== Main ===========
int main() {
	return 0;
}