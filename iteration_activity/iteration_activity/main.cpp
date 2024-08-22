//
//  main.cpp
//  iteration_activity
//
//  Created by Delaney Farrell on 1/30/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string num;
    
    cin >> num;
    
    for(int i = 3; i < num.length(); i+3){
        num.at(i);
    }
    
    return 0;
}
