#include <iostream>

#include "decorator.hpp"

const int ATTACK_FATIGUE = 10;
const int BLOCK_FATIGUE = 10;

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
    if(0 > health) {
        this->health = 0;
        std::cout << "Entity dead -- Health at zero" << std::endl;
    }
    else this->health = health;
}

void Entity::SetMana(int mana) {
    if(0 > mana) {
        this->mana = 0;
        std::cout << "Entity drained -- Mana at zero" << std::endl;
    }
    else this->mana = mana;
}

void Entity::SetFatigue(int fatigue) {
    if(0 > fatigue) {
        this->fatigue = 0;
        std::cout << "Entity tired -- Fatigue at zero" << std::endl;
    } 
    else this->fatigue = fatigue;
}

// =========== Knight ===========
Knight::Knight(int health, int mana, int fatigue) :
    Entity(health, mana, fatigue)
{
    std::cout << "Knight created" << std::endl;
}

Knight::~Knight() {
    std::cout << "Knight destroyed" << std::endl;
}

void Knight::EquipArmor() {

}

void Knight::EquipGreaves() {

}

void Knight::EquipHelmet() {

}

void Knight::EquipMainHand() {

}

void Knight::EquipSecondaryHand() {

}

void Knight::EquipSabaton() {

}

int Knight::Attack(int fatigue) {
    SetFatigue(fatigue - ATTACK_FATIGUE);
    return GetFatigue();
}

int Knight::Block(int fatigue) {
    SetFatigue(fatigue - BLOCK_FATIGUE);
    return GetFatigue();
}

void Knight::Reload() {
    std::cout << "Knight don't reload!" << std::endl;
}

// =========== Archer ===========
Archer::Archer(int arrowsEquip, int health, int mana, int fatigue) :
    arrowsEquip(arrowsEquip),
    Entity(health, mana, fatigue)
{
    std::cout << "Archer created" << std::endl;
}

Archer::~Archer() {
    std::cout << "Archer destroyed" << std::endl;
}

int Archer::GetArrowsEquip() const {
    return this->arrowsEquip;
}

void Archer::SetArrowsEquip(int arrowsEquip) {
    this->arrowsEquip = arrowsEquip;
}

void Archer::EquipArmor() {

}

void Archer::EquipGreaves() {

}

void Archer::EquipHelmet() {

}

void Archer::EquipMainHand() {

}

void Archer::EquipSecondaryHand() {

}

void Archer::EquipSabaton() {

}

int Archer::Attack(int fatigue) {
    SetFatigue(fatigue - ATTACK_FATIGUE);
    return GetFatigue();
}

int Archer::Block(int fatigue) {
    SetFatigue(fatigue - BLOCK_FATIGUE);
    return GetFatigue();
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

int HolyKnight::GetFaithMagic() {

}

void HolyKnight::SetFaithMagic(int faithMagic) {

}

void HolyKnight::ClassAttack() {

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

int DarkKnight::GetDarkMagic() {

}

void DarkKnight::SetDarkMagic(int darkMagic) {

}

void DarkKnight::ClassAttack() {

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

void LongBowArcher::ClassAttack() {

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

void CrossBowArcher::ClassAttack() {

}

// =========== Main ===========
int main()
{
    std::cout << "Hello World" << std::endl;

    Knight * knight = new Knight();

    return 0;
}