#include <iostream>
#include "PrQueue.h"

int main()
{
	try {
		pr_queue <unsigned int> a;
		for (auto i = 0; i < 15; i++)
		{
			a.enqueue(-12);
		}
		/*a.enqueue(-457);
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(2);
		a.enqueue(4);
		a.enqueue(6);
		a.enqueue(8);
		a.enqueue(8);
		a.enqueue(9);
		a.enqueue(0);
		a.enqueue(12);
		a.enqueue(460);
		a.enqueue(460);
		a.enqueue(4580);
		a.enqueue(-1);*/
		for (auto i = 0; i < 15; i++)
		{
			std::cout << a.top() << std::endl;
			a.dequeue();
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		system("pause");
		exit(1);
	}

	system("pause");
}