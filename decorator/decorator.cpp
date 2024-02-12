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

int Entity::GetHealth() const {
    return this->health;
}

int Entity::GetMana() const {
    return this->mana;
}

int Entity::GetFatigue() const {
    return this->fatigue;
}

void Entity::SetHealth(int health) {
    if(0 > health) this->health = 0;
    else this->health = health;
}

void Entity::SetMana(int mana) {
    if(0 > mana) this->mana = 0;
    else this->mana = mana;
}

void Entity::SetFatigue(int fatigue) {
    if(0 > fatigue) this->fatigue = 0;
    else this->fatigue = fatigue;
}

// =========== Knight ===========
Knight::Knight(int health = 100, int mana = 100, int fatigue = 100) :
    Entity(health, mana, fatigue)
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
Archer::Archer(int health = 100, int mana = 100, int fatigue = 100) :
    Entity(health, mana, fatigue)
{
    std::cout << "Archer created" << std::endl;
}

Archer::~Archer() {
    std::cout << "Archer destroyed" << std::endl;
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

Entity * EntitySpecialization::GetEntity() const {
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