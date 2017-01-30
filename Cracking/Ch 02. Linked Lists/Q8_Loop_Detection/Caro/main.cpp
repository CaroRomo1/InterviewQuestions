//
//  main.cpp
//  Q8_Loop_Detection
//
//  Created by Carolina Romo on 1/25/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 2 Question 8
 * Loop Detection: 
 * Given a circular linked list, implement an algorithm that 
 * returns the node at the beginning of the loop.
 */

#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;


void removeLoop(node<int> * loopNode, node<int> * h){
    node<int> * ptr1 = h;
    node<int> * ptr2 = loopNode;
    while (ptr1 != ptr2) {
        ptr1 = ptr1->getNext();
        ptr2 = ptr2->getNext();
    }
    ptr2->setNext(NULL);
}

node<int> *findBeginning(node<int> * h) {
    node<int> * slow = h;
    node<int> * fast = h;
    while (fast != NULL && fast->getNext() != NULL) {

        slow = slow->getNext();
        fast = fast->getNext()->getNext();
        //        cout << i++ << endl;
        if (slow == fast) {
            removeLoop(slow, h);
            break;
            
        }
    }

    slow = h;
    while (slow != fast) {
        slow = slow->getNext();
        fast = fast->getNext();
        //cout << k++ << endl;
    }
    
    return fast;
}

int main() {
    
    LinkedList<int> list1;
    list1.addLast(7);
    list1.addLast(1);
    list1.addLast(2);
    list1.addLast(3);
    list1.addLast(6);
    
    list1.print();
    
    list1.head->getNext()->getNext()->getNext()->getNext()->setNext(list1.head->getNext()->getNext());
    cout << "Loop starts in: " << (findBeginning(list1.head))->getData() << endl;
    
    list1.deleteAll();
    return 0;
}
