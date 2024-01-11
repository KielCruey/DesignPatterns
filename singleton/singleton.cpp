#include <string>
#include <iostream>

#include "singleton.hpp"

// ========== Singleton class ==========
Globals::Globals(): 
    systemState(static_cast<int>(standardMode)), 
    numberOfFiles(0) 
{ }

Globals::Globals(int systemState, int numberOfFiles)
{
    this->systemState = systemState;
    this->numberOfFiles = numberOfFiles;
}

Globals * Globals::getInstance()
{
    // checking if no instance of class
    if (pGlobals == nullptr) 
    {
        std::cout << "Creating a new Globals object" << std::endl;

        // We can access private members within the class.
        pGlobals = new Globals(); 
        
        return pGlobals; 
    }
    else
    {
        std::cout << "Globals object exists, returning existing Globals object" << std::endl;

        // if instancePtr != NULL that means the class already have an instance. 
        // So, we are returning that instance and not creating new one.
        return pGlobals;
    }
}

int Globals::GetSystemState()
{
    return this->systemState;
}

int Globals::GetNumberOfFiles()
{
    return this->numberOfFiles;
}

void Globals::SetSystemState(int systemState)
{
    this->systemState = systemState;
}

void Globals::SetNumberOfFiles(int numberOfFiles)
{
    this->numberOfFiles = numberOfFiles;
}

// ========== Main ==========
// initializing member pointer to itself
Globals * Globals::pGlobals = nullptr;

int main()
{
    // directly calling the getInstance() method which act as the constructor
    Globals * pMainGlobals = Globals::getInstance();

    pMainGlobals->SetNumberOfFiles(4);
    int state = pMainGlobals->GetSystemState();
    return 0;
}