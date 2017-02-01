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
#include "stackWithMin.h"

using namespace std;

int main(){
    stackWithMin<int> myStack;
    
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
