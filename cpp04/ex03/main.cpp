#include "AMateria.h"
#include "Ice.h"
#include "Cure.h"
#include "MateriaSource.h"
#include "Character.h"

int main() {
	// code from the excersize (a little bit modified)
	
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	

	/*  std::cout << "		Create a materia source1." << std::endl;
	IMateriaSource* src1 = new MateriaSource();

	std::cout << "		learn 3 materias (ICE, ICE, CURE)" << std::endl;
	src1->learnMateria(new Ice());
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());
	std::cout << "		learn null(should print message)" << std::endl;
	src1->learnMateria(NULL);
	std::cout << "		learn 1 materia" << std::endl;
	src1->learnMateria(new Cure());

	std::cout << "		has to fail learning next 2 materias:" << std::endl;
	src1->learnMateria(new Cure());
	src1->learnMateria(new Ice());

	std::cout << "		Create a materia source2:" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	std::cout << "		learn 4 (4xICE) materias" << std::endl;
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	std::cout << "*****************************" << std::endl;

	// AMateria* tmp;
	AMateria* storageToDelete[8];
	for (int i = 0; i < 8; i++) {storageToDelete[i] = NULL;}

	std::cout << "		new character test1 & test2:" << std::endl;
	ICharacter* test1 = new Character("test1");
	ICharacter* test2 = new Character("test2");

	std::cout << "\n		create materia and equip test1:" << std::endl;
	storageToDelete[0] = src1->createMateria("cure");
	test1->equip(storageToDelete[0]);
	storageToDelete[1] = src1->createMateria("ice");
	test1->equip(storageToDelete[1]);
	storageToDelete[2] = src1->createMateria("ice");
	test1->equip(storageToDelete[2]); 
	std::cout << "\n		create materia from source2:" << std::endl;
	storageToDelete[3] = src2->createMateria("ice");
	test1->equip(storageToDelete[3]);

	std::cout << "		has to fail(print message) creating materia from source2:" << std::endl;
	storageToDelete[4] = src2->createMateria("cure");

	std::cout << "		has to fail equip null materia:" << std::endl;
	test1->equip(storageToDelete[4]);
	std::cout << "*****************************" << std::endl;

	std::cout << "		create materia and equip test2:" << std::endl;
	storageToDelete[5] = src1->createMateria("cure");
	test2->equip(storageToDelete[5]);
	std::cout << "		has to fail creating materia from source2:" << std::endl;
	storageToDelete[6] = src2->createMateria("");
	std::cout << "		has to try to equip NULL materia:" << std::endl;
	test2->equip(storageToDelete[6]);
	std::cout << "		create materia from source2:" << std::endl;
	storageToDelete[7] = src2->createMateria("ice");
	test2->equip(storageToDelete[7]);

	// test1->printInv();
	// test2->printInv();
	std::cout << "\n		test1 uses materia on test2:" << std::endl;
	test1->use(0, *test2); //cure src1
	test1->use(1, *test2); //ice src1
	test1->use(2, *test2); //ice src1
	test1->use(3, *test2); //ice src2
	std::cout << "		test1 uses materia on test2 in invalid index:" << std::endl;
	test1->use(5, *test2);
	std::cout << "		test2 uses materia on test1 in invalid index:" << std::endl;
	test2->use(2, *test1);
	std::cout << "		test2 tries unequip materia in invalid index:" << std::endl;
	test2->unequip(2);
	

	std::cout << "		test1 try unequip materia:" << std::endl;
	test1->unequip(3);
	test1->unequip(2);
	test1->unequip(1);
	test1->unequip(0);
	test1->unequip(0);
	test1->unequip(-1);
	std::cout << "		test2 try unequip materia:" << std::endl;
	test2->unequip(0);
	test2->unequip(1);
	test2->unequip(2);
	std::cout << "		test1 uses materia on test2 after unequip:" << std::endl;
	test1->use(0, *test2);

	// std::cout << "\n		deleting:" << std::endl;
	delete test1;
	delete test2; 
	delete src1;
	delete src2;
	for (int i = 0; i < 8; i++) {
		if (storageToDelete[i] != NULL) {
			delete storageToDelete[i];
			storageToDelete[i] = NULL;
		}
	} 
 */
	return 0;
}