#include "Stack.h"
#include <vector>

#ifndef SetsOfStacks_h
#define SetsOfStacks_h

template <class T>
class SetsOfStacks
{
public:
	vector<Stack<T>*> stacks;
	int capacity;
	SetsOfStacks(int cap);
	Stack<T>* getLastStack();
	void push(T val);
	T pop();
	bool isEmpty();
	T popAt(size_t index);
	T leftShift(size_t index, bool removeTop);

};

template <typename T>
SetsOfStacks<T>::SetsOfStacks(int cap)
{
	capacity = cap;
}

template <typename T>
Stack<T>* SetsOfStacks<T>::getLastStack()
{
	if (stacks.empty())
	{
		return NULL;
	}
	return stacks[stacks.size() - 1];
}

template <typename T>
void SetsOfStacks<T>::push(T val)
{
	Stack<T> *last = getLastStack();

	if (!last == NULL && !last->isFull())
	{
		last->push(val);
	}
	else
	{
		Stack<T> *newLast = new Stack<T>(capacity);
		newLast->push(val);
		stacks.push_back(newLast);
	}
}

template <typename T>
T SetsOfStacks<T>::pop()
{
	Stack<T> *last = getLastStack();
	if (last == NULL)
	{
		return -1;	
	}
	T val = last->pop();
	if (last->isEmpty())
	{
		stacks.pop_back();
	}
	return val;
}

template <typename T>
bool SetsOfStacks<T>::isEmpty()
{
	Stack<T> *last = getLastStack();
	return (last == NULL || last.isEmpty());
}

template <typename T>
T SetsOfStacks<T>::popAt(size_t index)
{
	return leftShift(index, true);
}

template <typename T>
T SetsOfStacks<T>::leftShift(size_t index, bool remove_top)
{
	Stack<T> *stack = stacks[index];
	int rem;
	if (remove_top)
	{
		rem = stack->pop();
	}
	else
	{
		rem = stack->removeBottom();
	}
	if (stack->isEmpty())
	{
		stacks.erase(stacks.begin() + index);
	}
	else if (stacks.size() > (index + 1))
	{
		int val = leftShift(index + 1, false);
		stack->push(val);
	}
	return rem;
}

#endif

