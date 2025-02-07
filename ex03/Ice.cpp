#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    // std::cout << "Constructor for Ice" << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy) {
    // std::cout << "Copy for Ice" << std::endl;
}

Ice &Ice::operator=(const Ice &source) {
    if (this != &source) {
        AMateria::operator=(source);
        // std::cout << "Operator = for Ice is called" << std::endl;
    }
    return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}