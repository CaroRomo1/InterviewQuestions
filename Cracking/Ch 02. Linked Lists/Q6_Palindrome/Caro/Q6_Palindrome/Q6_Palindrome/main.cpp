//
//  main.cpp
//  Q6_Palindrome
//
//  Created by Carolina Romo on 1/22/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*  
 * Cracking the coding interview edition 6
 * Chapter 2 Question 6
 * Palindrome: 
 * Implement a function to check if a linked list is a palindrome.
 */

#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

node<int> *reverseAndClone(node<int> *n){
    if(n == NULL || n->getNext() == NULL){
        return NULL;
    }
    
    node<int> *head = NULL;

    while(n != NULL){
        node<int> *aux = new node<int>(n->getData());
        aux->setNext(head);
        head = aux;
        n = n->getNext();
    }
    return head;
}

bool isEqual(node<int> *one, node<int> *two){
    while (one != NULL && two != NULL){
        if (one->getData() != two->getData()){
            return false;
        }
        one = one->getNext();
        two = two->getNext();
    }
    return (one == NULL && two == NULL);
}

bool isPalindrome(node<int> *head){
    node<int> reversed = *reverseAndClone(head);
    return isEqual(head, &reversed);
}


int main() {
    LinkedList<int> list1;
    
    list1.addFirst(1);
    list1.addLast(2);
    list1.addLast(2);
    list1.addLast(1);
    
    list1.print();
    if (isPalindrome(list1.head)){
        cout << "Is PALINDROME" << endl;
    }
    else {
        cout << "Is NOT PALINDROME" << endl;
    }
    
    LinkedList<int> list2;
    list2.addFirst(1);
    list2.addLast(2);
    list2.addLast(3);
    
    list2.print();
    if (isPalindrome(list2.head)){
        cout << "Is PALINDROME" << endl;
    }
    else {
        cout << "Is NOT PALINDROME" << endl;
    }
    
    
    return 0;
}
