//
//  main.cpp
//  2620 - Aaaaaaaah
//
//  Created by Carolina Romo on 2/7/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int r = 0;
    string ah = "";
    cin >> r;
    
    ah += 'A';
    for (int i = 0; i < r*4; i++){
        ah += 'a';
    }
    
    ah += 'h';
    
    cout << ah << endl;
    
    
    return 0;
}
