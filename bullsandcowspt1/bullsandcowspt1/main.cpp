//
//  HW: Bulls & Cows (Part 1)
//
//  Name: Delaney Farrell
//  Date: 2/18/19
//  Course: CSCE 121
//  Section: 507
//
//  “On my honor, as an Aggie, I have neither given nor received unauthorized aid
//  on this academic work. In particular, I certify that I have listed above all
//  the sources that I consulted regarding this assignment, and that I have not
//  received or given any assistance that is contrary to the letter or the spirit
//  of the collaboration guidelines for this assignment.”
//

#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

// check to see if integer array has duplicate digits
bool IsArrDuplicate(int arr[], int numDigits) {
    
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

// for printing arrays with dashes
void PrintArray (int arr[], int numDigits) {
    
    cout << arr[0];
    for(int i = 1; i < numDigits; i++) {
        cout << "-" << arr[i];
    }
}

// create a new random code between 0 and 9, with numDigits
void NewRandomCode(int numDigits, int* guessCode) {
    int digits[] = {0,1,2,3,4,5,6,7,8,9};
    int temp, index, num = 9;
    
    // loop runs until a code with numDigits has been reached
    for(int i = 0; i < numDigits; i++) {
        // choose a random index
        index = rand() % num;
        
        // set i of guessCode to value at index of digits
        guessCode[i] = digits[index];
        
        // swap chosen number to the back of digits
        temp = digits[index];
        digits[index] = digits[num];
        digits[num] = temp;
        
        // decrease num by 1
        num -= 1;
    }
}

int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
          (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000);
    // needed to autograde some test cases in Mimir
    
    int numCode, numDigits = 10;
    bool validCode = false;
    
    // integer array with pointer for storing digits
    int* guessCode = new int[numDigits];
    
    while(validCode == false) {
        // ask for a value for numDigits
        // while loop will repeat until an acceptable value is entered
        cout << "Enter number of digits in code (3, 4 or 5): ";
        cin >> numDigits;
        
        // "cheat code" for testing
        if(numDigits == 0) {
            // user enters value for code and number of digits
            cout << "Enter code: ";
            cin >> numCode;
            cout << "Enter number of digits in code: ";
            cin >> numDigits;
            
            // loop to convert integer to array
            for(int i = numDigits - 1; i >= 0; i--) {
                guessCode[i] = numCode % 10;
                numCode /= 10;
            }
            
            validCode = true;
            
            // edit this else if to add more acceptable digits if desired
        }else if(numDigits >= 3 && numDigits <= 5) {
            // generates random code
            NewRandomCode(numDigits, guessCode);
            validCode = true;
            
        }else {
            // default value for numCode if numDigits is not acceptable
            numCode = 0;
        }
    }
    
    // output array of digits
    cout << "Number to guess: ";
    PrintArray(guessCode, numDigits);
    cout << endl;
    
    // delete guessCode and guessArr array references to avoid memory leak
    delete[] guessCode;
    
    return 0;
}

