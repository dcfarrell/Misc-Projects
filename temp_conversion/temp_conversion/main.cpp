//
//  main.cpp
//  temp_conversion
//
//  Created by Delaney Farrell on 1/30/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>

using namespace std;

float CtoF(float C) {
    return 9/5*C+32;
}

float FtoC (float F) {
    return 5/9*(F-32);
}

int main() {
    char c;
    cout << "(C) to F or (F) to C? ";
    cin >> c;
    float T;
    if (c == 'c' || c == 'C') {
        cout << "temp in C: ";
        cin >> T;
        cout << "temp in F: " << CtoF(T) << endl;
    } else if (c == 'f' || c == 'F') {
        cout << "temp in F: ";
        cin >> T;
        cout << "temp in C: " << FtoC(T) << endl;
    } else {
        cout << "invalid response" << endl;
    }
    return 0;
}
