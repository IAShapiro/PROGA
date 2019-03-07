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
			std::cout << "Input error! size < 0" << std::endl << "Default dimensions(1*1) are set" << std::endl;
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
			for (int j = 0; i < size2; i++)
			{
				array[i][j] = 0;
			}
		}
	}

	virtual ~Matrix() {
		for (int i = 0; i < size1; i++)
		{
			delete [] array[i];
		}
		delete [] array;
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
			for (int j = 0; i < size2; i++)
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

	friend Matrix operator+(const Matrix& r1, const Matrix& r2)
	{
		if (!(r1.size1 == r2.size1 && r1.size2 == r2.size2))
		{
			std::cout << "������� ������� �������!\n";
			exit(1);
		}

		Matrix n(r1);
		for (int i = 0; i < r1.size1; i++) 
		{
			for (int j = 0; i < r1.size2; i++)
			{
				n.array[i][j] += r2.array[i][j];
			}
		}
		return n;
	}

	Matrix& operator+= (const Matrix &r)
	{
		if (size1 != r.size1 || size2 != r.size2)
		{
			std::cout << "������� ������� �������!\n";
			exit(1);
		}

		for (int i = 0; i < size1; i++)
			for (int j = 0; j < size2; j++)
				array[i][j] = array[i][j] + r.array[i][j];

		return *this;
	}

	friend Matrix operator-(const Matrix& r1, const Matrix& r2)
	{
		if (!(r1.size1 == r2.size1 && r1.size2 == r2.size2))
		{
			std::cout << "������� ������� �������!\n";
			exit(1);
		}

		Matrix n(r1);
		for (int i = 0; i < r1.size1; i++)
		{
			for (int j = 0; i < r1.size2; i++)
			{
				n.array[i][j] -= r2.array[i][j];
			}
		}
		return n;
	}

	Matrix& operator-= (const Matrix &r)
	{
		if (size1 != r.size1 || size2 != r.size2)
		{
			std::cout << "������� ������� �������!\n";
			exit(1);
		}

		for (int i = 0; i < size1; i++)
			for (int j = 0; j < size2; j++)
				array[i][j] = array[i][j] - r.array[i][j];

		return *this;
	}

	const Matrix operator= (Matrix& r)
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
			for (int j = 0; i < size2; i++)
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
			for (int j = 0; j < size2; j++)
				if (array[i][j] != r.array[i][j])
					return false;

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
			std::cout << "������� �� ����� ���� ��������!\n";
			exit(1);
		}

		Matrix n(r2.size2, r1.size1);
		for (int i = 0; i < n.size1; i++)
		{
			for (int j = 0; i < n.size2; i++)
			{
				n.array[i][j] = 0;
				for (int k = 0; k < r1.size2; k++)
					n.array[i][j] += r1.array[i][k] * r2.array[k][j];
			}
		}
		return n;
	}

	Matrix& operator*= (const Matrix &r)
	{
		if (size2 != r.size1)
		{
			std::cout << "������� �� ����� ���� ��������!\n";
			exit(1);
		}

		Matrix n(*this);

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
			for (int j = 0; i < size2; i++)
			{
				array[i][j] = 0;
				for (int k = 0; k < n.size2; k++)
					array[i][j] += n.array[i][k] * r.array[k][j];
			}
		}

		return *this;
	}

	friend Matrix& Transpose(Matrix& r1)
	{
		
		//Matrix n(r1.size2, r1.size1);
		auto n = std::make_unique<Matrix>(r1.size2, r1.size1);
		for (int i = 0; i < n->size1; i++)
		{
			for (int j = 0; i < n->size2; i++)
			{
					n->array[i][j] = r1.array[j][i];
			}
		}

		return *n;
	}
	
};

int main()
{
	Matrix A(3,2);//x - �������, y - ������
	Matrix B(A);
	//Matrix B(A);
	std::cin >> A;
	std::cout << A;
	B = Transpose(A);
	std::cout << B;

	system("pause");
	return 0;
}