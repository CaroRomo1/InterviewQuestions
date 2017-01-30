//
//  MyQueue.h
//  Q4_Queue_via_Stacks
//
//  Created by Carolina Romo on 1/30/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#ifndef MyQueue_h
#define MyQueue_h

#include <stack>

using namespace std;

template <class T>

class MyQueue{
private:
    void shiftStacks();
public:
    stack<int> stackNew, stackOld;
    MyQueue();
    int size();
    void add(T value);
    T peek();
    void remove();

};

template <typename T>
MyQueue<T>::MyQueue(){
    stackNew = *new stack<T>();
    stackOld = *new stack<T>();
}

template <typename T>
int MyQueue<T>::size(){
    return stackNew.size() + stackOld.size();
}

template <typename T>
void MyQueue<T>::add(T value){
    stackNew.push(value);
}

template <typename T>
void MyQueue<T>::shiftStacks(){
    if (stackOld.empty()){
        while (!(stackNew.empty())){
            stackOld.push(stackNew.top());
            stackNew.pop();
        }
    }
}

template <typename T>
T MyQueue<T>::peek(){
    shiftStacks();
    return stackOld.top();
    
}

template <typename T>
void MyQueue<T>::remove(){
    shiftStacks();
    stackOld.pop();
}


#endif /* MyQueue_h */
