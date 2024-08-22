//  HW: Grade Calculator
//
//  Name: Delaney Farrell
//  Date: 02/04/19
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

double ExamAverage() {
    double examOne, examTwo, finalExam, examAvg = 0;
    
    // collect user's exam scores
    cout << "exam 1 grade [0-100]: ";
    cin >> examOne;
    cout << "exam 2 grade [0-100]: ";
    cin >> examTwo;
    cout << "final exam grade [0-100, -1 to skip]: ";
    cin >> finalExam;
    
    // calculate exam average
    if(finalExam != -1) {
        if((finalExam>examOne) && (finalExam>examTwo)){
            examAvg = finalExam;
        }else {
            examAvg = (examOne+examTwo+finalExam)/3.0;
        }
    }else {
        examAvg = (0.4*examOne)+(0.6*examTwo);
    }
    
    return examAvg;
}

char LetterGrade(double numGrade, int hwCounter, double examAvg) {
    char letterGrade;
    
    // determine letter grade
    if(hwCounter<=2) {
        if(numGrade>=60&&examAvg>=60) {
            if(numGrade>=90) {
                letterGrade = 'A';
            }else if(numGrade >= 80) {
                letterGrade = 'B';
            }else if(numGrade >= 70) {
                letterGrade = 'C';
            }else if(numGrade >= 60) {
                letterGrade = 'D';
            }else {
                letterGrade = 'F';
            }
        }else {
            letterGrade = 'D';
        }
    }else {
        letterGrade = 'F';
    }
    
    return letterGrade;
}

double PercentComplete(double num) {
    
    // determine and return the percentage completed
    if(num >= 85) {
        num = 100;
    }else if(num > 0) {
        num += 15;
    }else {
        num = 0;
    }
    
    return num;
}

double CalculateAverage(string type, int& hwCounter) {
    int count = 1;
    double temp, avg;
    
    // collect first value from user
    cout << type << " 1 [0-100, -1 to end]: ";
    cin >> avg;
    
    // if user did not enter -1, calculate average
    if(avg != -1){
        do{
            cout << type << " " << count+1 << " [0-100, -1 to end]: ";
            cin >> temp;
            if(temp!=-1) {
                avg += temp;
                count++;
                // only for checking to see if less then 2 homeworks are missing
                if(temp==0&&type=="homework") {
                    hwCounter++;
                }
            }
        } while(temp!=-1);
        avg = avg/count;
    }else {
        avg = 0;
    }
    
    return avg;
}

int main() {
    char syllabusQuiz, letGrade;
    double zyPart, zyChal, classPart, extraCredit, numGrade, examAvg, zyAvg, hwAvg, labAvg;
    int hwCounter = 0;
    
    // check to see if user completed syllabus quizy

    cout << "did you get 100% on the syllabus quiz [y/n]? ";
    cin >> syllabusQuiz;
    
    if(syllabusQuiz=='y' || syllabusQuiz=='Y') {
        
        // collect user's exam scores and calculate exam average
        examAvg = ExamAverage();
        
        // collect zybook participation and challenge grades
        cout << "zybook participation (%): ";
        cin >> zyPart;
        cout << "zybook challenge (%): ";
        cin >> zyChal;
        
        // calculate zybook average
        zyAvg = ((4.0/7.0)*PercentComplete(zyPart))+((3.0/7.0)*PercentComplete(zyChal));
        
        // collect class participation percent
        cout << "class participation (%): ";
        cin >> classPart;
        
        classPart = PercentComplete(classPart);
        
        // collect and calculate homework and labwork grades
        hwAvg = CalculateAverage("homework", hwCounter);
        labAvg = PercentComplete(CalculateAverage("labwork", hwCounter));
        
        // collect extra credit points
        cout << "extra credit points [0-1]: ";
        cin >> extraCredit;
        
        cout << endl;
        
        // output averages
        cout << "exams:               " << examAvg << endl;
        cout << "zybook activities:   " << zyAvg << endl;
        cout << "class participation: " << classPart << endl;
        cout << "homework:            " << hwAvg << endl;
        cout << "labwork:             " << labAvg << endl;
        cout << "extra credit:        " << extraCredit << endl;
        
        cout << endl;
        
        // calculate numeric and letter grades
        numGrade = (0.5*examAvg)+(0.07*zyAvg)+(0.03*classPart)+(.35*hwAvg)+(0.05*labAvg)+extraCredit;
        letGrade = LetterGrade(numGrade, hwCounter, examAvg);
        
        //output numeric and letter grades
        cout << "numeric grade: " << numGrade << endl;
        cout << "letter grade:  " << letGrade << endl;
    }else {
        cout << "letter grade:  F" << endl;
    }
    
    return 0;
}
