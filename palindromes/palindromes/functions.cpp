// functions.cpp

#include <string>
#include <iostream>
#include "functions.h"

using namespace std;

string tolower(string word) {
    // changes a string to lower case
    // using ASCII values to find a capital letters and change to lowercase.
    for(unsigned int i = 0; i < word.size(); i++) {
        if((word.at(i) >= 65) && (word.at(i) <= 90)) {
            word.at(i) = word.at(i) + 32;
        }
    }
    return word;
}

string removePunctuation(string word, bool ignoreSpaces) {
    // removes space if ignoreSpaces is true (no flag)
    if(ignoreSpaces) {
        for(unsigned int i = 0; i < word.size(); i++) {
            if(word.at(i) == ' ') {
                word = word.substr(0,i-1) + word.substr(i+1,word.size()-1);
            }
        }
    }
    // removes punctuation using ASCII values
    for(unsigned int i = 0; i < word.size(); i++) {
        if(word.at(i) >= 33 && word.at(i) <= 64) {
            word = word.substr(0,i-1) + word.substr(i+1,word.size()-1);
        }
    }
    return word;
}

string preprocessString(string word, bool caseChange, bool ignoreSpaces) {
    // if case is to be ignored, change case to lower case
    if(caseChange == false) {
        word = tolower(word);
    }
    // remove punctuation from string
    word = removePunctuation(word, ignoreSpaces);
    
    //cout << word << endl;
    
    return word;
}

bool isPalindromeR(string word) {
    // check to see if the first and last characters of the string match
    // first make sure the string has more than one character
    if(word.size()>1) {
        // if the first and last characters match call the function again with
        // a smaller substring minus the first and last characters of original
        if(word.at(0) == word.at(word.size()-1)) {
            return isPalindromeR(word.substr(1,word.size()-2));
        } else {
            // if the characters don't match, return false and stop the recursion
            return false;
        }
    } else {
        // reached the middle of the string and found all characters matching
        // return true and stop the recursion
        return true;
    }
}

bool isPalindrome(string word, bool caseChange, bool ignoreSpaces) {
    // remove punctuation, spaces, and change case
    word = preprocessString(word, caseChange, ignoreSpaces);
    // call recursive function to check to see if the string is a palindrome
    // return this value
    return isPalindromeR(word);
}

void printUsageInfo(string programName) {
    cout << "Usage: " << programName << " [-c] [-s] string ..." << endl;
    cout << "  -c: turn on case sensitivity" << endl;
    cout << "  -s: turn off ignoring spaces" << endl;
    exit(1);
}
