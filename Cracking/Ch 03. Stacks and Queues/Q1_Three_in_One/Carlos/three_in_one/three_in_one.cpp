#include <iostream>

using namespace std;

class FixedMultiStack
{
public:
	FixedMultiStack(int stackSize);
	//~FixedMultiStack();
	void push(int val, int num);
	void pop(int num);
	int top(int num);
	bool isEmpty(int num);
	bool isFull(int num);
	int getSize(int num);
	int topIndex(int num);

private:
	int stackNumber = 3;
	int stackCapacity;
	int *sizes;
	int *value;
};

FixedMultiStack::FixedMultiStack(int stackSize)
{
	stackCapacity = stackSize;
	value = new int[stackSize*stackNumber]();
	sizes = new int[stackNumber]();
}

//FixedMultiStack::~FixedMultiStack()
//{
//		delete sizes;
//
//		delete value;
//
//}

void FixedMultiStack::push(int num, int val)
{
	if (isFull(num))
	{
		cout << "El stack " << num << "esta lleno." << endl;
	}
	else
	{
		sizes[num]++;
		value[topIndex(num)] = val;
	}
}

void FixedMultiStack::pop(int num)
{
	if (isEmpty(num))
	{
		cout << "El stack " << num << " esta vacio." << endl;
	}
	else
	{
		value[topIndex(num)] = 0;
		sizes[num]--;
	}
}

int FixedMultiStack::top(int num)
{
	if (isEmpty(num))
	{
		cout << "El stack " << num << " esta vacio." << endl;
		exit(1);
	}
	else
	{
		return value[topIndex(num)];
	}
}

bool FixedMultiStack::isEmpty(int num)
{
	return (sizes[num] == 0);
}

bool FixedMultiStack::isFull(int num)
{
	return (sizes[num] == stackCapacity);
}

int FixedMultiStack::topIndex(int num)
{
	int offset = num * stackCapacity;
	int size = sizes[num];
	return (offset + size - 1);
}

int FixedMultiStack::getSize(int num)
{
	return sizes[num];
}

int main()
{
	FixedMultiStack multiStack(900);

	for (int i = 0; i < 10; i++) {
		multiStack.push(0, i);
	}

	for (int i = 10; i < 20; i++) {
		multiStack.push(1, i);
	}

	for (int i = 100; i < 110; i++) {
		multiStack.push(2, i);
	}

	for (int i = 0; i < 3; i++) {
		cout << multiStack.top(i) << " ";
	}

	cout << endl;

	for (int i = 0; i < 3; i++) {
		multiStack.pop(i);
		cout << multiStack.top(i) << " ";
	}

	cout << endl;

	multiStack.push(0, 111);
	multiStack.push(1, 222);
	multiStack.push(2, 333);
	for (int i = 0; i < 3; i++) {
		cout << multiStack.top(i) << " ";
	}

	cout << endl;

	system("pause");

	return 0;
}