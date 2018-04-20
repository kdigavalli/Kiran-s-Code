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
    
    //initialize offset
    int offset = 0;
    
    //initialize flags
    bool flag1 = false;
    bool flag2 = false;
    //bool flag3 = false;
    //bool flag4 = false;
    //bool flag5 = false;
    bool flag6 = false;
    char intFlag = 'N';
    
    //request & receive dimension from user
    cout << "For an NxN matrix, enter N" <<endl;
    cin >> N;
    
    //set output precision if non integer entries
    cout << "Non integer entries? (Y or N)" <<endl;
    cin >> intFlag;
    cout << "\n";
    
    if(intFlag == 'Y' || intFlag == 'y'){
        cout.setf(ios::fixed);
        cout.precision(1);
    }
    
    //generate random matrix if requested
    cout << "Would you like a random matrix? (0 or 1)" <<endl;
    cin >> flag6;
    
    if(flag6){
        randomMatrix newMatrix(N);
        newMatrix.setCap();
        newMatrix.setMix();
        newMatrix.doStuff();
    }
    
    //initialize dynamic 2D arrays
    double **matrix1;
    double **matrix2;
    matrix1 = new double *[N];
    matrix2 = new double *[N];
    
    for(int i=0; i<N; i++){
        matrix1[i] = new double[N];
        matrix2[i] = new double[N];
    }
    
    //initialize 2x2 array
    double matrix_2x2[2][2];
    
    //read, check & copy data
    readData_NxN(N, matrix1);
    checkData_NxN(N, matrix1);
    copyF_NxN(N, matrix1, matrix2);
    
    //first analysis function call
    analyzeF_NxN(N, offset, flag2, matrix1, matrix2);
    
    //recursive function call
    arrayFunctionThing(N, offset, flag1, flag2, matrix1, matrix2, matrix_2x2);
    
    //sort out last row
    scalM_NxN(N, 0, 1/matrix1[N-1][N-1], N-1, matrix1);
    //negativeZeroCheck(N, matrix1);
    copyF_NxN(N, matrix1, matrix2);
    
    //final set precision
    decimalCheck(N, matrix1);
    
    cout << "\nFinal result:" <<endl;
    checkData_NxN(N, matrix1);
    
    
    
    return 0;
}