// functions.h

#include <string>
//#include <iostream>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//using namespace std;

std::string tolower(std::string word);
std::string removePunctuation(std::string word, bool ignoreSpaces);
std::string preprocessString(std::string word, bool caseChange, bool ignoreSpaces);
bool isPalindromeR(std::string word);
bool isPalindrome(std::string word, bool caseChange, bool ignoreSpaces);
void printUsageInfo(std::string programName);

#endif  //functions_h
