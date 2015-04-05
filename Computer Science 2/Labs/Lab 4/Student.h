#ifndef STUDENT_H
#define STUDENT_H
#include "Course.h"

class Student{
	private:
	long studentNum;
	Course course1;
	Course course2;
	Course course3;
	
	public:
	void setAStudent(long, long, std::string, long, std::string, long, std::string);
	void printAStudent();
	
};

#endif

