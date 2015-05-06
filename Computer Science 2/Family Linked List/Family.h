/*
	Family.h
		The class definition of the Family class.
*/
#ifndef FAMILY_H
#define FAMILY_H
#include <string>
#include "Husband.h"
using namespace std;

typedef Husband* DadPtr;

class Family {
	protected:
	HusbandPtr top;
	
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
	void RemoveAllChildrenInFamily(long);
	
	// Print Functions
	void PrintAFamily(long);
	void PrintAllFamilies();
	
	// List Initialization
	void ReadTransactionFile();
	
	// Helper Functions
	DadPtr getDad(long);
	HusbandPtr getHusband(long);
	void RemoveAllFamilies();
};


#endif
