//
//  NxN_Header.h
//  Matrix_NxN
//
//  Created by Kiran Digavalli on 8/4/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "NewMatrixHeader.h"

using namespace std;


class matrix {
    
private:
    
    //dimension variables
    int N;
    int M;
    
    //offset
    int offset;
    
    //flags
    bool flag1;
    bool flag2;
    char randFlag;
    char intFlag;
    
    //random matrix variables
    int randCap;
    int randSign;
    int mix;
    
    //pointers for 2D dynamic arrays
    double **matrix1;
    double **matrix2;
    
public:
    
    //constructors
    matrix(){
        M = 3;
        N = 3;
        offset = 0;
        flag1 = false;
        flag2 = false;
        randFlag = 'N';
        intFlag = 'N';
        
        //initialize dynamic 2D arrays
        matrix1 = new double *[N];
        matrix2 = new double *[N];
        
        for(int i=0; i<N; i++){
            matrix1[i] = new double[M];
            matrix2[i] = new double[M];
        }
    }
    
    matrix(int rows, int cols){
        N = rows;
        M = cols;
        offset = 0;
        flag1 = false;
        flag2 = false;
        randFlag = 'N';
        intFlag = 'N';
        
        //initialize dynamic 2D arrays
        matrix1 = new double *[N];
        matrix2 = new double *[N];
        
        for(int i=0; i<N; i++){
            matrix1[i] = new double[M];
            matrix2[i] = new double[M];
        }
        
    }
    
    //other functions
    
    //read data into an NxM array
    void readData(void){
        
        cout << "\nEnter " << N << "x" << M << " matrix separated by spaces\n"  <<endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> matrix1[i][j];
            }
        }
    }
    
    //display contents of NxM array
    void display(){
        
        cout << "" <<endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cout << matrix1[i][j] << " ";
            }
            cout <<endl;
        }
        cout << "" <<endl;
    }
    
    // create a copy
    matrix* copy(){
        matrix *m = new matrix(M, N);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                m->matrix1[i][j] = matrix1[i][j];
            }
        }
        return m;
    }
    
    double trace(){
        int limit = (N > M) ? M : N;
        double trace = 0.0;
        for (int idx = 0; idx < limit; idx++){
            trace += matrix1[idx][idx];
        }
        return trace;
    }
    
    double sumOfEntries(){
        double sum = 0.0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                sum += matrix1[i][j];
            }
        }
        return sum;
    }
    
    //returns sum of all elements of NxN array
    double matrixSum(){
        // only for square matrices
        double sum = 0;
        if(N == M){
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    sum += matrix1[i][j];
                }
            }
            return sum;
        } else {
            return 0;
        }
    }
    
    //checks if there are decimal points after the elements of the matrix
    //if so, sets output precision to 1
    void decimalCheck(){
        double temp = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(modf(matrix1[i][j], &temp) != 0 && modf(matrix1[i][j], &temp) != -0){
                    cout.setf(ios::fixed);
                    cout.precision(1);
                    break;
                }
            }
        }
    }
    
    //takes absolute values of all zeroes to avoid irritating negative zeros
    void negativeZeroCheck(){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(matrix1[i][j] == -0 || matrix1[i][j] == 0){
                    matrix1[i][j] = 0; // stupid negative zero
                }
            }
        }
    }
    
    //swaps lines line1 and line2 for NxM arrays
    void lineSwap_NxN(int N, int M, int offset, int line1, int line2, double **mat1, double **mat2){
        
        //method to swap lines
        for(int i=0; i<M; i++){
            mat2[line2][i] = mat1[line1][i];
            mat2[line1][i] = mat1[line2][i];
        }
        copyF_NxN(N, M, mat2, mat1);
        checkData_NxN(N, M, mat1);
    }
    
    //gives the scalar multiple of a particular row for NxM matrices
    double scalM_NxN(int N, int M, int offset, double mult, int row, double **mat1){
        
        if(fabs(row)>=N){
            cout << "\nScalM error" <<endl;
        }
        
        //scalar multiplication method
        for(int i=0; i<M; i++){
            mat1[row][i] *= mult;
        }
        
        checkData_NxN(N, M, mat1);
        
        return 0;
    }
    
    //replaces a row with the sum of itself and the scalar multiple of another row for NxM matrices
    double replaceF_NxN(int N, int M, int offset, double mult, int replaceRow, int multRow, double **mat1, double **mat2){
        
        if(fabs(replaceRow) >= N || fabs(multRow) >= N){
            cout << "\nReplaceF error" <<endl;
        }
        
        for(int i=0; i<M; i++){
            mat2[replaceRow][i] += mult * mat1[multRow][i];
        }
        
        //copy & check data
        copyF_NxN(N, M, mat2, mat1);
        checkData_NxN(N, M, mat1);
        return 0;
    }
    
    //row reduce to identity matrix if invertible
    void rref(){
        if(diagonalSum(N, M, matrix1) == N){
            for(int i=1; i<N; i++){
                for(int j=i-1; j>=0; j--){
                    if(matrix1[i][i] != 0){
                        replaceF_NxN(N, M, i, -matrix1[j][i], j, i, matrix1, matrix2);
                    } else{
                        continue;
                    }
                }
            }
            copyF_NxN(N, M, matrix1, matrix2);
            negativeZeroCheck(N, M, matrix1);
        } else{
            cout << "\nRREF not possible" <<endl;
        }
    }
    
    // NxM analysis function
    //note: name is still analyzeF_NxN, but the function works on non-square matrices
    void analyzeF_NxN(int N, int M, int offset, bool block6flag, double **matrix1, double **matrix2){
        
        //sum of all components and sum along the main diagonal
        double fullSum = matrixSum();
        double diaSum = trace();
        
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
            for(row=offset; row<N; row++){
                for(compare=offset; compare<N; compare++){
                    ratio = matrix1[row][offset]/matrix1[compare][offset];
                    for(int element=offset; element<M; element++){
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
                    replaceF_NxN(N, M, offset, -ratio, row, compare, matrix1, matrix2);
                    cout << "Linear dependency present" << endl;
                    break;
                }
            }
            
            //if a row begins with zero and this operation has not yet been performed, the row is swapped with the last row
            if(!flag3 && !((fullSum==diaSum) && (diaSum == N))){
                for(int p=offset; p<N; p++){
                    if(matrix1[p][offset] == 0){
                        cout << "Block 2" <<endl;
                        lineSwap_NxN(N, M, offset, p, N-1, matrix1, matrix2);
                        flag3 = true;
                        break;
                    }
                }
            }
            
            //if a row begins with a 1, it is swapped with the first row
            if(!pivot1Flag){
                for(int k=offset; k<N; k++){
                    if(matrix1[k][offset] == 1 && !pivot1Flag){
                        cout << "Block 3" <<endl;
                        lineSwap_NxN(N, M, offset, offset, k, matrix1, matrix2);
                        pivot1Flag = true;
                        break;
                    }
                    if(pivot1Flag){
                        break;
                    }
                }
            }
            
            //if a a 1 can be produced by row replacement, it is done
            if(!pivot1Flag){
                for (int j=offset+1; j<N; j++){
                    for (int l=-9; l<10; l++){
                        if(l * matrix1[j][offset] + matrix1[offset][offset] == 1){
                            cout << "Block 4" <<endl;
                            replaceF_NxN(N, M, offset, l, offset, j, matrix1, matrix2);
                            copyF_NxN(N, M, matrix2, matrix1);
                            pivot1Flag = true;
                            break;
                        }
                    }
                }
            }
            
            //if all else fails, brute force approach; mess will result
            if(!pivot1Flag && ((matrix1[offset+1][offset]) != 0) && (matrix1[offset][offset] != 1) && !block6flag){
                cout << "Block 5" <<endl;
                checkData_NxN(N, M, matrix1);
                scalM_NxN(N, M, offset, 1/matrix1[offset][offset], offset, matrix1);
                copyF_NxN(N, M, matrix1, matrix2);
                checkData_NxN(N,M, matrix1);
                pivot1Flag = true;
            }
            
            //after getting a 1 in the pivot position, we obtain zeros under it
            if(!block6flag){
                for(int d=offset+1; d<N; d++){
                    if(matrix1[d][offset] != 0){
                        cout << "Block 6" <<endl;
                        checkData_NxN(N, M, matrix1);
                        replaceF_NxN(N, M, offset, -matrix1[d][offset], d, offset, matrix1, matrix2);
                        
                    }
                }
                block6flag = true;
            }
            
            copyF_NxN(N, M, matrix1, matrix2);
            checkData_NxN(N, M, matrix1);
            
        }
        
    }
    
    
    //recursive function to analyze the matrix with progressively larger offset
    // row reduces the matrix
    void arrayFunctionThing(int N, int M, int offset, bool flag1, bool flag2, double **mat1, double **mat2){
        
        //reset flag2 and dimension
        flag2 = false;
        
        //tracking
        cout << "Array function call for offset: " << offset << "\n" <<endl;
        
        //copy into the mirror
        copyF_NxN(N, M, mat1, mat2);
        
        //if decimals are present, set output precision to 1
        decimalCheck(N, M, mat2);
        
        // analysis function call
        analyzeF_NxN(N, M, offset, flag2, mat1, mat2);
        
        //increment offset
        offset++;
        
        //recursive step
        if(offset < N-1){
            arrayFunctionThing(N, M, offset, flag1, flag2, mat1, mat2);
        }
        
    }
    
    //pulls together functions to row reduce the matrix
    void matrix_NxN(char Flag){
        
        char contFlag = 'N';
        
        //read data if no random matrix was requested
        if(Flag == 'N' || Flag == 'n'){
            readData();
        } else{
            
            //pause to ask the user to continue
            cout << "Continue? (Y/N)" <<endl;
            cin >> contFlag;
        }
        
        //loop to catch continuation choice
        while(contFlag != 'Y' && contFlag != 'y'){
            cout << "\nContinue? (Y/N)" <<endl;
            cin >> contFlag;
        }
        
        //check & copy data
        checkData_NxN(N, M, matrix1);
        copyF_NxN(N, M, matrix1, matrix2);
        
        //first analysis function call
        analyzeF_NxN(N, M, offset, flag2, matrix1, matrix2);
        
        //recursive function call
        arrayFunctionThing(N, M, offset, flag1, flag2, matrix1, matrix2);
        
        //sort out last row
        scalM_NxN(N, M, 0, 1/matrix1[N-1][N-1], N-1, matrix1);
        //negativeZeroCheck(N, matrix1);
        
        copyF_NxN(N, M, matrix1, matrix2);
        
        //final set precision
        decimalCheck();
        
        //get rid of negative zeros
        negativeZeroCheck();
        
        cout << "\nResult:" <<endl;
        display();
    }
    
    //-------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------
    
    //functions relating to random matrix generation
    
    void setCap(){
        printf("Enter cap\n");
        scanf("%d", &randCap);
    }
    void setMix(){
        printf("Enter mix (0 to 10)\n");
        scanf("%d", &mix);
    }
    
    //create tally of positives, negatives, and zeros
    void tallySigns(){
        int posTally = 0;
        int zeroTally = 0;
        int negTally = 0;
        //
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(matrix1[i][j] > 0){
                    posTally++;
                }else if(matrix1[i][j] == 0){
                    zeroTally++;
                } else{
                    negTally++;
                }
            }
        }
        printf("There are %d positive numbers,\n%d zeros, and %d negative numbers in this matrix\n\n", posTally, zeroTally, negTally);
    }
    
    //populates a 2D dynamic array with random numbers
    void populate(){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                randSign = rand() % 10;
                if(randSign > mix){
                    matrix1[i][j] = rand() % (1+randCap);
                } else {
                    matrix1[i][j] = -(rand() % (1+randCap));
                }
            }
        }
    }
    
    //actually do stuff
    // this is a terrible method name
    void makeRandomMatrixAndDoStuff(){
        
        //seed random
        srand(time_t(NULL));
        
        // populate array with random numbers
        populate();
        
        //output matrix and tally
        display();
        tallySigns();
    }
    
    
};


#endif
