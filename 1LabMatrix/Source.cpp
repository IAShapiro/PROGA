#include <iostream>
#include <iomanip>
#include "Header.h"

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