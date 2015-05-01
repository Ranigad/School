/*
	Husband.cpp
		Implementation of the Husband class. Husband is the top of each
		family list and will point to the wife. The list of families itself is
		comprised of Husbands.
		
		Inherits the social security number, first name, and last name from 
		the person class.

*/

#ifndef HUSBAND_CPP
#define HUSBAND_CPP

#include "Husband.h"
using namespace std;

/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Initializes the values of Husband to default "unknown" type values.     *
 * Utilizes the Person default constructor and points wife/nextFam to NULL.*
 ***************************************************************************/
Husband::Husband() : Person()
{
	nextFamily = NULL;
	myWife = NULL;
}

/***************************************************************************
 * Constructor                                                             *
 *                                                                         *
 * Initializes the values of Husband utilizing the Person constructor.     *
 * Also sets wife and nextFamily to NULL.                                                 *
 ***************************************************************************/
Husband::Husband(long social, string first, string last) : Person(social, first, last)
{
	nextFamily = NULL;
	myWife = NULL;
}

/***************************************************************************
 * ~Husband                                                                *
 *                                                                         *
 * The destructor.                                                         *
 ***************************************************************************/
Husband::~Husband()
{
}

#endif


