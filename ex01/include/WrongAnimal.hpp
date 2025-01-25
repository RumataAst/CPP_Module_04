#pragma once

#include <iostream>

class WrongAnimal {
protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal(const std::string &type);
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal &operator = (const WrongAnimal &source);

    std::string getType() const ;

    virtual ~WrongAnimal();
    void makeSound() const;
};
