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
#include <ctime>
#include "NewMatrixHeader.h"
#include "NxN_Header.h"

using namespace std;

int main(){

    //initialize dimension variables
    int N = 0;
    int M = 0;
    
    //initialize flags
    char randFlag = 'N';
    char intFlag = 'N';
    
    //request & receive dimensions from user
    //note: M and N are reversed here to make the program easier to use
    //conventionally, matrix dimensions are listed as MxN, but this program uses NxM internally
    cout << "For an MxN matrix, enter M" <<endl;
    cin >> N;
    cout << "Enter N" <<endl;
    cin >> M;
    
    //error trapping
    while(N > M){
        cout << "\nInvalid entry. N must be less than or equal to M" <<endl;
        cout << "Enter M" <<endl;
        cin >> N;
        cout << "Enter N" <<endl;
        cin >> M;
    }
    
    //set output precision if non integer entries
    cout << "\nNon integer entries? (Y or N)" <<endl;
    cin >> intFlag;
    cout << "\n";
    
    if(intFlag == 'Y' || intFlag == 'y'){
        cout.setf(ios::fixed);
        cout.precision(1);
    }
    
    //determine whether the user requires a random matrix
    if(N>3 && M>3){
        cout << "Would you like a random matrix? (Y or N)" <<endl;
        cin >> randFlag;
    }
    
    //if matrix is 2x2, old 2x2 analysis methods are used
    if(N==2 && M==2){
        matrix_2x2();
    //if the matrix is 3x3, old 3x3 analysis methods are used
    } else if(N==3 && M==3){
        matrix_3x3();
    //otherwise, we proceed with dynamic arrays and new stuff
    } else{
        
        //create matrix object
        matrix newMatrix(N, M);
        
        //generate random matrix if requested
        if(randFlag == 'y' || randFlag == 'Y'){
            newMatrix.setCap();
            newMatrix.setMix();
            newMatrix.doStuff();
        }
        
        //perform analysis
        newMatrix.matrix_NxN(randFlag);
    }
    
    return 0;
}