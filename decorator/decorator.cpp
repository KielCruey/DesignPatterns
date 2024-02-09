#include <iostream>

#include "decorator.hpp"

// =========== Entity ===========
Entity::Entity() {
    std::cout << "Entity created" << std::endl;
}

Entity::~Entity() {
    std::cout << "Entity destroyed" << std::endl;
}

int Entity::GetHealth() {
    return this->health;
}

void Entity::SetHealth(int health) {
    this->health = health;
}

int Entity::GetMana() {
    return this->mana;
}

void Entity::SetMana(int mana) {
    this->mana = mana;
}

int Entity::GetFatigue() {
    return this->fatigue;
}

void Entity::SetFatigue(int fatigue) {
    this->fatigue = fatigue;
}