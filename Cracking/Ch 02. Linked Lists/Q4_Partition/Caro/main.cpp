//
//  main.cpp
//  Q4_Partition
//
//  Created by Carolina Romo on 1/22/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 2 Question 4
 * Partition: 
 * Write code to partition a linked list around a value x, 
 * such that all nodes less than x come before all nodes greater than or equal to x. 
 * If x is contained within the list, the values of x only need to be after the 
 * elements less than x (see below). The partition element x can appear anywhere 
 * in the "right partition"; it does not need to appear between the left and 
 * right partitions.
 *      EXAMPLE
 *      Input: 3 -) 5 -) 8 -) 5 -) 10 -) 2 -) 1[partition=5]
 *      Output: 3 -) 1 -) 2 -) 10 -) 5 -) 5 -) 8
 */

#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

void partition(node<int> * &head, int x){
    
    node<int> *tail = head;
    node<int> *curr = head;
    while(curr != NULL) {
        node<int> *nextNode = curr->next;
        if (curr->data < x) {
            //Insert at head
            curr->next = head;
            head = curr;
        }
        else {
            //Insert at tail
            tail->next = curr;
            tail = curr;
        }
        curr = nextNode;
    }
    tail->next = NULL;
}


int main() {
    
    int p = 0;
    LinkedList<int> list1;
    
    list1.addFirst(rand() % 15);
    int length = rand() % 15;
    for (int i = 0; i < length; ++i ) {
        list1.addLast(rand() % 15);
    }
    
    list1.print();
    cout << "Enter partition number: " << endl;
    cin >> p;
    partition(list1.head, p);
    list1.print();
    
    return 0;
}
