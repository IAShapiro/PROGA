#include <iostream>
#include "PrQueue.h"

int main()
{
	try {
		pr_queue <unsigned int> a;
		for (auto i = 0; i < 150; i++)
		{
			a.push(rand() % 10000);
		}
		/*a.push(-457);
		a.push(1);
		a.push(2);
		a.push(2);
		a.push(4);
		a.push(6);
		a.push(8);
		a.push(8);
		a.push(9);
		a.push(0);
		a.push(12);
		a.push(460);
		a.push(460);
		a.push(4580);
		a.push(-1);*/
		for (auto i = 0; i < 150; i++)
		{
			std::cout << a.top() << std::endl;
			a.pop();
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		system("pause");
	}

	//std::priority_queue<int> ab;
	//ab.

	system("pause");
}