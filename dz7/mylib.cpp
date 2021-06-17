#include "mylib.h"

#define ARRAYSIZE 7


/* задание 1 и 5
* Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: для инициализации массива (типа float),
* печати его на экран и подсчета количества отрицательных и положительных элементов. Вызывайте эти 3-и функции из main для работы с массивом.
*/
namespace task1
{
	void ArrayInitialization(float* array, const size_t sizeArray)
	{
		srand(time(0));
		for (size_t i = 0; i < sizeArray; i++)
		{
			array[i] = (rand() % 1000 - 400) / 1.5f;
		}
	}

	void PrintArray(float* array, size_t arreySize)
	{
		for (size_t i = 0; i < arreySize; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << "\n";
	}

	void CountingValues(float* array, size_t arreySize)
	{
		int negative = 0;
		int positive = 0;
		for (size_t i = 0; i < arreySize; i++)
		{
			if (array[i] > 0)
				positive++;
			else
				negative++;
		}
		std::cout << "в массиве " << positive << " полжительных чисел" << std::endl;
		std::cout << "в массиве " << negative << " отрицательных чисел" << std::endl;
	}
}

/*
* Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию
* сортировки (например Пузырьком). Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
*/

namespace task3
{
	void InputDataInArray()
	{
		std::cout << "Введите " << ARRAYSIZE << " натуральных чисел: ";
		int* arrayNaturalNumbers = new int[ARRAYSIZE];
		int value;
		for (size_t i = 0; i < ARRAYSIZE; i++)
		{
			std::cin >> value;
			arrayNaturalNumbers[i] = value;
		}
		PrintArray(arrayNaturalNumbers);
		SortArray(arrayNaturalNumbers);
		PrintArray(arrayNaturalNumbers);
		delete[]arrayNaturalNumbers;
	}

	void SSSSS(int &a, int &b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
#define ssss(a,b)SSSSS(a,b)

	void SortArray(int* array)
	{

		for (size_t i = 0; i < ARRAYSIZE - 1; i++)
		{
			for (size_t i = 0; i < ARRAYSIZE - 1; i++)
			{
				if (array[i] > array[i + 1])
				{
					ssss(array[i], array[i + 1]);
				}
			}
		}
	}
#undef ssss

	void PrintArray(int* array)
	{
		for (size_t i = 0; i < ARRAYSIZE; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << "\n";
	}
}