#include <iostream>
#include "../../../Carlos LL/node.h"
#include "../../../Carlos LL/LinkedList.h"

using namespace std;

int main()
{
	LinkedList<char> lista1;
	LinkedList<char> lista2;

	lista1.addLast('a');
	lista1.addLast('b');
	lista1.addLast('c');
	lista1.addLast('d');
	lista1.addLast('e');
	lista1.addLast('f');

	cout << "Lista 1:" << endl;
	lista1.print();
	cout << endl;

	lista1.deleteMiddle();

	cout << "Lista nueva:" << endl;
	lista1.print();
	cout << endl;

	system("pause");

}