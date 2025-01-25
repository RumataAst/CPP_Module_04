#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Frankenstein") {
    std::cout << "Frankenstein was created" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
    std::cout << type << " was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    *this = copy;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal & source) {
    if (this != &source) {
        this->_type = source._type;
        std::cout << "Operator = was called for Frankenstein" << std::endl;
    }
    return *this;
}

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout << "Generic monster noise" << std::endl;
}

WrongAnimal::~WrongAnimal () {
    std::cout << "Monster was slayed" << std::endl;
}