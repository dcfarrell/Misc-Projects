//
//  main.cpp
//  experiment_alnum
//
//  Created by Delaney Farrell on 2/6/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    char temp;
    
    for(int i = 0; i<10; i++){
        cin >> temp;
        cout << isalnum(temp);
    }
    return 0;
}
