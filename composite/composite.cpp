#include <iostream>
    
#include "composite.hpp"  

// ============= Component =============
ComputerPart::ComputerPart(ComputerPart * parent)
{
    SetParent(parent);

    std::cout << "ComputerPart created" << std::endl;
}

ComputerPart::~ComputerPart() {
    std::cout << "ComputerPart destroyed" << std::endl;
}

// hard coded because it will have no other value
bool ComputerPart::IsComposite() {
    return false;
}

// --------------- getters/setters ---------------
void ComputerPart::SetParent(ComputerPart * parent) {
    this->parent = parent;
}

ComputerPart * ComputerPart::GetParent() {
    return this->parent;
}

// ============= Peripherals -- Composite =============
Peripherals::Peripherals() {
    std::cout << "Peripherals composite object created" << std::endl;
}

Peripherals::~Peripherals() {
    std::cout << "Peripherals composite object destroyed" << std::endl;
}

// this Composite class adds an object to its list and assigns that object to its parent Component
void Peripherals::Add(ComputerPart * computerPart) {
    children.push_back(computerPart);
    computerPart->SetParent(computerPart);
}

// this Composite class deletes an object from its list and removes that object from its parent Component
void Peripherals::Remove(ComputerPart * computerPart) {
    children.remove(computerPart);
    computerPart->SetParent(nullptr);
}

bool Peripherals::IsComposite() {
    return true;
}

// ============= Tower -- Composite =============
Tower::Tower() {
    std::cout << "Tower composite object created" << std::endl;
}

Tower::~Tower() {
    std::cout << "Tower composite object destroyed" << std::endl;
}

// this Composite class adds an object to its list and assigns that object to its parent Component
void Tower::Add(ComputerPart * computerPart) {
    children.push_back(computerPart);
    computerPart->SetParent(nullptr);
}

// this Composite class deletes an object from its list and removes that object from its parent Component
void Tower::Remove(ComputerPart * computerPart) {
    children.remove(computerPart);
    computerPart->SetParent(nullptr);
}

bool Tower::IsComposite() {
    return true;
}

// ============= Motherboard -- Composite =============
Motherboard::Motherboard() {
    std::cout << "Motherboard composite object created" << std::endl;
}

Motherboard::~Motherboard() {
    std::cout << "Motherboard composite object destroyed" << std::endl;
}

void Motherboard::Add(ComputerPart * computerPart) {
    children.push_back(computerPart);
    computerPart->SetParent(nullptr);
}

void Motherboard::Remove(ComputerPart * computerPart) {
    children.remove(computerPart);
    computerPart->SetParent(nullptr);
}

bool Motherboard::IsComposite() {
    return true;
}

// ================== Main ==================
int main()
{
    return 0;
}
