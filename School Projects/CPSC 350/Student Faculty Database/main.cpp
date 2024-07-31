#include "Student.h"
#include "PopulateTree.h"
#include "Interaction.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    Interaction i;
    BST<string> b;
    PopulateTree p;
    string command;
    cout << p.students.isEmpty() << endl;
    std::cout << "Menu Options:" << std::endl;
    std::cout << "1. Print all students and their information" << std::endl;
    std::cout << "2. Print all faculty and their information" << std::endl;
    std::cout << "3. Find and display student information given the student id" << std::endl;
    std::cout << "4. Find and display faculty information given the faculty id" << std::endl;
    std::cout << "5. Add a new student" << std::endl;
    std::cout << "6. Delete a student given the id" << std::endl;
    std::cout << "7. Add a new faculty member" << std::endl;
    std::cout << "8. Delete a faculty member given the id" << std::endl;
    std::cout << "9. Change a student's advisor given the student id and the new faculty id" << std::endl;
    std::cout << "10. Remove an advisee from a faculty member given the ids" << std::endl;
    std::cout << "Type 'exit' to quit the program" << std::endl;

    while (true)
    {
        std::cout << "Enter your choice: ";
        std::cin >> command;
        if (command == "exit")
        {
            break;
        }
        if (command == "1")
        {
            if (i.students.isEmpty() == 1){
                cout << "There are no students, please enter a student first" << endl;
            }
            else{
                i.printStudents();
            }
            }
        else if (command == "2")
        {
            if (i.faculty.isEmpty() == 1){
                cout << "There are no faculty, please enter a faculty first" << endl;
            }
            else{
            i.printFaculty();
            }
        }
        else if (command == "3")
        {
            std::cout << "Please enter the students ID number" << std::endl;
            int IDNumber;
            std::cin >> IDNumber;
            if (i.students.isEmpty() == 1){
                cout << "There are no students, please enter a student first" << endl;
            }
            else{
            i.findStudentInfo(IDNumber);
            }
        }
        else if (command == "4")
        {
            std::cout << "Please enter the faculty ID number" << std::endl;
            int facIDNum;
            std::cin >> facIDNum;
            if (i.faculty.isEmpty() == 1){
                cout << "There are no faculty, please enter a faculty first" << endl;
            }
            else{
            i.findFacultyInfo(facIDNum);
            }
        }
        else if (command == "5")
        {
            std::cout << "Please enter the new students ID number" << std::endl;
            int IDNum;
            std::cin >> IDNum;
            std::cout << "Please enter the new students name" << std::endl;
            string Name;
            std::cin >> Name;
            std::cout << "Please enter the new students grade" << std::endl;
            string Grade;
            std::cin >> Grade;
            std::cout << "Please enter the new students major" << std::endl;
            string Major;
            std::cin >> Major;
            std::cout << "Please enter the new students GPA" << std::endl;
            double GPA;
            std::cin >> GPA;
            std::cout << "Please enter the new students advisor ID number" << std::endl;
            int advisorID;
            std::cin >> advisorID;
            i.addStudent(IDNum, Name, Grade, Major, GPA, advisorID);
            std::cout << "New student added" << std::endl;
        }
        else if (command == "6")
        {
            std::cout << "Please enter the students ID number you wish to delete" << std::endl;
            int IDNumb;
            std::cin >> IDNumb;
            if (i.students.isEmpty() == 1){
                cout << "There are no students, please enter a student first" << endl;
            }
            else{
            i.deleteStudent(IDNumb);
            std::cout << "Student deleted" << std::endl;
            }
        }
        else if (command == "7")
        {
            std::cout << "Please enter the new faculty's ID number" << std::endl;
            int IDNum;
            std::cin >> IDNum;
            std::cout << "Please enter the new faculty's name" << std::endl;
            string Name;
            std::cin >> Name;
            std::cout << "Please enter the new faculty's level" << std::endl;
            string Level;
            std::cin >> Level;
            std::cout << "Please enter the new faculty's department" << std::endl;
            string Dept;
            std::cin >> Dept;
            std::cout << "Please enter the new faculty advisees ID number" << std::endl;
            int Advisee;
            std::cin >> Advisee;
            i.addFaculty(IDNum, Name, Level, Dept, Advisee);
            std::cout << "New faculty added" << std::endl;
        }
        else if (command == "8")
        {
            std::cout << "Please enter the faculty members ID you wish to delete" << std::endl;
            int IDNumber;
            std::cin >> IDNumber;
            if (i.faculty.isEmpty() == 1){
                cout << "There are no faculty, please enter a faculty first" << endl;
            }
            else{
            i.deleteFaculty(IDNumber);
            std::cout << "Faculty deleted" << std::endl;
            }
        }
        else if (command == "9")
        {
            std::cout << "Enter the students ID number" << std::endl;
            int ID;
            std::cin >> ID;
            std::cout << "Enter the new advisors ID number" << std::endl;
            int advID;
            std::cin >> advID;
            if (i.students.isEmpty() == 1){
                cout << "There are no students, please enter a student first" << endl;
            }
            else{
            i.students.changeAdvisor(to_string(ID), advID);
            std::cout << "Student advisor changed" << std::endl;
            }
        }
        else if (command == "10")
        {
            std::cout << "Enter the faculty ID number" << std::endl;
            int IDnum;
            std::cin >> IDnum;
            std::cout << "Enter the new student advisee" << std::endl;
            int newID;
            std::cin >> newID;
            if (i.faculty.isEmpty() == 1){
                cout << "There are no faculty, please enter a faculty first" << endl;
            }
            else{
            i.faculty.changeAdvisor(to_string(IDnum), newID);
            std::cout << "Faculty advisee changed" << std::endl;
            }
        }
        else if (command == "11"){
            cout << i.students.isEmpty() << endl;
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    std::cout << "Exiting the program..." << std::endl;
    return 0;
}