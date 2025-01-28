#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
protected:
    std::string _name;
    AMateria* _inventory[4];
public:
    Character(const std::string &name);
    Character(const Character &copy);
    Character &operator= (const Character &source);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};
