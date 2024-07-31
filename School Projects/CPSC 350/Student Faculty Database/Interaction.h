#ifndef INTERACTION_H
#define INTERACTION_H
#include <iostream>
#include <string>
#include "PopulateTree.h"

using namespace std;

class Interaction{

    public:
    Interaction();
    ~Interaction();
    BST<string> students;
    BST<string> faculty;
    void printStudents();
    void printFaculty();
    void findStudentInfo(int IDNumber);
    void findFacultyInfo(int IDNumber);
    void addStudent(int IDNumber, string Name, string Grade, string Major, double gpa, int Advisor);
    void deleteStudent(int IDNumber);
    void addFaculty(int IDNumber, string Name, string Level, string Department, int Advisees);
    void changeStudentAdvisor(int IDNumber, int NewAdvisor);
    void removeAdvisee(int IDNumber, int NewAdvisee);
    void addStudToArray(int IDNumber, string Name, string Grade, string Major, double gpa, int Advisor);
    void addFacToArray(int FacID, string FacName, string FacLevel, string FacDept, int FacAdv);
    void deleteFaculty(int IDNumber);


    private:
    PopulateTree p;
    Student s;
    Faculty f;

};



#endif