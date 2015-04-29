/*
	Class definition for Faculty class
*/

#ifndef FACULTY_H
#define FACULTY_H

#include "person.h"

class Faculty : public Person{
	friend ostream& operator<< (ostream&, const Faculty&);
	
	protected:
	float salary;
	int yearOfExp;
	long departID;
	static long nextFacultyID;
	
	public:
	//Constructor / Destructors
	Faculty();
	Faculty(string, string, string, string, string, float, int, long);
	~Faculty();
	
	// Accessors
	long getFacultyID();
	long getDepID();
	
	};

#endif

