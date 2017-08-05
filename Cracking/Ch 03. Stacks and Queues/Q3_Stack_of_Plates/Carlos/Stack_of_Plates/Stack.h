#ifndef Stack_h
#define Stack_h

template <class T>
class Stack
{
public:
	Stack(int cap);
	bool push(T data);
	T pop();
	bool isEmpty();
	bool isFull();
	T removeBottom();
	node<T>* top;
	node<T>* bot;
	int stackSize;

private:
	int capacity;
};

template <typename T>
Stack<T>::Stack(int cap)
{
	stackSize = 0;
	capacity = cap;
}

template <typename T>
bool Stack<T>::push(T data)
{
	if (stackSize >= capacity)
	{
		return false;
	}
	stackSize++;

	if (stackSize == 1)
	{
		bot = new node<T>(data);
		top = bot;
	}
	else
	{
		node<T> *aux = new node<T>(data);
		top->setNext(aux);
		top = aux;
	}
	return true;

}

template <typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		node<T> *aux = top;
		top = bot;
		while ((bot != aux) && (top->getNext() != aux))
		{
			top = top->getNext();
		}
		T val = aux->getData();
		delete aux;
		stackSize--;
		return val;
	}
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return (stackSize == 0);
}

template <typename T>
bool Stack<T>::isFull()
{
	return (stackSize == capacity);
}

template <typename T>
T Stack<T>::removeBottom()
{
	if (!isEmpty())
	{
		node<T> *aux = bot;
		bot = bot->getNext();
		int val = aux->getData();
		delete aux;
		stackSize--;
		return val;
	}
	else
	{
		return -1;
	}
	
}

#endif

