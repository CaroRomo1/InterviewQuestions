//
//  main.cpp
//  Q2_Check_Permutation
//
//  Created by Carolina Romo on 1/10/17.
//  Copyright © 2017 ITESM. All rights reserved.
//

/* 
 * Cracking the coding interview edition 6
 * Chapter 1 Question 2
 * Check Permutation:
 * Given two strings, write a method to decide if one is a permutation of the other. 
 */

#include <iostream>
#include <algorithm>  // this header is required for std::sort to work
#include <string>

using namespace std;

string sortString(string str){
    sort(str.begin(),str.end());
    return str;
}

//Sorting strings
bool solutionOne(string str1, string str2){
    if (str1.length() != str2.length()) {
        return false;
    }
    else{
        str1 = sortString(str1);
        str2 = sortString(str2);
        if (str1.compare(str2) != 0) {
            return false;
        }
        else {
            return true;
        }
    }
    
}

//Checking char count
bool solutionTwo(string str1, string str2){
    if (str1.length() != str2.length()) {
        return false;
    }
    
    //Assuming there is ASCII standard
    int countletters[128];
    
    for (int i = 0; i < str1.length(); i++){
        int asciiChar = (int) str1[i];
        countletters[asciiChar]++;
    }
    for (int i = 0; i < str2.length(); i++){
        int asciiChar = (int) str2[i];
        countletters[asciiChar]--;
        if (countletters[asciiChar] < 0){
            return false;
        }
    }
    return true;
}

int main() {
    string str1, str2, str3, str4;
    cout << "Escriba dos palabras:" << endl;
    cin >> str1;
    cin >> str2;
    if (solutionOne(str1,str2)){
        cout << "Si son permutaciones" << endl;
    }
    else {
        cout << "No son permutaciones" << endl;
    }
    
    cout << "Escriba dos palabras:" << endl;
    cin >> str3;
    cin >> str4;
    if (solutionTwo(str3,str4)){
        cout << "Si son permutaciones" << endl;
    }
    else {
        cout << "No son permutaciones" << endl;
    }

    
    return 0;
}
