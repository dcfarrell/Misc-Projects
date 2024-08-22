//
//  main.cpp
//  prime_number_maze
//
//  Created by Delaney Farrell on 2/8/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>

using namespace std;

string DecToBin(int num) {
    string bin;
    while(num>0){
        bin = to_string(num % 2) + bin;
        num = num / 2;
    }
    return bin;
}

bool IsPrime(int num) {
    
    for(int i = num-1; i>1; i--) {
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int room = 2;
    string bin;
    
    
    bin = DecToBin(room);
    cout << bin << endl;
    
    
    
    return 0;
}
