#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog is created" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    std::cout << "Copy of a Dog is created" << std::endl;
}

Dog &Dog::operator=(const Dog &source) {
    if (this != &source) {
        Animal::operator = (source);
        std::cout << "Dog's operator = is called" << std::endl;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Heaven welcomes best animal" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Woof ?" << std::endl;
}