#include "Interaction.h"

Interaction::Interaction(){

}


Interaction::~Interaction(){

}

void Interaction::printStudents(){
    students.printTree();
}

void Interaction::printFaculty(){
    faculty.printTree();
}


void Interaction::findStudentInfo(int IDNumber){
    BST<string> b;
    string ID = to_string(IDNumber);
    TreeNode<string>* result = students.findID(ID);
    if (result != nullptr) {
        cout << "Student found: " << result->key << endl;
    } else {
        cout << "Student not found" << endl;
    }
}

void Interaction::findFacultyInfo(int IDNumber){
    BST<string> b;
    string ID = to_string(IDNumber);
    TreeNode<string>* result = faculty.findID(ID);
    if (result != nullptr) {
            cout << "Student found: " << result->key << endl;
    } else {
        cout << "Student not found" << endl;
    }
}


void Interaction::addStudent(int IDNumber, string Name, string Grade, string Major, double gpa, int Advisor){
    students.insert(s.newStudent(IDNumber, Name, Grade, Major, gpa, Advisor));
}

void Interaction::deleteStudent(int IDNumber){
    string ID = to_string(IDNumber);
    TreeNode<string>* result = students.findID(ID);
    if (result != nullptr) {
       students.deleteNode(result->key);
    } else {
        cout << "Student not found" << endl;
    }
}

void Interaction::addFaculty(int IDNumber, string Name, string Level, string Department, int Advisees){
    faculty.insert(f.newFaculty(IDNumber, Name, Level, Department, Advisees));
}

void Interaction::deleteFaculty(int IDNumber){
    BST<string> b;
    string ID = to_string(IDNumber);
    TreeNode<string>* result = faculty.findID(ID);
    if (result != nullptr) {
        faculty.deleteNode(result->key);
    } else {
        cout << "Faculty not found" << endl;
    }
}

void Interaction::changeStudentAdvisor(int IDNumber, int NewAdvisor){
    p.students.changeAdvisor(to_string(IDNumber), NewAdvisor);
}

void Interaction::removeAdvisee(int IDNumber, int NewAdvisee){
    p.faculty.changeAdvisor(to_string(IDNumber), NewAdvisee);
}
