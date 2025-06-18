#include <iostream>
#include <string>
#include <iomanip>
#include "student.h"

// Constructor:
Student::Student(std::string StudentID, std::string FirstName, std::string LastName, std::string Email, int Age, int DaysToComplete[3], DegreeProgram degreeProgram) {
	this->StudentID = StudentID;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->Email = Email;
	this->Age = Age;
	// Iterating for each index in DaysToComplete:
	for (int i = 0; i < 3; ++i) {
		this->DaysToComplete[i] = DaysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}
// Getters:
std::string Student::getStudentID() const {
	return StudentID;
}
std::string Student::getFirstName() const {
	return FirstName;
}
std::string Student::getLastName() const {
	return LastName;
}
std::string Student::getEmail() const {
	return Email;
}
int Student::getAge() const {
	return Age;
}
const int* Student::getDaysToComplete() const {
	return DaysToComplete;
}
DegreeProgram Student::getDegreeProgram() const {
	return degreeProgram;
}

// Setters:
void Student::setStudentID(std::string StudentID) {
	this->StudentID = StudentID;
}
void Student::setFirstName(std::string FirstName) {
	this->FirstName = FirstName;
}
void Student::setLastName(std::string LastName) {
	this->LastName = LastName;
}
void Student::setEmail(std::string Email) {
	this->Email = Email;
}
void Student::setAge(int Age) {
	this->Age = Age;
}
void Student::setDaysToComplete(int DaysToComplete[]) {
	for (int i = 0; i < 3; ++i) {
		this->DaysToComplete[i] = DaysToComplete[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

// Display (Source):
void Student::StudentPrint() const {
	// Local variables (More efficient compilation):
	std::string TempStudentID = getStudentID();
	std::string TempFirstName = getFirstName();
	std::string TempLastName = getLastName();
	std::string TempEmail = getEmail();
	int TempAge = getAge();
	const int* TempDays = getDaysToComplete();
	DegreeProgram TempProgram = getDegreeProgram();

	// Output with more specific information regarding what is being shown:
	std::cout << "Student ID: " << std::setw(4) << TempStudentID << "\t"
		<< "First Name: " << std::setw(10) << TempFirstName << "\t"
		<< "Last Name: " << std::setw(10) << TempLastName << "\t"
		<< "Email: " << std::setw(25) << TempEmail << "\t"
		<< "Age: " << std::setw(3) << TempAge << "\t"
		<< "Days: " << TempDays[0]
		<< "," << TempDays[1]
		<< "," << TempDays[2] << "\t"
		<< "Degree Program: " << DegreeProgramStrings[TempProgram] << "\n";
}