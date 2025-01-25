#include "Animal.hpp"

Animal::Animal () : _type("Animal") {
    std::cout << "Animal is created" << std::endl;
}

Animal::Animal (const std::string &type) : _type(type) {
    std::cout << "Animal is created" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal went for evolution route" << std::endl;
}

Animal::Animal (const Animal &copy) {
    *this = copy;
    std::cout << "Copy was called for Animal" << std::endl;
}

Animal &Animal::operator =(const Animal &source) {
    if (this != &source)
    {
        _type = source._type;
        std::cout << "Operator = was called for Animal" << std::endl;
    }
    return *this;
}

void Animal::makeSound() const{
    std::cout << "Generic animal sound" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}