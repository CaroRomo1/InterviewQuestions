#include <iostream>
#include "node.h"
#include "LinkedList.h"
#include <stack>

using namespace std;

int main()
{
	LinkedList<int> *lista1 = new LinkedList<int>();
	LinkedList<int> *lista2 = new LinkedList<int>();

	lista1->addFirst(1);
	lista1->addFirst(2);
	lista1->addFirst(3);
	lista1->addFirst(4);
	lista1->addFirst(5);
	lista1->addFirst(6);

	cout << "Lista 1:" << endl;
	lista1->print();

	cout << endl;

	if (lista1->isPalindrome())
	{
		cout << "Lista 1 es palindrome" << endl;
	}
	else
	{
		cout << "Lista 1 no es palindrome" << endl;
	}

	cout << endl;

	lista2->addFirst(2m);
	lista2->addFirst(2);
	lista2->addFirst(3);
	lista2->addFirst(2);
	lista2->addFirst(1);

	cout << "Lista 2:" << endl;
	lista2->print();

	cout << endl;

	if (lista2->isPalindrome())
	{
		cout << "Lista 2 es palindrome" << endl;
	}
	else
	{
		cout << "Lista 2 no es palindrome" << endl;
	}

	cout << endl;

	system("pause");

}