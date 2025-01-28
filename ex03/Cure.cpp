#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &copy) : AMateria(copy) {}

Cure &Cure::operator=(const Cure &source) {
    if (this != &source) {
        AMateria::operator=(source);
    }
    return *this;
}

Cure::~Cure() {}

Cure *Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}