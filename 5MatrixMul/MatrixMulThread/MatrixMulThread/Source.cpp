#include <iostream>
#include "Matrix.h"

int main()
{
	try
	{
		matrix A(2, 3), B(2, 3), C(A.getSize1(), B.getSize2()), D(2,3);
		for (auto i = 0; i < A.getSize1(); i++)
		{
			for (auto j = 0; j < A.getSize2(); j++)
			{
				A[i][j] = i + j;
			}
		}
		for (auto i = 0; i < B.getSize1(); i++)
		{
			for (auto j = 0; j < B.getSize2(); j++)
			{
				B[i][j] = i + j;
			}
		}
		for (auto i = 0; i < C.getSize1(); i++)
		{
			for (auto j = 0; j < C.getSize2(); j++)
			{
				C[i][j] = 3 * (i + j * (i + 1) + 2) - 1;
			}
		}
		std::cout << A;
		std::cout << B;
		D = A * B;
		
		std::cout << C;
		std::cout << D;
		std::cout << A;
		std::cout << B;
	}
	catch (const std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
		system("pause");
		exit(1);
	}
	system("pause");
	return 0;
}
