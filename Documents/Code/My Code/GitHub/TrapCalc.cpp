//
//  main.cpp
//  TrapezoidCalc
//
//
//  Created by Kiran Digavalli on 25/1/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//
//  Program to calculate the area of a trapezoid

// v2.1: area calculation from vertex coordinates
//
// Notes: This version has some issues - verticies must be entered in order (A,B,C,D not A,C,B,D)
// Otherwise, the Tsides become diagonals, and everything goes haywire. Secondly, it only works with trapezoids and parallelograms (which includes rectangles &  squares, obviously). If a completely wonky quadrilateral is entered, it will give an error. On the other hand, this calculator will work regardless of the position and angle of the trapezoid/parallelogram in question, and does not care where around the shape the user starts entering the verticies, so long as they are entered in order.


#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

struct lines {       // lines with properties slope and y-intercept
    double slope;
    double Y_intr;
} line1, line2, line3, line4, line5;

struct trapezoid {  // 4 sides AB, BC, CD, and DA with properties length (Tside) and slope
    double Tside;
    double slope;
} AB, BC, CD, DA;

struct Tpoints {   // verticies A, B, C, D, & point intersec with properties x-coordinate and y-coordinate
    double x;
    double y;
} A, B, C, D, intersec;

double distF(double a, double b, double c, double d){  // calculates distance between two points with
    double r;                                          // coordinates (a,c) and (b,d).
    r = fabs(sqrt(pow(a-b,2) + pow(c-d,2)));           // Outputs only positive.
    return r;
}

double slopeF(double m, double n, double p, double q){  // calculates slope of line defined by points
    double z;                                           // (m,p) and (n,q)
    z = ((p-q) / (m-n));
    return z;
}

double intrF(double u, double v, double s){  // calculates y-intercept of a line given point on it (u,v)
    double t;                                // and slope s
    t = (v - (s * u));
    return t;
}


int main(){
    
    //declare variables
    //most data is stored in the three structs before int main() - lines, trapezoid, and Tpoints
    
    double base1 = 0;
    double base2 = 0;
    double trapH = 0;
    
    double trapA = 0;
    
    
    //request and receive inputs
    
    cout << " " <<endl;
    cout << "Please ensure that the verticies are entered in order!" <<endl;
    cout << " " <<endl;
    
    cout << "Enter x-coordinate of vertex A" <<endl;
    cin >> A.x;
    cout << "Enter y-coordinate of vertex A" <<endl;
    cin >> A.y;
    
    cout << "Enter x-coordinate of vertex B" <<endl;
    cin >> B.x;
    cout << "Enter y-coordinate of vertex B" <<endl;
    cin >> B.y;
    
    cout << "Enter x-coordinate of vertex C" <<endl;
    cin >> C.x;
    cout << "Enter y-coordinate of vertex C" <<endl;
    cin >> C.y;
    
    cout << "Enter x-coordinate of vertex D" <<endl;
    cin >> D.x;
    cout << "Enter y-coordinate of vertex D" <<endl;
    cin >> D.y;
    
    
    // Generate side lengths using distF function.
    
     AB.Tside = distF(B.x, A.x, B.y, A.y);
     BC.Tside = distF(C.x, B.x, C.y, B.y);
     CD.Tside = distF(D.x, C.x, D.y, C.y);
     DA.Tside = distF(A.x, D.x, A.y, D.y);
    
    //generate line slopes using slopeF function.
    
    AB.slope = slopeF(B.y, A.y, B.x, A.x);
    BC.slope = slopeF(C.y, B.y, C.x, B.x);
    CD.slope = slopeF(D.y, C.y, D.x, C.x);
    DA.slope = slopeF(A.y, D.y, A.x, D.x);
    
    
    //check which slopes are equal, and assigns the lengths of the parallel pair of sides to base1 & base2
    
    if(AB.slope == CD.slope){
        base1 = AB.Tside;
        base2 = CD.Tside;
        
    } else if(BC.slope == DA.slope){
        base1 = BC.Tside;
        base2 = DA.Tside;
        
    } else {
        cout << "Error 1" <<endl;  // Gives error 1 if neither pair of sides is parallel, i.e. the shape
    }                              // is not a trapezoid
    
    
    //assign slope and y-intercept values to line1 and line2
    
    int whichLine = 0;
    
    if(AB.slope == CD.slope){
        whichLine = 1;            // If the first pair (AB and CD) are parallel, whichLine=1
        line1.slope = AB.slope;
        line2.slope = CD.slope;
        line1.Y_intr = intrF(A.x, A.y, line1.slope);
        line2.Y_intr = intrF(C.x, C.y, line2.slope);
        
    } else if(BC.slope == DA.slope){
        whichLine = 2;           // If the second pair (BC and DA) are parallel, whichLine=2
        line1.slope = BC.slope;
        line2.slope = DA.slope;
        line1.Y_intr = intrF(B.x, B.y, line1.slope);
        line2.Y_intr = intrF(D.x, D.y, line2.slope);
        
    } else {
        cout << "Error 2" <<endl;
    }
    
    
    
    // if the trapezoid is flat (parallel to the x-axis), the difference between the y-coordinates of the
    // bases is taken as the trapezoid's height
    
    if(line1.slope==0 && line2.slope==0){
        trapH = fabs(double (line1.Y_intr - line2.Y_intr));
    } else {
        
        // otherwise, we must calculate intersection of inverted_line 1, and line 2
       
        line5.slope = -1 * (1/line1.slope); //inverting line1's slope to get line5's slope
        
        
        // the y-intercept of the inverted line1 depends on which pair of sides were parallel, as recorded
        // in whichLine
        
        if(whichLine==1){
            line5.Y_intr = intrF(A.x, A.y, line5.slope);  //calling intrF function for whichCalc=1
        } else if (whichLine==2){
            line5.Y_intr = intrF(B.x, B.y, line5.slope);  //calling intrF function for whichCalc=2
        } else {
            cout << "Error 3" <<endl;
        }
        
        
        //actually doing the algebra to determine the point of intersection
        
        intersec.x = (line5.Y_intr - line2.Y_intr) / (line2.slope - line5.slope); //solving for x
        intersec.y = line2.slope * intersec.x + line2.Y_intr;                  //substituting in to get y
        
        if(whichLine==1){
            trapH = distF(intersec.x, A.x, intersec.y, A.y); //calling distF function
        } else if(whichLine==2){
            trapH = distF(intersec.x, B.x, intersec.y, B.y); //calling distF function
        } else {
            cout << "Error 4" <<endl;
        }
    
    }
    
    
    //calculate trapezoid area according to formula
    
    trapA = .5 * trapH * (base1 + base2);
    
    
    //output the result
    
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The area you requested is: " << setw(7) << trapA <<endl;
    cout << " " <<endl;
    
    //easter egg
    
    if(trapA == 42){
        cout << "Ayy lmao" <<endl;
    }
    
    
    // system("Pause") <------- Commented out here, but necessary in visual studio/windoge
    
    
    return 0;
}

