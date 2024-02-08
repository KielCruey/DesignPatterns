#include <list>
#include <string>

// ============= Abstract Component =============
// The base Component class declares common operations for both simple and complex objects of a composition.
// In this case, it's a base for the 'leaf' and 'composite' classes
class ComputerComponent
{
public:
    ComputerComponent(ComputerComponent * parent = nullptr);
    ~ComputerComponent();
    
    ComputerComponent * GetParent();
    void SetParent(ComputerComponent * parent);

    // ------ virtuals ------
    virtual void Add(ComputerComponent * computerComponent) {};
    virtual void Remove(ComputerComponent * computerComponent) {};
    virtual bool IsComposite();
    virtual void Print();

protected:
    ComputerComponent * parent;
};

// ============= "Abstract" Leaf =============
class Part : public ComputerComponent
{
public:
    Part(std::string brandName = "N/A", std::string modelName = "N/A");
    ~Part();

    std::string GetBrandName();
    std::string GetModelName();
    void SetBrandName(std::string brandName);
    void SetModelName(std::string modelName);

    // ------ virtuals ------
    virtual void Add(ComputerComponent * computerComponent) {};
    virtual void Remove(ComputerComponent * computerComponent) {};
    virtual bool IsComposite() override;
    virtual void Print() override;

private:
    std::string brandName;
    std::string modelName;
};

// ============= Concrete Leaves =============
class Mouse : public Part
{
public:
    Mouse(int dpi = 1000);
    ~Mouse();

    int GetDPI();
    void SetDPI(int dpi);

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;   

private:   
    int dpi;
};

class Keyboard : public Part
{
public:
    Keyboard(bool hasClickyKeys = false);
    ~Keyboard();

    bool GetHasClickyKeys();
    void SetHasClickyKeys(bool HasClickyKeys);

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:   
    bool hasClickyKeys;
};

class Monitor : public Part
{
public:
    Monitor(double length = 0.0, double width = 0.0);
    ~Monitor();

    int GetLength();
    void SetLength(int length);

    int GetWidth();
    void SetWidth(int width);

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:   
    double length;
    double width;
};

class Speakers : public Part
{
public:
    Speakers(bool isPowered = false, int volume = 0.0);
    ~Speakers(); 

    bool GetIsPowered();
    void SetIsPowered(bool isPowered);

    int GetVolume();
    void SetVolume(int volume);

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:
    bool isPowered;
    int volume;
};

class SSD : public Part
{
public:
    SSD(double currentStorage = 0, double totalStorage = 0);
    ~SSD(); 

    double GetCurrentStorage();
    void SetCurrentStorage(double currentStorage);

    double GetTotalStorage();
    void SetTotalStorage(double totalStorage);

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:
    double currentStorage;
    double totalStorage;
};

class RAM : public Part
{
public:
    RAM(double capacity = 0);   // in GB
    ~RAM(); 

    int GetCapacity();
    void SetCapacity(int capacity);

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:
    double capacity;
};

class CPU : public Part
{
public:
    CPU(int cores = 0);
    ~CPU(); 

    int GetCores();
    void SetCores(int cores);

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:
    int cores;
};

class GPU : public Part
{
public:
    GPU(double memory = 0);
    ~GPU();

    double GetMemory();
    void SetMemory(double memory);

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:
    double memory;
};

// ============= Composite =============
// The Composite class represents the complex components that may have children.
class Computer : public ComputerComponent
{
protected: 
    std::list<ComputerComponent *> children;

public: 
    Computer();
    ~Computer();

    // ------ virtuals ------
    void Add(ComputerComponent * computerComponent) override;
    void Remove(ComputerComponent * computerComponent) override;
    bool IsComposite() override;
    void Print() override;
};

class Peripherals : public ComputerComponent
{
protected: 
    std::list<ComputerComponent *> children;

public: 
    Peripherals();
    ~Peripherals();

    // ------ virtuals ------
    void Add(ComputerComponent * computerComponent) override;
    void Remove(ComputerComponent * computerComponent) override;
    bool IsComposite() override;
    void Print() override;
};

class Tower : public ComputerComponent
{
protected: 
    std::list<ComputerComponent *> children;

public: 
    Tower();
    ~Tower();

    // ------ virtuals ------
    void Add(ComputerComponent * computerComponent) override;
    void Remove(ComputerComponent * computerComponent) override;
    bool IsComposite() override;
    void Print() override;
};

class Motherboard : public ComputerComponent
{
protected: 
    std::list<ComputerComponent *> children;

public: 
    Motherboard();
    ~Motherboard();

    // ------ virtuals ------
    void Add(ComputerComponent * computerComponent) override;
    void Remove(ComputerComponent * computerComponent) override;
    bool IsComposite() override;
    void Print() override;
};