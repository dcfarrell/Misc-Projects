//
//  functions.cpp
//  mountain paths parts 1 & 2
//
//  Delaney Farrell
//  03/27/19
//  CSCE 121 - 507
//

#include <iostream>
#include <fstream>
#include <cmath>
#include "functions.h"
using namespace std;

// find the minimum and maximum values of the array
void findMaxMin(const int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, int& max, int& min) {
    // setting default values
    max = elevations[0][0];
    min = elevations[0][0];
    
    // traverse 2D array
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            // check to see if current spot is > max or spot is < min
            if(max < elevations[row][col]) {
                max = elevations[row][col];
            } else if(min > elevations[row][col]) {
                min = elevations[row][col];
            }
        }
    }
}

// load data into 2D array
void loadData(int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, istream& inData) {
    // variable for error checking
    int test;
    
    // traverse 2D array
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            // check to make sure there are still data points
            if(!inData.eof()) {
                // set current spot to next data value from file
                inData >> elevations[row][col];
                // check to see if the value is an int (previous line was successful)
                if(inData.fail()) {
                    cout << "Error: Read a non-integer value." << endl;
                    exit(1);
                }
            } else {
                cout << "Error: End of file reached prior to getting all the required data." << endl;
                exit(1);
            }
        }
    }
    
    // check to see if any data is left
    inData >> test;
    if(!inData.fail()) {
        cout << "Error: Too many data points." << endl;
        exit(1);
    }
}

// returns a grayscale value
int scaleValue(int value, int max, int min) {
    double shade;
    
    // equation to calculate grayscale value
    // (casting int values as doubles to calculate more accurate value)
    shade = ((static_cast<double>(value - min))/(static_cast<double>(max - min))) * 255;
    
    // round to nearest whole number
    if((ceil(shade) - shade) <= (shade - floor(shade))) {
        shade = ceil(shade);
    } else {
        shade = floor(shade);
    }
    
    // return grayscale value as an int
    return static_cast<int>(shade);
}

// load parallel array with Pixel rgb values
void loadGreyscale(Pixel image[MAX_ROWS][MAX_COLS], const int elevations[MAX_ROWS][MAX_COLS],
                   int rows, int cols, int max, int min) {
    int shade;
    
    // traverse 2D arrays
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            // set shade to grayscale value
            shade = scaleValue(elevations[row][col], max, min);
            // set rgb values to shade
            image[row][col].red = shade;
            image[row][col].green = shade;
            image[row][col].blue = shade;
        }
    }
}

int colorPath(const int elevations[MAX_ROWS][MAX_COLS], Pixel image[MAX_ROWS][MAX_COLS], int rows, int cols, Pixel color, int start_row) {
    int northEast, southEast, east, row, col, distance;
    
    // setting starting values
    col = 0;
    row = start_row;
    distance = 0;
    
    // color current spot
    image[row][col] = color;
    
    // loop will break once it reaches the last column
    while(col < cols-1) {
        
        // check upper (north) bounds
        if(row > 0) {
            // set change in elevation of north eastern value
            northEast = abs(elevations[row-1][col+1] - elevations[row][col]);
        } else {
            northEast = -1;
        }
        
        // check lower (south) bounds
        if(row+1 < rows) {
            // set change in elevation of south eastern value
            southEast = abs(elevations[row+1][col+1] - elevations[row][col]);
        } else {
            southEast = -1;
        }
        
        // set change in elevation of eastern value
        east = abs(elevations[row][col+1] - elevations[row][col]);
        
        // check to see if east is less than northEast and southEast or if they don't exist (== -1)
        if((northEast == -1 || east <= northEast) && (southEast == -1 || east <= southEast)) {
            // move east and add change in elevation to distance
            distance += east;
        // check to see if southEast exists and is less than northEast or if northEast does not exist
        } else if(southEast != -1 && (northEast == -1 || southEast <= northEast)) {
            // move south east and add change in elevation to distance
            distance += southEast;
            row++;
        // otherwise, move northEast
        } else {
            // move north east and add change in elevation to distance
            distance += northEast;
            row--;
        }
        
        // move forward
        col++;
        
        // color current spot
        image[row][col] = color;
    }
   
    return distance;
}

// output ppm file of image
void outputImage(const Pixel image[MAX_ROWS][MAX_COLS], int rows, int cols, ostream& outData) {
    // output first three rows
    outData << "P3" << endl;
    // output # of columns and rows
    outData << cols << ' ' << rows << endl;
    // output max color value
    outData << 255 << endl;
    
    // traverse 2D array
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            // output rgb values for each pixel
            outData << image[row][col].red << ' ' << image[row][col].green << ' ' << image[row][col].blue << ' ';
        }
        // adding a new line after each row for formatting
        outData << endl;
    }
}
