#include <iostream>

#include "Vector.h"

template<typename T>
void print_Vector(const my_class::Vector<T>& vector);

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tАналог std::vector\n" << std::endl;

	my_class::Vector<int> my_vector;

	std::cout << "my_vector:" << std::endl;
	try {
		std::cout << "\tПроверка метода 'at()' на пустом векторе:" << std::endl;
		std::cout << "\tat(0): ";
		std::cout << "\t" << my_vector.at(0) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << "\tsize(): " << my_vector.size() << std::endl;
	std::cout << "\tcapacity(): " << my_vector.capacity() << std::endl << std::endl;

	std::cout << "\tПроверка методов 'push_back()', 'size()', 'capacity()':" << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << "\tДобавление элемента со значением '" << i << "':" << std::endl;
		my_vector.push_back(i);
		std::cout << "\tat(" << i << "): " << my_vector.at(i) << std::endl;
		std::cout << "\tsize(): " << my_vector.size() << std::endl;
		std::cout << "\tcapacity(): " << my_vector.capacity() << std::endl << std::endl;
	}

	std::cout << "\tmy_vector: ";
	print_Vector(my_vector);
	std::cout << std::endl;


	my_class::Vector<int> my_vector_2(10, 5);

	std::cout << "my_vector_2:" << std::endl;
	std::cout << "\tcapacity() при создании вектора на 10 элементов со значением '5': " << my_vector_2.capacity() << std::endl;
	my_vector_2.resize(100);
	std::cout << "\tcapacity() после увеличения вектора до 100 елементов(resize(100)): " << my_vector_2.capacity() << std::endl;
	my_vector_2.clear();
	std::cout << "\tcapacity() после метода clear(): " << my_vector_2.capacity() << std::endl;
	my_vector_2.push_back(7);
	std::cout << "\tcapacity() после добавления элемента '7'(push_back(7)): " << my_vector_2.capacity() << std::endl;
	my_vector_2.shrink_to_fit();
	std::cout << "\tcapacity() после метода уменьшения вектора до размера количества элементов(shrink_to_fit()): " << my_vector_2.capacity() << std::endl << std::endl;

	std::cout << "\tmy_vector_2: ";
	print_Vector(my_vector_2);
	std::cout << std::endl;


	my_class::Vector<int> my_vector_3{ 5,7,13,57,99 };

	std::cout << "my_vector_3:" << std::endl;
	std::cout << "\tПроверка конструктора 'initializer_list' - { 5,7,13,57,99 }." << std::endl << std::endl;
	std::cout << "\tsize(): " << my_vector_3.size() << std::endl;
	std::cout << "\tcapacity(): " << my_vector_3.capacity() << std::endl << std::endl;
	std::cout << "\tmy_vector_3: ";
	print_Vector(my_vector_3);
	std::cout << std::endl;

	system("pause > nul");
	return 0;
}

template<typename T>
void print_Vector(const my_class::Vector<T>& vector) {
	for (size_t i = 0; i < vector.size(); ++i) {
		std::cout << vector.at(i) << " ";
	}
	std::cout << std::endl;
}
