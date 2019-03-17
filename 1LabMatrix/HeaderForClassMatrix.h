#pragma once
#include <iostream>
#include <iomanip>

class matrix {
	int** array_;
	int size1_;
	int size2_;

public:
	matrix() {
		size2_ = size1_ = 1;
		array_ = new int*[size2_];
		array_[0] = new int[size1_];
		array_[0][0] = 0;
	}

	matrix(const int y, const int x) {
		if (y <= 0 || x <= 0)
		{
			size2_ = size1_ = 1;
			std::cout << "Error! size < 0" << std::endl << "Default dimensions(1*1) are set" << std::endl;
		}
		else
		{
			size2_ = x;
			size1_ = y;
		}
		array_ = new int*[size1_];
		for (auto i = 0; i < size1_; i++)
		{
			array_[i] = new int[size2_];
		}
		for (auto i = 0; i < size1_; i++)
		{
			for (auto j = 0; j < size2_; j++)
			{
				array_[i][j] = 0;
			}
		}
	}

	virtual ~matrix() {
		for (auto i = 0; i < size1_; i++)
		{
			delete[] array_[i];
		}
		delete[] array_;
	}

	matrix(matrix const& source) {
		size1_ = source.size1_;
		size2_ = source.size2_;
		array_ = new int*[size1_];
		for (auto i = 0; i < size1_; i++)
		{
			array_[i] = new int[size2_];
		}
		for (auto i = 0; i < size1_; i++)
		{
			for (auto j = 0; j < size2_; j++)
			{
				array_[i][j] = source.array_[i][j];
			}
		}
	}

	matrix(matrix&& source) {
		size1_ = source.size1_;
		size2_ = source.size2_;
		array_ = source.array_;
		source.array_ = nullptr;
	}

	int getSize() const;

	friend matrix operator+ (const matrix& r1, const matrix& r2);

	matrix& operator+= (const matrix &r);

	friend matrix operator-(const matrix& r1, const matrix& r2);

	matrix& operator-= (const matrix &r);

	matrix& operator= (const matrix& r);

	bool operator== (const matrix &r) const;

	friend std::ostream& operator<< (std::ostream &out, const matrix &obj);

	friend std::istream& operator>> (std::istream & in, matrix &obj);

	friend matrix operator*(const matrix& r1, const matrix& r2);

	matrix& operator*= (const matrix &r);

	matrix& transpose();

	friend matrix operator*(const matrix& r1, const int a);

	friend matrix operator* (const int a, const matrix& r1);

	matrix& operator*= (const int a);

	int search_count(const int a) const;

	double search_frequency(const int a) const;
};