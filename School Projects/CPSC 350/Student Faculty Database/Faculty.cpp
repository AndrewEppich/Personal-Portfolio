#include "Faculty.h"

Faculty::Faculty(){

}

Faculty::~Faculty(){

}

int Faculty::createFacultyID(int IDNumber){
    return IDNumber;
}

string Faculty::createFacultyName(string Name){
    return Name;
}

string Faculty::createFacultyLevel(string Level){
    return Level;
}

string Faculty::createFacultyDepartment(string Department){
    return Department;
}

int Faculty::createFacultyAdvisees(int Advisees){
 return Advisees;
}



string Faculty::newFaculty(int IDNumber, string Name, string Level, string Department, int Advisees){

    facultyIDnumber = createFacultyID(IDNumber);
    facultyName = createFacultyName(Name);
    facLevel = createFacultyLevel(Level);
    facDepartment = createFacultyDepartment(Department);
    facultyAdvisees = createFacultyAdvisees(Advisees);

    faculty += to_string(facultyIDnumber) + ", ";
    faculty += facultyName + ", ";
    faculty += facLevel + ", ";
    faculty += facDepartment + ", ";
    faculty += to_string(facultyAdvisees) + ", ";

    return faculty;

}

string Faculty::getFacultyID(){
    return to_string(facultyIDnumber);
}


string Faculty::getFalcultyDept(){
    return facDepartment;
}

