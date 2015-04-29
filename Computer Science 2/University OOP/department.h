/*
	Class definition of the Department Class
*/

#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
using namespace std;

class Department {
	
	friend ostream& operator<< (ostream&, const Department&);	
	
	// Department information
	protected:
	long id;
	string name;
	string location;
	long chairID;
	static long nextDepartID;
	
	public:
	// Constructor / Destructor
	Department();
	Department(string, string, long);
	~Department();
	
	// Get/Set methods
	long getDepartmentID();
	string getName();
	long getChairID();
	
	void setChair(long);
};

#endif

