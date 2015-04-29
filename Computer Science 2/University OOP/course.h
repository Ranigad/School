/*
	Class definition of the Course class
*/

#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course{
	
	friend ostream& operator<< (ostream&, const Course&);
	protected:
	
	// Course Info
	long CRN;
	int maxAvailableSeats;
	string name;
	long departID;
	long assignedSeats;
	long isTaughtBy;
	static long nextCRN;
	
	public:
	// Constructor / Destructor
	Course();
	Course(string, int, long, long);
	~Course();
	
	// Get / Set methods
	void setProfessor(long);
	long getProfessor();
	long getCRN();
	long getAssignedSeats();
	string getName();
	long getDepartID();
	
	// IsFull method
	bool isFull();	// Checks if the class is full
	
	// Additional Operator Overloads
	Course operator++(int);	// Increments assignedSeats
	Course operator--(int);	// Decrements assignedSeats

	};


#endif

