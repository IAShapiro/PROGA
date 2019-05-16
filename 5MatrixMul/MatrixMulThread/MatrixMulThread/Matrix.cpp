#include "Matrix.h"
#include <iostream>
#include <thread>

int numb_of_threads = 1;

matrix::matrix(matrix&& source) {
	size1_ = source.size1_;
	size2_ = source.size2_;
	array_ = source.array_;
	source.array_ = nullptr;
}

matrix::matrix(matrix const& source) {
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

matrix::~matrix() {
	for (auto i = 0; i < size1_; i++)
	{
		delete[] array_[i];
	}
	delete[] array_;
}

matrix::matrix(const int y, const int x) {
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

matrix::matrix() {
	size2_ = size1_ = 1;
	array_ = new int*[size2_];
	array_[0] = new int[size1_];
	array_[0][0] = 0;
}

int matrix::getSize() const
{
	return size1_ * size2_;
}

int matrix::getSize1() const
{
	return size1_;
}

int matrix::getSize2() const
{
	return size2_;
}


std::ostream& operator<< (std::ostream &out, const matrix &obj)
{
	for (auto i = 0; i < obj.size1_; i++)
	{
		for (auto j = 0; j < obj.size2_; j++)
		{
			out << std::setw(7) << obj.array_[i][j];
		}
		out << std::endl;
	}

	out << std::endl;

	return out;
}

std::istream& operator>> (std::istream & in, matrix &obj)
{
	for (auto i = 0; i < obj.size1_; i++)
	{
		for (auto j = 0; j < obj.size2_; j++)
		{
			if (!(in >> obj.array_[i][j]))
			{
				in.clear();
				while (in.get() != '\n')
				{
					;
				}
				throw std::runtime_error("Runtime error! Incorrect input");
			};
		}
	}

	return in;
}

matrix operator*(const matrix& r1, const matrix& r2)
{
	return matrix(r1) *= r2;
}


matrix& matrix::operator= (const matrix& r)
{
	if (this == &r)
	{
		return *this;
	}

	for (auto i = 0; i < size1_; i++)
	{
		delete[] array_[i];
	}
	delete[] array_;

	size1_ = r.size1_;
	size2_ = r.size2_;

	array_ = new int*[size1_];
	for (auto i = 0; i < size1_; i++)
	{
		array_[i] = new int[size2_];
	}
	for (auto i = 0; i < size1_; i++)
	{
		for (auto j = 0; j < size2_; j++)
		{
			array_[i][j] = r.array_[i][j];
		}
	}
	return *this;
}

bool matrix::operator== (const matrix &r) const
{
	if (size1_ != r.size1_ || size2_ != r.size2_)
	{
		return false;
	}

	for (auto i = 0; i < size1_; i++)
	{
		for (auto j = 0; j < size2_; j++)
		{
			if (array_[i][j] != r.array_[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

matrix& matrix::operator*= (const matrix &r)
{
	if (size2_ != r.size1_)
	{
		throw std::invalid_argument("Error! Matrices can not be multiplied!");
	}

	matrix tmp(size1_, r.size2_);

	std::thread *streams = new std::thread[numb_of_threads];

	int residue = (size1_ * r.size2_) % numb_of_threads, numb_of_cell_without_res = (size1_ * r.size2_) / numb_of_threads;
/*
	for(int s = 0; s < numb_of_threads; s++)
	{
		streams[s] = std::thread([residue, s, numb_of_cell, tmp]()
		{
			for (int p = 0; p < (residue > s ? numb_of_cell_without_res : (numb_of_cell_without_res + 1)); p++)
			{

			}

		});
	}
	*/

	for (int s = 0; s < numb_of_threads - residue; s++)
	{
		streams[s] = std::thread([residue, s, numb_of_cell_without_res, &tmp, this,r]()
		{
			for (auto p = 0; p < numb_of_cell_without_res; p++)
			{
				auto i = (s * numb_of_cell_without_res + p) / (tmp.size2_);
				auto j = (s * numb_of_cell_without_res + p) % (tmp.size2_);
				for (auto a = 0; a < size2_; a++)
				{
					tmp[i][j] += this->array_[i][a] * r.array_[a][j];
				}
			}
		});
	}

	for (int s = numb_of_threads - residue; s < numb_of_threads; s++)
	{
		streams[s] = std::thread([residue, s, numb_of_cell_without_res, &tmp, this, r]()
		{
			for (auto p = 0; p < numb_of_cell_without_res + 1; p++)
			{			
				auto i = ((numb_of_threads - residue) * numb_of_cell_without_res + (s - (numb_of_threads - residue)) * (numb_of_cell_without_res + 1) + p) / tmp.size2_;
				auto j = ((numb_of_threads - residue) * numb_of_cell_without_res + (s - (numb_of_threads - residue)) * (numb_of_cell_without_res + 1) + p) % tmp.size2_;
				for (auto a = 0; a < size2_; a++)
				{
					tmp[i][j] += this->array_[i][a] * r.array_[a][j];
				}
			}
		});
	}

	for (int s = 0; s < numb_of_threads; s++)
	{
		streams[s].join();
	}

	//matrix tmp(size1_, r.size2_);
	/*
	for (auto i = 0; i < size1_; i++)
	{
		for (auto j = 0; j < r.size2_; j++)
		{
			//tmp.array_[i][j] = 0;
			for (auto k = 0; k < size2_; k++)
			{
				tmp.array_[i][j] += array_[i][k] * r.array_[k][j];
			}
		}
	}
	*/
	*this = tmp;

	return *this;
}

int* matrix::operator[] (const int i) const
{
	if (i < 0 || i >= this->getSize1())
	{
		throw std::runtime_error("Error! Invalid index!");
	}
	return array_[i];
}