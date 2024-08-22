//
//  main.cpp
//  dynamic_memory
//
//  Created by Delaney Farrell on 2/20/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>

using namespace std;

int* foo(int* A, unsigned int len) {
    int* B = new int[len];
    for (unsigned int i = 0; i < len; ++i) {
        B[i] = A[i];
    }
    return B;
}

void bar(int* A) {
    A[0]++;
}

/*
// Doesn't change value of array
void bar(const int* A) {
    A[0]++;
}
*/

int main() {
    int A[10];
    
    int n = 10;
    int* B = new int[n];
    
    int* C = foo(B, n);
    
    cout << A[0] << endl;
    bar(A);
    cout << A[0] << endl;
    
    delete[] C;
    delete[] B;
    
    return 0;
}
