//
//  main.cpp
//  Q6_String_Compression
//
//  Created by Carolina Romo on 1/14/17.
//  Copyright © 2017 CaroRomo. All rights reserved.

/*
 * Cracking the coding interview edition 6
 * Chapter 1 Question 6
 * String Compression: 
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example, the string aabcccccaaa would become a2blc5a3.
 * If the "compressed"string would not become smaller than the original string, 
 * your method should return the original string. You can assume the string 
 * has only uppercase and lowercase letters (a - z).
 */

#include <iostream>
#include <string>

using namespace std;

string compress(string str) {
    int originalLength = str.length();
    // We assume that if it has a lenght smaller than 2, it could not be compressed
    if (originalLength < 2) {
        return str;
    }
    string out = "";
    int count = 1;
    for(int i = 1; i < originalLength; i++) {
        if (str[i-1] == str[i]) {
            count++;
        }
        else {
            out += str[i-1];
            out += to_string(count);
            count = 1;
        }
        if (out.length() >= originalLength) {
            return str;
        }
    }
    
    out += str[originalLength-1];
    out += to_string(count);
    
    if (out.length() >= originalLength) {
        return str;
    }
    return out;
}

int main() {
    string str, compressedStr;
    cout << "Enter a string:" << endl;
    cin >> str;

    compressedStr = compress(str);
    if (str.compare(compressedStr)) {
        cout << str << " can be compressed to " << compressedStr << endl;
    } else {
        cout << str << " can not be compressed" << endl;
    }
    return 0;
}

