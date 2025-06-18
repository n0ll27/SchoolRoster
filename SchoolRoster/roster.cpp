#include <iostream>
#include <string>
#include <vector>
#include "roster.h"

// Constructor:
Roster::Roster() {
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}

// Destructor:
Roster::~Roster() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}

// Add student method w/ body:
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
    DegreeProgram degreeProgram) {

    // Convert separate integers into an array
    int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    // Create a new Student object dynamically
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);

    // Find an empty slot in classRosterArray
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = newStudent;
            return;  // Exit function after adding student
        }
    }

    // If we reach here, the array is full, and we should free the allocated memory
    std::cerr << "Error: Cannot add more students. Roster is full.\n";
    delete newStudent;
}

// Remove student method w/ body given 'studentID' param:
void Roster::remove(std::string studentID) {
    bool studentFound = false;

    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            studentFound = true;
            std::cout << "Student with ID: " << studentID << " has been removed." << "\n";
            break;
        }
    }

    if (!studentFound) {
        std::cout << "Error: Student with ID: " << studentID << " not found." << "\n";
    }
}

// Print all student data w/ body:
void Roster::printAll() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->StudentPrint();  
        }
    }
}

// Print avg w/ body given 'studentID' param:
void Roster::printAverageDaysInCourse(std::string studentID) {
    bool studentFound = false;

    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            const int* days = classRosterArray[i]->getDaysToComplete();
            double avgDays = (days[0] + days[1] + days[2]) / 3.0;
            std::cout << "Student ID: " << studentID << ", Average Days in Course: " << avgDays << "\n";
            studentFound = true;
            break;
        }
    }

    if (!studentFound) {
        std::cout << "Error: Student with ID: " << studentID << " not found.\n";
    }
}



// Print invalid email addresses:
void Roster::printInvalidEmails() {
    bool invalidEmailFound = false;

    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            std::string email = classRosterArray[i]->getEmail();

            if (email.find('@') == std::string::npos ||              
                email.find('.') == std::string::npos ||              
                email.find(' ') != std::string::npos ||            
                email.find('@') > email.find('.') ||               
                email.find('@') == 0 ||                           
                email.find('.') == email.length() - 1 ||         
                email.find('@') == email.length() - 1) {         
                std::cout << "Invalid email: " << email << "\n";
                invalidEmailFound = true;
            }
        }
    }

    if (!invalidEmailFound) {
        std::cout << "No invalid emails found." << "\n";
    }
}



// Printing students given their degree program as a parameter:
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->StudentPrint(); 
        }
    }
}

// Get student at index (helper method for main.cpp):
Student* Roster::getStudentAt(int index) const {
    if (index >= 0 && index < 5) {
        return classRosterArray[index];
    }
    return nullptr;
}
