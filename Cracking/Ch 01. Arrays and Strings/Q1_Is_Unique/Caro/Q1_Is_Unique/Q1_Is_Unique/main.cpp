//
//  main.cpp
//  Q1_Is_Unique
//
//  Created by Carolina Romo on 1/9/17.
//  Copyright © 2017 ITESM. All rights reserved.
//

/* Chapter 1 - Q1 Is Unique:
 Implement an algorithm to determine if a string has all unique characters.
 What if you cannot use additional data structures? 
 */

#include <iostream>
#include <string>

using namespace std;

//Best Option Time Complexity O(n) or O(1)
bool isUniqueOne(string str){
    // Consider ASCII normal
    if (str.length() > 128){
        return false;
    }
    
    bool uniqueArr[128] = {false};
    
    for (int index = 0; index < str.length(); index++){
        int asciiChar = (int) str[index];
        if (uniqueArr[asciiChar]){
            return false;
        }
        uniqueArr[asciiChar] = true;
    }
    return true;
}

//Brute Force
bool isUniqueTwo(string str){
    for(int i = 0; i < str.length()-1; i++){
        for(int j = 1; j < str.length(); j++){
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;
    
    if(isUniqueOne(str1)){
        cout << "Si es unico" << endl;
    }
    else {
        cout << "No es unico" << endl;
    }
    if(isUniqueTwo(str2)){
        cout << "Si es unico" << endl;
    }
    else{
        cout << "No es unico" << endl;
    }
    
    return 0;
}
