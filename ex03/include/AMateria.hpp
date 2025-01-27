#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
protected:

public:
    AMateria(std::string const & type);
    AMateria(const AMateria &copy);
    AMateria &operator =(const AMateria &source);
    ~AMateria();
    std::string const & getType() const; 
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
