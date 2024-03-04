// the relationship between the Originator/Memento is a dependency relationship
class Memento
{

};

class ConcreteMemento : public Memento
{

};

class Originator
{

};

// the Memento has a Caretaker
class Caretaker 
{

};

#include "memento.inl"