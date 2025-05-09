#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"

using namespace std;

int main() {



	const string studentData[]
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",

		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",

		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

		"A5,Ariel,Jones,ajone335@wgu.edu,24,20,45,37,SOFTWARE" 
	};

	//G.1.Print to the screen, via your application, the course title, the 
	// programming language used, your WGU student ID, and your name.
	cout << "Course Title: Scriptin and Programming - Applications - C867" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "WGU StudentID: 012515260" << endl;
	cout << "Name: Ariel Jones" << endl;
	cout << endl;

	//G.2 create instance of Roster class called classRoster
	Roster classRoster;


	//Parse & Add each set of data from studentDataTable
	const int amtOfStuds = 5;

	for (int i = 0; i < amtOfStuds; i++)
	{
		classRoster.parseStudentData(studentData[i]); 
	}

	//print class roster
	classRoster.printAll();

	cout << endl;
	
	//print invalid emails
	cout << "Invalid emails: " << endl;
	classRoster.printInvalidEmails();

	cout << endl;

	
	for (int i = 0; i < amtOfStuds; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	
	cout << endl;


	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	
	classRoster.printAll();

	classRoster.remove("A3");
};