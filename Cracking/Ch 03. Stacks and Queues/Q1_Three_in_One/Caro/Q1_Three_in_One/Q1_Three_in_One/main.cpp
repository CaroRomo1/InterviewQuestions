//
//  main.cpp
//  Q1_Three_in_One
//
//  Created by Carolina Romo on 1/29/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//


/*
 * Cracking the coding interview edition 6
 * Chapter 3 Question 1
 * Three in One: 
 * Describe how you could use a single array to implement three stacks.
 */

#include <iostream>
#include <stack>
#include "FixedMultiStack.h"

using namespace std;

int main() {
    FixedMultiStack<int> multiStack(900);
    
    for(int i = 0; i < 10; i++){
        multiStack.push(0, i);
    }
    
    for(int i = 10; i < 20; i++){
        multiStack.push(1, i);
    }
    
    for(int i = 100; i < 110; i++){
        multiStack.push(2, i);
    }
    
    for(int i = 0; i < 3; i++){
        cout << multiStack.top(i) << " ";
    }
    
    cout << endl;
    
    for(int i = 0; i < 3; i++){
        multiStack.pop(i);
        cout << multiStack.top(i) << " ";
    }
    
    cout << endl;
    
    multiStack.push(0, 111);
    multiStack.push(1, 222);
    multiStack.push(2, 333);
    for(int i = 0; i < 3; i++){
        cout << multiStack.top(i) << " ";
    }
   
    cout << endl;
    
    return 0;
}
