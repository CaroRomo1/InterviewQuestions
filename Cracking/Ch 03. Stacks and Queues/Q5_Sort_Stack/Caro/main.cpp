//
//  main.cpp
//  Q5_Sort_Stack
//
//  Created by Carolina Romo on 1/31/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 3 Question 5
 * Sort Stack: 
 * Write a program to sort a stack such that the smallest items are on the top. 
 * You can use an additional temporary stack, but you may not copy the elements into 
 * any other data structure (such as an array).The stack supports the following operations:
 * push, pop, peek, and isEmpty.
 */

#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int> *s1){
    stack<int> s2;
    
    while(!(*s1).empty()){
        //Insert each element in s1 in sorted order into s2
        int tmp = (*s1).top();
        
        (*s1).pop();
        
        while(!s2.empty() && tmp > s2.top()){
            (*s1).push(s2.top());
            s2.pop();
        }
        
        s2.push(tmp);
    }
    
    while(!s2.empty()){
        (*s1).push(s2.top());
        s2.pop();
    }
}

int main(){
    stack<int> stackSorted;
    int arr[] = {6, 4, 8, 9, 10, 99, 7, 1, 0};
    
    for(int i = 0; i < 9; i++){
        stackSorted.push(arr[i]);
    }
    
    sortStack(&stackSorted);
    
    while(!stackSorted.empty()){
        cout << stackSorted.top() << endl;
        stackSorted.pop();
    }
   
    return 0;
}
