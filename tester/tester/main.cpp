//============================================================================
// Name        : tester.cpp
// Author      : Me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

void tester1() {
    int x;
    cout << "uninitialized x: " << x << endl;
    x = 13;
    cout << "Now x = " << x << endl;
}

void tester2(int &z){
    int w = 77;
    z = 11;
}

int main() {
    int v = 19;
    cout << "v before: " << v << endl;
    tester1();
    tester2(v);
    tester1();
    cout << "v after: " << v << endl;
}
