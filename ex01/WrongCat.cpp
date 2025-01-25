#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Experiment cat") {
    std::cout << "The attempt to create a perfect cat" << std::endl;
}

WrongCat:: WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
    std::cout << "Making a copy of experiment" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &source) {
    if (this != &source) {
        WrongAnimal::operator= (source);
        std::cout << "IT'S = " << std::endl;
    }
    return *this;
}

WrongCat::~WrongCat () {}

void WrongCat::makeSound() const {
    std::cout << "I AM PERFECT" << std::endl;
}