#include <iostream>

using namespace std;

#include "../../../Carlos LL/node.h"
#include "../../../Carlos LL/LinkedList.h"

template <class T>
struct nodo {
public:
	node<T>* n;
	T dato;
	nodo(node<T>* n, T dato);
};

template <typename T>
nodo<T>::nodo(node<T>* n, T dato)
{
	this->n = n;
	this->dato = dato;
}

template <typename T>
nodo<T> loopDet(node<T>* head)
{
	node<T>* fast = head;
	node<T>* slow = head;

	while (fast != NULL && fast->getNext() != NULL)
	{
		slow = slow->getNext();
		fast = fast->getNext()->getNext();
		if (slow == fast)
		{
			break;
		}
	}

	if (fast == NULL || fast->getNext() == NULL)
	{
		return nodo<T>(NULL, 0);
	}

	slow = head;
	int cont = 1;

	while (slow != fast)
	{
		slow = slow->getNext();
		fast = fast->getNext();
		cont++;
	}

	return nodo<T>(fast, cont);
}

int main()
{
	LinkedList<int> lista1;

	lista1.addLast(4);
	lista1.addLast(2);
	lista1.addLast(6);
	lista1.addLast(8);
	lista1.addLast(3);
	lista1.addLast(6);
	lista1.addLast(9);
	lista1.addLast(0);
	lista1.addLast(1);
	lista1.addLast(0);
	lista1.addLast(21);

	cout << "Lista 1: " << endl;
	lista1.print();
	cout << endl;

	node<int>* nfin = lista1.getTail();

	//nfin->setNext(lista1.getKthElement(2));

	nodo<int> loop = loopDet(lista1.getHead());

	if (loop.n != false)
	{
		cout << "El nodo valor del nodo " << loop.dato << " en donde comienza el ciclo es: " << loop.n->getData() << endl;
	}

	else
	{
		cout << "No existe ciclo" << endl;
	}

	
	system("pause");
}
