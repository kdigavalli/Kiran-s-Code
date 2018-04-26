//
//  NewMatrixHeader.h
//  Matrix_NxN
//
//  Created by Kiran Digavalli on 8/4/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//

#ifndef Matrix_NxN_NewMatrixHeader_h
#define Matrix_NxN_NewMatrixHeader_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

//read data into a 3x3 array
void readData(double mat1[3][3]){
    
    cout << "\nEnter 3x3 matrix separated by spaces\n"  <<endl;
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            cin >> mat1[i][j];
        }
    }
}

//read data into a 2x2 array
void readData_2x2(double mat1[2][2]){
    
    cout << "\nEnter 2x2 matrix separated by spaces\n"  <<endl;
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
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

//copy the values of mat1 into mat1
void copyF_2x2(double mat1[2][2], double mat2[2][2]){
    
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
            mat2[i][j] = mat1[i][j];
        }
    }
}

//copy the values of mat1 into mat1 for 3x3 matrices. H for header file
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

//display 3x3 array contents. H for header file
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

//returns sum of along the main diagonal of 2x2 array
double diagonalSum_2x2(double mat1[2][2]){
    
    double sum = 0;
    for(int i=0; i<2; i++){
        sum += mat1[i][i];
    }
    return sum;
}

//returns sum of all elements of 2x2 array
double matrixSum_2x2(double mat1[2][2]){
    
    double sum = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            sum += mat1[i][j];
        }
    }
    return sum;
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
        } else if(matrix[0][0] != matrix[1][0] && !block3Flag){
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
    } while(!solvedFlag);
    
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
    
    //sum of all components and sum along the main diagonal
    int fullSum = matrixSum_2x2(matrix);
    int diaSum = diagonalSum_2x2(matrix2);

    if(fullSum == diaSum && diaSum == 2){
        cout << "This is the identity matrix" << endl;
    } else{
        
        do{
            //linear dependency checking
            for(int i=-100; i<=100; i++){
                if(i * matrix[0][0] == matrix[1][0] && i * matrix[0][1] == matrix[1][1]){
                    cout << "\nBlock 0" <<endl;
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
            if (matrix[0][0] == 1 && !linFlag){
                
                cout << "\nBlock 1" <<endl;
                replaceF_2x2(-matrix[1][0], 1, 0, matrix, matrix2);
                copyF_2x2(matrix2, matrix);
                scalM_2x2((1/matrix[1][1]), 1, matrix);
                absRow_2x2(1, matrix);
                copyF_2x2(matrix, matrix2);
                solvedFlag = true;
                
                //if the (1,0) element is 1
            } else if(matrix[1][0] == 1 && !linFlag){
                
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
            } else if(!solvedFlag && !block3Flag  && !linFlag && (matrix[0][0] != matrix[1][0])){
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
            } else if(!solvedFlag && !block3Flag && !linFlag){  // brute force divide the first line by the inverse of
                cout << "\nBlock4" <<endl;                                               // (0,0) element, to get 1; cycles back around
                scalM_2x2(1/matrix[0][0], 0, matrix);
            }
            
        } while(!solvedFlag);
    }
    
    
    
    return 0;
}


void matrix_3x3(){
    
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

}


void matrix_2x2(){
    
    //create 2x2 matrices
    double matrix [2][2] = {};
    double matrix2 [2][2] = {};
    
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    
    //read in data
    readData_2x2(matrix);
    
    //check data
    cout << "\nEntry:" <<endl;
    checkData_2x2(matrix);
    
    copyF_2x2(matrix, matrix2);
    
    analyzeF_2x2(flag1, flag2, flag3, matrix, matrix2);
    
    checkData_2x2(matrix);
}


#endif
