#include <iostream>
#include "../../../Carlos LL/node.h"
#include "../../../Carlos LL/LinkedList.h"

using namespace std;

template <typename T>
node<T>* kthElement(node<T> *head, int k, int &i)
{
	if (head == NULL)
	{
		return NULL;
	}
	node<T>* nd = kthElement(head->getNext(), k, i);

	i++;
	if (i == k)
	{
		return head;
	}

	return nd;
}

template <typename T>
node<T>* kthElement(node<T> *head, int k)
{
	int i = 0;
	return kthElement(head, k, i);
}

int main()
{
	LinkedList<int> lista1;
	LinkedList<int> lista2;

	lista1.addFirst(9);
	lista1.addFirst(5);
	lista1.addFirst(2);
	lista1.addFirst(1);
	lista1.addFirst(2);
	lista1.addFirst(6);

	cout << "Lista 1:" << endl;
	lista1.print();
	cout << endl;

	int k;
	cout << "k = "; 
	cin >> k;
	cout << endl;

	//node<int>* kNode = kthElement(lista1.getHead(), k);
	node<int>* kNode = lista1.kthElement(k);

	cout <<  "El elemento " << k << " es: " << kNode->getData();
	cout << endl;

	system("pause");

}