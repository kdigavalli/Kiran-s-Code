//
//  main.cpp
//  RectangleClassThing
//
//  Created by Kiran Digavalli on 14/4/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//

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
        cout << "Enter length" <<endl;
        cin >> length;
        cout << "Enter width" <<endl;
        cin >> width;
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
            cout << "This rectangle is a square!!" <<endl;
        }
    }
};



int main(){
    
    //declare instance of rectangle class
    rectangle rect1;
    
    //set dimensions
    rect1.setDims();
    
    //output dimensions
    rect1.outputDims();
    
    //output perimeter and area
    cout << "\nPerimeter: " << rect1.perimeter() <<endl;
    cout << "Area: " << rect1.area() <<endl;

    
    return 0;
}