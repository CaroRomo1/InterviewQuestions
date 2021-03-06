template <class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void addFirst(T data);
	void addLast(T data);
	bool add(T data, int pos);
	void deleteFirst();
	void deleteLast();
	bool del(int pos);
	int  deleteAll();
	bool isEmpty();
	bool change(int pos1, int pos2);
	void impares();
	void EliminaImpares();
	T get(int pos);
	T Set(T data, int pos);
	void print();

	void Reverse();
	void shift(int c);
	void spin(int num);
	bool operator==(LinkedList<T> lista);
	void operator+=(T dato);
	void operator+=(LinkedList<T> lista);
	LinkedList(const LinkedList<T>& lista);
	void operator=(LinkedList<T> lista);

	bool isPalindrome();


private:
	node<T> *head;
	int iC;
	void borra();
};

template <typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	iC = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	borra();
}


template <typename T>
bool LinkedList<T>::isEmpty()
{
	return (head == NULL);
}

template <typename T>
void LinkedList<T>::addFirst(T data)
{
	head = new node<T>(data, head);
	iC++;
}

template <typename T>
void LinkedList<T>::addLast(T data)
{
	if (this->isEmpty())
	{
		addFirst(data);
	}
	else
	{
		node<T> *aux = head;
		while (aux->getNext() != NULL)
		{
			aux = aux->getNext();
		}
		aux->setNext(new node<T>(data));
		iC++;
	}
}

template <typename T>
bool LinkedList<T>::add(T data, int pos)
{
	if (pos < 0 || pos > iC)
	{
		return false;
	}

	if (pos == 0)
	{
		addFirst(data);
	}

	else if (pos == iC)
	{
		addLast(data);
	}
	else
	{
		node<T> *aux = head;
		for (int iA = 1; iA < pos; iA++)
		{
			aux = aux->getNext();
		}
		aux->setNext(new node<T>(data, aux->getNext()));
		iC++;
	}
	return true;
}


template <typename T>
void LinkedList<T>::deleteFirst()
{
	if (!this->isEmpty())
	{
		node<T> *aux = head;
		head = head->getNext();
		delete aux;
		iC--;
	}
}

template <typename T>
void LinkedList<T>::deleteLast()
{
	if (this->iC <= 1)
	{
		this->deleteFirst();
	}

	else
	{
		node<T> *aux = head;
		while (aux->getNext()->getNext() != NULL)
		{
			aux = aux->getNext();
		}
		delete aux->getNext();
		aux->setNext(NULL);
		iC--;
	}
}

template <typename T>
bool LinkedList<T>::del(int pos)
{
	if (pos < 0 || pos >= iC)
	{
		return false;
	}

	if (pos == 0)
	{
		deleteFirst();
	}

	else if (pos == iC - 1)
	{
		deleteLast();
	}

	else
	{
		node<T> *aux = head;
		for (int iA = 1; iA < pos; iA++)
		{
			aux = aux->getNext();
		}
		node<T> *aux2 = aux->getNext();
		aux->setNext(aux->getNext()->getNext());
		delete aux2;
		iC--;
	}
	return true;
}

template <typename T>
void LinkedList<T>::borra()
{
	node<T> *aux = head;
	while (head != NULL)
	{
		head = head->getNext();
		delete aux;
		aux = head;
	}
}

template <typename T>
int LinkedList<T>::deleteAll()
{
	borra();
	int cuantos = iC;
	iC = 0;
	return cuantos;
}

template <typename T>
bool LinkedList<T>::change(int primero, int segundo)
{
	if (primero < 0 || primero >= iC || segundo < 0 || segundo >= iC)
	{
		return false;
	}
	if (primero == segundo)
	{
		return true;
	}
	int posmenor = (primero < segundo) ? primero : segundo;
	int posmayor = (primero > segundo) ? primero : segundo;

	node<T> *aux1 = head;
	for (int iA = 1; iA <= posmenor; iA++)
	{
		aux1 = aux1->getNext();
	}

	node<T> *aux2 = head;
	for (int iA = posmenor; iA <= posmayor; iA++)
	{
		aux2 = aux2->getNext();
	}

	T temp = aux1->getData();
	aux1->setData(aux2->getData());
	aux2->setData(temp);
	return true;
}

template <typename T>
T LinkedList<T>::get(int pos)
{
	if (pos < 0 || pos > iC)
	{
		return -1;
	}
	else
	{
		node<T> *aux = head;
		for (int iA = 0; iA < pos; iA++)
		{
			aux = aux->getNext();
		}
		return aux->getData();
	}
}

template <typename T>
T LinkedList<T>::Set(T data, int pos)
{
	if (pos < 0 || pos >= iC)
	{
		return -1;
	}

	else
	{
		node<T> *aux = head;
		for (int iA = 0; iA < pos; iA++)
		{
			aux = aux->getNext();
		}
		T auxData = aux->getData();
		aux->setData(data);
		return auxData;
	}
}

template<typename T>
void LinkedList<T>::print()
{
	node<T> *aux = head;
	cout << "INICIO ";
	while (aux != NULL)
	{
		cout << aux->getData() << " ";
		aux = aux->getNext();
	}
	cout << "FIN" << endl;
}

template<typename T>
void LinkedList<T>::impares()
{
	node<T> *aux;
	node<T> *aux2;
	int num;
	if (iC % 2 == 0)
	{
		num = iC / 2;
	}
	else
	{
		num = (iC / 2) + 1;
	}

	for (int i = 1; i <= num; i++)
	{
		if (i == 1)
		{
			aux = head;
			head = head->getNext();
			delete aux;
			iC--;
		}
		else
		{
			aux = head;
			for (int j = 1; j<i - 1; j++)
			{
				aux = aux->getNext();
			}
			aux2 = aux->getNext();
			aux->setNext(aux->getNext()->getNext());
			delete aux2;
			iC--;
		}
	}

}

//template <typename T>
//void LinkedList<T>::EliminaImpares()
//{
//    node<T> *aux=head;
//    node<T> *aux2;
//    for (int iA = 1; iA <= iC; iA+=2)
//    {
//        if (iA == 1)
//        {
//            head = aux->getNext();
//            delete aux;
//        }
//        else
//        {
//            if(iA==2)
//            {
//                aux= head;
//            }
//            else
//            {
//                aux= aux->getNext();
//            }
//            aux2 = aux->getNext();
//            aux->setNext(aux->getNext()->getNext());
//            delete aux2;
//        }
//
//    }
//}

template <typename T>
void LinkedList<T>::Reverse()
{
	node<T>* aux = head;
	node<T>* aux2 = NULL;
	node<T>* aux3;
	while (aux != NULL)
	{
		aux3 = aux->getNext();
		aux->setNext(aux2);
		aux2 = aux;
		aux = aux3;
	}
	head = aux2;
}

template <typename T>
void LinkedList<T>::shift(int c)
{
	if (c == 0) {
		return;
	}
	c = (c % iC + iC) % iC;
	node<T> *aux1, *aux2, *aux3;
	aux1 = head;
	aux2 = aux1;
	for (int i = 0; i<c; i++) {
		aux2 = aux2->getNext();
	}
	head = aux2;
	aux3 = aux2;
	while (aux3->getNext() != NULL) {
		aux3 = aux3->getNext();
	}
	aux3->setNext(aux1);
	for (int i = 0; i< c - 1; i++) {
		aux1 = aux1->getNext();
	}
	aux1->setNext(NULL);
}

template <typename T>
void LinkedList<T>::spin(int num)
{

}

template <typename T>
bool LinkedList<T>::operator==(LinkedList<T> lista)
{
	node<T>* aux = head;
	node<T>* aux2 = lista.head;
	bool iguales = true;

	while (aux != NULL)
	{
		if (aux->getData() != aux2->getData())
		{
			iguales = false;
		}
	}

	return iguales;

}

template <typename T>
void LinkedList<T>::operator+=(T dato)
{
	addLast(dato);
}

template <typename T>
void LinkedList<T>::operator+=(LinkedList<T> lista) //Por alguna razon copia el valor de miLista a Lista2
{
	node<T>* aux = lista.head;
	for (int i = 1; i <= lista.iC; i++)
	{
		addLast(aux->getData());
		aux = aux->getNext();
	}
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& lista)
{
	iC = lista.iC;
	node<T>* aux = head;
	node<T>* aux2 = lista.head;
	for (int i = 1; i <= iC; i++)
	{
		aux->setNext(new node<T>(aux2->getData()));
		aux2 = aux2->getNext();
	}
}

template <typename T>
void LinkedList<T>::operator=(LinkedList<T> lista)
{
	iC = lista.iC;
	node<T>* aux = head;
	node<T>* aux2 = lista.head;
	for (int i = 1; i <= iC; i++)
	{
		aux->setNext(new node<T>(aux2->getData()));
		aux2 = aux2->getNext();
	}
}

template <typename T>
bool LinkedList<T>::isPalindrome()
{
	node<T>* fast = head;
	node<T>* slow = head;

	stack<int> pila;

	while (fast != NULL && fast->getNext() != NULL)
	{
		pila.push(slow->getData());
		slow = slow->getNext();
		fast = fast->getNext()->getNext();
	}

	if (fast != NULL)
	{
		slow = slow->getNext();
	}

	while (slow != NULL)
	{
		int top = pila.top();
		pila.pop();

		if (slow->getData() != top)
		{
			return false;
		}
		slow = slow->getNext();
	}
	return true;
}
