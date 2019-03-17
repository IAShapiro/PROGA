#include <iostream>
#include <iomanip>
#include "HeaderForClassMatrix.h"

int main()
{

	matrix A(3, 2);
	std::cout << "Input elements of matrix(right to left, top to bottom), separated by space or \"Enter\":" << std::endl;
	std::cin >> A;
	matrix B(A);
	std::cout << A;
	std::cout << A.search_count(1) << A.search_frequency(1) << std::endl;
	B = B - A;
	std::cout << B;
	B -= (2 * A + B);
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

	system("pause");
	return 0;
}
