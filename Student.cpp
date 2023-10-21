#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Student.h"
using namespace std;

//Checks to see if username and password match line on file and correspond to the same student.
bool Student::login (string username, string password, string fileName) {
    string stuData;
    fstream stuF(fileName);
    string stuUsername;
    string stuPassword;
    string sName;
    string grade;
    while(getline(stuF, stuData)) {
        istringstream stuLine(stuData);
        getline(stuLine, stuUsername, '\t');
        getline(stuLine, stuPassword, '\t');
        if(username.compare(stuUsername)==0 && password.compare(stuPassword)==0) {
            getline(stuLine, sName, '\t');
            setStudentName(sName);

            getline(stuLine, grade, '\t');
            setProjectGrade(stoi(grade));

            getline(stuLine, grade, '\t');
            setQuizGrade(stoi(grade));

            getline(stuLine, grade, '\t');
            setMidtermGrade(stoi(grade));

            getline(stuLine, grade, '\t');
            setFinalGrade(stoi(grade));

            stuF.close();

            return true;

        }
    }
    return false;
}

// Gets student name.
string Student::getStudentName() {
    return fullName;
}

// Gets project grade
int Student::getProjectGrade() {
    return projectGrade;
}

//Gets quiz grade
int Student::getQuizGrade() {
    return quizGrade;
}

//Gets midterm grade
int Student::getMidtermGrade() {
    return midtermGrade;
}

//Gets final grade
int Student::getFinalGrade() {
    return finalGrade;
}

//Gets student name
void Student::setStudentName(string fullName) {
    this->fullName = fullName;
}

//Set project grade
void Student::setProjectGrade(int grade) {
    this->projectGrade = grade;
}

// Set quiz grade
void Student::setQuizGrade(int grade) {
    this->quizGrade = grade;
}

//Set midterm grade
void Student::setMidtermGrade(int grade) {
    this->midtermGrade = grade;
}

//Set final grade
void Student::setFinalGrade(int grade) {
    this->finalGrade = grade;
}

// Calculates overall grade
double Student::getOverallGrade() {
    double overall = (projectGrade * 0.3) + (quizGrade * 0.1) + (midtermGrade * 0.2) + (finalGrade * 0.4);
    return overall;
}
