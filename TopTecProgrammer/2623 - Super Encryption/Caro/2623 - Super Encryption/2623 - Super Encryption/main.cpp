//
//  main.cpp
//  2623 - Super Encryption
//
//  Created by Carolina Romo on 2/7/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#include <iostream>

using namespace std;

string reverseString(string str){
    int i = 0, j = int(str.length()-1);
    char aux;
    while (i < j) {
        aux = str[i];
        str[i] = str[j];
        str[j] = aux;
        i++;
        j--;
    }
    
    return str;
}

int main() {
    string str, part1 = "", part2 = "";
    
    cin >> str;
    if (int(str.length()) % 2 == 0){
        part1 = str.substr(0,int((str.length()/2)));
        part2 = str.substr(int(str.length()/2), int((str.length()/2)));
        cout << reverseString(part1) << reverseString(part2) << endl;
    }
    else {
        part1 = str.substr(0,int((str.length()/2)));
        part2 = str.substr(int(str.length()/2)+1, int((str.length()/2)));
        cout << reverseString(part1) << str[str.length()/2] << reverseString(part2) << endl;
    }
    
    return 0;
}
