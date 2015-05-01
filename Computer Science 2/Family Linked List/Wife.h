/*
	Wife.h
		The class definition of the Wife class.
*/

#ifndef WIFE_H
#define WIFE_H
#include "Person.h"
#include "Child.h"

class Wife : public Person{
	
	friend class Family;
	
	private:
	Child* children;
	
	public:
	Wife();
	Wife(long, std::string, std::string);
	~Wife();
};



#endif

