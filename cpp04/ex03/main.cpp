#include "AMateria.h"
#include "Ice.h"
#include "Cure.h"
#include "MateriaSource.h"
#include "Character.h"

int main() {
	// code from the excersize (a little bit modified)
	/*
	std::cout << "_____________" << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << "_____________" << std::endl;

	src->learnMateria(new Ice());
	std::cout << "_____________" << std::endl;
	src->learnMateria(new Cure());
	std::cout << "_____________" << std::endl;

	ICharacter* me = new Character("me");
	std::cout << "_____________" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << "_____________" << std::endl;
	me->equip(tmp);
	std::cout << "_____________" << std::endl;
	tmp = src->createMateria("cure");
	std::cout << "_____________" << std::endl;
	me->equip(tmp);
	std::cout << "_____________" << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << "_____________" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "_____________" << std::endl;
	delete bob;
	std::cout << "_____________" << std::endl;
	delete me;
	std::cout << "_____________" << std::endl;
	delete src;
	std::cout << "_____________" << std::endl;
*/
	std::cout << "		Create a materia source1:" << std::endl;
	IMateriaSource* src1 = new MateriaSource();

	std::cout << "		learn 3 materias, null(should print message), 1 materia" << std::endl;
	src1->learnMateria(new Ice());
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());
	src1->learnMateria(NULL);
	src1->learnMateria(new Cure());

	std::cout << "		has to fail learning next 2 materias:" << std::endl;
	src1->learnMateria(new Cure());
	src1->learnMateria(new Ice());

	std::cout << "		Create a materia source2:" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	std::cout << "*****************************" << std::endl;

	AMateria* tmp;
	std::cout << "		new character test1 & test2:" << std::endl;
	ICharacter* test1 = new Character("test1");
	ICharacter* test2 = new Character("test2");

	std::cout << "\n		create materia and equip test1:" << std::endl;
	tmp = src1->createMateria("cure");
	test1->equip(tmp);
	tmp = src1->createMateria("ice");
	test1->equip(tmp);
	tmp = src1->createMateria("ice");
	test1->equip(tmp); 
	std::cout << "\n		create materia from source2:" << std::endl;
	tmp = src2->createMateria("ice");
	test1->equip(tmp);
	std::cout << "		has to fail(print message) creating materia from source2:" << std::endl;
	tmp = src2->createMateria("cure");
	std::cout << "		has to fail equip materia:" << std::endl;
	test1->equip(tmp);
	std::cout << "*****************************" << std::endl;

	
	std::cout << "		create materia and equip test2:" << std::endl;
	tmp = src1->createMateria("cure");
	test2->equip(tmp);
	std::cout << "		has to fail creating materia from source2:" << std::endl;
	tmp = src2->createMateria("");
	std::cout << "		has to try to equip NULL materia:" << std::endl;
	test2->equip(tmp);
	std::cout << "		create materia from source2:" << std::endl;
	tmp = src2->createMateria("ice");
	test2->equip(tmp);


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
	std::cout << "		test1 & test2 try unequip materia:" << std::endl;
	test1->unequip(3);
	test1->unequip(2);
	test1->unequip(0);
	test2->unequip(1);
	std::cout << "		test1 uses materia on test2 after unequip:" << std::endl;
	test1->use(0, *test2);

	std::cout << "\n		deleting:" << std::endl;
	delete test1;
	delete test2;
	delete src1;
	delete src2;
	// delete tmp;
	return 0;
}