#include <iostream>

#include "UMLArrowsDependency.hpp"

static void printToConsole(std::string toConsole) {
    std::cout << toConsole << std::endl;
}

// ========== DependencyClass ==========
Bar::Bar() {
    printToConsole("DependencyClass created");
}

Bar::~Bar() {
    printToConsole("DependencyClass destroyed");
}

int Bar::addNumbers(int a, int b) {
    return a + b;
}

// ========== NonDependencyClass ==========
Foo::Foo() {
    printToConsole("NonDependencyClass created");
}

Foo::~Foo() {
    printToConsole("NonDependencyClass destroyed");
}

void Foo::DoWork(Bar * bar) {
    int a = 10;
    int b = 5;

    auto results = bar->addNumbers(a, b);

    std::cout << "Results: " << results << std::endl;
    
    delete bar;
}

// ========== Main ==========
int main() {
    Foo * foo = new Foo();
    Bar * bar = new Bar();

    foo->DoWork(bar);

    delete foo;

    return 0;
}