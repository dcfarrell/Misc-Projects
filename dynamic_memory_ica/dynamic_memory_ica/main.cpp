//
//  main.cpp
//  dynamic_memory_ica
//
//  Created by Delaney Farrell on 3/29/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    // allocate an array of 10 ints on the heap using new
    int* A = new int[10];
    
    // print the values of the 10 int to standard out
    cout << "A (pointer value) = " << A << endl;
    for(int i = 0; i < 10; i++) {
        cout << "A[" << i << "] = " << A[i] << endl;
    }
    
    // deallocate the array using delete[]
    delete[] A;
    
    // BAD:
    // print the values of the 10 int to standard out
    cout << "A (pointer value) = " << A << endl;
    for(int i = 0; i < 10; i++) {
        cout << "A[" << i << "] = " << A[i] << endl;
    }
    
    A = nullptr;
    // print the values of the 10 int to standard out
    cout << "A (pointer value) = " << A << endl;
    for(int i = 0; i < 10; i++) {
        cout << "A[" << i << "] = " << A[i] << endl;
    }
    
    return 0;
}
