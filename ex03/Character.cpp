#include "Character.hpp"

Character::Character(const std::string &name) : _name(name) {
    for (int i = 0; i < 4; ++i) {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character &copy) : _name(copy._name) {
    for (int i = 0; i < 4; ++i) {
        if (copy._inventory[i]) {
            _inventory[i] = copy._inventory[i]->clone();
        } else {
            _inventory[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &source) {
    if (this != &source) {
        // Deallocate old Materia objects first
        for (int i = 0; i < 4; ++i) {
            delete _inventory[i];
        }

        // Copy new values
        _name = source._name;
        for (int i = 0; i < 4; ++i) {
            if (source._inventory[i]) {
                _inventory[i] = source._inventory[i]->clone();
            } else {
                _inventory[i] = NULL;
            }
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete _inventory[i];
    }
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) return;

    for (int i = 0; i < 4; ++i) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) 
        return;
    _inventory[idx] = NULL;
}

void Character::use (int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || _inventory[idx] == NULL) 
        return;
    _inventory[idx]->use(target);
}