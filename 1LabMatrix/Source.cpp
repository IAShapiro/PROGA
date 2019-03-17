#include <iostream>
#include <iomanip>
#include "Header.h"
#include <conio.h>

int main()
{
	try
	{
		matrix A(3, 2);
		matrix j(5, 1);

		std::cout << "Input elements of matrix(right to left, top to bottom), separated by space or \"Enter\":" << std::endl;
		std::cin >> A;
		matrix B(A);
		std::cout << A[1][1];
		std::cout << A.search_count(1) << A.search_frequency(1) << std::endl;
		B = 2 * B - A;
		std::cout << B;
		B -= (2 * A + 2 * B);
		std::cout << "________________" << std::endl << A << "________________" << std::endl << B;
		B.transpose();
		std::cout << B;
		B.transpose();
		std::cout << B;
		A = B + (A + B);
		std::cout << A;
		matrix C(B);
		std::cout << C;
		A.transpose();
		B.transpose();
		std::cout << A + B;
		A = C * (A + B);
		std::cout << A;

		std::cout << A * 2;
		std::cout << 2 * A;
		A *= 3;
		std::cout << A;


	}
	catch (const std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
		_getch();
		exit(1);
	}
	system("pause");
	return 0;
}
