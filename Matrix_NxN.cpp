//
//  main.cpp
//  Matrix_NxN
//
//  Created by Kiran Digavalli on 8/4/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "NewMatrixHeader.h"
#include "NxN_Header.h"

using namespace std;


int main(){
    
    //initialize dimension variable
    int N = 0;
    
    //initialize flags
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    bool flag4 = false;
    bool flag5 = false;
    
    //request & receive dimension from user
    cout << "For an NxN matrix, enter N" <<endl;
    cin >> N;
    
    //initialize dynamic 2D arrays
    double **matrix1;
    double **matrix2;
    matrix1 = new double *[N];
    matrix2 = new double *[N];
    
    for(int i=0; i<N; i++){
        matrix1[i] = new double[N];
        matrix2[i] = new double[N];
    }
    
    //initialize static 2x2 arrays
    double matrix_2x2[2][2];
    double mirror_2x2[2][2];
    
    //read, check & copy data
    readData_NxN(N, matrix1);
    checkData_NxN(N, matrix1);
    copyF_NxN(N, matrix1, matrix2);
    
    //first analysis function call
    analyzeF_NxN(N, flag2, matrix1, matrix2);
    
    //recursive function call
    arrayFunctionThing(N, flag1, flag2, matrix1, matrix2, matrix_2x2);
    
    //2x2 analysis function call
    copyF_2x2(matrix_2x2, mirror_2x2);
    analyzeF_2x2(flag3, flag4, flag5, matrix_2x2, mirror_2x2);
    absRow_2x2(1, matrix_2x2);
    checkData_2x2(matrix_2x2);
    
    
    
    
    return 0;
}