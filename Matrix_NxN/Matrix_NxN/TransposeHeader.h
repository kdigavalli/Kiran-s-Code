//
//  TransposeHeader.h
//  Matrix_NxN
//
//  Created by Kiran Digavalli on 6/5/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

#ifndef Matrix_NxN_TransposeHeader_h
#define Matrix_NxN_TransposeHeader_h


class transpose{
    
private:
    
    int M;
    int N;
    double **mat1;
    double **mat2;
    
    
public:
    
    //default constructor
    transpose(){
        M = 0;
        N = 0;
        
        //initialize dynamic 2D arrays
        mat1 = new double *[M];
        mat2 = new double *[N];
        
        for(int i=0; i<M; i++){
            mat1[i] = new double[N];
        }
        for(int i=0; i<N; i++){
            mat2[i] = new double[M];
        }
    }
    
    //constructor with arguments
    transpose(int rows, int cols){
        M = rows;
        N = cols;
        
        //initialize dynamic 2D arrays
        mat1 = new double *[M];
        mat2 = new double *[N];
        
        for(int i=0; i<M; i++){
            mat1[i] = new double[N];
        }
        for(int i=0; i<N; i++){
            mat2[i] = new double[M];
        }
    }
    
    //read data into an MxN array
    void readData(){
        
        cout << "\nEnter MxN matrix separated by spaces\n"  <<endl;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                cin >> mat1[i][j];
            }
        }
    }
    
    //display contents of NxN array
    void checkData(){
        
        cout << "" <<endl;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                cout << mat1[i][j] << " ";
            }
            cout <<endl;
        }
        cout << "" <<endl;
    }
    
    void checkData(int N, double **matrix){
        cout << "" <<endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cout << matrix[i][j] << " ";
            }
            cout <<endl;
        }
        cout << "" <<endl;
    }

    
    //makes mat2 into the transpose of mat1
    void matrixTranspose(){
        
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                mat2[j][i] = mat1[i][j];
            }
        }
    }
    
    //returns trace of matrix (sum along main diagonal)
    double traceF(){
        double sum = 0;
        for(int i=0; i<M; i++){
            sum += mat1[i][i];
        }
        return sum;
    }
    
    //returns determinant of 2x2 matrix
    double detF_2x2(){
        return (mat1[0][0] * mat1[1][1]) - (mat1[0][1] * mat1[1][0]);
    }
    
    //returns determinant of 3x3 matrix
    double detF_3x3(){
        return
        mat1[0][0]*((mat1[1][1] * mat1[2][1]) - (mat1[1][2] * mat1[2][1]))-
        mat1[0][1]*((mat1[1][0] * mat1[2][2]) - (mat1[1][2] * mat1[2][0]))+
        mat1[0][2]*((mat1[1][0] * mat1[2][1]) - (mat1[1][1] * mat1[2][0]));
    }
    
    //does stuff
    void doStuff(){
        
        //initialize local variables
        double trace = 0;
        double determinant = 0;
        
        //read and check data
        readData();
        cout << "\nYou have entered the matrix:" <<endl;
        checkData();
        
        //calculate trace
        trace = traceF();
        
        //calculate determinant if possible
        if(N==2 && M==2){
            determinant = detF_2x2();
        } else if(N==3 && M==3){
            determinant = detF_3x3();
        } else{
            cout << "Determinant calculation is not supported for this matrix\n" <<endl;
        }
        
        //calculate transpose
        matrixTranspose();
        
        //output results
        cout << "The transpose of the matrix you entered is:" <<endl;
        checkData(N, mat2);
        cout << "Its trace is: " << trace <<endl;
        if(N<=3 && M<=3){
            cout << "\nAnd its determinant is: " << determinant <<endl;
        }
    }
    
};


#endif
