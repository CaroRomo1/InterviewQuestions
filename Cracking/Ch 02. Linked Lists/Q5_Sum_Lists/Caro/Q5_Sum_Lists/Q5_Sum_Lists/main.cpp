//
//  main.cpp
//  Q5_Sum_Lists
//
//  Created by Carolina Romo on 1/22/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//



/*
 * Sum Lists: 
 * You have two numbers represented by a linked list, where each node 
 * contains a single digit. The digits are stored in reverse order, 
 * such that the 1's digit is at the head of the list. 
 * Write a function that adds the two numbers and returns the sum as a linked list.
 *      EXAMPLE 
 *      Input: (7-> 1 -> 6) + (5 -> 9 -> 2) .
 *      That is, 617 + 295.
 *      Output: 2 -> 1 -> 9. That is,912.
*/

#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

/// Print list method, when getting node
void printList(node<int> * head ) {
    while ( head ) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}


node<int> * sumListIterative(node<int> *list1, node<int> *list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    
    // List3 will store result
    LinkedList<int> list3;
    
    // For adding new nodes to tail of list3
    node<int> *list3Tail = NULL;
    
    int value = 0, carry = 0;
    
    // While at least one list has values
    while(list1 || list2) {
        // Add the values, if one of the list has already been traversed, add 0
        value = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
        
        // Get the new value and carry
        if (value > 9) {
            carry = 1;
            value = value % 10;
        }
        else {
            carry = 0;
        }
        
        // New node with value
        node<int>  *temp = new node<int>(value);
        
        // If this is the first node, populate the result, else add to the tail
        if (list3.isEmpty()) {
            list3.addFirst(value);
        }
        else {
            list3Tail->setNext(temp);
        }
        
        // Make new tail
        list3Tail = temp;
        
        if (list1) {
            list1 = list1->next;
        }
        
        if (list2) {
            list2 = list2->next;
        }
    }
    
    if (carry > 0) {
        list3Tail->next = new node<int>(carry);
    }
    return list3.head;
}


node<int> *sumListRecursive(node<int> * list1, node<int> * list2, int carry) {
    if (list1 == NULL && list2 == NULL && carry == 0) {
        return NULL;
    }
    int value = carry;
    if (list1) {
        value += list1->data;
    }
    if (list2) {
        value += list2->data;
    }
    
    node<int> * resultNode = new node<int>(value % 10 );
    
    resultNode->next = sumListRecursive(list1 ? (list1->next) : NULL,
                                     list2 ? (list2->next) : NULL,
                                     value > 9 ? 1 : 0 );
    return resultNode;
}

/* 
 *      FOLLOW UP
 *      Suppose the digits are stored in forward order.
 *      Repeat the above problem.
 *      Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).
 *      That is, 617 + 295.
 *      Output:9 -> 1 -> 2. That is,912.
 */

void padList(node<int> * &list, int padding) {
    for (int i = 0; i < padding; ++i ) {
        list->setNext(0);
    }
}


int length(node<int> * head ) {
    int len = 0;
    while( head ) {
        len++;
        head = head->next;
    }
    return len;
}

node<int> *sumHelper(node<int> * list1, node<int> * list2, int &carry) {
    if (list1 == NULL && list2 == NULL && carry == 0) {
        return nullptr;
    }
    
    node<int> * result = sumHelper(list1 ? (list1->next) : nullptr,
                                        list2 ? (list2->next) : nullptr,
                                        carry);
    
    int value = carry + (list1 ? list1->data : 0 ) + (list2 ? list2->data : 0);
    node<int> * resultNode = new node<int>(value % 10 );
    result->setNext(resultNode);
    carry = (value > 9 ) ? 1 : 0;
    return result;
}

node<int>  *addMethod2(node<int>  *list1,node<int>  * list2 ) {
    int len1 = length(list1);
    int len2 = length(list2);
    
    //pad the smaller list
    if (len1 > len2 ) {
        padList(list2, len1 - len2 );
    } else {
        padList(list1, len2 - len1 );
    }
    int carry = 0;
    node<int>  * list3 = sumHelper(list1, list2, carry);
    if (carry) {
        node<int> * resultNode = new node<int>(carry);
        list3->setNext(resultNode);
    }
    return list3;
}

int main() {
    // List 1 for number 617
    LinkedList<int> list1;
    list1.addLast(6);
    list1.addLast(1);
    list1.addLast(7);
    cout << "List 1:  ";
    list1.print();
    
    // List2 for number 295
    LinkedList<int> list2;
    list2.addLast(2);
    list2.addLast(9);
    list2.addLast(5);
    cout << "List 2:  ";
    list2.print();
    
    node<int> list3 = *sumListIterative(list1.head, list2.head);
    cout << "Iterative Solution: " << endl;
    cout << "List 3:  ";
    printList(&list3);
    
    node<int> list4 = *sumListRecursive(list1.head, list2.head, 0);
    cout << "Recursive Solution: " << endl;
    cout << "List 4:  ";
    printList(&list4);
    

    cout << "Follow up case" << endl;
    cout << "List 1:  ";
    list1.print();

    cout << "List 2:  ";
    list2.print();
    
    list3 = *addMethod2(list1.head, list2.head);
    cout << "Adding two above lists\n";
    cout << "List3:  ";
    printList(&list3);

    return 0;
}

