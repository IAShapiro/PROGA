#pragma once
#include <iomanip>

class matrix {
	int** array_;
	int size1_;
	int size2_;

public:
	matrix();

	matrix(const int y, const int x);

	virtual ~matrix();

	matrix(matrix const& source);

	matrix(matrix&& source);

	int getSize() const;

	int getSize1() const;

	int getSize2() const;

	matrix& operator= (const matrix& r);

	friend std::ostream& operator<< (std::ostream &out, const matrix &obj);

	friend std::istream& operator>> (std::istream & in, matrix &obj);

	friend matrix operator*(const matrix& r1, const matrix& r2);

	matrix& operator*= (const matrix &r);

	int* operator[] (const int i) const;
};