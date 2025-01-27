#pragma once

#include <iostream>

class Animal {
protected:
    std::string _type;
public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &copy);
    Animal &operator = (const Animal &source);

    std::string getType() const ;

    virtual ~Animal();
    virtual void makeSound() const = 0;
};