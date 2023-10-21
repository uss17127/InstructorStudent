//Instructor.h

#include "Student.h"

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

class Instructor {
private:
    std::string fullName;
    std::string inFileName;
public:
    bool login(std::string username, std::string password, std::string fileName);
    std::string getInstructorName();
    Student getStudent(std::string username);
    Student getMinStudent(int gradeType);
    Student getMaxStudent(int gradeType);
    double getAvg(int gradeType);

};

#endif
