//
//  main.cpp
//  mountainpaths_tester
//
//  Created by Delaney Farrell on 3/27/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>

using namespace std;

int colorPath(const int elevations[2][2], int rows, int cols, int start_row) {
    int northEast, southEast, east, row, col, distance;
    
    col = 0;
    row = start_row;
    distance = 0;
    
    // color current spot
    
    while(col < cols-1) {
        northEast = 0;
        southEast = 0;
        east = 0;
        
        // check bounds
        if(row > 0) {
            northEast = abs(elevations[row-1][col+1] - elevations[row][col]);
            cout << "northEast = " << northEast << endl;
        } else {
            northEast = -1;
        }
        
        if(row+1 < rows) {
            southEast = abs(elevations[row+1][col+1] - elevations[row][col]);
            cout << "southEast = " << southEast << endl;
        } else {
            southEast = -1;
        }
        
        east = abs(elevations[row][col+1] - elevations[row][col]);
        cout << "east = " << east << endl;
        
        if((northEast == -1 || east <= northEast) && (southEast == -1 || east <= southEast)) {
            // move east and add change in elevation to distance
            distance += east;
            cout << "going east" << endl;
        } else if(southEast != -1 && (northEast == -1 || southEast <= northEast) && southEast < east) {
            // move south east and add change in elevation to distance
            distance += southEast;
            row++;
            cout << "going south east" << endl;
        } else if(northEast != -1){
            // move north east and add change in elevation to distance
            distance += northEast;
            row--;
            cout << "going north east" << endl;
        }
        
        // move forward
        col++;
        cout << distance << endl;
    }
    
    return distance;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int num;
    int elevations[2][2] = {{7,14},{9,12}};
    
    num = colorPath(elevations, 2, 2, 1);
    
    cout << num << endl;
}
