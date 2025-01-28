#pragma once

#include <iostream>
#include <IMateriaSource.hpp>

class MateriaSource : public IMateriaSource {
protected:
    AMateria* _learned[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource &copy);
    MateriaSource &operator=(const MateriaSource &source);
    ~MateriaSource();

    void learnMateria(AMateria *);
    AMateria* createMateria(std::string const &type);
};