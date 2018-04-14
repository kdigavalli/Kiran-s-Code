//
//  main.cpp
//  Lab10_Revision
//
//  Created by Kiran Digavalli on 8/4/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

//read data into an MxN array
void readData(int M, int N, double *mat1[M]){
    
    cout << "Enter MxN matrix separated by spaces\n"  <<endl;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> mat1[i][j];
        }
    }
}

//display contents of NxN array
void checkData(int M, int N, double *mat1[M]){
    
    cout << "" <<endl;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout << mat1[i][j] << " ";
        }
        cout <<endl;
    }
    cout << "" <<endl;
}

//makes mat2 into the transpose of mat1
void matrixTranspose(int M, int N, double *mat[M], double *tpose[N]){
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            tpose[j][i] = mat[i][j];
        }
    }
}

//returns trace of matrix (sum along main diagonal)
double traceF(int M, double *mat1[M]){
    double sum = 0;
    for(int i=0; i<M; i++){
        sum += mat1[i][i];
    }
    return sum;
}

//returns determinant of 2x2 matrix
double detF_2x2(int N, double *mat1[N]){
    return (mat1[0][0] * mat1[1][1]) - (mat1[0][1] * mat1[1][0]);
}

//returns determinant of 3x3 matrix
double detF_3x3(int N, double *mat1[N]){
    return
    mat1[0][0]*((mat1[1][1] * mat1[2][1]) - (mat1[1][2] * mat1[2][1]))-
    mat1[0][1]*((mat1[1][0] * mat1[2][2]) - (mat1[1][2] * mat1[2][0]))+
    mat1[0][2]*((mat1[1][0] * mat1[2][1]) - (mat1[1][1] * mat1[2][0]));
}


int main(){
    
    //initialize variables
    int M = 0;
    int N = 0;
    double trace = 0;
    double determinant = 0;
    
    //request & receive dimension from user
    cout << "For an MxN matrix, enter M" <<endl;
    cin >> M;
    cout << "Enter N" <<endl;
    cin >> N;
    
    //initialize dynamic 2D arrays
    double **matrix1;
    double **transpose1;

    matrix1 = new double *[M];
    transpose1 = new double *[N];
    
    for(int i=0; i<M; i++){
        matrix1[i] = new double[N];
    }
    
    for(int i=0; i<N; i++){
        transpose1[i] = new double[M];
    }
    
    //read and check data
    readData(M, N, matrix1);
    cout << "\nYou have entered the matrix:" <<endl;
    checkData(M, N, matrix1);
    
    //calculate trace
    trace = traceF(M, matrix1);
    
    //calculate determinant if possible
    if(N==2 && M==2){
        determinant = detF_2x2(N, matrix1);
    } else if(N==3 && M==3){
        determinant = detF_3x3(N, matrix1);
    } else{
        cout << "Determinant calculation is not supported for this matrix\n" <<endl;
    }
    
    //calculate transpose
    matrixTranspose(M, N, matrix1, transpose1);
    
    //output results
    cout << "The transpose of the matrix you entered is:" <<endl;
    checkData(N, M, transpose1);
    cout << "Its trace is: " << trace <<endl;
    if(N<=3 && M<=3){
        cout << "\nAnd its determinant is: " << determinant <<endl;
    }

    
    
    
    
    return 0;
}