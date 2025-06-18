#include <iostream>
#include <string>
#include "roster.h"

int main() {
    // Output general info:
    const std::string CourseTitle = "SCRIPTING AND PROGRAMING - APPLICATIONS - C867";
    std::cout << "WGU Course Title: " << CourseTitle << "\n";
    std::cout << "Programming Language Used: C++" << "\n";
    std::cout << "WGU Student ID: 011869871" << "\n";
    std::cout << "My Name: Daniel R.C. Chaves" << "\n\n";

    // Instantiating a 'Roster' class object:
    Roster classRoster;

    // Adding students to the roster:
    classRoster.add("A1", "John", "Smith", "John1989@gmail.com", 20, 30, 35, 40, SECURITY);
    classRoster.add("A2", "Suzan", "Erickson", "Erickson_1990@gmail.com", 19, 50, 30, 40, NETWORK);
    classRoster.add("A3", "Jack", "Napoli", "The_lawyer99@yahoo.com", 19, 20, 40, 33, SOFTWARE);
    classRoster.add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
    classRoster.add("A5", "Daniel", "Chaves", "dcha444@wgu.edu", 19, 9, 21, 17, SOFTWARE);

    // Output all student data:
    std::cout << "[ALL STUDENT DATA]" << "\n";
    classRoster.printAll();
    std::cout << "\n";

    // Output invalid emails:
    std::cout << "[INVALID EMAILS]" << "\n";
    classRoster.printInvalidEmails();
    std::cout << "\n";

    // Output avg days in course/student:
    std::cout << "[AVERAGE DAYS IN COURSE PER STUDENT]" << "\n";
    for (int i = 0; i < 5; ++i) {
        Student* TempStudent = classRoster.getStudentAt(i);
        if (TempStudent != nullptr) {  // Null check to avoid dereferencing
            classRoster.printAverageDaysInCourse(TempStudent->getStudentID());
        }
    }
    std::cout << "\n";

    // Output by degree program:
    std::cout << "[OUTPUT BY DEGREE PROGRAM (SOFTWARE)]" << "\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << "\n";

    // Removing a student:
    std::cout << "[REMOVING STUDENT 'A3']" << "\n";
    classRoster.remove("A3");
    std::cout << "\n";

    // Attempting to remove 'A3' again (should trigger "not found" message):
    std::cout << "[ATTEMPTING TO REMOVE 'A3' AGAIN]" << "\n";
    classRoster.remove("A3");
    std::cout << "\n";

    // Final roster display after removal:
    std::cout << "[FINAL ROSTER AFTER REMOVAL]" << "\n";
    classRoster.printAll();
    std::cout << "\n";

    return 0;
}
