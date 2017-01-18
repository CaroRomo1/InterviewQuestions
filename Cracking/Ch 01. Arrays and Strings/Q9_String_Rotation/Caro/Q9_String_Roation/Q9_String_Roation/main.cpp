//
//  main.cpp
//  Q9_String_Roation
//
//  Created by Carolina Romo on 1/17/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//


/*
 * Cracking the coding interview edition 6
 * Chapter 1 Question 9
 * String Rotation: 
 * Assume you have a method isSubstring which checks if one word is a
 * substring of another. Given two strings, s1 and s2, write code to check
 * if s2 is a rotation of s1 using only one call to isSubstring 
 * (e.g., waterbottleuis a rotation ofuerbottlewat).
 */

#include <iostream>
#include <string>
using namespace std;

/* string::npos is a constant (probably -1) representing a non-position. 
 * It's returned by method find when the pattern was not found.
 */
bool isSubstring(string str1, string str2){
    if (str1.find(str2) != -1){
        return true;
    }
    return false;
}

bool isRotation(string str1, string str2) {
    int length1 = int(str1.length());
    int length2 = int(str2.length());
    if (length1 == 0 || length1 != length2) {
        return false;
    }
    string doubleStr1 = str1 + str1;
    return isSubstring(doubleStr1, str2);
}

int main() {
    string str1, str2;
    
    cout << "String 1: " << endl;
    cin >> str1;
    
    cout << "String 2: " << endl;
    cin >> str2;
   
    if (isRotation(str1, str2)) {
        cout << str2 << " is a rotation of " << str1 << endl;
    } else {
        cout << str2 << " is NOT a rotation of " << str1 << endl;
    }
    return 0;
}
