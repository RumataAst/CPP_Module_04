#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain was created" << std::endl;
}

Brain::Brain(const Brain &copy) {
    *this = copy;
}

Brain &Brain::operator=(const Brain &source) {
    if (this != &source) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = source.ideas[i];
    }
    return *this;
}

Brain::~Brain () {
    std::cout <<  "Returning to Andrei's usual state" << std::endl;
}