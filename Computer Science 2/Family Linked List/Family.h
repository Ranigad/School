/*
	Family.h
		The class definition of the Family class.
*/
#ifndef FAMILY_H
#define FAMILY_H
#include <string>
#include "Husband.h"
using namespace std;

class Family {
	protected:
	Husband* top;
	
	public:
	Family();
	~Family();

	// Mutators (Add/Removes)
	
		// Husband
	void AddHusband(long, string, string);
	void RemoveHusband(long);
	
		// Wife
	void AddWife(long, string, string, long);
	void RemoveWife(long);
	
		// Child
	void AddAChild(long, string, string, long);
	void RemoveAChild(long, long);
	
	// Print Functions
	void PrintAFamily(long);
	void PrintAllFamilies();
	
	// List Initialization
	void ReadTransactionFile();
	
	bool SearchForHusband(long);
	void RemoveAllChildrenInFamily(long);
	Husband* getHusband(long);
	bool RemoveAllFamilies();
};


#endif