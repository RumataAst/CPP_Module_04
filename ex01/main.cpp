#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define SEPARATOR std::cout << "------------------------" << std::endl

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    SEPARATOR;
    const int arraySize = 4;
    Animal *animals[arraySize]; 
    
    for (int i = 0; i < arraySize; i++) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < arraySize; i++) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    
    return 0;
}