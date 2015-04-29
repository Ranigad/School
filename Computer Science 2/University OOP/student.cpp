/*
	Implementation of the Student Class
	Purpose: To represent a student at a university. Has information about
		the student including a vector of courses that the student has signed	
		up for. 
*/

#ifndef STUDENT_CPP
#define STUDENT_CPP

#include <iostream>
#include "student.h"

long Student::nextStID = 500;	// Student ID of students begin at 500

/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Initializes all the data to "unknown" type data. Utilizes the default   *
 * constructor of the Person class to initialize the personal data.		   *
 ***************************************************************************/
Student::Student() : Person() {
	yearOfStudy = 0;
	major = "None";
	advisorID = 0;
	nextStID++;
}

/***************************************************************************
 * Constructor                                                             *
 *                                                                         *
 * Assigns passed information and utilizes the Person constructor to       *
 * initialize personal data. Increments the student id for next pass       *
 ***************************************************************************/
Student::Student(string nm, string eml, string add, string dob, string gend, int yos, string maj, long adID) : Person(nextStID, nm, eml, add, dob, gend)
{
	yearOfStudy = yos;
	major = maj;
	advisorID = adID;
	nextStID++;
}
	
/***************************************************************************
 * ~Student                                                                *
 *                                                                         *
 * The default destructor.                                                 *
 ***************************************************************************/
Student::~Student()
{
}

/***************************************************************************
 * printCourses                                                            *
 *                                                                         *
 * Prints all the courses taken by the student.                            *
 ***************************************************************************/
void Student::printCourses()
{
	for(int i = 0; i < coursesTaken.size(); i++)
	{
		cout << coursesTaken.at(i) << endl;
	}
}

/***************************************************************************
 * getFacultyID                                                            *
 *                                                                         *
 * Returns the ID of the faculty advisor.                                  *
 ***************************************************************************/
long Student::getFacultyId()
{
	return advisorID;
}

/***************************************************************************
 * getCourseList                                                           *
 *                                                                         *
 * Returns the Course vector that holds the list of courses being taken by *
 * 		the student.						                               *
 ***************************************************************************/
 vector<Course> Student::getCourseList()
 {
	return coursesTaken;
 }
 
/***************************************************************************
 * getMajor                                                                *
 *                                                                         *
 * Returns student's intended major.									   *
 ***************************************************************************/
 string Student::getMajor()
 {
	return major;
 }
/***************************************************************************
 * addCourse                                                               *
 *                                                                         *
 * Takes a passed in course and pushes it into the vector of courses taken *
 ***************************************************************************/
void Student::addCourse(Course newCourse)
{
	coursesTaken.push_back(newCourse);
}

/***************************************************************************
 * removeCourse                                                            *
 *                                                                         *
 * Finds and removes a course from the student's list if it exists.        *
 ***************************************************************************/
bool Student::removeCourse(long courseNum)
{
	for(int i = 0; i < coursesTaken.size(); i++)
	{
		if(coursesTaken.at(i).getCRN() == courseNum)
		{
			coursesTaken.erase(coursesTaken.begin() + i);
			return true;
		}
	}
	return false;
}

/***************************************************************************
 * operator<<                                                              *
 *                                                                         *
 * Defines the output of cout << Student. Displays the name of the Student *
 * and then the ID in parentheses.                                         *
 ***************************************************************************/
ostream& operator<< (ostream& os, const Student& S)
{
	os << S.name << " (" << S.id << ")";
	return os;
}


#endif

