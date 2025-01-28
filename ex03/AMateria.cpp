#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type){
    // std::cout << "Class AMateria construct" << std::endl;
}

AMateria::AMateria(const AMateria &copy) {
    *this = copy;
}

AMateria &AMateria::operator=(const AMateria &source) {
    if (this != &source) {
        _type = source._type;
        // std::cout << "Operator = called for AMateria class" << std::endl;
    }
    return *this;
}

AMateria::~AMateria() {
    // std::cout << "Destructor for AMateria is called" << std::endl;
}

std::string const &AMateria::getType () const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "Generic materia used" << target.getName() << std::endl; 
}