#pragma once

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
private:

public:
    WrongCat();
    WrongCat(const WrongCat &copy);
    WrongCat &operator = (const WrongCat &source);
    ~WrongCat();

    void makeSound() const;
};