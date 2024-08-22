//
//  main.cpp
//  mountain paths parts 1 & 2
//
//  Delaney Farrell
//  03/27/19
//  CSCE 121 - 507
//

#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;

// Normally you should not use global variables. However, the stack is
//   limited in size and will not allow arrays of this size. We'll learn
//   later how to put these arrays on the heap instead. Regardless, for now
//   we'll use these and treat them as if they were declared in main. So
//   when used in functions, we'll pass them as we would any other array.

static int elevations[MAX_ROWS][MAX_COLS];
static Pixel image[MAX_ROWS][MAX_COLS];

int main() {
    // default variables
    string fileName, outFileName;
    int rows, cols, max, min, currentDistance, minDistance, minRow;
    
    // get user input for # of rows and columns and file name
    // check for invalid inputs of rows and columns
    cin >> rows;
    if(cin.fail() || rows < 1) {
        cout << "Error: Problem reading in rows and columns." << endl;
        exit(1);
    }
    cin >> cols;
    if(cin.fail() || cols < 1) {
        cout << "Error: Problem reading in rows and columns." << endl;
        exit(1);
    }
    cin >> fileName;
    
    // open file
    ifstream elevationData(fileName);
    
    // check to see if file was opened properly
    if(!elevationData.is_open()) {
        cout << "Error: Unable to open file <" << fileName << ">." << endl;
        exit(1);
    }
    
    // create the image
    loadData(elevations, rows, cols, elevationData);
    findMaxMin(elevations, rows, cols, max, min);
    loadGreyscale(image, elevations, rows, cols, max, min);
    
    Pixel colorRed;
    colorRed.red = 252;
    colorRed.green = 25;
    colorRed.blue = 63;
    
    Pixel colorGreen;
    colorGreen.red = 31;
    colorGreen.green = 253;
    colorGreen.blue = 13;
    
    minDistance = colorPath(elevations, image, rows, cols, colorRed, 0);
    minRow = 0;
    
    for(int row = 1; row < rows; row++) {
        currentDistance = colorPath(elevations, image, rows, cols, colorRed, row);
        if(currentDistance < minDistance) {
            minDistance = currentDistance;
            minRow = row;
        }
    }
    
    minDistance = colorPath(elevations, image, rows, cols, colorGreen, minRow);
    
    // opening new file for export
    outFileName = fileName + ".ppm";
    ofstream outData(outFileName);
    
    // check to see if file was opened properly
    if(!outData.is_open()) {
        cout << "Unable to open file <" << fileName << ">." << endl;
        return 1;
    }
    
    // output the new ppm file
    outputImage(image, rows, cols, outData);
    
    return 0;
}
