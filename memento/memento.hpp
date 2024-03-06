#include <string>
#include <vector>

// ========= Memento =========
/*
* The Memento object is responsible for storing the state of the Originator. 
* It doesn’t expose the state to other objects. 
* It typically has methods to get and set the state of the Originator.
*/
class AbstractMemento
{
public:
	virtual ~AbstractMemento() = default;

	// variables for memento
	virtual std::string getDate() = 0; // date of the memento save
	virtual std::string getTime() = 0; // time of the memento save

	// the originator's variables it's saving
	virtual std::string getName() = 0;
	virtual std::string getSpecialization() = 0;
	virtual std::string getState() = 0;
	virtual int getHealth() = 0;
	virtual int getMana() = 0;
	virtual int getLevel() = 0;
	virtual std::string getState() = 0; // like dazed, drunk, or fear
};

class Memento : public AbstractMemento
{
public:
	Memento();
	virtual ~Memento();

	virtual std::string getDate(); // date of the memento save
	virtual std::string getTime(); // time of the save

	virtual std::string getName() override;
	virtual std::string getSpecialization() override;
	virtual std::string getState() override;
	virtual int getHealth() override;
	virtual int getMana() override;
	virtual int getLevel() override;
	virtual std::string getState() override; // like dazed, drunk, or fear

private:
	std::string date;
	std::string time;
	
	std::string name;
	std::string specialization;
	std::string state;
	int level;
	int health;
	int mana;
};

/*
* The Originator si the object whose state you want to save. 
* The Originator creates a Memento object to store its state or can restore its state from a Memento object.
*/
class Originator
{
public:
	Originator();
	~Originator();

	// class actions
	void changeName();
	void changeSpecialization();
	void changeState();

	void levelUp();
	void levelDown();
	void healUp();
	void healDown();
	void manaUp();
	void manaDown();

	// saving actions
	Memento * save();
	void restore(Memento * memento);

private:
	std::string name;
	std::string specialization;
	std::string state;
	int level;
	int health;
	int mana;
};

/*
* The Caretaker is responsible for keeping track of the Memento objects and their history. It can save and retrieve Memento objects from a collection. 
* It doesn’t modify the Memento’s state but can request the Originator to save or restore its state using a Memento.
*/
class Caretaker 
{
public:
	Caretaker(Originator * originator);
	~Caretaker();

	void backup();
	void undo();
	void showHistory();

private:
	std::vector<Memento*> mementos;
};

#include "memento.inl"