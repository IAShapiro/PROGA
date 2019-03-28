#pragma once
#include <iostream>
#include <queue>

template <typename T>
class pr_queue {

	static const int max_size = 10;
	T * arr_;
	int size_;

	T & operator[] (const int i)//from unsigned int and explicit 
	{
		if (i < 0 || i >= size_)
		{
			throw std::out_of_range("Invalid index!");
		}
		return this->arr_[i];
	}

	void swap(T & lv, T & rv)
	{
		T tmp = lv;
		lv = rv;
		rv = tmp;
	}

	void up(int i)
	{
		while (i != 0 && arr_[i] > arr_[(i - 1) / 2])
		{
			swap(arr_[i], arr_[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void down(int i)
	{
		while (i < size_ / 2)
		{
			int max_i = 2 * i + 1; //child 1
			if (2 * i + 2 < size_ && arr_[2 * i + 2] > arr_[2 * i + 1])
			{
				max_i = 2 * i + 2;//child 2
			}
			if (arr_[i] >= arr_[max_i])
			{
				return;
			}
			swap(arr_[i], arr_[max_i]);
			i = max_i;
		}
	}

public:

	pr_queue()
	{
		size_ = 0;
		arr_ = new T[max_size];
	}

	virtual ~pr_queue()
	{
		delete[] arr_;
	}

	pr_queue(pr_queue const& source)
	{
		size_ = source.size_;
		arr_ = new T[static_cast<int>(ceil(size_ / max_size)) * max_size];
		for (auto i = 0; i < source.size_; i++)
		{
			arr_[i] = source.arr_[i];
		}
	}

	pr_queue(pr_queue&& source)
	{
		size_ = source.size_;
		arr_ = source.arr_;
		source.arr_ = nullptr;
	}

	void push(const T value)
	{
		if (size_ % max_size == 0 && size_ != 0)
		{
			T * tmp = new T[size_ + max_size];
			for (auto i = 0; i < size_; i++)
			{
				tmp[i] = this->arr_[i];
			}
			delete[] this->arr_;
			this->arr_ = tmp;
		}
		arr_[size_++] = value;
		up(size_ - 1);
	}

	bool pop()
	{
		if (size_ <= 0)
		{
			return false;
		}
		swap(arr_[0], arr_[size_ - 1]);
		size_--;
		down(0);
		return true;
	}

	bool empty() const
	{
		return size_ == 0;
	}

	T & top()
	{
		if (this->empty())
		{
			throw std::out_of_range("List is empty");
		}
		return this->arr_[0];
	}

	int size() const
	{
		return size_;
	}
};

