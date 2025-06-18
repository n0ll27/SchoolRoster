#ifndef DEGREE_H
#define DEGREE_H
#include <string>

enum DegreeProgram {

	SECURITY,
	NETWORK,
	SOFTWARE
};

static const std::string DegreeProgramStrings[3] = { "SECURITY", "NETWORK", "SOFTWARE" };

#endif