#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Student.h"
#include "Instructor.h"
using namespace std;

int main(int argc, char *argv[]) {
    string instructorFile = argv[1];
    string studentFile  = argv[2];
    ifstream instruct(instructorFile , ios::in);
    ifstream studentf(studentFile , ios::in);
    int userType = 0;
    string username;
    string password;
    string yesNo = "n/a";

    //Checks command line files
    if (argc < 3) {
        cout << "Usage: main [instructor_file] [student_file]" << endl;
        exit(1);
    }
    if (!instruct) {
        cerr << "Error: cannot parse instructors information from file " << instructorFile << endl;
    }
    if (!studentf) {
        cerr << "Error: cannot parse instructors information from file " << studentFile << endl;
    }
    if (!instruct || !studentf) {
        exit(1);
    }
    instruct.close();
    studentf.close();


    // while loop continues as long as user does not decide to end program
    while (userType != 3) {
        cout << "User types," << endl;
        cout << "\t 1 - Instructor" << endl;
        cout << "\t 2 - Student" << endl;
        cout << "Select a login user type of enter 3 to exit: ";
        cin >> userType;

        // if user is an instructor
        if (userType == 1) {
            cout << "Enter credentials to login" << endl;
            cout << "\t Enter username: ";
            cin >> username;
            cout << "\t Enter password: ";
            cin >> password;


            Instructor instruct;
            int optionNum = 0;
            int gradeType = 0;
            bool option = false;
            if (instruct.login(username, password, instructorFile) == true) {
                cout << "You are now logged in as " << instruct.getInstructorName() << "." << endl;
                while (option == false) {
                    cout << "Query options," << endl;
                    cout << "\t1 - view grades of student" << endl;
                    cout << "\t2 - view stats" << endl;
                    cout << "Enter option number: ";
                    cin >> optionNum;
                    if (optionNum != 1 && optionNum != 2) {
                        cout << "Invalid option. Please enter a valid option" << endl;
                    } else {
                        option = true;
                    }
                }

                // section for option 1 for instructor - grades of students
                string stuUser;
                Student student2;
                bool studentUser = false;
                if (optionNum == 1) {
                    // if there is no such username while loop will contine
                    while (studentUser == false) {
                        cout << "Enter student username to view grades: ";
                        cin >> stuUser;
                        student2 = instruct.getStudent(stuUser);
                        if (student2.getStudentName().compare("")!=0) {
                            //prints out grades
                            cout << "Student name: " << student2.getStudentName() << endl;
                            cout << "\tProject " << student2.getProjectGrade() << "%" << endl;
                            cout << "\tQuiz " << student2.getQuizGrade() << "%" << endl;
                            cout << "\tMidterm " << student2.getMidtermGrade() << "%" << endl;
                            cout << "\tFinal " << student2.getFinalGrade() << "%" << endl;
                            cout << "\tOverall " << student2.getOverallGrade() << "%" << endl;
                            studentUser = true;


                        } else {
                            cout << "Student username is not valid." << endl;
                        }

                    }
                }

                // section for option 2 for instructor - stats
                bool statState = false;
                if (optionNum == 2) {
                    // if there is no such grade type while loop will continue
                    while (statState == false) {
                    cout << "Grade types," << endl;
                    cout << "\t1 -  Project grade" << endl;
                    cout << "\t2 - Quiz grade" << endl;
                    cout << "\t3 - Midterm grade" << endl;
                    cout << "\t4 - Final grade" << endl;
                    cout << "\t5 - Overall grade" << endl;

                    cout << "Select a grade type to view stats: ";
                    cin >> gradeType;


                    Student sMin = instruct.getMinStudent(gradeType);
                    Student sMax = instruct.getMaxStudent(gradeType);
                    double averageGrade = instruct.getAvg(gradeType);
                    // Depending on grade type, min, max, and avg is printed
                    if (gradeType == 1) {

                        cout << "Project grade stats," << endl;
                        cout << "\tmin " <<  sMin.getProjectGrade() << "% " << "(" << sMin.getStudentName()  << ")"  <<endl;
                        cout << "\tmax "  <<  sMax.getProjectGrade() << "% " << "(" << sMax.getStudentName()  << ")" << endl;
                        cout << "\tavg " << averageGrade << "%" << endl;
                        statState = true;

                    }

                    if (gradeType == 2) {
                        cout << "Quiz grade stats," << endl;
                        cout << "\tmin " <<  sMin.getQuizGrade() << "% " << "(" << sMin.getStudentName()  << ")"  <<endl;
                        cout << "\tmax "  <<  sMax.getQuizGrade() << "% " << "(" << sMax.getStudentName()  << ")" << endl;
                        cout << "\tavg " << averageGrade << "%" << endl;
                        statState = true;
                    }

                    if (gradeType == 3) {
                        cout << "Midterm grade stats," << endl;
                        cout << "\tmin " <<  sMin.getMidtermGrade() << "% " << "(" << sMin.getStudentName()  << ")"  <<endl;
                        cout << "\tmax "  <<  sMax.getMidtermGrade() << "% " << "(" << sMax.getStudentName()  << ")" << endl;
                            cout << "\tavg " << averageGrade << "%" << endl;
                            statState = true;

                    }
                    if (gradeType == 4) {
                        cout << "Final grade stats," << endl;
                        cout << "\tmin " <<  sMin.getFinalGrade() << "% " << "(" << sMin.getStudentName()  << ")"  <<endl;
                        cout << "\tmax "  <<  sMax.getFinalGrade() << "% " << "(" << sMax.getStudentName()  << ")" << endl;
                        cout << "\tavg " << averageGrade << "%" << endl;
                        statState = true;
                    }

                    if (gradeType == 5) {
                        cout << "Overall grade stats," << endl;
                        cout << "\tmin " <<  sMin.getOverallGrade() << "% " << "(" << sMin.getStudentName()  << ")"  <<endl;
                        cout << "\tmax "  <<  sMax.getOverallGrade() << "% " << "(" << sMax.getStudentName()  << ")" << endl;
                        cout << "\tavg " << averageGrade << "%" << endl;
                        statState = true;
                    }

                    if (gradeType != 1 && gradeType != 2 && gradeType != 3 && gradeType != 4 && gradeType != 5) {
                        cout << "Invalid option. Please enter a valid option." << endl;
                    }
                    }


                }

            } else {
                cout << "Login as instructor failed." << endl;
            }
        }

        // if user is a student
        if (userType == 2) {
            cout << "Enter credentials to login" << endl;
            cout << "\t Enter username: ";
            cin >> username;
            cout << "\t Enter password: ";
            cin >> password;

            Student student;
            if (student.login(username, password, studentFile) == true) {
                // Prints out grades
                    cout << "Do you want to view grades (y/n)? ";
                    cin >> yesNo;
                    if (yesNo.compare("y") == 0) {
                        cout << "Student name: " << student.getStudentName() << endl;
                        cout << "\tProject " << student.getProjectGrade() << "%" << endl;
                        cout << "\tQuiz " << student.getQuizGrade() << "%" << endl;
                        cout << "\tMidterm " << student.getMidtermGrade() << "%" << endl;
                        cout << "\tFinal " << student.getFinalGrade() << "%" << endl;
                        cout << "\tOverall " << student.getOverallGrade() << "%" << endl;
                    }


            } else {
                cout << "Login as student failed." << endl;
            }

        }

        if (userType != 1 && userType != 2 && userType != 3) {
            cout << "Invalid option. Please enter a valid option." << endl;
        }
    }


    return 0;
}
