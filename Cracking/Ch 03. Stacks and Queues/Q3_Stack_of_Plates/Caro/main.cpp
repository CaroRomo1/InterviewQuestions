//
//  main.cpp
//  Q3_Stack_of_Plates
//
//  Created by Carolina Romo on 1/29/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 3 Question 3
 * Stack of Plates: 
 * Imagine a (literal) stack of plates. If the stack gets too high, it might topple. 
 * Therefore, in real life, we would likely start a new stack when the previous stack 
 * exceeds some threshold. Implement a data structure SetOfStacks that mimics this. 
 * SetOfStacks should be composed of several stacks and should create a new stack once the
 * previous one exceeds capacity. SetOfStacks. push () and SetOfStacks. pop() 
 * should behave identically to a single stack (that is, pop ( ) 
 * should return the same values as it would if there were just a single stack).
 * 
 * FOLLOW UP
 * Implement a function popAt (int index) which performs a pop operation 
 * on a specific sub- stack.
 */

#include <iostream>
#include <stack>

using namespace std;

class setOfStacks{
private:
    stack<int> *myStack;
    int threshold;
    int curStack;
public:
    setOfStacks(){
        threshold = 10;
        myStack = new stack<int>[100];
        curStack = 0;
    }
    
    void push(int data){
        if(myStack[curStack].size() >= threshold){
            curStack++;
        }
        myStack[curStack].push(data);
    }
    
    void pop(){
        if(myStack[curStack].empty()){
            if(curStack == 0){
                cout << "Stack is empty" << endl;
                return;
            }
            curStack--;
        }
        myStack[curStack].pop();
    }
    
    int top(){
        if(myStack[curStack].empty()){
            if(curStack == 0){
                return -1;
            }
            curStack--;
        }
        return myStack[curStack].top();
    }
    
    bool empty(){
        if(curStack == 0){
            return myStack[curStack].empty();
        }
        else {
            return false;
        }
    }
    /* FOLLOW-UP */
    void popAt(int index){
        if(myStack[index].empty()){
            cout << "sub-stack " << index << " is empty" << endl;
        }
        cout << myStack[index].top() << endl;
        myStack[index].pop();
    }
};

int main(){
    setOfStacks sta;
    
    for(int i = 0; i < 100; i++){
        sta.push(i);
    }
    
    sta.popAt(4);
    sta.popAt(5);
    sta.popAt(2);
    sta.popAt(2);
    
    for(int i = 0; i < 101; i++){
        cout << sta.top() << endl;
        sta.pop();
    }
    return 0;
}
