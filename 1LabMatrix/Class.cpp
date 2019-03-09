#include "Header.h"

Matrix operator+ (const Matrix& r1, const Matrix& r2) {
	if (!(r1.size1 == r2.size1 && r1.size2 == r2.size2))
	{
		std::cout << "Matrix sizes are different!\n";
		system("pause");
		exit(1);//Уточнить, нормально ли использовать exit()
	}

	const Matrix n(r1);
	for (int i = 0; i < r1.size1; i++)
	{
		for (int j = 0; j < r1.size2; j++)
		{
			n.array[i][j] += r2.array[i][j];
		}
	}
	return Matrix(n);
}

Matrix operator-(const Matrix& r1, const Matrix& r2)
{
	if (!(r1.size1 == r2.size1 && r1.size2 == r2.size2))
	{
		std::cout << "Matrix sizes are different!\n";
		system("pause");
		exit(1);
	}

	const Matrix n(r1);
	for (int i = 0; i < r1.size1; i++)
	{
		for (int j = 0; j < r1.size2; j++)
		{
			n.array[i][j] -= r2.array[i][j];
		}
	}
	return Matrix(n);
}

std::ostream& operator<< (std::ostream &out, const Matrix &obj)
{
	for (int i = 0; i < obj.size1; i++)
	{
		for (int j = 0; j < obj.size2; j++)
		{
			out << std::setw(7) << obj.array[i][j];
		}
		std::cout << std::endl;
	}

	out << std::endl;

	return out;
}

std::istream& operator>> (std::istream & in, Matrix &obj)
{
	for (int i = 0; i < obj.size1; i++)
	{
		for (int j = 0; j < obj.size2; j++)
		{
			std::cout << "Input array[" << i << "]" << "[" << j << "]: ";
			bool err = false;
			while (!err)
			{
				in >> obj.array[i][j];
				if (!(std::cin) || std::cin.rdbuf()->in_avail() != 1)
				{

					std::cin.clear();
					while (std::cin.get() != '\n')
					{
						;
					}
					std::cout << "Input error! Try again: " << std::endl;
				}
				else
				{
					err = true;
				}
			}
		}
	}
	return in;
}

Matrix operator*(const Matrix& r1, const Matrix& r2)
{
	if (!(r1.size2 == r2.size1))
	{
		std::cout << "Matrices can not be multiplied!\n";
		system("pause");
		exit(1);
	}

	const Matrix n(r2.size2, r1.size1);
	for (int i = 0; i < n.size1; i++)
	{
		for (int j = 0; j < n.size2; j++)
		{
			n.array[i][j] = 0;
			for (int k = 0; k < r1.size2; k++)
				n.array[i][j] += r1.array[i][k] * r2.array[k][j];
		}
	}
	return Matrix(n);
}

Matrix operator*(const Matrix& r1, const int a)
{
	const Matrix n(r1);

	for (int i = 0; i < n.size1; i++)
	{
		for (int j = 0; j < n.size2; j++)
		{
			n.array[i][j] *= a;
		}
	}
	return Matrix(n);
}

Matrix operator* (const int a, const Matrix& r1)
{
	return r1 * a;
} //Недоработка в том, что допустимы записи A * 2.1234, A * 'a' и т.д. Уточнить, как их отсеять