//
//  main.cpp
//  2799 - Classifying Triangles
//
//  Created by Carolina Romo on 2/7/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#include <iostream>
using namespace std;

bool checkSides(int x, int y) {
    return y > 200000 - x;
}

string defineTriangle(int l1, int l2, int l3) {
    if((l1 <= 0) || (l2 <= 0) || (l3 <= 0) || (l1 + l2 <= l3 || l1 + l3 <= l2 || l3 + l2 <= l1) || (checkSides(l1, l2) || checkSides(l1, l3) || checkSides(l2, l3))){
        return "ERROR";
    }
    
    else if(l1 == l2 && l2 == l3){
        return "EQUILATERAL";
    }
    
    else if((l1 == l2) || (l1 == l3) || (l2 == l3)) {
        return "ISOSCELES";
    }
    
    else {
        return "SCALENE";
    }
}


int main() {
    int s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    cout << defineTriangle(s1, s2, s3) << endl;
    
    return 0;
}
