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

// --------------- getters/setters ---------------
ComputerPart * ComputerPart::GetParent() {
    return this->parent;
}

void ComputerPart::SetParent(ComputerPart * parent) {
    this->parent = parent;
}

// --------------- virtuals ---------------
bool ComputerPart::IsComposite() {
    return false;
}

void ComputerPart::Print() {
    std::cout << "Parent: " << GetParent() << std::endl;
}


// ============= Leaf =============
Part::Part(std::string brandName, std::string modelName) :
    brandName(brandName),
    modelName(modelName)
{
    std::cout << "Part created" << std::endl;
}

Part::~Part() {
    std::cout << "Part destroyed" << std::endl;
}

std::string Part::GetBrandName() {
    return this->brandName;
}

std::string Part::GetModelName() {
    return this->modelName;
}

void Part::SetBrandName(std::string brandName) {
    this->brandName = brandName;
}

void Part::SetModelName(std::string modelName) {
    this->modelName = modelName;
}

// --------------- virtuals ---------------
bool Part::IsComposite() {
    return false;
}

void Part::Print() {
    std::cout << "Brand Name: " << brandName << std::endl;
    std::cout << "Model Name: " << modelName << std::endl;
}

// ============= Concrete Leaves =============
Mouse::Mouse(int dpi) :
    dpi(dpi)
{
    std::cout << "Mouse created" << std::endl;
}

Mouse::~Mouse() {
    std::cout << "Mouse destroyed" << std::endl;
}

int Mouse::GetDPI() {
    return this->dpi;
}

void Mouse::SetDPI(int dpi) {
    this->dpi = dpi;
}

// ------ virtuals ------
bool Mouse::IsComposite() {
    return false;
}

void Mouse::Print() {
    std::cout << "DPI: " << GetDPI() << std::endl;
} 

// ============= Computer -- Composite =============
Computer::Computer() {
    std::cout << "Computer composite object created" << std::endl;
}

Computer::~Computer() {
    std::cout << "Computer composite object created" << std::endl;
}

void Computer::Add(ComputerPart * computerPart) {
    children.push_back(computerPart);
    computerPart->SetParent(computerPart);
}

void Computer::Remove(ComputerPart * computerPart) {
    children.remove(computerPart);
    computerPart->SetParent(nullptr);
}

bool Computer::IsComposite() {
    return true;
}

void Computer::Print() {

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

void Peripherals::Print() {

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

void Tower::Print() {

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

void Motherboard::Print() {

}

// ================== Main ==================
int main()
{
    std::cout << "Hello World" << std::endl;

    Part * mouse = new Mouse();
    Computer * computer = new Computer();

    computer->Add(mouse);
    
    return 0;
}
