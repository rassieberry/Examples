/******************************************************************************
Rachel Eden 
11/25/2018
This program will create a gradebook for a class of students, then display it.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

//structure to hold an individual student's data
struct student {
    string name;
    string IDNum;
    vector<double> tests;
    double average;
    char grade;
};

void welcomeMessage();
int getNumStudents();
int getNumGrades();
vector<student> getTestScores(int, int);
double calculateAverageGrade(vector<double>);
double getLetterGrade(double);
void displayResults(vector<student>);

int main()
{
    //ask user for how many test scores and how many students
    welcomeMessage();
    int numStudents = getNumStudents();
    int numGrades = getNumGrades();
    
    //allocate an array of structures
    //ask for the ID number and test scores of each students
    //input validation - all numbers entered and no negative numbers
    vector<student> studentClass = getTestScores(numStudents, numGrades);
    
    

    
    
    //calculate average test scores
    //assign letter grade
    for (int i = 0; i < studentClass.size(); i++) {
        studentClass[i].average = calculateAverageGrade(studentClass[i].tests);
        studentClass[i].grade = getLetterGrade(studentClass[i].average);
    }
    
    
    
    
    //display tables of all info to user
    displayResults(studentClass);
    
    
    //main return statement
    return 0;
}

//welcome the user and explain the program
void welcomeMessage() {
    cout << "Hello! This program will create a gradebook for your students.\n";
}

//get the number of students in the class from the user and validate input
int getNumStudents() {
    int numStudents;
    cout << "First, how many students are in your class? ";
    cin >> numStudents;
    while (numStudents < 0) {
        cout << "Please enter a valid number of students.\n";
        cin >> numStudents;
    }
    return numStudents;
}

//get the number of test grades in the course from the user and validate input
int getNumGrades() {
    int numGrades;
    cout << "Next, how many test grades are there in your course? ";
    cin >> numGrades;
    while (numGrades < 0) {
        cout << "Please enter a valid number of grades.\n";
        cin >> numGrades;
    }
    return numGrades;
}

//get the student names, id numbers, and grades from the user and validate input
vector<student> getTestScores(int numStudents, int numGrades) {
    cout << "Now, please enter the ID number and test scores of each student: \n";
    vector<student> studentClass;
    string currentName;
    string currentIDnum;
    double currentGrade;
    //do this for each student in the class
    for (int i = 0; i < numStudents; i++) {
        //create a new student entry and get their name and id number
        cout << "Enter a student's name: ";
        cin.ignore();
        getline(cin, currentName);
        cout << "Enter that student's ID number (####): ";
        getline(cin, currentIDnum);
        student newStudent;
        studentClass.push_back(newStudent);
        studentClass[i].name = currentName;
        studentClass[i].IDNum = currentIDnum;
        //get that student's grades as well
        for (int j = 0; j < numGrades; j++) {
            cout << "Enter grade " << (j+1) << ": ";
            cin >> currentGrade;
            while (currentGrade < 0) {
                cout << "Please enter a valid grade number: ";
                cin >> currentGrade;
            }
            studentClass[i].tests.push_back(currentGrade);
        }
    }
    return studentClass;
}

//calculate the average of the student's test grades from data in the student structure
double calculateAverageGrade(vector<double> testScores) {
    double total = 0;
    for (int i = 0; i < testScores.size(); i++) {
        total += testScores[i];
    }
    return (total/testScores.size());
}

//calculate the letter grade for a student 
double getLetterGrade(double average) {
    char letter;
    if (average >= 90) {
        letter = 'A';
    } else if (average >=80) {
        letter = 'B';
    } else if (average >= 70) {
        letter = 'C';
    } else if (average >= 60) {
        letter = 'D';
    } else {
        letter = 'F';
    }
    return letter;
}

//display a table of results of the gradebook to the user
void displayResults(vector<student> studentClass) {
    cout << "Displaying the gradebook for your class:" << endl << endl;
    for (int i = 0; i < studentClass.size(); i++) {
        cout << "Name: " << studentClass[i].name << endl;
        cout << "ID Number: " << studentClass[i].IDNum << endl;
        cout << "Average test score: " << studentClass[i].average << endl;
        cout << "Course grade: " << studentClass[i].grade << endl << endl;
    }
}