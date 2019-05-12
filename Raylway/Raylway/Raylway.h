#pragma once
#include <string>
#include <vector>
#include <algorithm>

struct Event {
	std::string station1;
	std::string data_time1;
	std::string station2;
	std::string data_time2;
	int residue;
	int capacity;
	int n_of_booking;
};

class raylway {
	std::vector<Event> array_;

public:
	raylway() = default;

	raylway(const int l);

	virtual ~raylway() = default;

	raylway(raylway const& source);

	raylway(raylway&& source);

	Event& operator[] (const int l);

	void book(const int l);

	friend std::ostream& operator<< (std::ostream &out, const raylway &obj);

	friend std::istream& operator>> (std::istream & in, raylway &obj);

	static bool cmp_data(Event &a, Event &b);

	static bool cmp_name(Event &a, Event &b);

	void sort_data();

	void sort_name();

	int get_size() const;

	std::vector<Event>::iterator begin();

	std::vector<Event>::iterator end();
};