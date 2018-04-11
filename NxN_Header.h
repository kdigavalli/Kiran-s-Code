//
//  NxN_Header.h
//  Matrix_NxN
//
//  Created by Kiran Digavalli on 8/4/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//

#ifndef Matrix_NxN_NxN_Header_h
#define Matrix_NxN_NxN_Header_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "NewMatrixHeader.h"

using namespace std;

//read data into an NxN array
void readData_NxN(int N, double *mat1[N]){
    
    cout << "Enter NxN matrix separated by spaces\n"  <<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> mat1[i][j];
        }
    }
}

//display contents of NxN array
void checkData_NxN(int N, double *mat1[N]){
    
    cout << "" <<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << mat1[i][j] << " ";
        }
        cout <<endl;
    }
    cout << "" <<endl;
}

//copy the values of mat1 into mat2 for NxN arrays
void copyF_NxN(int N, double *mat1[N], double *mat2[N]){
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mat2[i][j] = mat1[i][j];
        }
    }
}

//copy the values of dynamic array mat1 into static array mat2
void copyF_dyn(int N, double *mat1[N], double mat2[2][2]){
    
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
            mat2[i][j] = mat1[i][j];
        }
    }
}

//returns sum of along the main diagonal of NxN array
double diagonalSum(int N, double *mat1[N]){
    
    double sum = 0;
    for(int i=0; i<N; i++){
        sum += mat1[i][i];
    }
    return sum;
}

//returns sum of all elements of NxN array
double matrixSum(int N, double *mat1[N]){
    
    double sum = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            sum += mat1[i][j];
        }
    }
    return sum;
}

//swaps lines line1 and line2 for NxN arrays
void lineSwap_NxN(int N, int line1, int line2, double *mat1[N], double *mat2[N]){
    
    //method to swap lines
    for(int i=0; i<N; i++){
        mat2[line2][i] = mat1[line1][i];
        mat2[line1][i] = mat1[line2][i];
    }
    copyF_NxN(N, mat2, mat1);
    checkData_NxN(N, mat1);
}

//gives the scalar multiple of a particular row for 3x3 matrices
double scalM_NxN(int N, double mult, int row, double *mat1[N]){
    
    if(fabs(row)>=N){
        cout << "\nScalM error" <<endl;
    }
    
    //scalar multiplication method
    for(int i=0; i<N; i++){
        mat1[row][i] *= mult;
    }
    
    checkData_NxN(N, mat1);
    
    return 0;
}

//replaces a row with the sum of itself and the scalar multiple of another row for NxN matrices
double replaceF_NxN(int N, double mult, int replaceRow, int multRow, double *mat1[N], double *mat2[N]){
    
    if(fabs(replaceRow) >= N || fabs(multRow) >= N){
        cout << "\nReplaceF error" <<endl;
    }
    
    for(int i=0; i<N; i++){
        mat2[replaceRow][i] += mult * mat1[multRow][i];
    }
    
    //copy & check data
    copyF_NxN(N, mat2, mat1);
    checkData_NxN(N, mat1);
    return 0;
}

//copy the lower left submatrix of mat1 into mat2
void subMatrixCopy_NxN(int N, double *mat1[N], double *mat2[N-1]){
    
    for(int i=1; i<N; i++){
        for(int j=1; j<N; j++){
            mat2[i-1][j-1] = mat1[i][j];
        }
    }
}

// NxN analysis function
void analyzeF_NxN(int N, bool block6flag, double *matrix1[N], double *matrix2[N]){
    
    //sum of all components and sum along the main diagonal
    int fullSum = matrixSum(N, matrix1);
    int diaSum = diagonalSum(N, matrix1);
    
    //initialize flags
    bool pivot1Flag = false;
    bool flag2 = false;
    bool flag3 = false;
    
    //declaring variables for the next block
    int row = 0;
    int compare = 0;
    int ratio = 0;
    
    //self explanatory
    if(fullSum == diaSum && diaSum == N){
        cout << "This is the identity matrix" << endl;
    } else{
        
        //if there is a linear dependency between any two rows, the row is converted to zeros
        for(row=0; row<N; row++){
            for(compare=0; compare<N; compare++){
                ratio = matrix1[row][0]/matrix1[compare][0];
                for(int element=0; element<N; element++){
                    if((row!=compare) && (matrix1[row][element]/matrix1[compare][element]) == ratio){
                        flag2 = true;
                        continue;
                    } else {
                        flag2 = false;
                        break;
                    }
                }
                if(flag2 == true){
                    cout << "Block 1" <<endl;
                    break;
                }
            }
            if(flag2 == true){
                replaceF_NxN(N, -ratio, row, compare, matrix1, matrix2);
                cout << "Linear dependency present" << endl;
                break;
            }
        }
        
        //if a row begins with zero and this operation has not yet been performed, the row is swapped with the last row
        if(!flag3 && !((fullSum==diaSum) && (diaSum == N))){
            for(int p=0; p<N; p++){
                if(matrix1[p][0] == 0){
                    cout << "Block 2" <<endl;
                    lineSwap_NxN(N, p, N-1, matrix1, matrix2);
                    flag3 = true;
                    break;
                }
            }
        }
        
        //if a row begins with a 1, it is swapped with the first row
        if(!pivot1Flag){
            for(int k=0; k<N; k++){
                if(matrix1[k][0] == 1){
                    cout << "Block 3" <<endl;
                    lineSwap_NxN(N, 0, k, matrix1, matrix2);
                    pivot1Flag = true;
                    break;
                }
            }
        }
        
        //if a a 1 can be produced by row replacement, it is done
        if(!pivot1Flag){
            for (int j=1; j<N; j++){
                for (int l=-9; l<10; l++){
                    if(l * matrix1[j][0] + matrix1[0][0] == 1){
                        cout << "Block 4" <<endl;
                        replaceF_NxN(N, l, 0, j, matrix1, matrix2);
                        copyF_NxN(N, matrix2, matrix1);
                        pivot1Flag = true;
                        break;
                    }
                }
            }
        }
        
        //if all else fails, brute force approach; mess will result
        if(!pivot1Flag && ((matrix1[1][0]) != 0) && (matrix1[0][0] != 1) && !block6flag){
            cout << "Block 5" <<endl;
            checkData_NxN(N, matrix1);
            scalM_NxN(N, 1/matrix1[0][0], 0, matrix1);
            copyF_NxN(N, matrix1, matrix2);
            checkData_NxN(N, matrix1);
            pivot1Flag = true;
        }
        
        //after getting a 1 in the pivot position, we obtain zeros under it
        if((fabs(matrix1[1][0]) > 0) && !block6flag){
            for(int d=1; d<N; d++){
                if(matrix1[d][0] != 0 && matrix1[d][0] != 1){
                    cout << "Block 6" <<endl;
                    checkData_NxN(N, matrix1);
                    replaceF_NxN(N, -matrix1[d][0], d, 0, matrix1, matrix2);
                    block6flag = true;
                }
            }
        }
        
        copyF_NxN(N, matrix1, matrix2);
        checkData_NxN(N, matrix1);

    }
    
}


//recursive function to create progressively smaller submatrices and row reduce them
//stops after a 2x2 submatrix is created
void arrayFunctionThing(int N, bool flag1, bool flag2, double *matrix1[N], double *matrix2[N], double matrix_2x2[2][2]){
    
    //reset flag2 and dimension
    flag2 = false;
    int dimension = N;
    
    //tracking
    cout << "Array function call for dimension: " << dimension-1 << "\n" <<endl;
    
    while (dimension > 2){
        
        //decrement the matrix dimension
        dimension--;
        
        //create new dynamic arrays
        double **mat1;
        double **mat2;
        mat1 = new double *[dimension];
        mat2 = new double *[dimension];
        
        for(int i=0; i<dimension; i++){
            mat1[i] = new double[dimension];
            mat2[i] = new double[dimension];
        }

        //copy the next submatrix into mat1
        subMatrixCopy_NxN(N, matrix1, mat1);
        
        //copy into the mirror
        copyF_NxN(dimension, mat1, mat2);
        
        // analysis function call
        analyzeF_NxN(dimension,flag2, mat1, mat2);

        //recursive step
        if(dimension > 3){
            arrayFunctionThing(dimension, flag1, flag2, mat1, mat2, matrix_2x2);
        }
    }
    
    //if dimension is 2, copy matrix1 into a static 2x2 array for analysis
    if(dimension == 2){
        copyF_dyn(dimension, matrix1, matrix_2x2);
    }
    
}




#endif
