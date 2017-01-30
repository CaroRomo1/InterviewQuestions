//
//  main.cpp
//  Q7_Intersection
//
//  Created by Carolina Romo on 1/25/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 2 Question 7
 * Intersection: 
 * Given two (singly) linked lists, determine if the two lists intersect. 
 * Return the intersecting node. Note that the intersection is defined based 
 * on reference, not value. That is, if the kth node of the first linked list 
 * is the exact same node (by reference) as the jth node of the second linked list, 
 * then they are intersecting.
 */

#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;


int listLen(node<int> * head){
    int count = 0;
    while(head) {
        head = head->getNext();
        count++;
    }
    return count;
}

node<int> * intersectionPoint(node<int> *head1, node<int> *head2 ){
    int len1 = listLen(head1);
    int len2 = listLen(head2);
    
    node<int> *ptr1 = (len1 > len2) ? head1 : head2;
    node<int> *ptr2 = (len1 > len2) ? head2 : head1;
    int i = 0;
    
    while (i < abs(len1 - len2) && ptr1) {
        ptr1 = ptr1->getNext();
        i++;
    }

    while(ptr1 && ptr2) {
        if (ptr1->getData() == ptr2->getData()) {
            return ptr1;

        }
        ptr1 = ptr1->getNext();
        ptr2 = ptr2->getNext();
    }
    return NULL;
}


int main() {
    LinkedList<int> list1;
    list1.addFirst(3);
    list1.addLast(6);
    list1.addLast(9);
    list1.addLast(12);
    list1.addLast(15);
    list1.addLast(18);
    
    LinkedList<int> list2;
    list2.addFirst(7);
    list2.addLast(10);
    list2.addLast(12);
    list2.addLast(15);
    list2.addLast(18);

    list1.print();
    list2.print();
    
    node<int> *intersectingNode = intersectionPoint(list1.head , list2.head);
    if (intersectingNode) {
        cout << "Intersecting Node of lists is :" << intersectingNode->data << std::endl;
    } else {
        cout << "Lists do not interset" << std::endl;
    }
    return 0;
}
