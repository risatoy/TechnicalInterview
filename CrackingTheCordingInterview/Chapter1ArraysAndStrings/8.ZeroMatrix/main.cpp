//
//  1.8 ZeroMatrix
//  Wrete a algorithm such that if an element in an M×N matrix is 0, its entire row and column are set to 0.
//
//  Created by Risa Toyoshima
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void setToZero(int **matrix, int row, int col, int rowSize, int colSize) {
    
    //set the entire row that found 0, to 0
    for (int i = 0; i < colSize; i++) {
        matrix[row][i] = 0;
    }
    
    //set the entire col that found 0, to 0
    for (int i = 0; i < rowSize; i++) {
        matrix[i][col] = 0;
    }
}

void foundZero(int **matrix, int rowSize, int colSize) {
    vector<int> rows;
    vector<int> cols;
    
    
    //store the row and col of where have 0 into vector 'rows' and 'cols'
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (matrix[i][j] == 0) {
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }
    
    //wherever found 0, set that entire row and col to 0
    for (int i = 0; i < rows.size(); i++) {
        setToZero(matrix, rows[i], cols[i], rowSize, colSize);
    }
}

void printMatrix(int **matrix, int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}



int main() {
    
    int M, N;
    
    cout << "How many rows?:";
    cin >> M;
    cout << "How many cols?:";
    cin >> N;
    
    //create 2d matrix
    int ** matrix = new int*[M];
    for ( int i =0; i < M; ++i ) {
        matrix[i] = new int[N];
    }
    cout << "Provide M x N matrix" << endl;
    for ( int i = 0; i < M; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "Matrix Before: " << endl;
    printMatrix(matrix, M, N);
    
    foundZero(matrix, M, N);
    
    cout << "Matrix After: " << endl;
    printMatrix(matrix, M, N);
    

    return 0;
}
