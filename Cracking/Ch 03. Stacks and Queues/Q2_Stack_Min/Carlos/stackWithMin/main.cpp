#include <iostream>

using namespace std;

#include "stackWithMin.h"

int main()
{
	stackWithMin<int> mystack = stackWithMin<int>();

	mystack.push(5);
	mystack.push(6);
	mystack.push(7);
	mystack.push(8);

	cout << mystack.min() << " ";
	mystack.pop();
	cout << mystack.min() << " ";
	mystack.pop();					//ERROR
	cout << mystack.min() << " ";
	mystack.pop();
	cout << mystack.min() << " ";
	mystack.pop();

	mystack.push(1);
	mystack.push(2);
	mystack.push(3);
	mystack.push(4);

	cout << endl;

	cout << mystack.min() << " ";
	mystack.pop();
	cout << mystack.min() << " ";
	mystack.pop();
	cout << mystack.min() << " ";
	mystack.pop();
	cout << mystack.min() << " ";
	mystack.pop();

	system("pause");

}