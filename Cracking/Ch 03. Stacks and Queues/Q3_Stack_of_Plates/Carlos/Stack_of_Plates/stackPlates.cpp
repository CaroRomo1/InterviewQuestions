#include <iostream>

using namespace std;

#include "node.h"
#include "SetsOfStacks.h"

int main()
{
	SetsOfStacks<int> test(3);

	for (int i = 0; i < 10; i++)
	{
		test.push(i);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << test.pop() << endl;
	}

	cout << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		test.push(i);
	}

	test.popAt(2);
	test.popAt(1);
	test.popAt(2);

	for (int i = 0; i < 7; i++)
	{
		cout << test.pop() << endl;
	}


	system("pause");
}