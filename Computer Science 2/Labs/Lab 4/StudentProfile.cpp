#ifndef STUDENTPROFILE_CPP
#define	STUDENTPROFILE_CPP

#include <string>
#include "StudentProfile.h"
using namespace std;

	void StudentProfile::setAStudentProfile(long SSN, string first, string last, int age, char gender, long stNo, long courseNum1, string courseName1, long courseNum2, string courseName2, long courseNum3, string courseName3)
	{
		personalInfo.setAPerson(SSN, first, last, age, gender);
		stdInfo.setAStudent(stNo, courseNum1, courseName1, courseNum2, courseName2, courseNum3, courseName3);
	}	
	
	void StudentProfile::printAStudentProfile()
	{
		personalInfo.printAPerson();
		stdInfo.printAStudent();
	}

#endif
	
	
	