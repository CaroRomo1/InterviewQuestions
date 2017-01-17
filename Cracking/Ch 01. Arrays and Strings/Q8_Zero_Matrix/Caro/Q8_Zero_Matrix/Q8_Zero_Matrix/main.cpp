//
//  main.cpp
//  Q8_Zero_Matrix
//
//  Created by Carolina Romo on 1/15/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 1 Question 8
 * Zero Matrix: 
 * Write an algorithm such that if an element in an MxN matrix is 0, 
 * its entire row and column are set to 0.
 */

#include <iostream>
using namespace std;

void setZeros(int N1, int N2){
    int matrix[N1][N2];
    
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            matrix[i][j] = rand() % 7;
        }
    }
    
    for (int i = 0; i < N1; ++i) {
        for(int j = 0; j < N2; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    
    int r = int(sizeof(matrix) / sizeof(matrix[0]));
    int c = int(sizeof(matrix[0]) / sizeof(matrix[0][0]));
    
    bool row[r];
    bool column[c];
    
    // Store the row and column index with value 0
    for (int i = 0; i < r; i++){
        row[i] = false;
    }
    
    for (int i = 0; i < c; i++){
        column[i] = false;
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c;j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                column[j] = true;
            }
        }
    }
    
    // Nullify rows
    for (int i = 0; i < r; i++) {
        if (row[i]){
            for (int j = 0; j < c; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Nullify columns
    for (int i = 0; i < c; i++) {
        if (column[i]){
            for (int j = 0; j < r; j++) {
                matrix[j][i] = 0;
            }
        }
    }
    
    for (int i = 0; i < N1; ++i) {
        for(int j = 0; j < N2; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int N1, N2;
    cin >> N1;
    cin >> N2;
    
    setZeros(N1, N2);
    
    return 0;
}
