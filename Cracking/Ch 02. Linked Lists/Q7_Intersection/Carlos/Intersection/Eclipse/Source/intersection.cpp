#include <iostream>

using namespace std;

#include "../../../../../Carlos LL/node.h"
#include "../../../../../Carlos LL/LinkedList.h"

template <class T>
class Result
{
public:
	node<T>* tail;
	int size;
	Result(node<T>* tail, int size);
};

template <typename T>
Result<T>::Result(node<T>* tail, int size)
{
	this->tail = tail;
	this->size = size;
}

template <typename T>
Result getTail(node<T>* list)
{
	if(list == NULL)
	{
		return NULL;
	}

	int size = 1;

	node<T>* current = list;

	while(current != NULL)
	{
		current = current->getNext();
		size++;
	}
	return

}

template <typename T>
bool intersection(LinkedList<T> l1, LinkedList<T> l2)
{
	if((l1 == NULL) || (l2 == NULL))
	{
		return NULL;
	}


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

	n2->setNext(lista1.kthElement(3));

	LinkedList<int> lista2 = LinkedList<int>(head);

	cout << "Lista 1:" << endl;
	lista1.print();
	cout << endl;

	cout << "Lista 2:" << endl;
	lista2.print();
	cout << endl;
}
