#ifndef STUDENT_H
#define STUDENT_H   
#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <iomanip>
#include "Faculty.h"

using namespace std;

class Student{

    public:
    Student();
    ~Student();
    int createStudentID(int IDnumber);
    string createStudentName(string name);
    string createStudentGrade(string grade);
    string createStudentMajor(string major);
    double createStudentGPA(double GPA);
    int getStudentAdvisor(int advisor);
    string newStudent(int IDNumber, string Name, string Grade, string Major, double gpa, int Advisor);
    string getStudentIndex(int d);
    string getID();
    string getMajor();

    private:
    int studentIDNumber;
    string studentName;
    int studentGradeNum;
    string studentGrade;
    string studentMajor;
    double studentGPA;
    int IDnumber;
    string name;
    string grade;
    string major;
    double GPA;
    int advisor;
    string formattedGPA;
    string student;

};

#endif