#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
private:

public:
    Dog();
    Dog(const Dog &copy);
    Dog &operator = (const Dog &source);
    ~Dog();

    void makeSound() const;
};