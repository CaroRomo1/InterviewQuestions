#include <iostream>

using namespace std;

#include "../../../Carlos LL/node.h"

//template <class T>
//class Result
//{
//public:
//	node<T>* tail;
//	int size;
//	Result(node<T>* tail, int size);
//};
//
//template <typename T>
//Result<T>::Result(node<T>* tail, int size)
//{
//	this->tail = tail;
//	this->size = size;
//}

#include "../../../Carlos LL/LinkedList.h"

template <typename T>
node<T>* intersection(LinkedList<T> l1, LinkedList<T> l2)
{
	if ((l1.getHead() == NULL) || (l2.getHead() == NULL))
	{
		return NULL;
	}

	if (l1.getTail() != l2.getTail())
	{
		return NULL;
	}

	LinkedList<T> shrt = l1.getiC() < l2.getiC() ? l1 : l2;
	LinkedList<T> laux = l1.getiC() < l2.getiC() ? l2 : l1;

	LinkedList<T> lng = LinkedList<T>(laux.getKthElement(abs(l1.getiC() - l2.getiC())));

	node<T>* shorter = shrt.getHead();
	node<T>* longer = lng.getHead();

	while (longer != shorter)
	{
		shorter = shorter->getNext();
		longer = longer->getNext();
	}

	return longer;
}

int main()
{
	node<int>* n2 = new node<int>(15);
	node<int>* n1 = new node<int>(16, n2);
	node<int>* head = new node<int>(17, n1);

	LinkedList<int> lista1;

	lista1.addLast(1);
	lista1.addLast(2);
	lista1.addLast(3);
	lista1.addLast(4);
	lista1.addLast(5);
	lista1.addLast(6);

	n2->setNext(lista1.getKthElement(5));

	LinkedList<int> lista2 = LinkedList<int>(head);

	cout << "Lista 1: " << endl;
	lista1.print();
	cout << endl;

	cout << "Lista 2: " << endl;
	lista2.print();
	cout << endl;

	node<int>* com = intersection(lista1, lista2);
	cout << "El nodo comun es: " << com->getData() << endl;
	system("pause");
}
