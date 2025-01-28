#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {
protected: 

public:
    Ice();
    Ice(const Ice &copy);
    Ice &operator = (const Ice &source);
    ~Ice();

    Ice *clone() const;
    void use(ICharacter& target);
};