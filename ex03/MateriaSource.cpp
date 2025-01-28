#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        _learned[i] = NULL;  // Ensure no uninitialized memory
    }
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
    *this = copy;  // Delegate to assignment operator
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source) {
    if (this != &source) {
        // Properly clean up any previously allocated resources in the destination
        for (int i = 0; i < 4; ++i) {
            delete _learned[i];  // Clean up existing Materia objects
            _learned[i] = NULL;  // Reset to NULL before copying new ones
        }

        // Clone Materia objects from the source
        for (int i = 0; i < 4; ++i) {
            if (source._learned[i]) {
                _learned[i] = source._learned[i]->clone();
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    // Cleanup: Make sure to delete any cloned AMateria objects
    for (int i = 0; i < 4; ++i) {
        delete _learned[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    if (!m) return; // Check for invalid input

    for (int i = 0; i < 4; ++i) {
        if (_learned[i] == NULL) {
            _learned[i] = m->clone();  // Clone the AMateria to avoid ownership transfer
            return;
        }
    }

    std::cout << "MateriaSource is full, can't learn more Materia!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; ++i) {
        if (_learned[i] && _learned[i]->getType() == type) {
            return _learned[i]->clone();  // Clone the AMateria to return a new object
        }
    }
    return NULL;  // Return NULL if no matching Materia is found
}