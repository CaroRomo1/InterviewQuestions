//
//  main.cpp
//  Q4_Palindrome_Permutation
//
//  Created by Carolina Romo on 1/12/17.

/* 
 * Cracking the coding interview edition 6
 * Chapter 1 Question 4
 * Palindrome Permutation: Given a string, write a function to check if it is a
 * permutation of a palindrome. A palindrome is a word or phrase that is the same 
 * forwards and backwards. A permutation is a rearrangement of letters. 
 * The palindrome does not need to be limited to just dictionary words.
 *          EXAMPLE
 *          Input: Tact Coa
 *          Output: True (permutations:"taco cat'; "atco cta '; etc.)
 */

#include <iostream>
using namespace std;

int getCharIndex(char c){
    int idx = -1;
    if (c >= 'a' && c <= 'z' ){
        idx = c - 'a';
    }
    else if (c >= 'A' && c <= 'Z'){
        idx = c - 'A';
    }
    return idx;
}

bool solutionOne(string str){
    char countLetters[26] = {0};
    
    for (int index = 0; index < str.length(); index++){
        int letterValue = getCharIndex(str[index]);
        if (letterValue != -1){
            countLetters[letterValue]++;
        }
        
    }
    
    bool countOdd = false;
    
    for (int i = 0; i < 26; i++) {
        if ((countLetters[i] % 2 != 0) && (countLetters[i] != 0)){
            if (countOdd){
                return false;
            }
            countOdd = true;
        }
    }
    return true;
}


int main() {
    string word;
    
    getline(cin,word);
    
    if (solutionOne(word)){
        cout << "It has permutation palindrome" << endl;
    }
    else {
        cout << "It has NOT permutation palindrome" << endl;
    }
    
    return 0;
}
