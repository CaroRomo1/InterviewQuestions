//
//  main.cpp
//  2409 - Find the Heterochromatic Index
//
//  Created by Carolina Romo on 2/7/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#include <iostream>

using namespace std;


int main() {
    int e1 = 0, e2 = 0, result = 0;
    string catName = "";
    cin >> catName;
    cin >> e1;
    cin >> e2;
    if (e1 >= e2){
        result = e1 - e2;
    }
    else {
        result = e2 - e1;
    }
    cout << catName << " " << result << endl;
    
    return 0;
}
