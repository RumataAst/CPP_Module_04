#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define SEPARATOR std::cout << "------------------------" << std::endl

int main() {
    Dog myDog;
    const Animal* i = new Cat();
    
    std::cout << "The " << i->getType() << " says: ";
    i->makeSound();
    std::cout << "The " << myDog.getType() << " says: ";
    myDog.makeSound();

    delete i;
    // Animal myAnimal;
    // myAnimal.makeSound();
    //  WrongAnimal myAnimal;
    // myAnimal.makeSound();

    return 0;
}