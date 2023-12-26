#include <string>
#include <iostream>

class Globals
{
private:
    // creating private constructor, since only static methods can access the constructor only
    Globals() : systemState(static_cast<int>(standardMode)), numberOfFiles(0) {}

    Globals(int systemState, int numberOfFiles)
    {
        this->systemState = systemState;
        this->numberOfFiles = numberOfFiles;
    }

    // ========== member variables ==========
    static Globals * pGlobals;
    int systemState;
    int numberOfFiles;
    
public:
    enum state { standardMode, calibrationMode, maintenanceMode, idleMode } state;

    static Globals * getInstance()
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

    // deleting copy constructor -- can be clone-able
    Globals(const Globals& obj) = delete; 
    // deleting assignment operator -- can't use the "=" operator
    void operator=(const Globals &) = delete;

    // ============ getters ============ 
    int GetSystemState()
    {
        return this->systemState;
    }

    int GetNumberOfFiles()
    {
        return this->numberOfFiles;
    }

    // ============ setters ============
    void SetSystemState(int systemState)
    {
        this->systemState = systemState;
    }

    void SetNumberOfFiles(int numberOfFiles)
    {
        this->numberOfFiles = numberOfFiles;
    }
};

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