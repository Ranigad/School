#ifndef COURSE_CPP
#define COURSE_CPP

#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

	void Course::setACourse(long courseNumber, string courseNam)
	{
		courseNum = courseNumber;
		courseName = courseNam;
	}
	
	void Course::printACourse()
	{
		cout << "Course: (" << courseNum << ") " << courseName << endl;
	}
	
#endif
	
	