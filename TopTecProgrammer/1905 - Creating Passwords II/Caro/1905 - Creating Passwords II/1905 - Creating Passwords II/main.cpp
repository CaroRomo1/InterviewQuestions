//
//  main.cpp
//  1905 - Creating Passwords II
//
//  Created by Carolina Romo on 2/7/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string replaceSpaces(string str){
    string str2 = "";
    int lastSpace = int(str.length());
    for (int i = int(str.length() - 1); i >= 0; i--){
        if (str[i] == ' '){
            str2 += str.substr(i+1,lastSpace-i-1);
            str2 += "*";
            lastSpace = i;
        }
        if (i == 0){
            str2 += str.substr(i,lastSpace);
        }
    }
    return str2;
}

int main() {
    int n = 0;
    string str = "", name = "", password = "";
    cin >> n;
    cin.ignore();
    
    while (n > 0) {
        getline(cin, str);
        password = "";
        name = str.substr(5,str.length()-1);
        password = replaceSpaces(name);
        cout << str[0] << str[1] << password << str[2] << str[3] << endl;
        n--;
    }
    
    return 0;
}
