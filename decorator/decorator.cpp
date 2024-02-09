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
Knight::Knight() :
    Entity()
{
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
Archer::Archer() :
    Entity()
{

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
EntitySpecialization::EntitySpecialization(Entity * entity) :
    Entity(),
    entity(entity)
{
    std::cout << "EntitySpecialization created" << std::endl;
}

EntitySpecialization::~EntitySpecialization() {
    std::cout << "EntitySpecialization destroyed" << std::endl;
}

Entity * EntitySpecialization::GetEntity() {
    return this->entity;
}

void EntitySpecialization::SetEntity(Entity * entity) {
    this->entity = entity;
}


// =========== Holy Knight ===========
HolyKnight::HolyKnight(Entity * entity) :
    EntitySpecialization(entity)
{
    std::cout << "Holy Knight created" << std::endl;
}

HolyKnight::~HolyKnight() {
    std::cout << "Holy Knight destroyed" << std::endl;
}


// =========== Dark Knight ===========
DarkKnight::DarkKnight(Entity * entity) :
    EntitySpecialization(entity)
{
    std::cout << "Dark Knight created" << std::endl;
}

DarkKnight::~DarkKnight() {
    std::cout << "Dark Knight destroyed" << std::endl;
}

// =========== Long Bow Archer ===========
LongBowArcher::LongBowArcher(Entity * entity) :
    EntitySpecialization(entity)
{
    std::cout << "Long Bow Archer created" << std::endl;
}

LongBowArcher::~LongBowArcher() {
    std::cout << "Long Bow Archer destroyed" << std::endl;
}

// =========== Cross Bow Archer ===========
CrossBowArcher::CrossBowArcher(Entity * entity) :
    EntitySpecialization(entity)
{
    std::cout << "Cross Bow Archer created" << std::endl;
}

CrossBowArcher::~CrossBowArcher() {
    std::cout << "Cross Bow Archer destroyed" << std::endl;
}

// =========== Main ===========
int main()
{
    std::cout << "Hello World" << std::endl;

    return 0;
}