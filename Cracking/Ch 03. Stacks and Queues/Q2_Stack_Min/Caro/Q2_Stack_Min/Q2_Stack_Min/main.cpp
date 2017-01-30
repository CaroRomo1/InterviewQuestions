//
//  main.cpp
//  Q2_Stack_Min
//
//  Created by Carolina Romo on 1/29/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//


/*
 * Cracking the coding interview edition 6
 * Chapter 3 Question 2
 * Stack Min: 
 * How would you design a stack which, in addition to push and pop, has a function min
 * which returns the minimum element? Push, pop and min should all operate in 0(1) time.
 */

#include <iostream>
#include <stack>

using namespace std;

class stackWithMin{
private:
    stack<int> s1, s2;
    
public:
    void push(int x){
        s1.push(x);
        if(x <= min()){
            s2.push(x);
        }
    }
    
    void pop(){
        if(min() == s1.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int min(){
        if(s2.empty()){
            return INT_MAX;
        }
        return s2.top();
    }
    
    bool empty(){
        return s1.empty();
    }
    
    int top(){
        return s1.top();
    }
};

int main(){
    stackWithMin myStack;
    
    int arr[] = {6, 3, 5, 2, 2, 9, 2, 8, 1, 1};
    
    for(int i = 0; i < 10; i++){
        myStack.push(arr[i]);
        cout << arr[i] << " " << myStack.min() <<endl;
    }
    
    cout << "Min pop" << endl;
    
    for(int i = 0; i < 9; i++){
        myStack.pop();
        cout << i << " " << myStack.min() <<endl;
    }
    return 0;
}