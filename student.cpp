#include <iostream>
#include "student.h"

using namespace std;

//  Create the class Student in the files 
// student.h and student.cpp, which includes 
// each of the following private variables, 
// using the correct data type for each:

Student::Student(string studentID, string firstName, string lastName, string emailAdd, 
				int age, int daysToCompleteCourse[courses], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAdd = emailAdd;
	this->age = age;
	for (int i = 0; i < courses; i++)
	{
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
	this->degreeProgram = degreeProgram;

}


Student::~Student()
{

}

//accessors
string Student::getStudentID()
{
	return this->studentID;
}

string Student::getFirstName()
{
	return this->firstName;
}

string Student::getLastName()
{
	return this->lastName;
}

string Student::getEmail()
{
	return this->emailAdd;
}

int Student::getAge()
{
	return this->age;
}

int* Student::getDaysToCompleteCourse()
{
	return this->daysToCompleteCourse;
}

DegreeProgram Student::getDegreeProgram()
{
	return this->degreeProgram;
}


//mutators
void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string emailAdd)
{
	this->emailAdd = emailAdd;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysToCompleteCourse(int daysToCompleteCourse[])
{
	for (int i = 0; i < courses; i++)
	{
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

void Student::print()
{
	//cast degreeprogram to string somehow

	string degreeProgramWord = "";

	if (degreeProgram == SECURITY)
	{
		degreeProgramWord = "SECURITY";
	}
	else if (degreeProgram == NETWORK)
	{
		degreeProgramWord = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE)
	{
		degreeProgramWord = "SOFTWARE";
	}
	else
	{
		degreeProgramWord = "DEFAULT";
	}

	cout << this->getStudentID() << "\t" << "First Name: " << this->getFirstName() << "\t"
		<< "Last Name: " << this->getLastName() << "\t" << "Email: " << this->getEmail()
		<< "\t" << "Age: " << this->getAge() << "\t" << "daysInCourse: {" << this->getDaysToCompleteCourse()[0]
		<< ", " << this->getDaysToCompleteCourse()[1] << ", " << this->getDaysToCompleteCourse()[2] << "}\t"
		<< "Degree Program: " << degreeProgramWord << endl;
}
