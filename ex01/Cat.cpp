#include "Cat.hpp"

Cat::Cat () : Animal ("Cat") {
    std::cout << "Cat is created" << std::endl;
}

Cat::Cat (const Cat &copy) : Animal(copy ){
    std::cout << "Copy of Cat is created" << std::endl;
}

Cat &Cat::operator=(const Cat &source) {
    if (this != &source) {
        Animal::operator=(source);
        std::cout << "Cat's operator = is called" << std::endl;
    }
    return *this;
}

Cat::~Cat () {
    std::cout << "So now it's 8 out of 9" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}