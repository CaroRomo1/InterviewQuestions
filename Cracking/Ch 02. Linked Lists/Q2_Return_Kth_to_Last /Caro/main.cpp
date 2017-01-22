//
//  main.cpp
//  Q2_Return_Kth_to_Last
//
//  Created by Carolina Romo on 1/20/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

/*
 * Cracking the coding interview edition 6
 * Chapter 2 Question 2
 * Return Kth to Last: 
 * Implement an algorithm to find the kth to last element of a singly linked list.
 */

/*
 * Method 1. Iterative:
 * Use two pointers
 * Move first pointer k places.
 * Now move second pointer(from start) and first pointer (from k+1) simultanously.
 * When second pointer would have reached end, first pointer would be at kth node.
 * This algorithm takes O(n) time and O(1) space.
 */
node<int> *kthToLastIterative(node<int> * head, int k){
    if (head == NULL) {
        return head;
    }
    
    node<int> *ptr1 = head;
    node<int> *ptr2 = head;
    
    for (int i =0; i < k; i++) {
        if (ptr1 == NULL){ // Out of bounds
            return NULL;
        }
        ptr1 = ptr1->next;
    }
    

    while(ptr1 != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return ptr2;
}

/*
 * Method 2. Recursive:
 * Maintain an index to keep track of node.
 * Solve the problem for n-1 nodes and add 1 to index.
 * Since each parent call is adding 1, when counter reaches k,
 * we have reached length-k node from start, which is kth node from last.
 * Takes O(n) space due to the recursive calls.
 */

node<int> *kthToLastHelper(node<int> * head, int k, int &i) {
    if (head == NULL) {
        return NULL;
    }
    
    
node<int> *node = kthToLastHelper(head->next, k, i);
    i = i + 1;
    //If we have solved problem k times from last.
    if (i == k) {
        return head;
    }
    return node;
}


node<int> *kthToLastRecursive(node<int> *head, int k) {
    int i = 0;
    return kthToLastHelper(head, k, i);
}

int main() {
    int k1 = 7, k2 = 2;
    cout << "Method 1:" << endl;
    LinkedList<int> list1;
    
    list1.addFirst(rand() % 7);
    for (int i = 0; i < 10; ++i ) {
        list1.addLast(rand() % 10);
    }
    
    list1.print();
    cout << k1 << " from last:" << endl;
    cout << kthToLastIterative(list1.head, 7)->getData() << endl;
    
    cout << "Method 2:" << endl;
    LinkedList<int> list2;
    
    list2.addFirst(rand() % 7);
    for (int i = 0; i < 10; ++i ) {
        list2.addLast(rand() % 15);
    }
    
    list2.print();
    cout << k2 << " from last:" << endl;
    cout << kthToLastRecursive(list2.head, 2)->getData() << endl;
    
    return 0;
}
