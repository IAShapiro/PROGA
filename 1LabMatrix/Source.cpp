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

	Matrix(Matrix const& source) {//����������� �����������
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

	Matrix(Matrix&& source) {//����������� �����������
		size1 = source.size1;
		size2 = source.size2;
		array = source.array;
		source.array = nullptr;
	}

	int getSize() const // ���������� ���������� ��������� �������
	{
		return size1 * size2;
	}

	friend Matrix operator+ (const Matrix& r1, const Matrix& r2)
	{
		if (!(r1.size1 == r2.size1 && r1.size2 == r2.size2))
		{
			std::cout << "Matrix sizes are different!\n";
			system("pause");
			exit(1);//��������, ��������� �� ������������ exit()
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

	friend Matrix operator-(const Matrix& r1, const Matrix& r2)
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
		delete[] array;//���������� �� � ������ ������ ��������������� �������� ����� � ������?..

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

	friend std::ostream& operator<< (std::ostream &out, const Matrix &obj)
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

	friend std::istream& operator>> (std::istream & in, Matrix &obj)
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

	friend Matrix operator*(const Matrix& r1, const Matrix& r2)
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
		delete[] array;//���������� �� � ������ ������ ��������������� �������� ����� � ������?..

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

	friend Matrix operator*(const Matrix& r1, const int a)
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

	friend Matrix operator * (int p, const Matrix& a)
	{
		return a * p;
	}

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

int main()
{
	Matrix A(3, 2);

	std::cin >> A;
	Matrix B(A);
	std::cout << A;
	B += (A + B);
	B.Transpose();
	std::cout << B;
	B.Transpose();
	std::cout << B;
	A = B + (A + B);
	std::cout << A;
	Matrix C(B);
	std::cout << C;
	A.Transpose();
	B.Transpose();
	std::cout << A + B;
	A = C * (A + B);
	std::cout << A;

	std::cout << A * 2;
	std::cout << 2 * A;
	A *= 3;
	std::cout << A;

	system("pause");
	return 0;
}