#include <iostream>
#include "Matrix.h"
#include <fstream>

//long int numb_of_threads;

int main()
{
	clock_t start, end;
	try
	{
		std::ofstream out("report.txt");
		/*matrix A(2, 3), B(3, 3), C(A.getSize1(), B.getSize2()), D(2,3);
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

		*/
		matrix A(100, 205), B(205, 3000), C(100,3000);

		for (auto i = 0; i < A.getSize1(); i++)
		{
			for (auto j = 0; j < A.getSize2(); j++)
			{
				A[i][j] = rand() % 4;
			}
		}
		for (auto i = 0; i < B.getSize1(); i++)
		{
			for (auto j = 0; j < B.getSize2(); j++)
			{
				B[i][j] = rand() % 4;
			}
		}
		C = A * B;
		for (numb_of_threads = 1; numb_of_threads < static_cast<int>(pow(2, 5)); numb_of_threads ++)
		{
			start = clock();
			C = A * B;
			end = clock();

			out << numb_of_threads << char(9) <<std::showpoint << std::fixed << std::setprecision(3) << (static_cast<double>(end) - start) / static_cast<double>(CLOCKS_PER_SEC) << std::endl;
		}
		out.close();
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
