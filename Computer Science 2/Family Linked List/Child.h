/*
	Child.h
		The class definition of the Child class (not the child class)
*/

#ifndef CHILD_H
#define CHILD_H
#include "Person.h"
class Child;
typedef Child* ChildPtr;

class Child : public Person {

	friend class Family;

	private:
		ChildPtr mySibling;
		
	public:
		Child();
		Child(long, std::string, std::string);
		~Child();
};

#endif
