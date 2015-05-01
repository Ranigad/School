/*
	Child.cpp
		The implementation of the Child class, the child of the Person class.
		Child is pointed to by the Wife class and points to other Child classes.
		
		Child inherits social security, first name, and last name from the 
		Person class.
*/

#ifndef CHILD_CPP
#define CHILD_CPP

#include "Child.h"
using namespace std;

/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Utilizes the Person default constructor to initialize the Child class to*
 * default values. mySibling is initialized to NULL                        *
 ***************************************************************************/
 Child::Child() : Person()
 {
	mySibling = NULL;
 }
 
/***************************************************************************
 * Constructor                                                             *
 *                                                                         *
 * Takes a passed social security number, first name, and last name and    *
 * uses the Person constructor to initialize the values of Child.          *
 * Also initializes mySibling to NULL.									   *
 ***************************************************************************/
 Child::Child(long social, string first, string last) : Person(social, first, last)
 {
	mySibling = NULL;
 }
 
/***************************************************************************
 * ~Child                                                                  *
 *                                                                         *
 * The destructor.                                                         *
 ***************************************************************************/
 Child::~Child()
 {
 }


#endif

