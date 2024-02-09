
// =========== Abstract Component ===========
class Entity
{
public:
    Entity(int health = 100, int mana = 100, int fatigue = 100);
    virtual ~Entity();

    // concrete decorator's virtual responsibilities
    virtual void EquipArmor() = 0;
    virtual void EquipGreaves() = 0;
    virtual void EquipHelmet() = 0;
    virtual void EquipMainHand() = 0;
    virtual void EquipSecondaryHand() = 0;
    virtual void EquipSabaton() = 0; // feet

    // concrete component's virtual responsibilities
    virtual void Attack() = 0;
    virtual void Block() = 0;
    virtual void Reload() = 0;


    int GetHealth();
    void SetHealth(int health);

    int GetMana();
    void SetMana(int mana);

    int GetFatigue();
    void SetFatigue(int fatigue);

private:
    int health;
    int mana;
    int fatigue;
};

// =========== Concrete Component ===========
class Knight : public Entity
{
public:
    Knight();
    ~Knight();

    void Attack() override;
    void Block() override;
    void Reload() override;
};

class Archer : public Entity
{
public:
    Archer();
    ~Archer();

    void Attack() override;
    void Block() override;
    void Reload() override;
};

// =========== Abstract Decorator ===========
class EntitySpecialization
{
public:
    EntitySpecialization(Entity * entity);
    ~EntitySpecialization();

    Entity * GetEntity();
    void SetEntity(Entity * entity);

protected:
    Entity * entity;
};

// =========== Concrete Decorator ===========
class HolyKnight : public EntitySpecialization
{
public:
    HolyKnight(Entity * entity);
    ~HolyKnight();
};

class DarkKnight : public EntitySpecialization
{
public:
    DarkKnight(Entity * entity);
    ~DarkKnight();
};

class LongBowArcher : public Archer
{
    LongBowArcher(Entity * entity);
    ~LongBowArcher();
};

class CrossBowArcher : public Archer
{
    CrossBowArcher(Entity * entity);
    ~CrossBowArcher();
};