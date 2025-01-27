#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    _brain = new Brain();
    std::cout << "Dog is created" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
     _brain = new Brain(*copy._brain);
    std::cout << "Copy of a Dog is created" << std::endl;
}

Dog &Dog::operator=(const Dog &source) {
    if (this != &source) {
        Animal::operator = (source);
        delete _brain;
        _brain = new Brain(*source._brain);
        std::cout << "Dog's operator = is called" << std::endl;
    }
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Heaven welcomes best animal" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Woof ?" << std::endl;
}