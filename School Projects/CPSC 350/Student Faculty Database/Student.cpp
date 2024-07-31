#include "Student.h"

Student::Student(){

}

Student::~Student(){

}

int Student::createStudentID(int IDnumber){
    return IDnumber;
}

string Student::createStudentName(string name){
    return name;
}

string Student::createStudentGrade(string grade){
    return grade;
}

string Student::createStudentMajor(string major){
    return major;
}

double Student::createStudentGPA(double GPA){
    return GPA;
}


int Student::getStudentAdvisor(int advisor){
    return advisor;
}

string Student::newStudent(int IDNumber, string Name, string Grade, string Major, double gpa, int Advisor){
    IDnumber = createStudentID(IDNumber);
    name = createStudentName(Name);
    grade = createStudentGrade(Grade);
    major = createStudentMajor(Major);
    GPA = createStudentGPA(gpa);
    advisor = getStudentAdvisor(Advisor);

    stringstream gpaStream;
    gpaStream << fixed << setprecision(2) << GPA;
    string formattedGPA = gpaStream.str();  


        student += to_string(IDnumber) + ", ";
        student += name + ", ";
        student += grade + ", ";
        student += major + ", ";
        student += formattedGPA + ", ";
        student += to_string(advisor) + ", ";


    return student;
}




string Student::getID(){
    return to_string(IDnumber);
}

string Student::getMajor(){
    return major;
}

// for the getters to work neStudent must run before the