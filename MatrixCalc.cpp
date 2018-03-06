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

using namespace std;

double checkData (double mat1[2][2]){
    
    //display array contents
    cout << "" <<endl;
    cout << mat1[0][0] << " " << mat1[0][1] <<endl;
    cout << mat1[1][0] << " " << mat1[1][1] <<endl;

    return 0;
}

double copyF(double mat1[2][2], double mat2[2][2]){
    
    //copy the values of mat1 into mat1
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
            mat2[i][j] = mat1[i][j];
        }
    }
    return 0;
}


double lineSwap(double mat1[2][2], double mat2[2][2]){
    
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
    cout << "" <<endl;
    cout << mat2[0][0] << " " << mat2[0][1] <<endl;
    cout << mat2[1][0] << " " << mat2[1][1] <<endl;
    cout << "" <<endl;
    
    return 0;
}


double scalM(double mult, int row, double mat1[2][2]){
    
    if(fabs(row)>1){
        cout << "\nScalM error" <<endl;
    }
    
    //scalar multiplication method
    for(int i=0; i<=1; i++){
        mat1[row][i] *= mult;
    }
    
    //check data
    cout << "" <<endl;
    cout << mat1[0][0] << " " << mat1[0][1] <<endl;
    cout << mat1[1][0] << " " << mat1[1][1] <<endl;
    
    return 0;
}

double replaceF(double mult, int replaceRow, int multRow, double mat1[2][2], double mat2[2][2]){
    
    if(fabs(replaceRow)>1 || fabs(multRow) >1){
        cout << "\nReplaceF error" <<endl;
    }
    
    for(int i=0; i<=1; i++){
        mat2[replaceRow][i] += mult * mat1[multRow][i];
    }
    
    //check data
    cout << "" <<endl;
    cout << mat2[0][0] << " " << mat2[0][1] <<endl;
    cout << mat2[1][0] << " " << mat2[1][1] <<endl;
    cout << "" <<endl;
    
    return 0;
}

double absRow(int row, double mat1[2][2]){
    
    for(int i=0; i<=1; i++){
        mat1[row][i] = fabs(mat1[row][i]);
    }
    return 0;
}

double analyzeF(bool solvedFlag, bool block3Flag, double matrix[2][2], double matrix2[2][2]){
    
    do{
        //if the (0,0) element is 1
        if (matrix[0][0] == 1){
            
            cout << "\nBlock 1" <<endl;
            replaceF(-matrix[1][0], 1, 0, matrix, matrix2);
            copyF(matrix2, matrix);
            scalM((1/matrix[1][1]), 1, matrix);
            absRow(1, matrix);
            copyF(matrix, matrix2);
            solvedFlag = true;
            
            //if the (1,0) element is 1
        } else if(matrix[1][0] == 1){
            
            cout << "\nBlock 2" <<endl;
            lineSwap(matrix, matrix2);
            copyF(matrix2, matrix);
            
            //with the lines swapped, row reduction is implemented
            replaceF(-matrix[1][0], 1, 0, matrix, matrix2);
            copyF(matrix2, matrix);
            copyF(matrix2, matrix);
            scalM((1/matrix[1][1]), 1, matrix);
            absRow(1, matrix);
            copyF(matrix, matrix2);
            solvedFlag = true;
            
            // if neither of the above are true, we add multiples of the first row
            // to the second row, and if 0 or 1 results, we store that operation and break
        } else if(solvedFlag == false && block3Flag == false && (matrix[0][0] != matrix[1][0])){
            cout << "\nBlock 3" <<endl;
            
            for(int i=-9; i<=9; i++){
                
                // if 1 results, we swap lines
                if(i * matrix[0][0] + matrix[1][0] == 1){
                    cout << "\nBlock 3.1" <<endl;
                    replaceF(i, 1, 0, matrix, matrix2);
                    copyF(matrix2, matrix);
                    
                    lineSwap(matrix, matrix2);
                    copyF(matrix2, matrix);
                    block3Flag = true;
                    break;
                    
                    // if 0 results, we row-reduce to get a result
                } else if(i * matrix[0][0] + matrix[1][0] == 0){
                    cout << "\nBlock 3.2" <<endl;
                    replaceF(i, 1, 0, matrix, matrix2);
                    copyF(matrix2, matrix);
                    
                    lineSwap(matrix, matrix2);
                    copyF(matrix2, matrix);
                    block3Flag = true;
                    break;
                }
            }
            
        } else if(solvedFlag == false){  //linear dependency checking
            cout << "\nBlock 4" <<endl;
            for(int i=-100; i<=100; i++){
                if(i * matrix[0][0] == matrix[1][0] && i * matrix[0][1] == matrix[1][1]){
                    cout << "\nLinear dependency present" <<endl;
                    replaceF(-i, 1, 0, matrix, matrix2);
                    copyF(matrix2, matrix);
                    scalM(1/matrix[0][0], 0, matrix);
                    copyF(matrix, matrix2);
                    solvedFlag = true;
                    break;
                }
            }
        } else{  //brute force divide the first line by the inverse of (0,0) element, to get 1; cycles back around
            cout << "\nBlock5" <<endl;
            scalM(1/matrix[0][0], 0, matrix);
        }
    } while(solvedFlag == false);
    
    return 0;
}

int main(){
    
    //create 2x2 matrices
    double matrix [2][2] = {};
    double matrix2 [2][2] = {};
    
    bool flag1 = false;
    bool flag2 = false;
    
    //read in data
    cout << "Enter 2x2 integer matrix separated by spaces\n" <<endl;
    cin >> matrix[0][0] >> matrix[0][1] >> matrix[1][0] >> matrix[1][1];
    
    //check data
    cout << "\nEntry:" <<endl;
    checkData(matrix);
    
    copyF(matrix, matrix2);
    
    analyzeF(flag1, flag2, matrix, matrix2);
    
    checkData(matrix);
    
    
    return 0;
}

