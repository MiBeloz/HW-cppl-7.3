#include <iostream>

#include "Vector.h"


int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tАналог std::vector\n" << std::endl;

	MB::Vector<int> my_vector;

	try {
		std::cout << "Проверка метода 'at()' на пустом векторе:" << std::endl;
		std::cout << "at(0): ";
		std::cout << my_vector.at(0) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << "size(): " << my_vector.size() << std::endl;
	std::cout << "capacity(): " << my_vector.capacity() << std::endl << std::endl;

	std::cout << "Проверка методов 'push_back()', 'size()', 'capacity()':" << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << "Добавление элемента со значением '" << i << "':" << std::endl;
		my_vector.push_back(i);
		std::cout << "at(" << i << "): " << my_vector.at(i) << std::endl;
		std::cout << "size(): " << my_vector.size() << std::endl;
		std::cout << "capacity(): " << my_vector.capacity() << std::endl << std::endl;
	}

	system("pause > nul");
	return 0;
}