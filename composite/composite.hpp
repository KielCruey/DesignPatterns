#include <list>

// ============= Component =============
// The base Component class declares common operations for both simple and complex objects of a composition.
class Computer
{
private:
    Computer * parent;

public:
    Computer();
    ~Computer();

    void SetParent(Computer * computer);
    Computer * GetParent();

    virtual bool IsComposite();

    virtual void Add() = 0;
    virtual void Remove() = 0;
};

// ============= Leaf =============
class Mouse : public Computer
{
private:

public:
    Mouse(/* args */);
    ~Mouse();
};

class Keyboard : public Computer
{
private:

public:
    Keyboard();
    ~Keyboard();
};

class Monitor : public Computer
{
private:

public:
    Monitor();
    ~Monitor();
};

class Speakers : public Computer
{
private:
    
public:
    Speakers();
    ~Speakers();
};

class SSD : public Computer
{
private:
    
public:
    SSD();
    ~SSD();
};

class RAM : public Computer
{
private:

public:
    RAM();
    ~RAM();
};

class CPU : public Computer
{
private:

public:
    CPU();
    ~CPU();
};

class GPU : public Computer
{
private:

public:
    GPU();
    ~GPU();
};

// ============= Composite =============
class Peripherals : public Computer
{
protected: 
    std::list<Computer *> children;

public: 
    Peripherals();
    ~Peripherals();

    void Add() override;
    void Remove() override;
    bool IsComposite() override;
};

class Tower : public Computer
{
protected: 
    std::list<Computer *> children;

public: 
    Tower();
    ~Tower();

    void Add() override;
    void Remove() override;
    bool IsComposite() override;
};

class Motherboard : public Computer
{
protected: 
    std::list<Computer *> children;

public: 
    Motherboard();
    ~Motherboard();

    void Add() override;
    void Remove() override;
    bool IsComposite() override;
};