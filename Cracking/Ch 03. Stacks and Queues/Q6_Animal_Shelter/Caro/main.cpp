//
//  main.cpp
//  Q6_Animal_Shelter
//
//  Created by Carolina Romo on 2/6/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 3 Question 6
 * Animal Shelter: 
 * An animal shelter, which holds only dogs and cats, operates on a strictly 
 * "first in, first out"basis. People must adopt either the "oldest"(based on arrival time) 
 * of all animals at the shelter, or they can select whether they would prefer a dog or a cat 
 * (and will receive the oldest animal of that type). They cannot select which specific animal 
 * they would like. Create the data structures to maintain this system and implement operations 
 * such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the built-in LinkedList 
 * data structure.
 */

#include <iostream>
#include <queue>

using namespace std;

class animal{
private:
    queue<int> dog, cat;
    int order;
    
public:
    animal(){
        order = 1;
    }
    
    void enque(string a) {
        if (a == "dog"){
            dog.push(order);
            order++;
        }
        else if (a == "cat") {
            cat.push(order);
            order++;
        }
    }
    
    int dequeAny(){
        int tmp;
        if(dog.front() > cat.front()) {
            tmp = cat.front();
            cat.pop();
        }
        
        else {
            tmp = dog.front();
            dog.pop();
        }
        return tmp;
    }
    
    int dequeDog(){
        if (dog.empty()){
            return -1;
        }
        int tmp = dog.front();
        dog.pop();
        return tmp;
    }
    
    int dequeCat(){
        if (cat.empty()){
            return -1;
        }
        int tmp = cat.front();
        cat.pop();
        return tmp;
    }
};

int main(){
    animal a;
    a.enque("dog");
    a.enque("cat");
    a.enque("dog");
    a.enque("dog");
    a.enque("cat");
    a.enque("dog");
    
    cout << a.dequeCat() << endl;
    cout << a.dequeAny() << endl;
    cout << a.dequeDog() << endl;
    cout << a.dequeCat() << endl;
}
