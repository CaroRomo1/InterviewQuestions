//
//  main.cpp
//  Q4_Queue_via_Stacks
//
//  Created by Carolina Romo on 1/30/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 3 Question 4
 * Queue via Stacks: 
 * Implement a MyQueue class which implements a queue using two stacks.
 */

#include <iostream>
#include <stack>
#include "MyQueue.h"

using namespace std;

int main() {
    MyQueue<int> q;
    
    q.add(2);
    q.add(3);
    cout << q.peek() << endl;
    q.remove();
    
    q.add(4);
    q.add(5);
    cout << q.peek() << endl;
    q.remove();
    q.remove();
    cout << q.peek() << endl;
    
    
    
    return 0;
}
