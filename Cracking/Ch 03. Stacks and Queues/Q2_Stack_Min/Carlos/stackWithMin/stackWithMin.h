#ifndef stackWithMin_h
#define stackWithMin_h
#include <stack>

using namespace std;

template <class T>
class stackWithMin
{
private:
	stack<T> s1, s2;

public:
	stackWithMin();
	void push(T val);
	void pop();
	int min();

};

template <typename T>
stackWithMin<T>::stackWithMin()
{
	s2 = *new stack<T>();
}

template <typename T>
void stackWithMin<T>::push(T val)
{
	if (val <= min())
	{
		s2.push(val);
	}

	s1.push(val);
}

template <typename T>
void stackWithMin<T>::pop()
{
	if (s1.top() == min())
	{
		s2.pop();
	}
	s1.pop();
}

template <typename T>
int stackWithMin<T>::min()
{
	if (s2.empty())
	{
		return INT_MAX;
	}
	else
	{
		return s2.top();
	}
}

#endif 