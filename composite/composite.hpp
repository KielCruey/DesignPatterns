#include <list>
#include <string>

// ============= Component =============
// The base Component class declares common operations for both simple and complex objects of a composition.
class ComputerPart
{
protected:
    ComputerPart * parent;

public:
    ComputerPart(ComputerPart * parent = nullptr);
    ~ComputerPart();

    virtual bool IsComposite();

    void SetParent(ComputerPart * parent);
    ComputerPart * GetParent();

    virtual void Add(ComputerPart * computerPart) = 0;
    virtual void Remove(ComputerPart * computerPart) = 0;
};

// ============= Leaf =============
class Part
{
public:
    Part();
    ~Part();

    std::string SetBrandName();
    void GetBrandName();

    std::string SetModelName();
    void GetModelName();

private:
    std::string BrandName;
    std::string ModelName;
};

class Mouse : public ComputerPart, public Part
{
public:
    Mouse();
    ~Mouse();
};

class Keyboard : public ComputerPart, public Part
{
public:
    Keyboard();
    ~Keyboard();
};

class Monitor : public ComputerPart, public Part
{
public:
    Monitor();
    ~Monitor();
};

class Speakers : public ComputerPart, public Part
{
public:
    Speakers();
    ~Speakers(); 
};

class SSD : public ComputerPart, public Part
{
public:
    SSD();
    ~SSD(); 
};

class RAM : public ComputerPart, public Part
{
public:
    RAM();
    ~RAM();  
};

class CPU : public ComputerPart, public Part
{
public:
    CPU();
    ~CPU(); 
};

class GPU : public ComputerPart, public Part
{
public:
    GPU();
    ~GPU();
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