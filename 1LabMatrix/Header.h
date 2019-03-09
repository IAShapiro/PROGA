#pragma once
#include <iostream>
#include <iomanip>

class Matrix {
	int** array;
	int size1;
	int size2;

public:
	Matrix() {
		size2 = size1 = 1;
		array = new int*[size2];
		array[0] = new int[size1];
		array[0][0] = 0;
	}

	Matrix(int y, int x) {
		if (y <= 0 || x <= 0)
		{
			size2 = size1 = 1;
			std::cout << "Error! size < 0" << std::endl << "Default dimensions(1*1) are set" << std::endl;
		}
		else
		{
			size2 = x;
			size1 = y;
		}
		array = new int*[size1];
		for (int i = 0; i < size1; i++)
		{
			array[i] = new int[size2];
		}
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				array[i][j] = 0;
			}
		}
	}

	virtual ~Matrix() {
		for (int i = 0; i < size1; i++)
		{
			delete[] array[i];
		}
		delete[] array;
	}

	Matrix(Matrix const& source) {//конструктор копирования
		size1 = source.size1;
		size2 = source.size2;
		array = new int*[size1];
		for (int i = 0; i < size1; i++)
		{
			array[i] = new int[size2];
		}
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				array[i][j] = source.array[i][j];
			}
		}
	}

	Matrix(Matrix&& source) {//конструктор перемещения
		size1 = source.size1;
		size2 = source.size2;
		array = source.array;
		source.array = nullptr;
	}

	int getSize() const // возвратить количество элементов матрицы
	{
		return size1 * size2;
	}

	friend Matrix operator+ (const Matrix& r1, const Matrix& r2);

	Matrix& operator+= (const Matrix &r)
	{
		if (size1 != r.size1 || size2 != r.size2)
		{
			std::cout << "Matrix sizes are different!\n";
			system("pause");
			exit(1);
		}

		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				array[i][j] = array[i][j] + r.array[i][j];
			}
		}
		return *this;
	}

	friend Matrix operator-(const Matrix& r1, const Matrix& r2);

	Matrix& operator-= (const Matrix &r)
	{
		if (size1 != r.size1 || size2 != r.size2)
		{
			std::cout << "Matrix sizes are different!\n";
			system("pause");
			exit(1);
		}

		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				array[i][j] = array[i][j] - r.array[i][j];
			}
		}
		return *this;
	}

	Matrix& operator= (const Matrix& r)
	{
		if (this == &r)
		{
			return *this;
		}

		for (int i = 0; i < size1; i++)
		{
			delete[] array[i];
		}
		delete[] array;//Правильное ли в данном случае предварительное очищение места в памяти?..

		size1 = r.size1;
		size2 = r.size2;

		array = new int*[size1];
		for (int i = 0; i < size1; i++)
		{
			array[i] = new int[size2];
		}
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				array[i][j] = r.array[i][j];
			}
		}
		return *this;
	}

	bool operator== (const Matrix &r) const
	{
		if (size1 != r.size1 || size2 != r.size2)
		{
			return false;
		}

		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				if (array[i][j] != r.array[i][j])
				{
					return false;
				}
			}
		}

		return true;
	}

	friend std::ostream& operator<< (std::ostream &out, const Matrix &obj);

	friend std::istream& operator>> (std::istream & in, Matrix &obj);

	friend Matrix operator*(const Matrix& r1, const Matrix& r2);

	Matrix& operator*= (const Matrix &r)
	{
		if (size2 != r.size1)
		{
			std::cout << "Matrices can not be multiplied!\n";
			system("pause");
			exit(1);
		}

		const Matrix n(*this);

		for (int i = 0; i < size1; i++)
		{
			delete[] array[i];
		}
		delete[] array;//Правильное ли в данном случае предварительное очищение места в памяти?..

		size1 = r.size1;
		size2 = n.size2;

		array = new int*[size1];
		for (int i = 0; i < size1; i++)
		{
			array[i] = new int[size2];
		}

		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				array[i][j] = 0;
				for (int k = 0; k < n.size2; k++)
				{
					array[i][j] += n.array[i][k] * r.array[k][j];
				}
			}
		}

		return *this;
	}

	Matrix& Transpose()
	{
		const Matrix n(this->size2, this->size1);
		//	auto n = std::make_unique<Matrix>(r1.size2, r1.size1);
		for (int i = 0; i < n.size1; i++)
		{
			for (int j = 0; j < n.size2; j++)
			{
				n.array[i][j] = this->array[j][i];
			}
		}

		*this = n;
		return *this;
	}

	friend Matrix operator*(const Matrix& r1, const int a);

	friend Matrix operator* (const int a, const Matrix& r1);

	Matrix& operator*= (const int a)
	{
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				this->array[i][j] *= a;
			}
		}

		return *this;
	}
};