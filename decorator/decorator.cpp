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
    std::cout << "Armor equipped" << std::endl;
}

void Knight::EquipGreaves() {
    std::cout << "Greaves equipped" << std::endl;
}

void Knight::EquipHelmet() {
    std::cout << "Helmet equipped" << std::endl;
}

void Knight::EquipMainHand() {
    std::cout << "Sword equipped" << std::endl;
}

void Knight::EquipSecondaryHand() {
    std::cout << "Shield equipped" << std::endl;
}

void Knight::EquipSabaton() {
    std::cout << "Sabatons equipped" << std::endl;
}

int Knight::Attack() {
    std::cout << "Sword swung" << std::endl;
    SetFatigue(GetFatigue() - ATTACK_FATIGUE);
    return GetFatigue();
}

int Knight::Block() {
    std::cout << "Blocked with shield" << std::endl;
    SetFatigue(GetFatigue() - BLOCK_FATIGUE);
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
    std::cout << "Armor equipped" << std::endl;
}

void Archer::EquipGreaves() {
    std::cout << "Greaves equipped" << std::endl;
}

void Archer::EquipHelmet() {
    std::cout << "Helmet equipped" << std::endl;
}

void Archer::EquipMainHand() {
    std::cout << "Bow equipped" << std::endl;
}

void Archer::EquipSecondaryHand() {
    std::cout << "Arrows equipped" << std::endl;
}

void Archer::EquipSabaton() {
    std::cout << "Sabatons equipped" << std::endl;
}

int Archer::Attack() {
    std::cout << "Shot bow" << std::endl;
    SetFatigue(GetFatigue() - ATTACK_FATIGUE);
    return GetFatigue();
}

int Archer::Block() {
    std::cout << "Archer blocked" << std::endl;
    SetFatigue(GetFatigue() - BLOCK_FATIGUE);
    return GetFatigue();
}

void Archer::Reload() {
    SetArrowsEquip(GetArrowsEquip() - 1);

    if(0 > GetArrowsEquip()) {
        SetArrowsEquip(0);
        std::cout << "Insufficient arrows" << std::endl;
    }
    else {
        std::cout << "Reloaded bow and arrow" << std::endl;
    }
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
HolyKnight::HolyKnight(Entity * entity, int faithMagic) :
    EntitySpecialization(entity),
    faithMagic(faithMagic)
{
    std::cout << "Holy Knight created" << std::endl;
}

HolyKnight::~HolyKnight() {
    std::cout << "Holy Knight destroyed" << std::endl;
}

int HolyKnight::GetFaithMagic() {
    return this->faithMagic;
}

void HolyKnight::SetFaithMagic(int faithMagic) {
    this->faithMagic = faithMagic;
}

void HolyKnight::ClassAttack() {
    std::cout << "Holy Knight's Ultimate Attack!" << std::endl;
}

void HolyKnight::EquipArmor() {
    std::cout << "Holy Armor equipped" << std::endl;
}

void HolyKnight::EquipGreaves() {
    std::cout << "Holy Greaves equipped" << std::endl;
}

void HolyKnight::EquipHelmet() {
    std::cout << "Holy Helmet equipped" << std::endl;
}

void HolyKnight::EquipMainHand() {
    std::cout << "Holy Sword equipped" << std::endl;
}

void HolyKnight::EquipSecondaryHand() {
    std::cout << "Holy Shield equipped" << std::endl;
}

void HolyKnight::EquipSabaton() {
    std::cout << "Holy Sabatons equipped" << std::endl;
}

int HolyKnight::Attack() {
    std::cout << "Holy attack" << std::endl;
    return 0;
}

int HolyKnight::Block() {
    std::cout << "Holy block" << std::endl;
    return 0;
}

void HolyKnight::Reload() {

}

// =========== Dark Knight ===========
DarkKnight::DarkKnight(Entity * entity, int darkMagic) :
    EntitySpecialization(entity),
    darkMagic(darkMagic)
{
    std::cout << "Dark Knight created" << std::endl;
}

DarkKnight::~DarkKnight() {
    std::cout << "Dark Knight destroyed" << std::endl;
}

int DarkKnight::GetDarkMagic() {
    return 0;
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
    Knight * knight = new Knight();
    knight->EquipArmor();
    knight->EquipGreaves();
    knight->EquipHelmet();
    knight->EquipMainHand();
    knight->EquipSecondaryHand();
    knight->EquipSabaton();

    knight->Attack();
    knight->Block();
    knight->Reload();

    Archer * archer = new Archer();
    archer->EquipArmor();
    archer->EquipGreaves();
    archer->EquipHelmet();
    archer->EquipMainHand();
    archer->EquipSecondaryHand();
    archer->EquipSabaton();

    archer->Attack();
    archer->Block();
    archer->Reload();
    
    HolyKnight * holyKnight = new HolyKnight(knight);
    holyKnight->GetEntity()->Attack();
    holyKnight->Attack();


    return 0;
}