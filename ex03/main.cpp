#include "ICharacter.hpp"    
#include "IMateriaSource.hpp"  
#include "AMateria.hpp"         
#include "Character.hpp"        
#include "MateriaSource.hpp"    
#include "Ice.hpp"              
#include "Cure.hpp"             


#include <iostream>
#include <string>

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    // Equip some materias
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Use the materias
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);  // Should output: "* shoots an ice bolt at bob *"
    me->use(1, *bob);  // Should output: "* heals bob's wounds *"

    // Test: Copying and Assigning Character
    std::cout << "Testing copying Character..." << std::endl;
    // Copy constructor: Create a copy of 'me'
    Character* me3 = new Character(*(Character*)me);  // Casting to Character for copying
    me3->use(1, *bob);  // Should output: "* heals bob's wounds *"
    
    // Test: Copying and Assigning MateriaSource
    std::cout << "Testing copying MateriaSource..." << std::endl;
    // Copy constructor: Create a copy of MateriaSource
    MateriaSource* src2 = new MateriaSource(*dynamic_cast<MateriaSource*>(src)); // Safe copy constructor
    ICharacter* me2 = new Character("me2");
    tmp = src2->createMateria("ice");
    me2->equip(tmp);
    me2->use(0, *bob);  // Should output: "* shoots an ice bolt at bob *"
    
    // Test: Full Inventory Behavior
    std::cout << "Testing full inventory behavior..." << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp); // Should fail as inventory is full, no allocation error

    tmp = src->createMateria("ice");
    me->equip(tmp); // Should fail as inventory is full, no allocation error

    // Test: Trying to use an unassigned slot in inventory
    std::cout << "Testing using an empty inventory slot..." << std::endl;
    // Try to use a non-existing materia slot (index 3, empty)
    me->use(3, *bob); // Should not output anything or should show error if there's a check in the use method


    // Test:: Unequip
    IMateriaSource* src_1 = new MateriaSource();
    src_1->learnMateria(new Ice());
    src_1->learnMateria(new Cure());
    
    ICharacter* me_1 = new Character("me_1");
    AMateria* tmp_1;

    // Equip two materias ("ice" and "cure")
    tmp_1 = src_1->createMateria("ice");
    me_1->equip(tmp_1);
    AMateria* unequippedMateria  = src_1->createMateria("cure");
    me_1->equip(unequippedMateria);

    // Use both materias
    ICharacter* Andrei = new Character("Andrei");
    std::cout << "Using first materia (Ice)..." << std::endl;
    me_1->use(0, *Andrei);  // Should output: "* shoots an ice bolt at Andrei *"
    
    std::cout << "Using second materia (Cure)..." << std::endl;
    me_1->use(1, *Andrei);  // Should output: "* heals Andrei's wounds *"

    std::cout << "Unequipping first materia (Cure)..." << std::endl;
    me_1->unequip(1);
    std::cout << "First materia (Cure) has been unequipped and will be deleted manually." << std::endl;

    // At this point, the inventory slot 0 should be empty (null).
    // The second materia (Cure) should still be in slot 1.

    // Now we manually delete the unequipped materia
    delete unequippedMateria;
    
    // Try to use the remaining materia in inventory (Cure)
    std::cout << "Using remaining materia (Cure is unequiped so no message) after unequip..." << std::endl;
    me_1->use(0, *Andrei);
    me_1->use(1, *Andrei);

    // Cleanup
    delete Andrei;
    delete me_1;
    delete src_1;

    // Cleanup
    delete me2;
    delete me3;
    delete bob;
    delete me;
    delete src;
    delete src2;
    
    return 0;
}
