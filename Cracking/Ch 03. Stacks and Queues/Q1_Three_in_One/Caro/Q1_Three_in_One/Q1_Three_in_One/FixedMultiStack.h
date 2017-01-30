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

template <typename T>
class FixedMultiStack {
private:
    int numberOfStacks 3;
    int stackCapacity;
    int[] values;
    int[] sizes;
public:
    FixedMultiStack(int stackSize);
    void push(T stackNum, T value);
    T pop(T stackNum);
    T peek(T stackNum);
    bool isEmpty(T stackNum);
    bool isFull(T stackNum);
    int indexOfTop(T stackNum);
};

template <T>
FixedMultiStack<T>::FixedMultiStack(int stackSize){
    stackCapacity = stackSize;
    values = new int[stackSize * numberOfStacks];
    sizes = new int[numberOfStacks];
}

template <T>
void FixedMultiStack<T>::push(int stackNum, int value) throws FullStackException {
    /* Check that we have space for the next element */ i f (iSFull(stackNum) {
        throw new FullStackException();


#endif /* FixedMultiStack_h */
