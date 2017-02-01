//
//  FixedMultiStack.h
//  Q1_Three_in_One
//
//  Created by Carolina Romo on 1/30/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#ifndef FixedMultiStack_h
#define FixedMultiStack_h

using namespace std;

template <class T>
class FixedMultiStack {
private:
    int numOfStack = 3;
    int stackCapacity;
    int *stackArray;
    int *stackCapacityUsed;
public:
    //Create 3 stacks, each stack is of size stackCapacity.
    FixedMultiStack(int stackSize);
    //Push an element onto stack stackNum, where stackNum is from 0 to 2.
    void push(T stackNum, T value);
    //Pop the top element from stack stackNum, where stackNum is from 0 to 2.
    void pop(T stackNum);
    //Return the top element on stack stackNum, where stackNum is from 0 to 2.
    T top(T stackNum);
    bool isEmpty(T stackNum);
    bool isFull(T stackNum);
    //Return the top index of stack stackNum, where stackNum is from 0 to 2.
    int indexOfTop(T stackNum);
};

template <typename T>
FixedMultiStack<T>::FixedMultiStack(int stackSize){
    stackCapacity = stackSize;
    stackArray = new int[numOfStack * stackCapacity]();
    stackCapacityUsed = new int[numOfStack]();
}

template <typename T>
void FixedMultiStack<T>::push(T stackNum, T value) {
    if(isFull(stackNum))
        cout << "Stack " << stackNum << " is full" << endl;
    else {
        stackCapacityUsed[stackNum]++;
        stackArray[indexOfTop(stackNum)] = value;
    }
}

template <typename T>
void FixedMultiStack<T>::pop(T stackNum) {
    if(isEmpty(stackNum))
        cout << "Stack " << stackNum << " is empty" << endl;
    else {
        int topIndex = indexOfTop(stackNum);
        stackArray[topIndex] = 0;
        stackCapacityUsed[stackNum]--;
    }
}

template <typename T>
T FixedMultiStack<T>::top(T stackNum){
    if(isEmpty(stackNum)) {
        cout << "Stack " << stackNum << " is empty" << endl;
        exit(1); //Or throw an exception.
    }
    else {
        return stackArray[indexOfTop(stackNum)];
    }
}

template <typename T>
bool FixedMultiStack<T>::isEmpty(T stackNum){
    return (stackCapacityUsed[stackNum] == 0);
}

template <typename T>
bool FixedMultiStack<T>::isFull(T stackNum){
    return (stackCapacityUsed[stackNum] == stackCapacity);
}

template <typename T>
int FixedMultiStack<T>::indexOfTop(T stackNum){
    int startIndex = stackNum * stackCapacity;
    int capacity = stackCapacityUsed[stackNum];
    return (startIndex + capacity - 1);
}


#endif /* FixedMultiStack_h */
