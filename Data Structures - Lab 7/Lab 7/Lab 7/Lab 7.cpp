#include <iostream>
#include "List.h"
#include <cstdlib>
#include <time.h>

int main()
{
	

	srand(time(0));

	int array[100] = {};

	for (int n = 0; n < 100; n++)
	{
		array[n] = n;
	}
	
	int size; 
	int c;
	std::cout << "Size of Array: ";
	std::cin >> size;
	std::cout << std::endl;
	std::cout << "Test Class 1, 2, or 3 (Please Enter 1, 2, or 3):";
	std::cin >> c;
	std::cout << std::endl;

	List<int> list1(size);
	Derived<int> list2(size);
	Derived2<int> list3(size);
	if (c == 1)
	{
		for (int i = 0; i < 100; i++)
		{
			int add = 0;
			for (int j = 0; j < 55; j++)
			{
				int random = (rand() % (2 + 1));
				if (add < 30 && random == 1)
				{
					int a = (rand() % (100 + 1));
					list1.addItem(&(array[a]));
					add += 1;
				}
				else
				{
					int a = (rand() % (100 + 1));
					list1.removeItem(&(array[a]));
				}
			}
		};
		list1.printResults();
	}
	else if (c == 2)
	{
		for (int i = 0; i < 100; i++)
		{
			int add = 0;
			for (int j = 0; j < 55; j++)
			{
				int random = (rand() % (2 + 1));
				if (add < 30 && random == 1)
				{
					int a = (rand() % (100 + 1));
					list2.addItem(&(array[a]));
					add += 1;
				}
				else
				{
					int a = (rand() % (100 + 1));
					list2.removeItem(&(array[a]));
				}
			}
		};
		list2.printResults();
	}
	else if (c == 3)
	{
		for (int i = 0; i < 100; i++)
		{
			int add = 0;
			for (int j = 0; j < 55; j++)
			{
				int random = (rand() % (2 + 1));
				if (add < 30 && random == 1)
				{
					int a = (rand() % (100 + 1));
					list3.addItem(&(array[a]));
					add += 1;
				}
				else
				{
					int a = (rand() % (100 + 1));
					list3.removeItem(&(array[a]));
				}
			}
		};
		list3.printResults();
	}
}
