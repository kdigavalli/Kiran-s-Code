//
//  main.cpp
//  GroceryCalc
//
//  Created by Kiran Digavalli on 30/1/18.
//  Copyright (c) 2018 Midwest Aerospace Workshop. All rights reserved.
//


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main(){
    
    //declare variables
    
    double subtotal = 0;
    const double tax = 1.0625;
    double total = 0;
    double amt_tend = 0;
    double change = 0;
    
    // set output precision
    
    cout.setf(ios::fixed);
    cout.precision(2);
    
    //general info for the user
    
    cout << " " <<endl;
    cout << "Virtual Cash Register v1.1" <<endl;
    cout << "--------------------------" <<endl;
    cout << "     (c) K.Digavalli      " <<endl;
    cout << " " <<endl;
    cout << " " <<endl;
    
    //=================================================================================================
    //selecting fixed price or by weight calculation
    
    //declare variables
    
    string whichBuy = "0";
    string whichBuy1 = "1";
    string whichBuy2 = "2";
    
    //request choice between fixed price goods and by weight goods
    
    cout << "Are you purchasing fixed price items or goods by weight?\n" <<endl;
    cout << "For fixed price items, enter 1. For goods by weight, enter 2." <<endl;
    
    //error trapping
    
    while(1){                                                 //catching invalid selections with a while loop
        getline(cin,whichBuy);                                //The (1) is always true for the while loop
        if(whichBuy == whichBuy1 || whichBuy == whichBuy2){
            break;                                            //breaks if whichBuy is a valid selection (1 or 2)
        }else{
            cout << " " <<endl;
            cout << "Invalid entry. For fixed price items, enter 1. For goods by weight, enter 2." <<endl;
        }
    }
    
    
    //initiate the appropriate block of code
    
    if(whichBuy == whichBuy1){    // if fixed price goods are being bought
        
        //declare variables
        
        double fixed_price = 0;
        int quant = 0;
        
        //request and recieve inputs
        
        cout << "Enter item price" <<endl;
        cin >> fixed_price;
        cout << "Item price: $      " << setw(10) << fixed_price <<endl;
        cout << " " <<endl;
        cout << "Enter item quantity" <<endl;
        cin >> quant;
        cout << "Item quantity:     " << setw(10) << quant <<endl;
        cout << " " <<endl;
        
        //calculate subtotal
        
        subtotal = fixed_price * quant;
        
    } else if (whichBuy == whichBuy2){   // if goods by weight are being bought
        
        //declare variables
        
        string whichGood = "0";
        string whichGood1 = "1";
        string whichGood2 = "2";
        
        double rate = 0;
        double weight = 0;
        
        //request and receive inputs
        
        cout << "\nWhat are you purchasing? \n" <<endl;
        cout << "The rate for dry goods (rice, oats, flour, e.t.c.) is $1.00 per kg. \n" <<endl;
        cout << "The rate for produce (fruit and vegetables) is $2.00 per kg. \n" <<endl;
        cout << "For dry goods, enter 1. For produce, enter 2" <<endl;
        
        //error trapping
        
        while(1){                                                 //catching invalid selections with a while loop
            getline(cin,whichGood);                                //The (1) is always true for the while loop
            if(whichGood == whichGood1 || whichGood == whichGood2){
                break;                                            //breaks if whichGood is a valid selection (1 or 2)
            }else{
                cout << "Invalid entry. For dry goods, enter 1. For produce, enter 2" <<endl;
            }
        }
        
        
        //set rate according to value of whichGood
        
        if(whichGood == whichGood1){
            rate = 1.00;
        } else if(whichGood == whichGood2){
            rate = 2.00;
        } else {
            cout << "Error 1: invalid entry";
        }
        
        //request weight of goods
        
        if(whichGood == whichGood1){
            cout << " " <<endl;
            cout << "Enter the weight in kilograms of the dry goods you are purchasing" <<endl;
            cin >> weight;
            cout << "\nDry goods weight: " << setw(11) << weight << " kg" <<endl;
            cout << " " <<endl;
        } else if(whichGood == whichGood2){
            cout << " " <<endl;
            cout << "Enter the weight in kilograms of the produce you are purchasing" <<endl;
            cin >> weight;
            cout << "\nProduce weight:   " << setw(11) << weight << " kg" <<endl;
            cout << " " <<endl;
        } else {
            cout << "Error 2";
        }
        
        //calculate subtotal from values of rate and weight
        
        subtotal = weight * rate;
        
    } else {
        cout << "Error 1" <<endl;
    }
    
    
    //==============================================================================================
    
    //after price has been determined, tax, subtotal, etc can be calculated and output
    
    //output subtotal
    
    cout << "Your subtotal is: " << setw(11) << subtotal << " $" <<endl;
    cout << " " <<endl;
    
    //notify the user of current tax rate
    
    cout << "Sales tax rate:    " << setw(12) << "6.25 %" <<endl;
    cout << " " <<endl;
    
    //calculate total cost
    
    total = tax * subtotal;
    
    //output total cost
    
    cout << "Total price:      " << setw(11) << total << " $" <<endl;
    
    //request amount to be tendered
    
    cout << " " <<endl;
    cout << "Enter the amount you wish to tender" <<endl;
    cin >> amt_tend;
    cout << "\nAmount tendered:  " << setw(11) << amt_tend << " $" <<endl;
    
    //calculate change
    
    change = amt_tend - total;
    
    //output change amount
    
    cout << " " <<endl;
    cout << "Your change is:   " << setw(11) << change << " $" <<endl;
    cout << " " <<endl;
    
    
    return 0;
}