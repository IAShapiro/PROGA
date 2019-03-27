#pragma once
#include <iostream>

class pr_queue {

	static const int max_size = 10;
	int * arr_;
	int size_;

	int & operator[] (int i);

	void swap(int & lv, int & rv);

	void up(int i);

	void down(int i);

public:

	pr_queue();

	virtual ~pr_queue();

	pr_queue(pr_queue const& source);

	pr_queue(pr_queue&& source);

	void enqueue(const int value);

	bool dequeue();

	bool is_empty() const;

	int & top();
};

