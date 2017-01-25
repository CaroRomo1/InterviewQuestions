#include <iostream>
#include "../../../Carlos LL/node.h"
#include "../../../Carlos LL/LinkedList.h"
#include <map>

using namespace std;

void deleteDups(node<int> *head)
{
	map<int, bool> hash;
	node<int>* act = head;
	node<int>* prev = NULL;

	while (act != NULL)
	{
		if (hash[act->getData()])
		{
			prev->setNext(act->getNext());
			delete act;
			act = prev->getNext();
		}
		else
		{
			hash[act->getData()] = true;
			prev = act;
			act = act->getNext();
		}
	}
}

int main()
{
	LinkedList<int> lista1;
	LinkedList<int> lista2;

	lista1.addFirst(1);
	lista1.addFirst(1);
	lista1.addFirst(1);
	lista1.addFirst(2);
	lista1.addFirst(2);
	lista1.addFirst(7);

	cout << "Lista 1:" << endl;
	lista1.print();

	cout << endl;

	lista1.deleteDups();

	cout << endl;

	cout << "Lista 1 Mod:" << endl;
	lista1.print();

	cout << endl;

	lista2.addFirst(2);
	lista2.addFirst(2);
	lista2.addFirst(3);
	lista2.addFirst(2);
	lista2.addFirst(3);

	cout << "Lista 2:" << endl;
	lista2.print();

	cout << endl;

	deleteDups(lista2.getHead());

	cout << endl;

	cout << "Lista 2 Mod:" << endl;
	lista2.print();

	cout << endl;

	system("pause");

}