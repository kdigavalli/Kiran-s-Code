//
//  main.cpp
//  RectangleClassThing
//
//  Created by Kiran Digavalli on 14/4/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//
//  Rectangle class program

#include <iostream>
#include <cmath>

using namespace std;

class rectangle{
    
private:
    double length;
    double width;
    
public:
    
    //constructors
    rectangle(){
        length = 0;
        width = 0;
    }
    rectangle(double a, double b){
        length = a < 0 ? 0 : a;
        width = b < 0 ? 0 : b;
    }
    
    //setter
    void setDims(){
        
        //error trapping with a for loop
        cout << "Enter length" <<endl;
        while(1){
            cin >> length;
            if(length >= 0 && length <= 20){
                break;
            }else{
                cout << "Invalid entry. Enter a length between 0 and 20" <<endl;
            }
        }
        cout << "Enter width" <<endl;
        while(1){
            cin >> width;
            if(width >= 0 && width <= 20){
                break;
            }else{
                cout << "Invalid entry. Enter a width between 0 and 20" <<endl;
            }
        }
    }
    void setDimsArg(double a, double b){
        length = a;
        width = b;
    }
    
    //getters
    double getLength(){
        return length;
    }
    double getWidth(){
        return width;
    }
    void outputDims(){
        cout << "\nLength: " << length <<endl;
        cout << "Width: " << width <<endl;
    }
    
    //other stuff
    double perimeter(){
        return 2 * (length + width);
    }
    double area(){
        return length * width;
    }
    void squareCheck(){
        if(length == width){
            cout << "\nThis rectangle is a square!!" <<endl;
        }
    }
};



int main(){
    
    //declare instance of rectangle class
    rectangle rect1;
    
    //set dimensions
    rect1.setDims();
    
    //square check
    rect1.squareCheck();
    
    //output dimensions
    rect1.outputDims();
    
    //output perimeter and area
    cout << "\nPerimeter: " << rect1.perimeter() <<endl;
    cout << "Area: " << rect1.area() <<endl;
    
    return 0;
}