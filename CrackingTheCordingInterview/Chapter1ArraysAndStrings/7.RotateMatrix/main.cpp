//
//
//  1.7 RotateMatrix
//  Given an image represented by an N×N matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.
//
//  Created by Risa Toyoshima
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>

using namespace std;

class Matrix {
    int **newM;
    static const int row = 4, col = 4;
    
public:
    int M[row][col] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10 ,11, 12},
        {13, 14 , 15, 16}
    };
    int N = 4;
    
    void rotateWithNewMatrix();
    void printNewMatrix();
    
    void rotateInPlace();
    void printInPlace();
    
};

void Matrix::rotateWithNewMatrix() {     //Rotate M[][] replacing into the new matrix 'rotatedM'
    int temp = N - 1;
    
    //create new empty matrix
    newM = new int*[N];
    for (int i = 0; i < N; i++) {
        newM[i] = new int[N];
    }
    
    //rotating matrix
    for (int i = 0; i <= temp; i++) {
        for (int j = 0; j <= temp; j++) {
            newM[j][temp - i] = M[i][j];
        }
    }
    
    
    
}

void Matrix::printNewMatrix() {
    
    cout << "Rotated replacing into a new matrix:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << newM[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::rotateInPlace() {  // Rotating the matrix in place
    int k = N - 1;
    int temp = 0;
    
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < k - i; j++) {
            temp = M[j][k-i];
            M[j][k-i] = M[i][j];
            M[i][j] = M[k-j][i];
            M[k-j][i] = M[k-i][k-j];
            M[k-i][k-j] = temp;
        }
    }
}

void Matrix::printInPlace() {
    
    cout << "Rotated replacing in place:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    
    Matrix m;
    
    m.rotateWithNewMatrix();
    m.printNewMatrix();
    
    m.rotateInPlace();
    m.printInPlace();
    
    return 0;
}
