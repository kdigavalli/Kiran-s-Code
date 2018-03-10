//
//  mCalcHeaderNew.h
//  MatrixCalc
//
//  Created by Kiran Digavalli on 7/3/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//
//
// Note: many of these functions are of the return type "double" because, when I was creating them, I thought that void functions could not have any
// parameters. Obviously, this is not the case, but not all of the functions have been converted to void. Not sure if they need to be (?)

#ifndef MatrixCalc_mCalcHeaderNew_h
#define MatrixCalc_mCalcHeaderNew_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

//copy the values of mat1 into mat1
void copyF_2x2(double mat1[2][2], double mat2[2][2]){
    
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
            mat2[i][j] = mat1[i][j];
        }
    }
}

//copy the values of mat1 into mat1 for 3x3 matrices
void copyF_H(double mat1[3][3], double mat2[3][3]){
    
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            mat2[i][j] = mat1[i][j];
        }
    }
}

//display 2x2 array contents
void checkData_2x2 (double mat1[2][2]){
    
    cout << "" <<endl;
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
            cout << mat1[i][j] << " ";
        }
        cout <<endl;
    }
    cout << "" <<endl;
}

//display 3x3 array contents
void checkDataH (double mat1[3][3]){
    
    cout << "" <<endl;
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            cout << mat1[i][j] << " ";
        }
        cout <<endl;
    }
    cout << "" <<endl;
}

//swaps lines for 2x2 matrices
double lineSwap_2x2(double mat1[2][2], double mat2[2][2]){
    
    //method to swap lines
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
            if(i == 0){
                mat2[i][j] = mat1[i+1][j];
            } else if(i == 1){
                mat2[i][j] = mat1[i-1][j];
            } else {
                cout << "\nInterchange Error" <<endl;
            }
        }
    }
    
    //check data
    checkData_2x2(mat2);
    return 0;
}

//swaps the first two lines for 3x3 matrices
double lineSwap(double mat1[3][3], double mat2[3][3]){
    
    //method to swap lines
    for(int i=0; i<=1; i++){
        for(int j=0; j<=2; j++){
            if(i == 0){
                mat2[i][j] = mat1[i+1][j];
            } else if(i == 1){
                mat2[i][j] = mat1[i-1][j];
            } else {
                cout << "\nInterchange Error" <<endl;
            }
        }
    }
    
    //check data
    checkDataH(mat2);
    return 0;
}

//gives the scalar multiple of a particular row for 2x2 matrices
double scalM_2x2(double mult, int row, double mat1[2][2]){
    
    if(fabs(row)>1){
        cout << "\nScalM error" <<endl;
    }
    
    //scalar multiplication method
    for(int i=0; i<=1; i++){
        mat1[row][i] *= mult;
    }
    
    //check data
    checkData_2x2(mat1);
    
    return 0;
}

//gives the scalar multiple of a particular row for 3x3 matrices
double scalM(double mult, int row, double mat1[3][3]){
    
    if(fabs(row)>2){
        cout << "\nScalM error" <<endl;
    }
    
    //scalar multiplication method
    for(int i=0; i<=2; i++){
        mat1[row][i] *= mult;
    }
    
    //check data
    checkDataH(mat1);
    
    return 0;
}

//replaces a row with the sum of itself and the scalar multiple of another row for 2x2 matrices
double replaceF_2x2(double mult, int replaceRow, int multRow, double mat1[2][2], double mat2[2][2]){
    
    if(fabs(replaceRow) > 1 || fabs(multRow) > 1){
        cout << "\nReplaceF error" <<endl;
    }
    
    for(int i=0; i<=1; i++){
        mat2[replaceRow][i] += mult * mat1[multRow][i];
    }
    
    //check data
    checkData_2x2(mat2);
    return 0;
}

//replaces a row with the sum of itself and the scalar multiple of another row for 3x3 matrices
double replaceF(double mult, int replaceRow, int multRow, double mat1[3][3], double mat2[3][3]){
    
    if(fabs(replaceRow) > 2 || fabs(multRow) > 2){
        cout << "\nReplaceF error" <<endl;
    }
    
    for(int i=0; i<=2; i++){
        mat2[replaceRow][i] += mult * mat1[multRow][i];
    }
    
    //check data
    checkDataH(mat2);
    return 0;
}

//returns the absolute value of a row for 2x2 matrices
double absRow_2x2(int row, double mat1[2][2]){
    
    for(int i=0; i<=1; i++){
        mat1[row][i] = fabs(mat1[row][i]);
    }
    return 0;
}

//returns the absolute value of a row for 3x3 matrices
double absRow(int row, double mat1[3][3]){
    
    for(int i=0; i<=2; i++){
        mat1[row][i] = fabs(mat1[row][i]);
    }
    return 0;
}

//3x3 analysis function
double analyzeF_3x3(bool solvedFlag, bool block3Flag, double matrix[3][3], double matrix2[3][3]){
    
    do{
        //if the (0,0) element is 1
        if (matrix[0][0] == 1){
            
            cout << "\nBlock 1" <<endl;
            replaceF(-matrix[1][0], 1, 0, matrix, matrix2);
            copyF_H(matrix2, matrix);
            scalM((1/matrix[1][1]), 1, matrix);
            absRow(1, matrix);
            copyF_H(matrix, matrix2);
            solvedFlag = true;
            
            //if the (1,0) element is 1
        } else if(matrix[1][0] == 1){
            
            cout << "\nBlock 2" <<endl;
            lineSwap(matrix, matrix2);
            copyF_H(matrix2, matrix);
            
            //with the lines swapped, row reduction is implemented
            replaceF(-matrix[1][0], 1, 0, matrix, matrix2);
            copyF_H(matrix2, matrix);
            copyF_H(matrix2, matrix);
            scalM((1/matrix[1][1]), 1, matrix);
            absRow(1, matrix);
            copyF_H(matrix, matrix2);
            solvedFlag = true;
            
            // if neither of the above are true, we add multiples of the first row
            // to the second row, and if 0 or 1 results, we store that operation and break
        } else if(matrix[0][0] != matrix[1][0] && block3Flag == false){
            block3Flag = true;
            cout << "\nBlock 3" <<endl;
            
            for(int i=-9; i<=9; i++){
                
                // if 1 results, we swap lines
                if(i * matrix[0][0] + matrix[1][0] == 1){
                    cout << "\nBlock 3.1" <<endl;
                    replaceF(i, 1, 0, matrix, matrix2);
                    copyF_H(matrix2, matrix);
                    
                    lineSwap(matrix, matrix2);
                    copyF_H(matrix2, matrix);
                    block3Flag = true;
                    break;
                    
                    // if 0 results, we row-reduce to get a result
                } else if(i * matrix[0][0] + matrix[1][0] == 0){
                    cout << "\nBlock 3.2" <<endl;
                    replaceF(i, 1, 0, matrix, matrix2);
                    copyF_H(matrix2, matrix);
                    
                    lineSwap(matrix, matrix2);
                    copyF_H(matrix2, matrix);
                    block3Flag = true;
                    break;
                }
            }
        } else{  //brute force divide the first line by the inverse of (0,0) element, to get 1; cycles back around
            cout << "\nBlock4" <<endl;
            scalM(1/matrix[0][0], 0, matrix);
            copyF_H(matrix, matrix2);
        }
    } while(solvedFlag == false);
    
    copyF_H(matrix2, matrix);
    
    checkDataH(matrix);
    
    if(matrix[2][0] != 0){
        cout << "Block 6" <<endl;
        replaceF(-matrix[2][0], 2, 0, matrix, matrix2);
    }
    
    return 0;
}

//2x2 analysis function
double analyzeF_2x2(bool solvedFlag, bool block3Flag, bool linFlag, double matrix[2][2], double matrix2[2][2]){
    
    do{
        //linear dependency checking
        cout << "\nBlock 0" <<endl;
        for(int i=-100; i<=100; i++){
            if(i * matrix[0][0] == matrix[1][0] && i * matrix[0][1] == matrix[1][1]){
                cout << "\nLinear dependency present" <<endl;
                replaceF_2x2(-i, 1, 0, matrix, matrix2);
                copyF_2x2(matrix2, matrix);
                scalM_2x2(1/matrix[0][0], 0, matrix);
                copyF_2x2(matrix, matrix2);
                solvedFlag = true;
                linFlag = true;
                break;
            }
        }
        
        //if the (0,0) element is 1
        if (matrix[0][0] == 1 && linFlag == false){
            
            cout << "\nBlock 1" <<endl;
            replaceF_2x2(-matrix[1][0], 1, 0, matrix, matrix2);
            copyF_2x2(matrix2, matrix);
            scalM_2x2((1/matrix[1][1]), 1, matrix);
            absRow_2x2(1, matrix);
            copyF_2x2(matrix, matrix2);
            solvedFlag = true;
            
            //if the (1,0) element is 1
        } else if(matrix[1][0] == 1 && linFlag == false){
            
            cout << "\nBlock 2" <<endl;
            lineSwap_2x2(matrix, matrix2);
            copyF_2x2(matrix2, matrix);
            
            //with the lines swapped, row reduction is implemented
            replaceF_2x2(-matrix[1][0], 1, 0, matrix, matrix2);
            copyF_2x2(matrix2, matrix);
            copyF_2x2(matrix2, matrix);
            scalM_2x2((1/matrix[1][1]), 1, matrix);
            absRow_2x2(1, matrix);
            copyF_2x2(matrix, matrix2);
            solvedFlag = true;
            
            // if neither of the above are true, we add multiples of the first row
            // to the second row, and if 0 or 1 results, we store that operation and break
        } else if(solvedFlag == false && block3Flag == false  && linFlag == false && (matrix[0][0] != matrix[1][0])){
            cout << "\nBlock 3" <<endl;
            
            for(int i=-9; i<=9; i++){
                
                // if 1 results, we swap lines
                if(i * matrix[0][0] + matrix[1][0] == 1){
                    cout << "\nBlock 3.1" <<endl;
                    replaceF_2x2(i, 1, 0, matrix, matrix2);
                    copyF_2x2(matrix2, matrix);
                    
                    lineSwap_2x2(matrix, matrix2);
                    copyF_2x2(matrix2, matrix);
                    block3Flag = true;
                    break;
                    
                    // if 0 results, we row-reduce to get a result
                } else if(i * matrix[0][0] + matrix[1][0] == 0){
                    cout << "\nBlock 3.2" <<endl;
                    replaceF_2x2(i, 1, 0, matrix, matrix2);
                    copyF_2x2(matrix2, matrix);
                    
                    lineSwap_2x2(matrix, matrix2);
                    copyF_2x2(matrix2, matrix);
                    block3Flag = true;
                    break;
                }
            }
        } else if(solvedFlag == false && block3Flag == false && linFlag == false){  // brute force divide the first line by the inverse of
            cout << "\nBlock4" <<endl;                                               // (0,0) element, to get 1; cycles back around
            scalM_2x2(1/matrix[0][0], 0, matrix);
        }
        
    } while(solvedFlag == false);
    
    return 0;
}

#endif

