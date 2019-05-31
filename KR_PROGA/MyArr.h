#pragma once

#include <string>
#include <vector>
#include <algorithm>

template <typename T>
class myArray {
private:
	std::string name;
	std::vector<T> Arr;
	int count;

	static bool compare(T a, T b)
	{
		return a < b;
	}
public:
	myArray()
	{
		name = "default";
		count = 0;
	}

	myArray(const std::string name, const unsigned int number) : name(name)
	{
		count = number;
		Arr.reserve(number);
	}

	virtual ~myArray() {};

	myArray(myArray const& source)
	{
		name = source.name;
		count = source.count;
		Arr = source.Arr;
	}

	myArray(myArray && source)
	{
		name = source.name;
		count = source.count;
		Arr = source.Arr;
		source.Arr.clear();
	}

	T & operator[] (const int i)//from unsigned int and explicit 
	{
		if (i < 0 || i >= count)
		{
			throw std::out_of_range("Invalid index!");
		}
		return Arr[i];
	}

	void sort()
	{
		std::sort(Arr.begin(), Arr.end(), &compare);
	}

	T & compare_name(std::string name_)
	{
		for(auto i = 0; i < count; i++)
		{
			if (name_ == name)
			{
				return Arr[i];
			}
		}
		throw std::invalid_argument("Invalid index!");
	}
};

