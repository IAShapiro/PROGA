#include "HeaderForClassMatrix.h"
#include <conio.h>

int matrix::getSize() const
{
	return size1_ * size2_;
}

matrix operator+ (const matrix& r1, const matrix& r2) {
	if (!(r1.size1_ == r2.size1_ && r1.size2_ == r2.size2_))
	{
		std::cout << "Matrix sizes are different!\n";
		_getch();
		exit(1);
	}

	const matrix tmp(r1);
	for (auto i = 0; i < r1.size1_; i++)
	{
		for (auto j = 0; j < r1.size2_; j++)
		{
			tmp.array_[i][j] += r2.array_[i][j];
		}
	}
	return matrix(tmp);
}

matrix operator-(const matrix& r1, const matrix& r2)
{
	if (!(r1.size1_ == r2.size1_ && r1.size2_ == r2.size2_))
	{
		std::cout << "Matrix sizes are different!\n";
		_getch();
		exit(1);
	}

	const matrix tmp(r1);
	for (auto i = 0; i < r1.size1_; i++)
	{
		for (auto j = 0; j < r1.size2_; j++)
		{
			tmp.array_[i][j] -= r2.array_[i][j];
		}
	}
	return matrix(tmp);
}

std::ostream& operator<< (std::ostream &out, const matrix &obj)
{
	for (auto i = 0; i < obj.size1_; i++)
	{
		for (auto j = 0; j < obj.size2_; j++)
		{
			out << std::setw(7) << obj.array_[i][j];
		}
		std::cout << std::endl;
	}

	out << std::endl;

	return out;
}

std::istream& operator>> (std::istream & in, matrix &obj)
{
	try
	{
		for (auto i = 0; i < obj.size1_; i++)
		{
			for (auto j = 0; j < obj.size2_; j++)
			{
				if (!(in >> obj.array_[i][j]))
				{
					throw std::runtime_error("Runtime error!");
				};
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		in.clear();
		while (in.get() != '\n')
		{
			;
		}
		_getch();
		exit(1);
	}

	return in;
}

matrix operator*(const matrix& r1, const matrix& r2)
{
	if (!(r1.size2_ == r2.size1_))
	{
		std::cout << "Matrices can not be multiplied!\n";
		_getch();
		exit(1);
	}

	const matrix tmp(r2.size2_, r1.size1_);
	for (auto i = 0; i < tmp.size1_; i++)
	{
		for (auto j = 0; j < tmp.size2_; j++)
		{
			tmp.array_[i][j] = 0;
			for (auto k = 0; k < r1.size2_; k++)
				tmp.array_[i][j] += r1.array_[i][k] * r2.array_[k][j];
		}
	}
	return matrix(tmp);
}

matrix operator*(const matrix& r1, const int a)
{
	const matrix tmp(r1);

	for (auto i = 0; i < tmp.size1_; i++)
	{
		for (auto j = 0; j < tmp.size2_; j++)
		{
			tmp.array_[i][j] *= a;
		}
	}
	return matrix(tmp);
}

matrix operator* (const int a, const matrix& r1)
{
	return r1 * a;
}
// A * 2.1234, A * 'a' ???

matrix& matrix::operator+= (const matrix &r)
{
	if (size1_ != r.size1_ || size2_ != r.size2_)
	{
		std::cout << "Matrix sizes are different!\n";
		_getch();
		exit(1);
	}

	for (auto i = 0; i < size1_; i++)
	{
		for (auto j = 0; j < size2_; j++)
		{
			array_[i][j] = array_[i][j] + r.array_[i][j];
		}
	}
	return *this;
}

matrix& matrix::operator-= (const matrix &r)
{
	if (size1_ != r.size1_ || size2_ != r.size2_)
	{
		std::cout << "Matrix sizes are different!\n";
		_getch();
		exit(1);
	}

	for (auto i = 0; i < size1_; i++)
	{
		for (auto j = 0; j < size2_; j++)
		{
			array_[i][j] = array_[i][j] - r.array_[i][j];
		}
	}
	return *this;
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
		std::cout << "Matrices can not be multiplied!\n";
		system("pause");
		exit(1);
	}

	const matrix tmp(*this);

	for (auto i = 0; i < size1_; i++)
	{
		delete[] array_[i];
	}
	delete[] array_;

	size1_ = r.size1_;
	size2_ = tmp.size2_;

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
			for (auto k = 0; k < tmp.size2_; k++)
			{
				array_[i][j] += tmp.array_[i][k] * r.array_[k][j];
			}
		}
	}

	return *this;
}

matrix& matrix::transpose()
{
	const matrix tmp(this->size2_, this->size1_);
	for (auto i = 0; i < tmp.size1_; i++)
	{
		for (auto j = 0; j < tmp.size2_; j++)
		{
			tmp.array_[i][j] = this->array_[j][i];
		}
	}

	*this = tmp;
	return *this;
}

matrix& matrix::operator*= (const int a)
{
	for (auto i = 0; i < size1_; i++)
	{
		for (auto j = 0; j < size2_; j++)
		{
			this->array_[i][j] *= a;
		}
	}

	return *this;
}

int matrix::search_count(const int a) const
{
	auto n = 0;
	for (auto i = 0; i < this->size1_; i++)
	{
		for (auto j = 0; j < this->size2_; j++)
		{
			if (this->array_[i][j] == a)
			{
				n++;
			}
		}
	}
	return n;
}

double matrix::search_frequency(const int a) const
{
	return this->search_count(a) * 1. / this->getSize();
}
