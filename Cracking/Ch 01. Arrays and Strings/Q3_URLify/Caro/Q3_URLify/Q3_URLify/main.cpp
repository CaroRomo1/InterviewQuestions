/*
 * Cracking the coding interview Edition 6
 * Problem 1.3 URLify --> Replace all the spaces in a string with '%20'.
 * Assumption : We have enough space to accomodate addition chars
 * Preferebly in place
 */

//  Created by Carolina Romo on 1/11/17.


/*
 * Function : urlify
 * Args     : string long enough to accomodate extra chars + true len
 * Return   : void (in place transformation of string)
 */

#include <iostream>
using namespace std;


void urlify(char *str,int truelen ){
    int numberSpaces = 0, index = 0;
    
    for (int i = 0; i < truelen; i++){
        if (str[i] == ' '){
            numberSpaces++;
        }
    }
    
    index = truelen + (numberSpaces * 2);
    
    for (int i = truelen - 1; i >= 0; i--){
        if (str[i] == ' ') {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index = index - 3;
        }
        else {
            str[index - 1] = str[i];
            index--;
        }
    }
}

int main() {
    int length = 13;
    char str[] = "Mr John Smith    ";
    
    cout << "Normal String: " << str << endl;
    
    urlify(str, length);
    
    cout << "URLify string: " << str << endl;
    
    return 0;
}
