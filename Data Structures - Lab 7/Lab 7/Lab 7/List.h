#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>

template <class T>
class List
{
	public:
		List()
		{
			array = new T* [25] {nullptr };
			elements = 0;
			compare = 0;
			move = 0;
		}
		List(int size)
		{
			array = new T* [size] {nullptr };
			elements = 0;
			compare = 0;
			move = 0;
		}

		void addItem(T* item)
		{
			class fullArray {};
			try
			{
				if (isEmpty())
				{
					array[0] = item;
					elements += 1;
				}
				else if (isFull())
				{
					throw fullArray{};
				}
				else
				{
					array[elements] = item;

					for (int i = 0; i < elements; i++)
					{
						compare += 1;
						if (*item < *array[i])
						{
							move += 1;
							T* temp = array[i];
							array[i] = array[elements];
							array[elements] = temp;
						}
					}

					elements += 1;

				}
			}

			catch (fullArray f)
			{
				std::cout << "Array is Full, Element Cannot be Added" << std::endl;
			}
		}
		void removeItem(T* item)
		{
			class emptyArray {};
			try
			{
				int removed;
				bool exist = false;
				if (isEmpty())
				{
					throw emptyArray();
				}
				else
				{
					for (int i = 0; i < elements; i++)
					{
						compare += 1;
						if (array[i] == item)
						{
							removed = i;
							exist = true;
							break;
						}
					}

					if (exist == true)
					{
						for (int i = removed; i < elements - removed; i++)
						{
							move += 1;
							array[i] = array[i + 1];
						}
						elements -= 1;
					}
					else
					{
						std::cout << "Element Does Not Exist In List" << std::endl;
					}
				}
			}
			catch (emptyArray e)
			{
				std::cout << "Array is Empty, Item Cannot be Removed" << std::endl;
			}
		}

		bool isEmpty()
		{
			if (elements == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool isFull()
		{
			if (elements == 25)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void makeEmpty()
		{
			for (int i = 0; i < 25; i++)
			{
				array[i] = nullptr;
			}
			elements = 0;
		}

		void printArray()
		{
			for (int i = 0; i < elements; i++)
			{
				std::cout << *array[i] << " ";
			}
			std::cout << std::endl;
		}

		void printResults()
		{
			std::cout << "Comparisons: " << compare << ", Moves: " << move << std::endl;
		}
		

	protected:
		T** array = 0;
		int elements;
		int compare;
		int move;
};

template <class T>
class Derived : public List<T>
{
	public:	
		Derived()
		{
			array = new T * [25] {nullptr };
			elements = 0;
			compare = 0;
			move = 0;
		}
		Derived(int size)
		{
			array = new T* [size] {nullptr };
			elements = 0;
			compare = 0;
			move = 0;
		}

		using List<T>::array;
		using List<T>::elements;
		using List<T>::isEmpty;
		using List<T>::isFull;
		using List<T>::compare;
		using List<T>::move;


		void addItem(T* item) 
		{
			class fullArray {};
			try
			{
				bool end = true;
				if (isEmpty())
				{
					array[0] = item;
					elements += 1;
				}
				else if (isFull())
				{
					throw fullArray{};
				}
				else
				{
					array[elements] = item;

					int i = (elements / 2);
					if (*item > *array[i])
					{
						for (i; i < elements; i++)
						{
							compare += 1;
							if (*item < *array[i])
							{
								move += 1;
								T* temp = array[i];
								array[i] = array[elements];
								array[elements] = temp;
							}
						}
					}
					else if (*item < *array[i])
					{
						compare += 1;
						for (i; i > 0; i--)
						{
							compare += 1;
							if (*item < *array[i])
							{
								move += 1;
								T* temp = array[i];
								array[i] = array[elements];
								array[elements] = temp;
							}
						}
					}

					elements += 1;

				}
			}
			catch (fullArray e)
			{
				std::cout << "Array is Full, Item Cannot be Added" << std::endl;
			}
		}
			
};

template <class T>
class Derived2 : public List<T>
{
public:
	Derived2()
	{
		array = new T * [25] {nullptr };
		elements = 0;
		compare = 0;
		move = 0;
	}
	Derived2(int size)
	{
		array = new T * [size] {nullptr };
		elements = 0;
		compare = 0;
		move = 0;
		length = size;
	}

	using List<T>::array;
	using List<T>::elements;
	using List<T>::isEmpty;
	using List<T>::isFull;
	using List<T>::compare;
	using List<T>::move;

	void addItem(T* num)
	{
		int i = 0;
		int middle = length / 2;
		if (elements == 0)
		{
			array[middle] = num;
			elements += 1;
		}
		else
		{
			if (*num > *array[middle])
			{
				i = middle + (middle / 2);
			}
			else if (*num < *array[middle])
			{
				i = middle - (middle / 2);
			}
			else
			{
				i = middle + 1;
			}

			bool a = false;
			while (a == false)
			{
				if (array[i] == nullptr)
				{
					array[i] = num;
					a = true;
					elements += 1;
				}
				else
				{
					if (i < 0)
					{
						T* temp2 = array[i];
						for (int j = 0; j < length; j++)
						{
							if (array[j + 1] == nullptr)
							{
								array[j + 1] = temp2;
								j = length;
							}
							else
							{
								T* temp2 = array[j + 1];
								array[j + 1] = temp2;
							}
						}
					}
					else if (*num < *array[i])
					{
						i -= 1;
					}
					else if (*num > *array[i] or *num == *array[i])
					{
						if (array[i + 1] != nullptr)
						{
							if (*num < *array[i + 1])
							{
								T* temp = array[i];
								array[i] = num;
								num = temp;

							}
						}
						i += 1;
					}
				}
			}
		}
	}

	void removeItem(T* num)
	{
		if (isEmpty())
		{
			std::cout << "List is Empty; Item cannot be Removed \n";
		}
		else
		{
			for (int i = 0; i < 25; i++)
			{
				if (array[i] != nullptr)
				{
					if (*num == *array[i])
					{
						array[i] = nullptr;
						std::cout << "Element Removed: " << std::endl;
					}
				}
				
			}
		}
	}

	void printArray()
	{
		for (int i = 0; i < length; i++)
		{
			if (array[i] == nullptr)
			{
				std::cout << "Null ";
			}
			else
			{
				std::cout << *array[i] << " ";
			}
		}
		std::cout << std::endl;
	}

	private:
		int length;
};
