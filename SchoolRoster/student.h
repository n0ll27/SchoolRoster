#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"

class Student {
protected:
	// Attributes:
	std::string StudentID;
	std::string FirstName;
	std::string LastName;
	std::string Email;
	int Age;
	int DaysToComplete[3];
	DegreeProgram degreeProgram;

public:
	// Constructor:
	Student(std::string StudentID, std::string FirstName, std::string LastName, std::string Email, int Age, int DaysToComplete[3], DegreeProgram degreeProgram);
public:
	// Getters:
	std::string getStudentID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getEmail() const;
	int getAge() const;
	const int* getDaysToComplete() const;
	DegreeProgram getDegreeProgram() const;
public:
	// Setter:
	void setStudentID(std::string StudentID);
	void setFirstName(std::string FirstName);
	void setLastName(std::string LastName);
	void setEmail(std::string Email);
	void setAge(int Age);
	void setDaysToComplete(int DaysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);
public:
	// Display:
	void StudentPrint() const;
};

#endif