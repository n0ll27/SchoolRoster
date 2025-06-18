#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

class Roster {
protected:
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	int LastIndex = -1;
public:
	Roster();
	// Adding a student to roster method:
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
		DegreeProgram degreeProgram);

	// Removing a student from roster method:
	void remove(std::string studentID);

	// Print all students in roster method:
	void printAll();

	// Print avg no. of days in course for student method:
	void printAverageDaysInCourse(std::string studentID);

	// Print invalid email address:
	void printInvalidEmails();

	// Print students by degree program:
	void printByDegreeProgram(DegreeProgram degreeProgram);

	// Destructor:
	~Roster();

	// Getter for classRosterArray:
public:
	Student* getStudentAt(int index) const;

};

#endif