#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Instructor.h"
using namespace std;

// Checks to see if username and passwrod match line on file and correspond to the same instructor.
bool Instructor::login(std::string username, std::string password, std::string fileName) {
    string inData;
    fstream inF(fileName);
    string inUsername;
    string inPassword;
    string inName;
    while(getline(inF, inData)) {
        istringstream inLine(inData);
        getline(inLine, inUsername, '\t');
        getline(inLine, inPassword, '\t');
        if(username.compare(inUsername)==0 && password.compare(inPassword)==0) {
            getline(inLine, inName, '\t');
            this->fullName = inName;
            this->inFileName  = fileName;
            inF.close();
            return true;
        }
    }
    return false;
}

// Gets instructor name
string Instructor::getInstructorName() {
    return fullName;
}


// Returns student objects and sets student details within this object
Student Instructor::getStudent(string username) {

    string stuData;
    fstream stuF("students.txt");
    string stuUsername;
    string stuPassword;
    string sName;
    string grade;
    Student stud;
    while(getline(stuF, stuData)) {
        istringstream stuLine(stuData);
        getline(stuLine, stuUsername, '\t');

        getline(stuLine, stuPassword, '\t');
        if (stuUsername.compare(username.c_str())==0) {
            getline(stuLine, sName, '\t');
            stud.setStudentName(sName);

            getline(stuLine, grade, '\t');
            stud.setProjectGrade(stoi(grade));

            getline(stuLine, grade, '\t');
            stud.setQuizGrade(stoi(grade));

            getline(stuLine, grade, '\t');
            stud.setMidtermGrade(stoi(grade));

            getline(stuLine, grade, '\n');
            stud.setFinalGrade(stoi(grade));

            stuF.close();

            return stud;

        }
    }


    stuF.close();

    return stud;
}


// Gets student object that has the minimum grade of a specified grade category
Student Instructor::getMinStudent(int gradeType) {
    Student min;
    Student stud;
    string stuData;
    fstream stuF("students.txt");
    string stuUsername;
    string stuPassword;
    string sName;
    string grade;
    int counter = 0;
    while(getline(stuF, stuData)) {
        istringstream stuLine(stuData);
        getline(stuLine, stuUsername, '\t');
        getline(stuLine, stuPassword, '\t');
        getline(stuLine, sName, '\t');
        stud.setStudentName(sName);

        getline(stuLine, grade, '\t');
        stud.setProjectGrade(atoi(grade.c_str()));

        getline(stuLine, grade, '\t');
        stud.setQuizGrade(atoi(grade.c_str()));

        getline(stuLine, grade, '\t');
        stud.setMidtermGrade(atoi(grade.c_str()));

        getline(stuLine, grade, '\t');
        stud.setFinalGrade(atoi(grade.c_str()));



        if(counter == 0) {
            min = stud;
            counter++;
        }
        if (gradeType == 1 && (stud.getProjectGrade() < min.getProjectGrade())) {
            min = stud;
        } else if (gradeType == 2 && (stud.getQuizGrade() < min.getQuizGrade())) {
            min = stud;
        } else if (gradeType == 3 && (stud.getMidtermGrade() < min.getMidtermGrade())) {
            min = stud;
        } else if (gradeType == 4 && (stud.getFinalGrade() < min.getFinalGrade())) {
            min = stud;
        } else if (gradeType == 5 && (stud.getOverallGrade() < min.getOverallGrade())) {
            min = stud;
        } else {
        }
    }
    stuF.close();
    return min;

}

//Gets student object that has the maximum grade of a specified grade category
Student Instructor::getMaxStudent(int gradeType){
    Student max;
    Student stud;
    string stuData;
    fstream stuF("students.txt");
    string stuUsername;
    string stuPassword;
    string sName;
    string grade;
    int counter = 0;
    while(getline(stuF, stuData)) {
        istringstream stuLine(stuData);
        getline(stuLine, stuUsername, '\t');
        getline(stuLine, stuPassword, '\t');
        getline(stuLine, sName, '\t');
        stud.setStudentName(sName);

        getline(stuLine, grade, '\t');
        stud.setProjectGrade(atoi(grade.c_str()));

        getline(stuLine, grade, '\t');
        stud.setQuizGrade(atoi(grade.c_str()));

        getline(stuLine, grade, '\t');
        stud.setMidtermGrade(atoi(grade.c_str()));

        getline(stuLine, grade, '\t');
        stud.setFinalGrade(atoi(grade.c_str()));



        if(counter == 0) {
            max = stud;
            counter++;
        }
        if (gradeType == 1 && (stud.getProjectGrade() > max.getProjectGrade())) {
            max = stud;
        } else if (gradeType == 2 && (stud.getQuizGrade() > max.getQuizGrade())) {
            max = stud;
        } else if (gradeType == 3 && (stud.getMidtermGrade() > max.getMidtermGrade())) {
            max = stud;
        } else if (gradeType == 4 && (stud.getFinalGrade() > max.getFinalGrade())) {
            max = stud;
        } else if (gradeType == 5&& (stud.getOverallGrade() > max.getOverallGrade())) {
            max = stud;
        } else {
        }
    }
    stuF.close();
    return max;
}


// Gets the average of specified grade category
double Instructor::getAvg(int gradeType) {
    Student stud;
    string stuData;
    fstream stuF("students.txt");
    string stuUsername;
    string stuPassword;
    string sName;
    string grade;
    int summation = 0;
    int counter = 0;
    while(getline(stuF, stuData)) {
        istringstream stuLine(stuData);
        getline(stuLine, stuUsername, '\t');
        getline(stuLine, stuPassword, '\t');
        getline(stuLine, sName, '\t');
        stud.setStudentName(sName);

        getline(stuLine, grade, '\t');
        stud.setProjectGrade(atoi(grade.c_str()));

        getline(stuLine, grade, '\t');
        stud.setQuizGrade(atoi(grade.c_str()));

        getline(stuLine, grade, '\t');
        stud.setMidtermGrade(atoi(grade.c_str()));

        getline(stuLine, grade, '\t');
        stud.setFinalGrade(atoi(grade.c_str()));

        if (gradeType == 1) {
            summation += stud.getProjectGrade();
            counter++;
        } else if (gradeType == 2) {
            summation += stud.getQuizGrade();
            counter++;
        } else if (gradeType == 3) {
            summation += stud.getMidtermGrade();
            counter++;
        } else if (gradeType == 4) {
            summation += stud.getFinalGrade();
            counter++;
        } else if (gradeType == 5) {
            summation += stud.getOverallGrade();
            counter++;
        } else {
        }
    }
    stuF.close();
    return summation/counter;

}
