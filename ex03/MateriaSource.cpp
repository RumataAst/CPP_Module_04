#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        _learned[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source) {
    if (this != &source) {
        for (int i = 0; i < 4; ++i) {
            delete _learned[i];  // Clean up current memory
            if (source._learned[i]) {
                _learned[i] = source._learned[i]->clone();  // Clone the Materia
            } else {
                _learned[i] = NULL;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete _learned[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    if (!m) return;

    for (int i = 0; i < 4; ++i) {
        if (_learned[i] == NULL) {
            _learned[i] = m->clone();
            return;
        }
    }
    std::cout << "MateriaSource is full, can't learn more Materia!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; ++i) {
        if (_learned[i] && _learned[i]->getType() == type) {
            return _learned[i]->clone(); 
        }
    }
    return NULL;
}
