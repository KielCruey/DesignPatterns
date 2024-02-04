enum state { standardMode, calibrationMode, maintenanceMode, idleMode } state;

class Globals
{
private:
    // creating private constructor, since only static methods can access the constructor only
    Globals();
    Globals(int systemState, int numberOfFiles);

    // ========== member variables ==========
    static Globals * pGlobals; // need a pointer that references the unique instance of that class
    
    int systemState;
    int numberOfFiles;
    
public:
    Globals(const Globals& obj) = delete; // deleting copy constructor -- can't be clone-able
    void operator=(const Globals &) = delete; // deleting assignment operator -- can't use the "=" operator

    static Globals * getInstance(); // functions calls the private constructor -- effectively is the constructor

    // ============ getters ============ 
    int GetSystemState();
    int GetNumberOfFiles();

    // ============ setters ============
    void SetSystemState(int systemState);
    void SetNumberOfFiles(int numberOfFiles);
};
