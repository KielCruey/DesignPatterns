#include <list>
#include <string>

// ============= Component =============
// The base Component class declares common operations for both simple and complex objects of a composition.
class ComputerPart
{
public:
    ComputerPart(ComputerPart * parent = nullptr);
    ~ComputerPart();
    
    ComputerPart * GetParent();
    void SetParent(ComputerPart * parent);

    // ------ virtuals ------
    virtual void Add(ComputerPart * computerPart) {};
    virtual void Remove(ComputerPart * computerPart) {};
    virtual bool IsComposite();
    virtual void Print();

protected:
    ComputerPart * parent;
};

// ============= "Abstract" Leaf =============
class Part : public ComputerPart
{
public:
    Part(std::string brandName = "N/A", std::string modelName = "N/A");
    ~Part();

    std::string GetBrandName();
    std::string GetModelName();
    void SetBrandName(std::string brandName);
    void SetModelName(std::string modelName);

    // ------ virtuals ------
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

    // ------ virtuals from ComputerPart ------
    bool IsComposite() override;
    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override;

protected:
    virtual void Print() override;   

private:   
    int dpi;
};

class Keyboard : public Part
{
public:
    Keyboard();
    ~Keyboard();

    bool GetHasClickyKeys();
    void SetHasClickyKeys(bool HasClickyKeys);

    // ------ virtuals from ComputerPart ------
    bool IsComposite() override;
    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override;

private:   
    bool hasClickyKeys;
};

class Monitor : public Part
{
public:
    Monitor();
    ~Monitor();

    int GetLength();
    void SetLength(int length);

    int GetWidth();
    void SetWidth(int width);

    // ------ virtuals from ComputerPart ------
    bool IsComposite() override;
    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override;

private:   
    int length;
    int width;
};

class Speakers : public Part
{
public:
    Speakers();
    ~Speakers(); 

    bool GetIsPowered();
    void SetIsPowered(bool isPowered);

    int GetVolume();
    void SetVolume(int volume);

    // ------ virtuals from ComputerPart ------
    bool IsComposite() override;
    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override;

private:
    bool isPowered;
    int volume;
};

class SSD : public Part
{
public:
    SSD();
    ~SSD(); 

    double GetCurrentStorage();
    void SetCurrentStorage(double currentStorage);

    double GetTotalStorage();
    void SetTotalStorage(double currentStorage);

    // ------ virtuals from ComputerPart ------
    bool IsComposite() override;
    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override;

private:
    double currentStorage;
    double totalStorage;
};

class RAM : public Part
{
public:
    RAM();
    ~RAM(); 

    int GetCapacity();
    void SetCapacity(int capacity);

    // ------ virtuals from ComputerPart ------
    bool IsComposite() override;
    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override; 

private:
    int capacity;
};

class CPU : public Part
{
public:
    CPU();
    ~CPU(); 

    int GetCores();
    void SetCores(int cores);

    // ------ virtuals from ComputerPart ------
    bool IsComposite() override;
    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override;

private:
    int cores;
};

class GPU : public Part
{
public:
    GPU();
    ~GPU();

    double GetMemory();
    void SetMemory(double memory);

    // ------ virtuals from ComputerPart ------
    bool IsComposite() override;
    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override;

private:
    double memory;
};

// ============= Composite =============
// The Composite class represents the complex components that may have children.
class Peripherals : public ComputerPart
{
protected: 
    std::list<ComputerPart *> children;

public: 
    Peripherals();
    ~Peripherals();

    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override;
    bool IsComposite() override;
};

class Tower : public ComputerPart
{
protected: 
    std::list<ComputerPart *> children;

public: 
    Tower();
    ~Tower();

    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override;
    bool IsComposite() override;
};

class Motherboard : public ComputerPart
{
protected: 
    std::list<ComputerPart *> children;

public: 
    Motherboard();
    ~Motherboard();

    void Add(ComputerPart * computerPart) override;
    void Remove(ComputerPart * computerPart) override;
    bool IsComposite() override;
};