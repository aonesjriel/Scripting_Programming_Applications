#include <string>
#include "degree.h"

#ifndef student_h
#define student_h

using namespace std;

class Student {

	/*E.  For the Student class, do the following:
	1.  Create the class Student in the files student.h and student.cpp, 
	which includes each of the following private variables, using the 
	correct data type for each:*/

public:
	const static int courses = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAdd;
	int age;
	int daysToCompleteCourse[courses];
	DegreeProgram degreeProgram;

	/*2.  Create each of the following functions in the Student class:*/

public:
	//c.a constructor using all the input parameters provided in the table
	Student(string studentID, string firstName, string lastName,
		string emailAdd, int age, int daysToCompleteCourse[courses],
		DegreeProgram degreeProgram);

	//destructor
	~Student();

	//accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();

	//mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string emailAdd);
	void setAge(int age);
	void setDaysToCompleteCourse(int daysToCompleteCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//d.  a print() function to print specific student data in the 
	// provided format:
	void print();
};













#endif

