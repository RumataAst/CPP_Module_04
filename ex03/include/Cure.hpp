#pragma once
#include "AMateria.hpp"

#include <iostream>

class Cure : public AMateria {
protected:

public:
    Cure();
    Cure(const Cure &copy);
    Cure &operator=(const Cure &source);
    ~Cure();

    Cure *clone() const;
    void use(ICharacter& target);
};