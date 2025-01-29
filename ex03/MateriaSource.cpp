#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        _learned[i] = NULL;  // Ensure no uninitialized memory
    }
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
       for (int i = 0; i < 4; ++i) {
        _learned[i] = NULL;
    }
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source) {
    if (this != &source) {
        AMateria* temp[4] = {NULL, NULL, NULL, NULL};

        try {
            for (int i = 0; i < 4; ++i) {
                if (source._learned[i]) {
                    temp[i] = source._learned[i]->clone();
                }
            }

            for (int i = 0; i < 4; ++i) {
                delete _learned[i];
                _learned[i] = temp[i];
            }
        } catch (...) {
            for (int i = 0; i < 4; ++i) {
                delete temp[i];
            }
            throw;
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
            delete m;
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