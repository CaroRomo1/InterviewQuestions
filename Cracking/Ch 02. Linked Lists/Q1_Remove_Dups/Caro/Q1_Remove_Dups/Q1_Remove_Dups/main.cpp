//
//  main.cpp
//  Q1_Remove_Dups
//
//  Created by Carolina Romo on 1/19/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 2 Question 1
 * Remove Dups: 
 * Write code to remove duplicates from an unsorted linked list.
 */

#include <iostream>
#include <map>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

// Method 1: Using a hash map, using the number aa key and the boolean to determine if it is duplicated
void removeDuplicate1(node<int> *head){
    map<int,bool> table;
    node<int> *curr = head;
    node<int> *pre = NULL;
    while(curr!=NULL){
        // Delete the node if it already exists in the map
        if(table[curr->data]){
            pre->next = curr->next;
            delete curr;
            curr = pre->next;
        }
        // Add the node to the table if it does not exist in the map before
        else{
            table[curr->data] = true;
            pre = curr;
            curr = curr->next;
        }
    }
}

// Method 2: Withou using any additional buffer (map), using different pointers
void removeDuplicate2(node<int> *head){
    node<int> *curr = head;
    while(curr!=NULL){
        node<int> *runner = curr->next;
        node<int> *pre = curr;
        while(runner!=NULL){
            if(curr->data == runner->data){
                pre->next = runner->next;
                delete runner;
                runner = pre->next;
            }
            else{
                pre = runner;
                runner = runner ->next;
            }
            
        }
        curr = curr->next;
    }
}



int main() {
    
    cout << "Method 1:" << endl;
    LinkedList<int> list1;
    
    list1.addFirst(rand() % 7);
    for (int i = 0; i < 10; ++i ) {
        list1.addLast(rand() % 7);
    }
    
    list1.print();
    removeDuplicate1(list1.head);
    list1.print();
    
    cout << "Method 2:" << endl;;
    LinkedList<int> list2;
    
    list2.addFirst(rand() % 7);
    for (int i = 0; i < 10; ++i ) {
        list2.addLast(rand() % 7);
    }
    
    list2.print();
    removeDuplicate2(list2.head);
    list2.print();
   
    return 0;
}
