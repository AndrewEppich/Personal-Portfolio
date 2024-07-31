#ifndef POPULATE_TREE_H
#define POPULATE_TREE_H
#include "bst.h"
#include <string>
#include "Student.h"
#include "Faculty.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

using namespace std;


class PopulateTree{

    public:
    PopulateTree();
    ~PopulateTree();
    void getStudentPrint();
    void getFacultyPrint();
    BST<string> students;
    BST<string> faculty;
    void addStudentsToArray(int IDNumber, string Name, string Grade, string Major, double gpa, int Advisor);
    void addFacultyToArray(int IDNumber, string Name, string Level, string Department, int Advisees);
    void insertStudents();
    void insertFaculty();

    private:
    Faculty f;
    int newSize;
    int newSize2;
    int currentSize;
    int currentSize2;
    string studentArray[50];
    int size;
    string facultyArray[50];


};

void swap(std::string& a, std::string& b);
void bubbleSort(std::string arr[], int n);
void removeAtIndex(string arr[], int& size, int indexToRemove);


#endif