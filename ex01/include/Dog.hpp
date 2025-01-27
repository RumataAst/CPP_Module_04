#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain *_brain;
public:
    Dog();
    Dog(const Dog &copy);
    Dog &operator = (const Dog &source);
    ~Dog();

    void makeSound() const;
};