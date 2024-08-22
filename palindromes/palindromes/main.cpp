// main.cpp

#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

//bool isPalindrome(string word, bool caseChange, bool ignoreSpaces);

int main(int argc, const char * argv[]) {
    bool caseChange = false, ignoreSpaces = true;
    int start = 1;
    
    if(argc < 1) {
        printUsageInfo(argv[0]);
    }
    
    //for(int i = start; i < argc - 1; i++) {
    //cout << argv[i] << endl;
    //}
    
    // check for flags
    for(int i = 1; i < argc; i++) {
        if(argv[i][0] == '-' && argv[i][1] == '-') {
            start++;
            break;
        } else {
            if(argv[i][0] == '-') {
                start++;
                
                if(((argv[i][1] == 'c') || (argv[i][1] == 'C') || (argv[i][2] == 'c') || (argv[i][2] == 'C')) && caseChange == false) {
                    caseChange = true;
                }
                
                if(((argv[i][1] == 's') || (argv[i][1] == 'S') || (argv[i][2] == 's') || (argv[i][2] == 'S')) && ignoreSpaces == false) {
                    ignoreSpaces = false;
                }
            }
        }
    }
    
    // check to see if any strings are left and exit program if any are not
    if(argc - start < 1) {
        printUsageInfo(argv[0]);
    }
    
    // for loop to check to see if each string is a palindrome
    for(int i = start; i <= argc - 1; i++) {
        if(removePunctuation(argv[i], ignoreSpaces) != "") {
            if(isPalindrome(argv[i], caseChange, ignoreSpaces)) {
                cout << "\"" << argv[i] << "\" is a palindrome." << endl;
            } else {
                cout << "\"" << argv[i] << "\" is not a palindrome." << endl;
            }
        }
    }
    
    return 0;
}
