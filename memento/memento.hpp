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
	inline virtual std::string getDate() = 0; // date of the memento save
	inline virtual std::string getTime() = 0; // time of the memento save

	// the originator's variables it's saving
	inline virtual std::string getName() = 0;
	inline virtual std::string getSpecialization() = 0;
	inline virtual std::string getState() = 0; // like dazed, drunk, or fear
	inline virtual int getHealth() = 0;
	inline virtual int getMana() = 0;
	inline virtual int getLevel() = 0; 
};

class Memento : public AbstractMemento
{
public:
	Memento(std::string date = nullptr,
			std::string time = nullptr,
			std::string name = nullptr,
			std::string specialization = nullptr,
			std::string state = nullptr,
			int level = NULL,
			int health = NULL,
			int mana = NULL);
	virtual ~Memento();

	inline virtual std::string getDate(); // date of the memento save
	inline virtual std::string getTime(); // time of the save

	// only need getters for saving
	inline virtual std::string getName() override;
	inline virtual std::string getSpecialization() override;
	inline virtual std::string getState() override;  // like dazed, drunk, or fear
	inline virtual int getHealth() override;
	inline virtual int getMana() override;
	inline virtual int getLevel() override;

private:
	// memento information being saved
	std::string date;
	std::string time;
	
	// originator information being saved 
	std::string name;
	std::string specialization;
	std::string state;
	int level;
	int health;
	int mana;
};

/*
* The Originator is the object whose state you want to save. 
* The Originator creates a Memento object to store its state or can restore its state from a Memento object.
*/
class Originator
{
public:
	Originator(std::string name = nullptr,
			   std::string specialization = nullptr,
			   std::string state = nullptr,
			   int level = NULL,
			   int health = NULL,
			   int mana = NULL);
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

	// getters/setters
	inline std::string getName();
	inline std::string getSpecialization();
	inline std::string getState();
	inline int getLevel();
	inline int getHealth();
	inline int getMana();

	inline std::string setName();
	inline std::string setSpecialization();
	inline std::string setState();
	inline int setLevel();
	inline int setHealth();
	inline int setMana();

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
	Caretaker(Originator * originator = nullptr);
	~Caretaker();

	void backup();
	void undo();
	void showHistory();

private:
	Originator * originator;

	// data structure to hold Originator's snapshots/saves
	std::vector<Memento*> mementos;
};

#include "memento.inl"