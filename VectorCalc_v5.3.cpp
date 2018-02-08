//
//  main.cpp
//  VectorCalc4
//
//  Created by Kiran Digavalli on 30/1/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//
//  Version notes: v1 was a crappy cross-p calculator written in python one rainy day. v2 was in c++, v3
//  added dot-p, v3.1 added conventional vector format for the output ( <a,b,c> ), v3.2 added user selection
//  of the calculation to be performed, v4 added scalar multiplication, v4.1 added a catch for invalid
//  selection, v4.2 added a better, while-loop based catch, v4.3 added error trapping for invalid selections,
//  v5.0 adds factored out functions and the ability to calculate the angle between two vectors
//  v5.1 used a class and some trickery to calculate the cross product, instead of just working it out;
//  it took up a lot more space, but I created the class just for the heck of it.
//  v5.2 got rid of the class and replaced it with a much more concise function which works for all three components
//  of the cross product (with a little tweaking). v5.3 stores a bunch of informations in structs,
//  so the variable declaration section isn't enormous
//
//  to compile directly on mac/linux: cd into the folder containing this program file, then open a terminal
//  and type g++ -o exec_name main.cpp


#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

struct vector {
    double i;
    double j;
    double k;
};

double dot(struct vector v, struct vector w){
   return v.i * w.i + v.j * w.j + v.k * w.k;
}

double DotF (double a, double b, double c, double d, double e, double f){
    double dP = 0;
    dP = a * d + b * e + c * f;
    return dP;
}

double magnitude(struct vector v){
  return sqrt(dot(v,v));
}

double MagF (double a, double b, double c){
    double Vmag = 0;
    Vmag = sqrt(pow(a,2) + pow(b,2) + pow(c,2));
    return Vmag;
}

double CrossF(double p, double q, double m, double n){
    double cross = 0;
    cross = p * q - m * n;
    return cross;
}

struct vector cross(struct vector v, struct vector w){
  return (struct vector){v.j * w.k - v.k * w.j , v.k * w.i - v.i * w.k, v.i * w.j - v.j * w.i };
}

struct magnitudes {
    double a;
    double b;
    double cross;
} mag;

int main() {
    //declare variables
    //note: most of the data is stored in the two structs before int main()
    
    double dotp;
    
    double scalM;
    
    double thetaRad = 0;
    
    struct vector first ={};
    struct vector sec = {};
    struct vector out = {};
    struct vector scal = {};
    
    string whichCalc = "0";
    string which1 = "1";
    string which2 = "2";
    string which3 = "3";
    string which4 = "4";
    
    char cycle = '0';
    
    //General info for the user
    
    cout << "\nVectorCalc v5.3" <<endl;
    cout << "---------------" <<endl;
    cout << "(c) K.Digavalli\n" <<endl;

    
    do{
	    cin.clear(); //input clearing
		
	    //which computation does the user require?
	    cout<< "Which calculation would you like to perform? For cross-product enter 1; for dot-product enter 2; for scalar multiplication enter 3; for the angle between two vectors enter 4" <<endl;
    
	    //error trapping
	    while(1){                                              //catching invalid selections with a while loop
	        getline(cin,whichCalc);                            //The (1) is always true for the while loop
	        if(whichCalc == which1 || whichCalc == which2 || whichCalc == which3 || whichCalc == which4){
	            break;                                         //breaks if whichCalc is a valid selection (1,2,3,or 4)
	        }else{
	            cout << "Invalid entry, genius. For cross-product enter 1; for dot-product enter 2; for scalar multiplication enter 3; for the angle between two vectors enter 4" <<endl;
	        }
	    }
    
	    //request & receive inputs
	    if(whichCalc==which3){
	        cout << "enter scalar muliplier" <<endl;
	        cin >> scalM;
        
	        cout << "enter i" <<endl;
	        cin >> first.i;
	        cout << "enter j" <<endl;
	        cin >> first.j;
	        cout << "enter k" <<endl;
	        cin >> first.k;
        
	    } else {
	        cout << "enter first i" <<endl;
	        cin >> first.i;
	        cout << "enter first j" <<endl;
	        cin >> first.j;
	        cout << "enter first k" <<endl;
	        cin >> first.k;
        
	        cout << "enter second i" <<endl;
	        cin >> sec.i;
	        cout << "enter second j" <<endl;
	        cin >> sec.j;
	        cout << "enter second k" <<endl;
	        cin >> sec.k;
	    }
    
	    //calculate cross product using the CrossF function
    	    out = cross(first, sec);
    	    #if 0
	    out.i = CrossF(first.j, sec.k, first.k, sec.j);
	    out.j = CrossF(first.k, sec.i, first.i, sec.k);       //for some reason, the correct order of arguments for the j component
	    out.k = CrossF(first.i, sec.j, first.j, sec.i);       // produces a negative result, so I flipped it
    	    #endif 

	    //calculate dot product using the DotF function
	    //dotp = DotF(first.i, first.j, first.k, sec.i, sec.j, sec.k);
    	    dotp = dot(first, sec);

	    //calculate scalar multiple
	    scal.i = scalM * first.i;
	    scal.j = scalM * first.j;
	    scal.k = scalM * first.k;
    
	    //generate the magnitudes of the vectors using MagF
	    mag.a = magnitude(first);
	    mag.b = magnitude(sec);
	    mag.cross = magnitude(out);
	    #if 0
	    mag.a = MagF(first.i, first.j, first.k);
	    mag.b = MagF(sec.i, sec.j, sec.k);
	    mag.cross = MagF(out.i, out.j, out.k);
    	    #endif
	    //calculate angle between vectors
	    thetaRad = asin(mag.cross / (mag.a * mag.b));
    
	    //output the requested result according to the value of whichCalc
	    if(whichCalc==which1){
	        cout << "The cross-product you requested is: <" <<out.i<< "," <<out.j<< "," <<out.k<< ">" <<endl;
	    } else if(whichCalc==which2){
	        cout << "The dot-product you requested is: " <<dotp<<endl;
	    } else if(whichCalc==which3){
	        cout << "The scalar multiple you requested is: <" <<scal.i<< "," <<scal.j<< "," <<scal.k << ">" <<endl;
	    } else if (whichCalc==which4){
	        cout << "The angle between the two vectors you entered is: " << setprecision(4) << thetaRad << " radians." <<endl;
	    } else {
	        cout << "Error 1" <<endl;
	    }

	    //easter egg
	    if(whichCalc==which2 && dotp==42){
	        cout << "ayy lmao"<<endl;
	    }
    
            cout << "Do you wish to perform another calcuation? (Y or N)" <<endl;
	    cin >> cycle;
		
    } while (cycle == 'y' || cycle == 'Y');
    //system("pause");  <--- commented out here, but necessary in visual studio/windoge
    return 0;
}
