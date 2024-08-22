//  HW: Quadratic Equation Solver
//
//  Name: Delaney Farrell
//  Date: 1/28/19
//  Course: CSCE 121
//  Section: 507
//
//  “On my honor, as an Aggie, I have neither given nor received unauthorized aid on this academic work.
//  In particular, I certify that I have listed above all the sources that I consulted regarding this assignment,
//  and that I have not received or given any assistance that is contrary to the letter or the spirit of the
//  collaboration guidelines for this assignment.”
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    // define variables and take in input for a, b, and c.
    double a, b, c, det, rootOne, rootTwo, iNum;
    cin >> a >> b >> c;
    
    // set default values
    iNum = 0;
    rootOne = 0;
    rootTwo = 0;
    
    // set value for determinate
    det = pow(b,2)-4*a*c;
    
    // output equation with correct signs
    if(b<0 && c<0){
        cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
    }else if(b<0){
        cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
    }else if(c<0){
        cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
    }else{
        cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    }
    
    // check to see if equation is quadratic
    if(a!=0){
        // check to see if det is equal to 0
        if(det==0){
            // output one real root
            rootOne = -b/(2*a);
            cout << "x = " << rootOne << endl;
        //check to see if det is negative
        }else if(det<0){
            // output two roots w/ imaginary #s
            rootOne = -b/(2*a);
            iNum = fabs(sqrt(fabs(det))/(2*a));
            if(a>0){
                cout << "x = " << rootOne << " - " << iNum << "i" << endl;
                cout << "x = " << rootOne << " + " << iNum << "i" << endl;
            }else{
                cout << "x = " << rootOne << " + " << iNum << "i" << endl;
                cout << "x = " << rootOne << " - " << iNum << "i" << endl;
            }
        // determinate positive, solve for quadratic equation w/ two real roots
        }else{
            // output two real roots
            rootOne = (-b-sqrt(det))/(2*a);
            rootTwo = (-b+sqrt(det))/(2*a);
            cout << "x = " << rootOne << endl;
            cout << "x = " << rootTwo << endl;
        }
    // check to see if equation is linear
    }else if(b!=0){
        // output one real root
        rootOne = -c/b;
        cout << "x = " << rootOne << endl;
    // no real roots, a==0 and b==0
    }else{
        cout << "Unable to determine root(s)." << endl;
    }
    
    return 0;
    
}
