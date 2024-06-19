#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

extern "C" {
    double calculateGPA();
    double calculateCGPA();
    void method();
    void to_uppercase(string &s);
}

void to_uppercase(string &s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return toupper(c); });
}

double calculateGPA() {
    int num;
    cout << "Enter number of subjects: ";
    cin >> num;

    map<string, double> vals = {{"A+", 4.0}, {"A", 4.0}, {"A-", 3.7}, {"B+", 3.3}, {"B", 3.0},
                                {"B-", 2.7}, {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7}, {"D+", 1.3}, {"D", 1.0}, {"D-", 0.7}, {"E", 0.0}, {"P", 0.0},
                                {"F", 0.0}, {"CR", 0.0}, {"NC", 0.0}};

    double sum_of_pts = 0.0;
    int total_credits = 0;
    for (int i = 1; i <= num; i++) {
        cout << "Enter number of credits for subject " << i << ": ";
        int cred;
        cin >> cred;
        total_credits += cred;
        // multiply the credits with the grade
        cout << "Enter the grade for subject " << i << ": ";
        string grade;
        cin >> grade;
        to_uppercase(grade);
        double curr = vals[grade] * cred;
        sum_of_pts += curr;
    }
    // divide total credits taken
    double result = sum_of_pts / total_credits;
    return result;
}

double calculateCGPA() {
    cout << "Enter number of semesters to calculate CGPA for: ";
    int num;
    cin >> num;
    cout << endl;
    double sum_of_gpas = 0.0;
    for (int i = 1; i <= num; i++) {
        // ask for gpa of each sem and divide by the total number of sems
        cout << "Enter GPA for semester " << i << ": ";
        double curr;
        cin >> curr;
        sum_of_gpas += curr;
    }
    double result = sum_of_gpas / num;
    return result;
}

void method() {
    cout << "--------------- Method of Calculating GPA & CGPA ---------------\n\n" << endl;
    cout << " GPA = Sum of (Credit * Point) / Total Credits \n" << endl;
    cout << " CGPA = Sum of GPA / Number of Semesters " << endl;
    cout << "-----------------------------------------------------------------\n\n" << endl;
}
