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

	

	//F.2
	void parseStudentData(string studentData);

	//F.3
	void add(string studentID, string firstName, string lastName, string emailAdd,
			int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
			DegreeProgram degreeProgram);

	void remove(string studentID);

	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();
};








#endif 
