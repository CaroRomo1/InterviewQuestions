#include <iostream>
#include "../../../Carlos LL/node.h"
#include "../../../Carlos LL/LinkedList.h"

using namespace std;

//template <typename T>
//node<T>* sumList1(node<T>* l1, node<T>* l2, int carrie)
//{
//	if (l1 == NULL && l2 == NULL && carrie == 0)
//	{
//		return NULL;
//	}
//
//	node<T>* sum = new node();
//	int value = carrie;
//	if (l1 != NULL)
//	{
//		value += l1->getData();
//	}
//
//	if (l2 != NULL)
//	{
//		value += l2->getData();
//	}
//
//	sum->setData(value % 10);
//	
//	if (l1 != NULL || l2 != NULL)
//	{
//		node<T>* next = sumList1(
//			l1 == NULL ? NULL : l1->getNext(),
//			l2 == NULL ? NULL : l2->getNext(),
//			value >= 10 ? 1 : 0);
//
//		sum->setNext(next);
//	}
//
//	return sum;
//}

int main()
{
	LinkedList<int> lista1;
	LinkedList<int> lista2;

	lista1.addLast(7);
	lista1.addLast(1);
	lista1.addLast(6);
	lista1.addLast(1);
	lista1.addLast(6);

	cout << "Lista 1:" << endl;
	lista1.print();
	cout << endl;

	lista2.addLast(5);
	lista2.addLast(9);
	lista2.addLast(2);

	cout << "Lista 2:" << endl;
	lista2.print();
	cout << endl;

	LinkedList<int> sumed;

	//sumed.sumedList1(lista1.getHead(), lista2.getHead(), 0);
	sumed.sumedList2(lista2, lista1);

	cout << "Lista sumada:" << endl;
	sumed.print();
	cout << endl;

	system("pause");
}