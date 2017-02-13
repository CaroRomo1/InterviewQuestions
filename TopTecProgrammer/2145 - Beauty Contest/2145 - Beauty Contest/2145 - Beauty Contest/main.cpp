//
//  main.cpp
//  2145 - Beauty Contest
//
//  Created by Carolina Romo on 2/13/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#include <iostream>

using namespace std;


int main() {
    
    int n = 0, c = 1;
    int g[10];
    
    cin >> n;
    
    while (c <= n) {
        for (int i = 0; i < 10; i++){
            cin >> g[i];
        }
        
        int min = g[0];
        
        for (int i = 0; i < 10; i++) {
            if (g[i] < min) {
                min = g[i];
            }
        }
        
        int max = g[0];
        
        for (int i = 0; i < 10; i++) {
            if (g[i] > max) {
                max = g[i];            }
        }
        
        int result = 0;
        
        for (int i = 0; i < 10; i++) {
            result += g[i];
        }
        
        cout << c << " " << result - min - max << endl;
        
        c++;
    }
    
    return 0;
}
