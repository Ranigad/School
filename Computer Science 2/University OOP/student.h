/*
	Class definition of the Student class
*/

#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include "course.h"
#include <vector>

class Student : public Person{
	friend ostream& operator<< (ostream&, const Student&);
	
	protected:
	int yearOfStudy;
	string major;
	long advisorID;
	vector<Course> coursesTaken;	// Vector of courses enrolled in by student
	static long nextStID;
	
	public:
	// Constructor / Destructor
	Student();
	Student(string, string, string, string, string, int, string, long);
	~Student();
	
	// Accessors
	void printCourses();
	long getFacultyId();
	vector<Course> getCourseList();
	string getMajor();
	
	// Mutators
	bool removeCourse(long);
	void addCourse(Course);
};


#endif

