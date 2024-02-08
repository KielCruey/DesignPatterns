#include <iostream>
    
#include "composite.hpp"  

// ============= Component =============
ComputerComponent::ComputerComponent(ComputerComponent * parent)
{
    SetParent(parent);

    std::cout << "ComputerComponent created" << std::endl;
}

ComputerComponent::~ComputerComponent() {
    std::cout << "ComputerComponent destroyed" << std::endl;
}

// --------------- getters/setters ---------------
ComputerComponent * ComputerComponent::GetParent() {
    return this->parent;
}

void ComputerComponent::SetParent(ComputerComponent * parent) {
    this->parent = parent;
}

// --------------- virtuals ---------------
bool ComputerComponent::IsComposite() {
    return false;
}

void ComputerComponent::Print() {
    std::cout << "Parent: " << GetParent() << std::endl;
}

// ============= Abstract Leaf =============
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

// ============= Concrete Leaves -- Mouse =============
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

// ============= Concrete Leaf -- Keyboard =============
Keyboard::Keyboard(bool hasClickyKeys) :
    Part(),
    hasClickyKeys(hasClickyKeys)
{
    std::cout << "Keyboard created" << std::endl;
}

Keyboard::~Keyboard() {
    std::cout << "Keyboard destroyed" << std::endl;
}

bool Keyboard::GetHasClickyKeys() {
    return this->hasClickyKeys;
}

void Keyboard::SetHasClickyKeys(bool HasClickyKeys) {
    this->hasClickyKeys = hasClickyKeys;
}

// ------ virtuals ------
bool Keyboard::IsComposite() {
    return false;
}

void Keyboard::Print() {
    std::cout << "HasClickyKeys: " << GetHasClickyKeys() << std::endl;
}

// ============= Concrete Leaf -- Monitor =============
Monitor::Monitor(double length, double width) :
    Part(),
    length(length),
    width(width)
{
    std::cout << "Monitor created" << std::endl;
}

Monitor::~Monitor() {
    std::cout << "Monitor deleted" << std::endl;
}

int Monitor::GetLength() {
    return this->length;
}

void Monitor::SetLength(int length) {
    this->length = length;
}

int Monitor::GetWidth() {
    this->width;
}

void Monitor::SetWidth(int width) {
    this->width = width;
}

// ------ virtuals ------
bool Monitor::IsComposite() { 
    return false;
}

void Monitor::Print() {
    std::cout << "Monitor Length: " << GetLength() << std::endl;
    std::cout << "Monitor Width: " << GetWidth() << std::endl;
}

// ============= Concrete Leaf -- Speakers =============
Speakers::Speakers(bool isPowered, int volume) :
    Part(),
    isPowered(isPowered),
    volume(volume)
{
    std::cout << "Speakers created" << std::endl;
}

Speakers::~Speakers() {
    std::cout << "Speakers destroyed" << std::endl;
}

bool Speakers::GetIsPowered() {
    return this->isPowered;
}

void Speakers::SetIsPowered(bool isPowered) {
    this->isPowered = isPowered;
}

int Speakers::GetVolume() {
    return this->volume;
}

void Speakers::SetVolume(int volume) {
    this->volume = volume;
}

// ------ virtuals ------
bool Speakers::IsComposite() {
    return false;
}

void Speakers::Print() {
    std::cout << "Speakers Powered: " << GetIsPowered() << std::endl;
    std::cout << "Speakers Volume: " << GetVolume() << std::endl;
}

// ============= Concrete Leaf -- SSD =============
SSD::SSD(double currentStorage, double totalStorage) :
    Part(),
    currentStorage(currentStorage),
    totalStorage(totalStorage)
{
    std::cout << "SSD created" << std::endl;
}

SSD::~SSD() {
    std::cout << "SSD destroyed" << std::endl;
}

double SSD::GetCurrentStorage() {
    return this->currentStorage;
}

void SSD::SetCurrentStorage(double currentStorage) {
    this->currentStorage = currentStorage;
}

double SSD::GetTotalStorage(){
    return this->totalStorage;
}

void SSD::SetTotalStorage(double totalStorage) {
    this->totalStorage = totalStorage;
}

// ------ virtuals ------
bool SSD::IsComposite() {
    return false;
}

void SSD::Print() {
    std::cout << "SSD Current Storage: " << GetCurrentStorage() << std::endl;
    std::cout << "SSD Total Storage: " << GetTotalStorage() << std::endl;
}

// ============= Concrete Leaf -- RAM =============
RAM::RAM(double capacity) :
    Part(),
    capacity(capacity)
{
    std::cout << "RAM created" << std::endl;
}

RAM::~RAM() {
    std::cout << "RAM destroyed" << std::endl;
}

int RAM::GetCapacity() {
    return this->capacity;
}

void RAM::SetCapacity(int capacity) {
    this->capacity = capacity;
}

// ------ virtuals ------
bool RAM::IsComposite() {
    return false;
}

void RAM::Print() {
    std::cout << "SSD Capacity: " << GetCapacity() << std::endl;
}

// ============= Concrete Leaf -- CPU =============
CPU::CPU(int cores) :
    Part(),
    cores(cores)
{
    std::cout << "CPU created" << std::endl;
}

CPU::~CPU() {
    std::cout << "CPU destroyed" << std::endl;
}

int CPU::GetCores() {
    return this->cores;
}

void CPU::SetCores(int cores) {
    this->cores = cores;
}

// ------ virtuals ------
bool CPU::IsComposite() {
    return false;
}

void CPU::Print() {
    std::cout << "CPU Cores: " << GetCores() << std::endl;
}

// ============= Concrete Leaf -- GPU =============
GPU::GPU(double memory) :
    Part(),
    memory(memory)
{
    std::cout << "GPU created" << std::endl;
}

GPU::~GPU() {
    std::cout << "GPU destroyed" << std::endl;
}

double GPU::GetMemory() {
    return this->memory;
}

void GPU::SetMemory(double memory) {
    this->memory = memory;
}

// ------ virtuals ------
bool GPU::IsComposite() {
    return false;
}

void GPU::Print() {
    std::cout << "GPU Memory: " << GetMemory() << std::endl;
}

// ============= Computer -- Composite =============
Computer::Computer() {
    std::cout << "Computer composite object created" << std::endl;
}

Computer::~Computer() {
    std::cout << "Computer composite object created" << std::endl;
}

void Computer::Add(ComputerComponent * computerComponent) {
    children.push_back(computerComponent);
    computerComponent->SetParent(computerComponent);
}

void Computer::Remove(ComputerComponent * computerComponent) {
    children.remove(computerComponent);
    computerComponent->SetParent(nullptr);
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
void Peripherals::Add(ComputerComponent * computerComponent) {
    children.push_back(computerComponent);
    computerComponent->SetParent(computerComponent);
}

// this Composite class deletes an object from its list and removes that object from its parent Component
void Peripherals::Remove(ComputerComponent * computerComponent) {
    children.remove(computerComponent);
    computerComponent->SetParent(nullptr);
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
void Tower::Add(ComputerComponent * computerComponent) {
    children.push_back(computerComponent);
    computerComponent->SetParent(nullptr);
}

// this Composite class deletes an object from its list and removes that object from its parent Component
void Tower::Remove(ComputerComponent * computerComponent) {
    children.remove(computerComponent);
    computerComponent->SetParent(nullptr);
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

void Motherboard::Add(ComputerComponent * computerComponent) {
    children.push_back(computerComponent);
    computerComponent->SetParent(nullptr);
}

void Motherboard::Remove(ComputerComponent * computerComponent) {
    children.remove(computerComponent);
    computerComponent->SetParent(nullptr);
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

    /*
    // building a computer
    Computer * computer = new Computer();

    Peripherals * peripherals = new Peripherals();
    Tower * tower = new Tower();

    computer->Add(peripherals);
    computer->Add(tower);

    Motherboard * motherboard = new Motherboard();

    tower->Add(motherboard);

    Mouse * mouse = new Mouse();
    Keyboard * keyboard = new Keyboard();
    Monitor * monitor = new Monitor();
    Speakers * speakers = new Speakers();

    peripherals->Add(mouse);
    peripherals->Add(keyboard);
    peripherals->Add(monitor);
    peripherals->Add(speakers);

    SSD * ssd = new SSD();
    RAM * ram = new RAM();
    CPU * cpu = new CPU();
    GPU * gpu = new GPU();

    motherboard->Add(ssd);
    motherboard->Add(ram);
    motherboard->Add(cpu);
    motherboard->Add(gpu);
    
    return 0;
    */
}
