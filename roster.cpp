#include <iostream>
#include "roster.h"

using namespace std;

void Roster::parseStudentData(string studentData)
{
	//parse each set of data in studentDataTable

	//studentID
	int end = studentData.find(",");
	string studentID = studentData.substr(0, end);

	//first name
	int start = end + 1;
	end = studentData.find(",", start);
	string firstName = studentData.substr(start, end - start);

	//last name
	start = end + 1;
	end = studentData.find(",", start);
	string lastName = studentData.substr(start, end - start);
	
	// email address
	start = end + 1;
	end = studentData.find(",", start);
	string email = studentData.substr(start, end - start);

	// age
	start = end + 1;
	end = studentData.find(",", start);
	int age = stoi(studentData.substr(start, end - start));

	//course 1 days
	start = end + 1;
	end = studentData.find(",", start);
	int course1Days = stoi(studentData.substr(start, end - start));

	//course 2 days
	start = end + 1;
	end = studentData.find(",", start);
	int course2Days = stoi(studentData.substr(start, end - start));
	
	//course 3 days
	start = end + 1;
	end = studentData.find(",", start);
	int course3Days = stoi(studentData.substr(start, end - start));

	//degree program
	start = end + 1;
	end = studentData.find("/0", start);
	string program = studentData.substr(start, end - start);

	DegreeProgram degreeProgram = DEFAULT;

	if (program == "SECURITY")
	{
		degreeProgram = SECURITY;
	}
	else if (program == "NETWORK")
	{
		degreeProgram = NETWORK;
	}
	else if (program == "SOFTWARE")
	{
		degreeProgram = SOFTWARE;
	}

	//uses add func to create object from initial string
	add(studentID, firstName, lastName, email, age, course1Days, course2Days, course3Days, degreeProgram);


}

void Roster::add(string studentID, string firstName, string lastName, string emailAdd, 
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	//create daysInCourse array from individual int
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	//
	classRosterArray[++endOfArray] = new Student(studentID, firstName, lastName, emailAdd, age, daysInCourse, degreeProgram);
	

}

//b.  void remove(string studentID) that removes students from the roster by student ID
void Roster::remove(string studentID)
{
	bool found = false;

	for (int i = 0; i < Roster::endOfArray; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			if (i < amtOfStuds - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[amtOfStuds - 1];
				classRosterArray[amtOfStuds - 1] = temp;
			}
			Roster::endOfArray--;
		}
	}

	if (!found)
	{
		cout << studentID << " not found." << endl;
	}

}

void Roster::printAll()
{
	for (int i = 0; i <= endOfArray; i++)
	{
		classRosterArray[i]->print();
	}

}

void Roster::printAverageDaysInCourse(string studentID)
{
	int dayOne = 0;
	int dayTwo = 0;
	int dayThree = 0;

	float average = 0.0;

	for (int i = 0; i < amtOfStuds; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			dayOne = classRosterArray[i]->getDaysToCompleteCourse()[0];
			dayTwo = classRosterArray[i]->getDaysToCompleteCourse()[1];
			dayThree = classRosterArray[i]->getDaysToCompleteCourse()[2];
			average = (dayOne + dayTwo + dayThree) / 3;

			cout << "Average: " << average << endl;
		}
	}
	
}

//F.3.e verifies student email addresses and displays all invalid email addresses
void Roster::printInvalidEmails()
{
	for (int i = 0; i < amtOfStuds; i++) 
	{
		string email = classRosterArray[i]->getEmail();

		if (email.find("@") == string::npos) //string::npos means not found
		{
			cout << email << endl;
		}
		else if (email.find(".") == string::npos)
		{
			cout << email << endl;
		}
		else if (email.find(" ") != string::npos)
		{
			cout << email << endl;
		}

	}

}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{

	for (int i = 0; i < amtOfStuds; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}

}

Roster::~Roster()
{
	for (int i = 0; i < amtOfStuds; i++)
	{
		delete classRosterArray[i];
	}

	cout << "Roster deleted from memory.";

}



