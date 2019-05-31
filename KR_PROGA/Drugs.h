#pragma once

#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

class Drugs {
private:
	std::string name;
	int count;
	double price;
	int n_of_booking;

public:
	Drugs()
	{
		name = "default";
		count = 0;
		price = 0;
		n_of_booking = 0;
	}

	Drugs(std::string name_, const unsigned int c_, double  pr_, int n_of_) : name(std::move(name_)), count(c_), price(pr_), n_of_booking(n_of_) {};

	virtual ~Drugs() =default;

	Drugs(Drugs const& source)
	{
		name = source.name;
		count = source.count;
		price = source.price;
		n_of_booking = source.n_of_booking;
	}

	Drugs(Drugs && source)
	{
		name = source.name;
		count = source.count;
		price = source.price;
		n_of_booking = source.n_of_booking;
		source.name.clear();
	}

	std::ostream& operator<< (std::ostream &out, const Drugs &obj)
	{
		out << obj.name << " " << obj.count << " " << obj.price << " " << obj.n_of_booking << std::endl;

		return out;
	}

	bool operator< (const Drugs &obj)
	{
		return this->name < obj.name;
	}

};
