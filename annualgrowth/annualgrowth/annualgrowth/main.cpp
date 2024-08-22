//
//  HW: Annual Growth
//
//  Name: Delaney Farrell
//  Date: 1/22/19.
//  Course: CSCE 121
//  Section: 507
//
//  “On my honor, as an Aggie, I have neither given nor received unauthorized aid on this academic work.
//  In particular, I certify that I have listed above all the sources that I consulted regarding this assignment,
//  and that I have not received or given any assistance that is contrary to the letter or the spirit of the
//  collaboration guidelines for this assignment.”
//

#include <iostream>
#include <string>

using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    // insert code here...
    string firstName, lastName;
    int birthYear, currentYear, ftHeight, inHeight, userAge;
    float cmHeight, avgAnnGrowth;
    
    //set constant with current year
    currentYear = 2019;
    
    //ask for user input for first and last names, birth year, and height in feet and inches.
    cout << "First name: ";
    cin >> firstName;
    
    cout << "Last name: ";
    cin >> lastName;
    
    cout<<"Birth year: ";
    cin >> birthYear;
    
    cout << "Height in feet (do not include inches): ";
    cin >> ftHeight;
    
    cout << "Height in inches (do not include feet): \n";
    cin >> inHeight;
    
    // calculate user's age
    userAge = currentYear - birthYear;
    
    //calculate height in cm
    cmHeight = 2.54 * ((12 * ftHeight) + inHeight);
    
    //calculate average annual growth rate
    avgAnnGrowth = (cmHeight - 51)/userAge;
    
    //output final values
    cout << "Hello " << firstName << " " << lastName << ".\n";
    cout << "You are " << userAge << " years old in 2019.\n";
    cout << "Your height is " << cmHeight << " cm.\n";
    cout << "You grew an average of " << avgAnnGrowth << " cm per year (assuming you were 51 cm at birth).\n";
    
    return 0;
    
}
