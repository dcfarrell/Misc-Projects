//
//  main.cpp
//  power
//
//  Created by Delaney Farrell on 3/31/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>

using namespace std;

int powerOfTwo(int r, int n) {
    
    int p;
    
    if(n == 0) {
        return 1;
    }
    
    p = powerOfTwo(2, n - 1);
    
    return r * powerOfTwo(r, p - 1);
}

int main() {
    
    cout << powerOfTwo(3, 4) << endl;
    
    return 0;
}
