// ======== Memento ========
inline std::string Memento::getDate() {
	return this->date;
}

inline std::string Memento::getTime() {
	return this->time;
}

inline std::string Memento::getName() {
	return this->name;
}

inline std::string Memento::getSpecialization() {
	return this->specialization;
}

inline std::string Memento::getState() {
	return this->state;
}

inline int Memento::getHealth() {
	return this->health;
}

inline int Memento::getMana() {
	return this->mana;
}

inline int Memento::getLevel() {
	return this->level;
}

// ======== Originator ========
inline std::string Originator::getName() {
	return this->name;
}

inline std::string Originator::getSpecialization() {
	return this->specialization;
}

inline std::string Originator::getState() {
	return this->state;
}

inline int Originator::getLevel() {
	return this->level;
}

inline int Originator::getHealth() {
	return this->health;
}

inline int Originator::getMana() {
	return this->mana;
}

inline std::string Originator::setName() {
	this->name = name;
}

inline std::string Originator::setSpecialization() {
	this->specialization = specialization;
}

inline std::string Originator::setState() {
	this->state = state;
}

inline int Originator::setLevel() {
	this->level = level;
}

inline int Originator::setHealth() {
	this->health = health;
}

inline int Originator::setMana() {
	this->mana = mana;
}