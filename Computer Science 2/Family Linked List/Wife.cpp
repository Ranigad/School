/*
	Wife.cpp
		The implementation of the Wife class, a child of the Person class.
		Wife is pointed to by the Husband class and itself points to a Child.
		
		Wife inherits social security, first name, and last name from the Person
		class.
*/

#ifndef WIFE_CPP
#define WIFE_CPP

#include "Wife.h"
using namespace std;
/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Utilizes the Person default constructor to initialize the values to     *
 * "unknown" type values. children is initialized to NULL.                 *
 ***************************************************************************/
Wife::Wife() : Person()
{
	children = NULL;
}

/***************************************************************************
 * Constructor                                                             *
 *                                                                         *
 * Takes a passed in social security number, first name, and last name and *
 * passes it to the Person constructor to initialize the values.           *
 * children is initialized to NULL by default.							   *
 ***************************************************************************/
 Wife::Wife(long social, string first, string last) : Person(social, first, last)
 {
	children = NULL;
 }
 
/***************************************************************************
 * ~Wife                                                                   *
 *                                                                         *
 * The destructor.                                                         *
 ***************************************************************************/
Wife::~Wife()
{
}
  
  
#endif

