//
//  main.cpp
//  Q5_One_Way
//
//  Created by Carolina Romo on 1/13/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 1 Question 5
 * One Away: 
 * There are three types of edits that can be performed on strings: 
 * insert a character, remove a character, or replace a character. 
 * Given two strings, write a function to check if they are one edit 
 * (or zero edits) away.
 *      EXAMPLE: 
 * pale, ple -) true 
 * pales, pale - ) true 
 * pale, bale -) true 
 * pale, bae -) false
 */

#include <iostream>
using namespace std;

bool oneEditReplace(string str1, string str2){
    bool different = false;
    for (int i = 0; i < str1.length(); i++){
        if (str1[i] != str2[i]){
            if (different){
                return false;
            }
            different = true;
        }
    }
    return  true;
}

bool oneEditInsert(string str1, string str2){
    int index1 = 0, index2 = 0;
    while (index2 < str2.length() && index1 < str1.length()){
        if (str1[index1] != str2[index2]){
            if (index1 != index2){
                return false;
            }
            index2++;
        }
        else{
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneEditAway(string str1, string str2){
    if (str1.length() == str2.length()){
        return oneEditReplace(str1, str2);
    }
    else if (str1.length() + 1 == str2.length()){
        return oneEditInsert(str1, str2);
    }
    else if (str1.length() - 1 == str2.length()){
        return oneEditInsert(str2, str1);
    }
    return false;
}
int main() {
    
    string str1 = "pale", str2 = "ple", str3 = "pales", str4 = "bale", str5 = "bake";
    
    cout << "Compare " << str1 << " " << str2 << endl;
    if (oneEditAway(str1, str2)){
        cout << "One Away = true" << endl;
    }
    else{
        cout << "One Away = false" << endl;
    }
    
    cout << "Compare " << str3 << " " << str1 << endl;
    if (oneEditAway(str3, str1)){
        cout << "One Away = true" << endl;
    }
    else{
        cout << "One Away = false" << endl;
    }
    
    cout << "Compare " << str1 << " " << str3 << endl;
    if (oneEditAway(str1, str3)){
        cout << "One Away = true" << endl;
    }
    else{
        cout << "One Away = false" << endl;
    }
    
    cout << "Compare " << str1 << " " << str4 << endl;
    if (oneEditAway(str1, str4)){
        cout << "One Away = true" << endl;
    }
    else{
        cout << "One Away = false" << endl;
    }
    
    cout << "Compare " << str1 << " " << str5 << endl;
    if (oneEditAway(str1, str5)){
        cout << "One Away = true" << endl;
    }
    else{
        cout << "One Away = false" << endl;
    }

    return 0;
}
