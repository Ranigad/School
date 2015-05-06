/*
	Husband.h
		The class definition for the Husband class.
*/

#ifndef HUSBAND_H
#define HUSBAND_H
#include <string>
#include "Person.h"
#include "Wife.h"
class Husband;
typedef Husband* HusbandPtr;

class Husband : public Person{

	friend class Family;

	private:
		Husband* nextFamily;
		Wife* myWife;
		
	public:
		Husband();
		Husband(long, std::string, std::string);
		~Husband();

};

#endif
