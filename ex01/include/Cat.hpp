#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
private:

public:
    Cat();
    Cat(const Cat &copy);
    Cat &operator = (const Cat &source);
    ~Cat();

    void makeSound() const;
};