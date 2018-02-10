//
//  main.cpp
//  VectorCalc
//
//  Created by Kiran Digavalli on 30/1/18.
//  Co-authored by Nick Nusgart
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
//  so the variable declaration section isn't enormous, v5.4 tries to use a do-while loop to allow the user to make
//  more calculations after the first has been completed, and v5.5 uses some clever trickery with objects to clean up
//  functions, and also fixes a bug with the do-while loop by using cin.clear()
//
//  to compile directly on mac/linux: cd into the folder containing this program file, then open a terminal
//  and type g++ -o exec_name main.cpp


#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

//represents a vector (three-dimensional)
struct vector {
    double i;
    double j;
    double k;
};

//values used in the calculation of the angle between two vectors
struct magnitudes {
    double a;
    double b;
    double cross;
};

double dotF(struct vector v, struct vector w){
    return v.i * w.i + v.j * w.j + v.k * w.k;
}

double magF(struct vector v){
    return sqrt(dotF(v,v));
}

struct vector crossF(struct vector v, struct vector w){
    return (struct vector){v.j * w.k - v.k * w.j , v.k * w.i - v.i * w.k, v.i * w.j - v.j * w.i };
}


int main() {
    //declare variables
    //note: most of the data is stored in the two structs before int main()
    
    double dotp = 0;
    
    double scalM = 0;
    
    double thetaRad = 0;
    
    struct magnitudes mag = {};
    
    struct vector first = {};
    struct vector sec = {};
    struct vector out = {};
    struct vector scal = {};
    
    string whichCalc = "0";
    string which1 = "1";
    string which2 = "2";
    string which3 = "3";
    string which4 = "4";
    
    char cycle = 'N';
    
    //General info for the user
    
    cout << "\nVectorCalc v5.5" <<endl;
    cout << "---------------" <<endl;
    cout << "(c) K.Digavalli\n" <<endl;
    
    
    do{
        
        //input clearing
        cin.clear();
        
        //spacing if needed
        if(cycle == 'y' || cycle == 'Y'){
            cout << " " <<endl;
        }
        
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
        out = crossF(first, sec);
        
        //calculate dot product using the DotF function
        dotp = dotF(first, sec);
        
        //calculate scalar multiple
        scal.i = scalM * first.i;
        scal.j = scalM * first.j;
        scal.k = scalM * first.k;
        
        //generate the magnitudes of the vectors using MagF
        mag.a = magF(first);
        mag.b = magF(sec);
        mag.cross = magF(out);
        
        //calculate angle between vectors
        thetaRad = asin(mag.cross / (mag.a * mag.b));
        
        //output the requested result according to the value of whichCalc
        if(whichCalc==which1){
            cout << "The cross-product you requested is: <" << out.i << "," << out.j << "," << out.k << ">" <<endl;
        } else if(whichCalc==which2){
            cout << "The dot-product you requested is: " << dotp <<endl;
        } else if(whichCalc==which3){
            cout << "The scalar multiple you requested is: <" << scal.i << "," << scal.j << "," << scal.k << ">" <<endl;
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
        
        //input clearing
        cin.clear();
        string ignore;
        getline(cin,ignore);
        
    } while (cycle == 'y' || cycle == 'Y');
    //system("pause");  <--- commented out here, but necessary in visual studio/windoge
    
    return 0;
}
