#include <list>

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
class Mouse : public ComputerPart
{
private:

public:
    Mouse(/* args */);
    ~Mouse();
};

class Keyboard : public ComputerPart
{
private:

public:
    Keyboard();
    ~Keyboard();
};

class Monitor : public ComputerPart
{
private:

public:
    Monitor();
    ~Monitor();
};

class Speakers : public ComputerPart
{
private:
    
public:
    Speakers();
    ~Speakers();
};

class SSD : public ComputerPart
{
private:
    
public:
    SSD();
    ~SSD();
};

class RAM : public ComputerPart
{
private:

public:
    RAM();
    ~RAM();
};

class CPU : public ComputerPart
{
private:

public:
    CPU();
    ~CPU();
};

class GPU : public ComputerPart
{
private:

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

    void Add() override;
    void Remove() override;
    bool IsComposite() override;
};

class Motherboard : public ComputerPart
{
protected: 
    std::list<ComputerPart *> children;

public: 
    Motherboard();
    ~Motherboard();

    void Add() override;
    void Remove() override;
    bool IsComposite() override;
};