#ifndef FACULTY_H
#define FACULTY_H
#include "Student.h"
#include <iostream>
#include <random>

using namespace std;

class Faculty{
    public:
    Faculty();
    ~Faculty();
    int createFacultyID(int IDNumber);
    string createFacultyName(string Name);
    string createFacultyLevel(string Level);
    string createFacultyDepartment(string Department);
    int createFacultyAdvisees(int Advisees);
    string newFaculty(int IDNumber, string Name, string Level, string Department, int Advisees);
    string getFalcultyDept();
    string getFacultyID();


    private:
    int facultyIDNumber;
    string facultyName;
    string facultyLevel;
    string facultyDepartment;
    int facultyIDnumber;
    string facultName;
    string facLevel;
    string facDepartment;
    int facultyAdvisees;
    string faculty;
};


#endif