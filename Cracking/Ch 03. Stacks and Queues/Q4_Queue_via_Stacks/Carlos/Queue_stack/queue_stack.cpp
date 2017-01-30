#include <iostream>
#include <stack>

using namespace std;

#include "myQueue.h"

int main()
{
	myQueue<int> hello;

	hello.add(1);
	hello.add(2);
	hello.add(3);
	hello.add(4);
	hello.add(5);
	hello.add(6);

	cout << hello.remove() << endl;
	cout << hello.remove() << endl;
	cout << hello.remove() << endl;
	cout << hello.remove() << endl;
	cout << hello.remove() << endl;
	cout << hello.remove() << endl;
		
	system("pause");
}

