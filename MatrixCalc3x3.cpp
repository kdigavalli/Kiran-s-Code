//
//  main.cpp
//  MatrixCalc
//
//  Created by Kiran Digavalli on 5/3/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "mCalcHeaderNew.h"

using namespace std;

//read data into a 3x3 array
void readData(double mat1[3][3]){
    
    cout << "Enter 3x3 integer matrix separated by spaces\n"  <<endl;
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            cin >> mat1[i][j];
        }
    }
}

//display 3x3 array contents
void checkData (double mat1[3][3]){
    
    cout << "" <<endl;
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            cout << mat1[i][j] << " ";
        }
        cout <<endl;
    }
    cout << "" <<endl;
}

//copy the values of mat1 into mat1 for 3x3 matrices
void copyF(double mat1[3][3], double mat2[3][3]){
    
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            mat2[i][j] = mat1[i][j];
        }
    }
}

//copy the lower left submatrix of mat1 into mat2
void subMatrixCopyF(double mat1[3][3], double mat2[2][2]){
    
    for(int i=1; i<=2; i++){
        for(int j=1; j<=2; j++){
            mat2[i-1][j-1] = mat1[i][j];
        }
    }
}

//copy the reduced 2x2 submatrix back into 3x3 matrix
void backIn_CopyF(double mat1[2][2], double mat2[3][3]){
    
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
            mat2[i+1][j+1] = mat1[i][j];
        }
    }
}


int main(){
    
    //create 3x3 matrices
    double matrix [3][3] = {};
    double matrix2 [3][3] = {};
    
    //create 2x2 matrices
    double matrix3[2][2] = {};
    double matrix4[2][2] = {};
    
    //initialize boolean flags for functions
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    bool flag4 = false;
    bool flag5 = false;
    
    //read in data
    readData(matrix);
    
    //check data
    cout << "\nEntry:" <<endl;
    checkData(matrix);
    
    //perform computations
    copyF(matrix, matrix2);
    
    analyzeF_3x3(flag1, flag2, matrix, matrix2);
    
    copyF(matrix2, matrix);
    
    checkData(matrix);
    
    subMatrixCopyF(matrix, matrix3);
    
    copyF_2x2(matrix3, matrix4);
    
    checkData_2x2(matrix3);
    
    analyzeF_2x2(flag3, flag4, flag5, matrix3, matrix4);
    
    copyF_2x2(matrix3, matrix4);
    
    checkData_2x2(matrix3);
    
    backIn_CopyF(matrix3, matrix);
    
    copyF(matrix, matrix2);
    
    //output final result
    checkData(matrix);
    
    
    
    return 0;
}

