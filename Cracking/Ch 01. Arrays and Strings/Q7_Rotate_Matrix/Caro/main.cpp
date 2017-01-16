//
//  main.cpp
//  Q7_Rotate_Matrix
//
//  Created by Carolina Romo on 1/14/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

/*
 * Cracking the coding interview edition 6
 * Chapter 1 Question 7
 * Rotate Matrix: 
 * Given an image represented by an NxN matrix, where each pixel in the 
 * image is 4 bytes, write a method to rotate the image by 90 degrees. 
 * Can you do this in place?
 */

#include <iostream>
using namespace std;


void rotateMatrixAntiClockwise(int **matrix, int N ) {
    for(int i = 0; i < N/2; i++) { //Starts from first layer
        for(int j = i; j < N-i-1; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][N-i-1];
            matrix[j][N-i-1] = matrix[N-i-1][N-j-1];
            matrix[N-i-1][N-j-1]= matrix[N-j-1][i];
            matrix[N-j-1][i] = temp;
        }
    }
}

void rotateMatrixClockwise(int **matrix, int N ) {
    for(int layer = 0; layer < N/2; layer++) { //Starts from first layer
        int first = layer;
        int last = N-1-layer;
        for(int i = first; i < last; i++) { //Last layer = N - first - 1
            int offset = i - first;
            // save top
            int top = matrix[first][i];
            // left -> top
            matrix[first][i] = matrix[last-offset][first];
            // bottom -> left
            matrix[last-offset][first] = matrix[last][last-offset];
            // right -> bottom
            matrix[last][last-offset] = matrix[i][last];
            // top -> right
            matrix[i][last] = top;
        }
    }
}

void printMatrix( int **matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int N;
    // We assume we will receive the lenght of the matrix
    cout << "Enter N for NxN matrix:";
    cin >> N;
    int **matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    printMatrix(matrix, N);
    cout << "Rotated matrix by 90 (clockwise):" << endl;
    rotateMatrixClockwise(matrix, N);
    printMatrix(matrix, N);
    
    return 0;
}
