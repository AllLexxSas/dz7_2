#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>



/*
* �������� ��������� ��������� � ���������� ������. �������� ��� ��� ���������� ������������ � ������� ��������� 
* pragma pack. �������� ����������� ���������� ����� ����. ��������������� ��. �������� �� �� ����� � �� ������
* � ������� sizeof. ��������� ��� ��������� � ��������� ����.
*/
#pragma pack(push,1)
struct Employees
{

	std::string firstName;
	std::string lastName;
	uint8_t age;
	std::string position;
	std::string path;//���� ��� ����� �����

	//���������� ��������� � ��������� ����
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
		std::cout << "\n��������� �����:\n";
		std::cout << "���: "<<this->firstName<<std::endl;
		std::cout << "�������: " << this->lastName << std::endl;
		std::cout << "������ ���: " << std::to_string(this->age) << std::endl;
		std::cout << "���������: " << this->position << std::endl;
	}

};
#pragma pack(pop)


//���������� ������� ��� ������� 1 � 5
namespace task1
{
	void ArrayInitialization(float*, const size_t);
	void PrintArray(float*, size_t);
	void CountingValues(float*, size_t);

}

//���������� ������� ��� ������� 3
namespace task3
{
	void InputDataInArray();
	void PrintArray(int*);
	void SortArray(int*);
}