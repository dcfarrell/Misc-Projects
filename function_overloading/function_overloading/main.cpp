//
//  main.cpp
//  function_overloading
//
//  Created by Delaney Farrell on 2/4/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>


using namespace std;

double area(double x1, double y1, double x2, double y2);
double area(double length, double width);

//overloaded
double area(double x1, double y1, double x2, double y2) {
    //todo absolute value
    return (x2 - x1) * (y2 - y1);
}

//overloaded
double area(double length, double width) {
    //todo absolute value
    return length * width;
}

string toStr(bool boolean) {
    //convert true --> "true"
    //convert false --> "false"
    return "";
}

string toStr(int integer) {
    //ex: convert 123 --> "123"
    return "";
}

string toStr(double doubleVal) {
    //ex. convert 123.45 --> "123.45"
    return "";
}

int main() {
    // insert code here...
    cout << "length: ";
    double length;
    cin >> length;
    cout << "width: ";
    double width;
    cin >> width;
    cout << "area = " << area(length, width);
    
    cout << "x1 y1: ";
    double x1, y1, x2, y2;
    cin >> x1 >> y1;
    cout << "x2 y2: ";
    cin >> x2 >> y2;
    cout << "area: " << area(x1, y1, x2, y2);
    
    return 0;
}
