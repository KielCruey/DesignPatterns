#include <string>

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
	virtual std::string getTime() = 0; // time of the save

	// the originator's variables it's saving
	virtual int getHealth() = 0;
	virtual int getMana() = 0;
	virtual int getState() = 0; // like dazed, drunk, or fear

};

class Memento : public AbstractMemento
{
public:
	Memento();
	virtual ~Memento();

	virtual std::string getDate(); // date of the memento save
	virtual std::string getTime(); // time of the save

	virtual int getHealth() override;
	virtual int getMana() override;
	virtual int getState() override; // like dazed, drunk, or fear

private:
	std::string date;
	std::string time;

	int health;
	int mana;
	int state;
};

/*
* The Originator si the object whose state you want to save. 
* The Originator creates a Memento object to store its state or can restore its state from a Memento object.
*/
class Originator
{

};

/*
* The Caretaker is responsible for keeping track of the Memento objects and their history. It can save and retrieve Memento objects from a collection. 
* It doesn’t modify the Memento’s state but can request the Originator to save or restore its state using a Memento.
*/
class Caretaker 
{

};

#include "memento.inl"