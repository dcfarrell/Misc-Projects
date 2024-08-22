//
//  main.cpp
//  vectorspractice
//
//  Created by Delaney Farrell on 4/10/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols, count = 0;
    
    cin >> rows;
    cin >> cols;
    
    vector<int> vec(rows);
    vector<vector<int>> vec2(rows,vec);
    
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            vec2[r][c] = count;
            count++;
        }
    }
    
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            cout << vec2[r][c] << "\t";
        }
        cout << endl;
    }
    
    
    return 0;
}
