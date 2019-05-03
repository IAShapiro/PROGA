#include "stdafx.h"
#include "Raylway.h"
#include <string>
#include <iomanip>

raylway::raylway(const int l)
{
	if (l < 0)
	{
		throw std::invalid_argument("Error! Size < 0. Default dimensions(0) are set\n");
	}
	array_.reserve(l);
}

raylway::raylway(raylway const& source) {
	std::vector<Event> array(source.array_.capacity());
	array = source.array_;
}

raylway::raylway(raylway&& source) {
	array_ = source.array_;
	source.array_.clear();
}

Event& raylway::operator[] (const int l)
{
	if (l < 0 || static_cast<int>(this->array_.size()) <= l)
	{
		throw std::out_of_range("Error! Invalid index\n");
	}
	return this->array_[l];
}

void raylway::book(const int l)
{
	if (l < 1 || l > static_cast<int>(this->array_.size()))
	{
		throw std::out_of_range("Error! Incorrect number of raylway\n");
	}

	if (this->array_[l - 1].residue == 0)
	{
		throw std::exception("No tickets avilable\n");
	}
	this->array_[l - 1].n_of_booking++;
	this->array_[l - 1].residue--;
}

std::ostream& operator<< (std::ostream &out, const raylway &obj)
{
	for (int i = 0; i < static_cast<int>(obj.array_.size()); i++)
	{
		out << std::setw(20) << std::left << obj.array_[i].station1 << " " << obj.array_[i].data_time1 << std::setw(20) << std::left << obj.array_[i].station2 << " " << obj.array_[i].data_time2 << std::setw(7) <<
			std::right << obj.array_[i].residue << "/" << std::setw(7) << std::left <<
			obj.array_[i].capacity << std::endl;
	}

	out << std::endl;

	return out;
}

std::istream& operator>> (std::istream & in, raylway &obj)
{
	Event temp;
	std::string buffer;

	getline(in, temp.station1, ';');
	getline(in, temp.data_time1, ';');
	getline(in, temp.station2, ';');
	getline(in, temp.data_time2, ';');

	getline(in, buffer, ';');
	temp.capacity = std::stoi(buffer);
	buffer.clear();
	getline(in, buffer, '\n');
	temp.residue = std::stoi(buffer);
	buffer.clear();
	temp.n_of_booking = 0;
	obj.array_.push_back(temp);

	return in;
}

bool raylway::cmp_data(Event &a, Event &b)
{
	return (a.data_time1 < b.data_time1);
}

bool raylway::cmp_name(Event &a, Event &b)
{
	return (a.station1 < b.station1);
}

void raylway::sort_data()
{
	std::sort(array_.begin(), array_.end(), cmp_data);
}

void raylway::sort_name()
{
	std::sort(array_.begin(), array_.end(), cmp_name);
}

int raylway::get_size() const
{
	return this->array_.size();
}

std::vector<Event>::iterator raylway::begin()
{
	return array_.begin();
}

std::vector<Event>::iterator raylway::end()
{
	return array_.end();
}
