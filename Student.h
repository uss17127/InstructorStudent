// Student.h
#ifndef STUDENT_H
#define STUDENT_H

//#include<iostream>
//#include <string>
//#include <fstream>
//#include <sstream>

class Student {
    private:
    std::string fullName;
        int projectGrade;
        int quizGrade;
        int midtermGrade;
        int finalGrade;
public:
    bool login(std::string username, std::string password, std::string fileName);
    std::string getStudentName();
    int getProjectGrade();
    int getQuizGrade();
    int getMidtermGrade();
    int getFinalGrade();
    void setStudentName(std::string fullName);
    void setProjectGrade(int grade);
    void setQuizGrade(int grade);
    void setMidtermGrade(int grade);
    void setFinalGrade(int grade);
    double getOverallGrade();
};

#endif
