#include "ICharacter.hpp"    
#include "IMateriaSource.hpp"  
#include "AMateria.hpp"         
#include "Character.hpp"        
#include "MateriaSource.hpp"    
#include "Ice.hpp"              
#include "Cure.hpp"             

int main()
{
    // Test 1: Create MateriaSource and learn some Materia
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());  // Learn "Ice" Materia
    src->learnMateria(new Cure()); // Learn "Cure" Materia

    // Test 2: Create Character "me"
    ICharacter* me = new Character("me");

    // Equip "Ice" Materia to "me"
    AMateria* tmp = src->createMateria("ice");
    me->equip(tmp);

    // Equip "Cure" Materia to "me"
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Test 3: Trying to equip more than 4 Materia
    // Equipping more Materia should not work as there are only 4 slots
    std::cout << "Trying to equip more Materia after 4 slots..." << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp); // This should fail as inventory is full

    tmp = src->createMateria("cure");
    me->equip(tmp); // This should fail as inventory is full

    // Test 4: Create another Character "bob" and use Materia
    ICharacter* bob = new Character("bob");

    // Use "Ice" Materia on "bob"
    me->use(0, *bob);  // Should output: "* shoots an ice bolt at bob *"

    // Use "Cure" Materia on "bob"
    me->use(1, *bob);  // Should output: "* heals bob's wounds *"

    // Test 5: Unequip Materia and try using it again
    std::cout << "Unequipping Materia at index 0..." << std::endl;
    me->unequip(0);

    // Try to use the unequipped Materia
    me->use(0, *bob);  // Should not do anything as slot 0 is empty now

    // Test 6: Using an invalid index (out of bounds)
    std::cout << "Trying to use an invalid index (out of bounds)..." << std::endl;
    me->use(5, *bob);  // Should not do anything as index 5 is out of bounds

    // Test 7: Copying and assigning MateriaSource
    std::cout << "Testing copying MateriaSource..." << std::endl;
    // Cast to MateriaSource for copying
    MateriaSource* src2 = new MateriaSource(*dynamic_cast<MateriaSource*>(src)); // Safe copy constructor
    ICharacter* me2 = new Character("me2");
    tmp = src2->createMateria("ice");
    me2->equip(tmp);
    me2->use(0, *bob);  // Should output: "* shoots an ice bolt at bob *"
    
    // Test 8: Copying and assigning Character
    std::cout << "Testing copying Character..." << std::endl;
    // Cast to Character for copying
    Character* me3 = new Character(*(Character*)me);  // Copy constructor
    me3->use(1, *bob);  // Should output: "* heals bob's wounds *"

    // Test 9: Cleanup
    delete bob;
    delete me;
    delete me2;
    delete me3;
    delete src;
    delete src2;

    return 0;
}