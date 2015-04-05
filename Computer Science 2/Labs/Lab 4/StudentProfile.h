#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H
#include "Person.h"
#include "Student.h"

class StudentProfile{
	private: 
	Person personalInfo;
	Student stdInfo;
	
	public:
	void setAStudentProfile(long, std::string, std::string, int, char, long, long, std::string, long, std::string, long, std::string);
	void printAStudentProfile();
};

#endif


