//
//  stackWithMin.h
//  Q2_Stack_Min
//
//  Created by Carolina Romo on 1/30/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#ifndef stackWithMin_h
#define stackWithMin_h

#include <stack>

using namespace std;

template <class T>
class stackWithMin{
private:
    
public:
    stack<T> s1, s2;
    stackWithMin();
    void push(T value);
    void pop();
    int min();
    bool empty();
    int top();
};

template <typename T>
stackWithMin<T>::stackWithMin(){
    s2 = *new stack<T>();
}

template <typename T>
void stackWithMin<T>::push(T value){
    if(value <= min()){
        s2.push(value);
    }
    s1.push(value);
}

template <typename T>
void stackWithMin<T>::pop(){
    if(min() == s1.top()){
        s2.pop();
    }
    s1.pop();
}

template <typename T>
int stackWithMin<T>::min(){
    if(s2.empty()){
        return INT_MAX;
    }
    return s2.top();
}

template <typename T>
bool stackWithMin<T>::empty(){
    return s1.empty();
}

template <typename T>
int stackWithMin<T>::top(){
    return s1.top();
}

#endif /* stackWithMin_h */
