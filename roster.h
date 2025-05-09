#ifndef roster_h
#define roster_h
#include "student.h"

using namespace std;

class Roster {

private:
	const static int amtOfStuds = 5;
	int endOfArray = -1;

public:


	//F.1 Create array or vector of pointers named classRosterArray
	Student* classRosterArray[amtOfStuds];

	

	//F.2  Create a student object for each student in the data table and populate classRosterArray.
	void parseStudentData(string studentData);

	//F.3 a.  void add(string studentID, string firstName, string lastName, string emailAddress, 
	// int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
	// that sets the instance variables from part D1 and updates the roster
	void add(string studentID, string firstName, string lastName, string emailAdd,
			int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
			DegreeProgram degreeProgram);

	/*F.3.b. void remove(string studentID) that removes students from the roster by student ID. If the 
	student ID does not exist, the function prints an error message indicating that the student was not found*/
	void remove(string studentID);

	//F.3.c.  void printAll()that loops through all the students in classRosterArray and calls the print() 
	// function for each student
	void printAll();

	//F.3.d.  void printAverageDaysInCourse(string studentID) that correctly prints the average number of days 
	// in the three courses for the student whose studentID is passed in as the parameter
	void printAverageDaysInCourse(string studentID);

	//F.3. e.  void printInvalidEmails() that verifies student email addresses and displays all invalid email 
	// addresses to the user
	void printInvalidEmails();

	//F.3.f.  void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for 
	// a degree program specified by an enumerated type
	void printByDegreeProgram(DegreeProgram degreeProgram);

	//F.3.g.  The destructor that will release memory claimed by the roster object.
	~Roster();
};








#endif 
