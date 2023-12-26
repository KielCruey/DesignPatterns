#include <string>



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

    static Globals * pGlobals;

    // variables here:
    int systemState;
    int numberOfFiles;
    
public:
    enum state { standardMode, calibrationMode, maintenanceMode, idleMode } state;


    static Globals * getInstance()
    {
        // checking if no instance of class
        if (pGlobals == NULL) 
        {
            // We can access private members within the class.
            pGlobals = new Globals(); 
            
            return pGlobals; 
        }
        else
        {
            // if instancePtr != NULL that means the class already have an instance. 
            // So, we are returning that instance and not creating new one.
            return pGlobals;
        }
    }

    // deleting copy constructor
    Globals(const Globals& obj) = delete; 

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


    return 0;
}