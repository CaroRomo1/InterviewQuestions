#include <iostream>
#include "../../../Carlos LL/node.h"
#include "../../../Carlos LL/LinkedList.h"

using namespace std;

//template <typename T>
//node<T>* partition(node<T> *nodo, int x)
//{
//	node<T>* lowStart = NULL;
//	node<T>* lowEnd = NULL;
//	node<T>* highStart = NULL;
//	node<T>* highEnd = NULL;
//
//	while (nodo != NULL)
//	{
//		node<T>* next = nodo->getNext();
//		nodo->setNext(NULL);
//
//		if (x > nodo->getData())
//		{
//			if (lowStart == NULL)
//			{
//				lowStart = nodo;
//				lowEnd = lowStart;
//			}
//			else
//			{
//				lowEnd->setNext(nodo);
//				lowEnd = nodo;
//			}
//		}
//		else
//		{
//			if (highStart == NULL)
//			{
//				highStart = nodo;
//				highEnd = highStart;
//			}
//			else
//			{
//				highEnd->setNext(nodo);
//				highEnd = nodo;
//			}
//		}
//
//		nodo = next;
//	}
//
//	if (lowStart == NULL)
//	{
//		return highStart;
//	}
//
//	lowEnd->setNext(highStart);
//	return lowStart;
//}

int main()
{
	LinkedList<int> lista1;
	LinkedList<int> lista2;

	int x;
	cout << "x: ";
	cin >> x;

	cout << endl;

	lista1.addFirst(1);
	lista1.addFirst(2);
	lista1.addFirst(10);
	lista1.addFirst(5);
	lista1.addFirst(8);
	lista1.addFirst(5);
	lista1.addFirst(3);

	cout << "Lista 1:" << endl;
	lista1.print();
	cout << endl;

	//node<int>* parted = partition(lista1.getHead(), x);

	/*while (parted != NULL)
	{
		cout << parted->getData() << " -> ";
		parted = parted->getNext();
	}*/

	lista1.partition(x);

	cout << "Lista Sorted:" << endl;
	lista1.print();
	cout << endl;

	system("pause");

}