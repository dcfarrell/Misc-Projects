//
//  main.cpp
//  lucasnumbers
//
//  Created by Delaney Farrell on 2/15/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>
//#include <vector>

using namespace std;

unsigned long long L[100];

#define UNKNOWN 0;

unsigned long long LucasNum(int num) {
        if (num < 2) {
            return 2 - num;
        }if(L[num] == UNKNOWN) {
            L[num] = LucasNum(num - 1) + LucasNum(num - 2);
        }
    return L[num];
}

int main() {
    int num;
    //vector<int> listNum;
    
    cin >> num;
    
    for(int i = 0; i < 100; i++) {
        L[i] = UNKNOWN;
    }
    cout << "n: " << LucasNum(num) << endl;
    
    return 0;
}
