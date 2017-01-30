template <class T>
class myQueue
{
private:
	void shiftStacks();

public:
	myQueue();
	int size();
	void add(T value);
	T peek();
	T remove();
	stack<T> stackNew, stackOld;
};

template<typename T>
myQueue<T>::myQueue()
{
	stackNew = *new stack<T>();
	stackOld = *new stack<T>();
}

template<typename T>
int myQueue<T>::size()
{
	return stackNew.size() + stackOld.size();
}

template<typename T>
void myQueue<T>::add(T value)
{
	stackNew.push(value);
}

template<typename T>
void myQueue<T>::shiftStacks()
{
	if (stackOld.empty())
	{
		while (!stackNew.empty())
		{
			stackOld.push(stackNew.top());
			stackNew.pop();
		}
	}
}

template<typename T>
T myQueue<T>::peek()
{
	shiftStacks();
	return stackOld.top();
}

template<typename T>
T myQueue<T>::remove()
{
	shiftStacks();
	if (!stackOld.empty())
	{
		T value = stackOld.top();
		stackOld.pop();
		return value;
	}
	else
	{
		return -1;
	}
	
}


