#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>



/*
* Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы 
* pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер
* с помощью sizeof. Сохраните эту структуру в текстовый файл.
*/
#pragma pack(push,1)
struct Employees
{

	std::string firstName;
	std::string lastName;
	uint8_t age;
	std::string position;
	std::string path;//поле для имени файла

	//сохранение структуры в текстовый файл
	static bool SaveEmployees(Employees *employees)
	{
		employees->path = employees->lastName + '_' + employees->firstName + ".txt";
		std::stringstream temp;
		temp << employees->lastName<<" " << employees->firstName<<" "
			<< std::to_string(employees->age)<<" " << employees->position;

		std::ofstream inFile(employees->path, std::ofstream::out);

		if (inFile.is_open())
		{
		inFile << temp.rdbuf();
		inFile.close();
			return 1;
		}
		return 0;
	}

	static int GetSize(Employees *e)
	{
		return sizeof(e->firstName) + sizeof(e->firstName) + sizeof(e->age)+ sizeof(e->position)+ sizeof(e->path);
	}

	void Print()
	{
		std::cout << "\nСотрудник фирмы:\n";
		std::cout << "Имя: "<<this->firstName<<std::endl;
		std::cout << "Фамилия: " << this->lastName << std::endl;
		std::cout << "Полных лет: " << std::to_string(this->age) << std::endl;
		std::cout << "Должность: " << this->position << std::endl;
	}

};
#pragma pack(pop)


//объявления функций для задания 1 и 5
namespace task1
{
	void ArrayInitialization(float*, const size_t);
	void PrintArray(float*, size_t);
	void CountingValues(float*, size_t);

}

//объявления функций для задания 3
namespace task3
{
	void InputDataInArray();
	void PrintArray(int*);
	void SortArray(int*);
}
