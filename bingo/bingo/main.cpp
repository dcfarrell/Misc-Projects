//
//  main.cpp
//  bingo
//
//  Created by Delaney Farrell on 2/13/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

bool IsArrDuplicate(int arr[], int numDigits) {
    // check to see if integer array has duplicate digits
    
    // nested loops check each value of the array with the following values.
    for(int i = 0; i < numDigits - 1; i++) {
        for(int c = i + 1; c < numDigits; c++) {
            if(arr[i]==arr[c]) {
                // if a duplicate value is found
                return true;
            }
        }
    }
    // the loop ends and no duplicates found
    return false;
}
/*
void NewRandArray(int* arr[], int num, int length) {
    for(int i = 0; i < numDigits; i++) {
        arr[i] = (num * 15) + (rand() % 15);
    }
}
*/
int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
          (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000);
   
    int bingoBoard[5][5];
    int num = 0,temp;
    bool match = false;
    
    //int Bingo[] = {B,I,N,G,O};
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++) {
            temp = (num * 15) + (rand() % 15);
            for(int i = 0; i < 5; i++) {
                for(int a = 0; a < 5; a++) {
                    if(bingoBoard[i][a] == temp) {
                        match = true;
                    }
                }
            }
            if(match == false) {
                bingoBoard[c][r] = temp;
            }
            match = false;
        }
        num++;
    }
    
    cout << "  B   I   N   G   O  " << endl;
    
    for(int row = 0; row < 5; row++) {
        for(int col = 0; col < 5; col++) {
            cout << " " << bingoBoard[row][col] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
