#ifndef STUDENT_CPP
#define STUDENT_CPP

#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

	void Student::setAStudent(long studentNumber, long courseNum1, string courseName1, long courseNum2, string courseName2, long courseNum3, string courseName3)
	{
		studentNum = studentNumber;
		course1.setACourse(courseNum1, courseName1);
		course2.setACourse(courseNum2, courseName2);
		course3.setACourse(courseNum3, courseName3);
	}
	
	void Student::printAStudent()
	{
		cout << "Student Number: " << studentNum << endl;
		course1.printACourse();
		course2.printACourse();
		course3.printACourse();
	}
	
#endif

