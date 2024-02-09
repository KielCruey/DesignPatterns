#include <iostream>

#include "decorator.hpp"

// =========== Entity ===========
Entity::Entity(int health, int mana, int fatigue) :
    health(health),
    mana(mana),
    fatigue(fatigue)
{
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

// =========== Knight ===========
Knight::Knight() {
    std::cout << "Knight created" << std::endl;
}

Knight::~Knight() {
    std::cout << "Knight destroyed" << std::endl;
}

void Knight::Attack() {

}

void Knight::Block() {
    
}

void Knight::Reload() {
    
}

// =========== Archer ===========
Archer::Archer() {

}

Archer::~Archer() {

}

void Archer::Attack() {
    
}

void Archer::Block() {
    
}

void Archer::Reload() {

}
// =========== Entity Specialization ===========
EntitySpecialization::EntitySpecialization(Entity * entity) {
    std::cout << "EntitySpecialization created" << std::endl;
}

EntitySpecialization::~EntitySpecialization() {
    std::cout << "EntitySpecialization destroyed" << std::endl
}

Entity * EntitySpecialization::GetEntity() {
    this->entity;
}

void EntitySpecialization::SetEntity(Entity * entity) {
    this->entity = entity;
}

/*
// =========== Holy Knight ===========
HolyKnight::HolyKnight(Entity * entity)
{

}

HolyKnight::~HolyKnight() {

}

// =========== Dark Knight ===========
DarkKnight::DarkKnight(Entity * entity) {

}

DarkKnight::~DarkKnight() {

}

// =========== Long Bow Archer ===========
LongBowArcher::LongBowArcher(Entity * entity) {

}

LongBowArcher::~LongBowArcher() {

}

// =========== Cross Bow Archer ===========
CrossBowArcher::CrossBowArcher(Entity * entity) {

}

CrossBowArcher::~CrossBowArcher() {
    
}
*/

// =========== Main ===========
int main()
{
    std::cout << "Hello World" << std::endl;

    return 0;
}