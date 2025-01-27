#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
private:
    Brain *_brain;
public:
    Cat();
    Cat(const Cat &copy);
    Cat &operator = (const Cat &source);
    ~Cat();

    void makeSound() const;
};