enum state { standardMode, calibrationMode, maintenanceMode, idleMode } state;

class Globals
{
private:
    // creating private constructor, since only static methods can access the constructor only
    Globals();
    Globals(int systemState, int numberOfFiles);

    // ========== member variables ==========
    static Globals * pGlobals;
    int systemState;
    int numberOfFiles;
    
public:
    // deleting copy constructor -- can be clone-able
    Globals(const Globals& obj) = delete; 
    // deleting assignment operator -- can't use the "=" operator
    void operator=(const Globals &) = delete;

    // functions calls the private constructor -- effectively is the constructor
    static Globals * getInstance();

    // ============ getters ============ 
    int GetSystemState();
    int GetNumberOfFiles();

    // ============ setters ============
    void SetSystemState(int systemState);
    void SetNumberOfFiles(int numberOfFiles);
};
