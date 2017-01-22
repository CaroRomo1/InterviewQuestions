//
//  main.cpp
//  Q3_Delete_Middle_Node
//
//  Created by Carolina Romo on 1/20/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 2 Question 3
 * Delete Middle Node: 
 * Implement an algorithm to delete a node in the middle 
 * (Le., any node but the first and last node, not necessarily the exact middle) 
 * of a singly linked list, given only access to that node.
 *
 *      EXAMPLE
 *      Input: the node c from the linked list a- >b- >c - >d - >e- >f
 *      Result: nothing is returned, but the new linked list looks like a->b->d->e->f
 */

#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

bool deleteMiddleNode(node<int> *middleNode) {
    if (middleNode == NULL || middleNode->next == NULL) {
        return false;
    }
    
    node<int> *nextNode = middleNode->getNext();
    middleNode->setData(nextNode->getData());
    middleNode->setNext(nextNode->getNext());
    nextNode->~node();
    
    return true;
}

int main() {
    LinkedList<int> list1;
    
    list1.addFirst(rand() % 7);
    int length = rand() % 5;
    for (int i = 0; i < length; ++i ) {
        list1.addLast(rand() % 10);
    }
    
    list1.print();
    if (deleteMiddleNode(list1.head->getNext())){
        cout << "Middle node eliminated" << endl;
        list1.print();
    }
    else {
        cout << "Middle node NOT eliminated" << endl;
        list1.print();
    }
    
    
    return 0;
}
