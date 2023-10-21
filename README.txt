Program: main.cpp Instructor.cpp Student.cpp

The main program acts as a the interface to the account viewer and allows the user to
to login to see student and instructor details. Student.cpp and Instructor.cpp serve as
object that store username, password, name, and grade details, and main uses these objects
to retrieve student data.

------------------------------------------------------------------------------------
Instructor file functions and variables
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
------------------------------------------------------------------------------------
Student file functions and variables
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
------------------------------------------------------------------------------------
CODER: Urja Shah
Credit/Contribution:
- Assignment 2 pdf

How to compile:
g++ main.cpp Student.cpp Instructor.cpp -o main

OR Makefile:
   make - to compile

How to run:
    main [instructor_file] [student_file]
