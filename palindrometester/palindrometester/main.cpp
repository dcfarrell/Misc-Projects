//
//  main.cpp
//  palindrometester
//
//  Created by Delaney Farrell on 2/26/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

#include <iostream>
#include <string>

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
                word.erase(i,1);
                i--;
            }
        }
    }
    // removes punctuation using ASCII values
    //((word.at(i) >= 33 && word.at(i) <= 47) || (word.at(i) >= 58 && word.at(i) <= 64) || word.at(i) == 96)
    //isalnum(word.at(i)) == false
    //!(word.at(i) >= 48 && word.at(i) <= 57) && !(word.at(i) >= 65 && word.at(i) <= 90) && !(word.at(i) >= 97 && word.at(i) <= 122)
    /*for(unsigned int i = 0; i < word.size(); i++) {
        if(ispunct(word.at(i))) {
            word = word.substr(0, i) + word.substr(i+1, word.size()-1);
        }
    }*/
    for(unsigned int i = 0; i < word.size(); i++) {
        if(ispunct(word.at(i)) || !isprint(word.at(i))) {
            word.erase(i,1);
            i--;
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

int main() {
    
    string word = "T. Eliot, top bard, notes putrid tang emanating, is sad. I’d assign it a name: gnat dirt upset on drab pot-toilet.";
    string word2 = "Do good? I? No! Evil anon I deliver. I maim nine more hero-men in Saginaw, sanitary sword a-tuck, Carol, I — lo! — rack, cut a drowsy rat in Aswan. I gas nine more hero-men in Miami. Reviled, I (Nona) live on. I do, O God!";
    
    cout << isPalindrome(word, false, true) << endl;
    
        if(isPalindrome(word, false, true)) {
            cout << "\"" << word << "\" is a palindrome." << endl;
        } else {
            cout << "\"" << word << "\" is not a palindrome." << endl;
        }
    
    word = tolower(word);
    word = removePunctuation(word, true);
    
    cout << word << endl;
    
    cout << isPalindrome(word2, false, true) << endl;
    
    if(isPalindrome(word2, false, true)) {
        cout << "\"" << word2 << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << word2 << "\" is not a palindrome." << endl;
    }
    
    word2 = tolower(word2);
    word2 = removePunctuation(word2, true);
    
    cout << word2 << endl;
    
    //cout << ispunct('—') << endl;
    
    return 0;
}
