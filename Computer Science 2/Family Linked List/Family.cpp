/*
	Family.cpp
		The implementation of the Family class. 
		
		The Family class is the linked list for the various families which 
		contain the Husband, Wife, and Child classes.
		
		Utilizes a Husband pointer as the top of the list.
*/

#ifndef FAMILY_CPP
#define FAMILY_CPP

#include <fstream>
#include <iostream>
#include "Husband.h"
#include "Wife.h"
#include "Child.h"
#include "Family.h"
using namespace std;


//-----------------------------------------------------------------------------
// Static Bools
// Used to make the code more readable.
bool Family::success = true;
bool Family::failure = false;

//-----------------------------------------------------------------------------
// Constructor / Destructor 
/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Sets top to NULL.                                                       *
 ***************************************************************************/
Family::Family()
{
	top = NULL;
}

/***************************************************************************
 * ~Family                                                                 *
 *                                                                         *
 * The destructor.                                                         *
 ***************************************************************************/
Family::~Family()
{
	RemoveAllFamilies();
}

//-----------------------------------------------------------------------------
// Mutators

//-----------------------------------------------------------------------------
	// Husband
/***************************************************************************
 * AddAHusband                                                             *
 *                                                                         *
 * Adds a Node of Husband class to the end of the horizontal list.         *
 ***************************************************************************/
void Family::AddHusband(long husbandSSN, string first, string last)
{
	// Make the new family
	HusbandPtr newFamily = new Husband(husbandSSN, first, last);

	newFamily -> nextFamily = top;	// Prepares for insert at top
	top = newFamily;	// Inserts at top
	
	// Success message.
	cout << first << " " << last << " has been added to the list!" << endl;
}
  
/***************************************************************************
 * RemoveHusband                                                           *
 *                                                                         *
 * Given a long SSN, delete the husband in the list with the corresponding *
 * SSN.                                                                    *
 ***************************************************************************/
bool Family::RemoveHusband(long husbandSSN)
{
	HusbandPtr theHusband = getHusband(husbandSSN);
	
	// Case where husband not found.
	if(theHusband == NULL)
	{
		cout << "No husband to remove." << endl;
		return failure;
	}
	// If the husband has a wife, call RemoveWife.
	// RemoveWife automatically removes all children if applicable.
	if(theHusband -> myWife != NULL)
		RemoveWife(husbandSSN);
	
	// Case where the top node is the husband in question.
	if(top == theHusband)
	{
		top = top -> nextFamily;	// Move top down to the next family.
	}
	else
	{
		// Pointer to the family before currently selected husband.
		HusbandPtr previous = top;	
		
		// Cycle until you reach the correct Husband.
		while(previous -> nextFamily != theHusband)
		{
			previous = previous -> nextFamily;
		}
		// Connects the previous and next node from the current.
		previous -> nextFamily = theHusband -> nextFamily;	
	}

	delete theHusband;	// Deletes the husband.
	return success;
}

//-----------------------------------------------------------------------------
	// Wife
/***************************************************************************
 * AddAWife                                                                *
 *                                                                         *
 * Adds a Node of the Wife class below a Husband node. Is passed a husband *
 * SSN in order to identify the husband                                    *
 ***************************************************************************/
void Family::AddWife(long wifeSSN, string first, string last, long husbandSSN)
{		
	
	HusbandPtr theHusband = getHusband(husbandSSN);
	
	// Case for husband not found.
	if(theHusband == NULL)
	{
		cout << "There's nobody for " << first << " " << last 
			<< " to marry" << endl;
		return;
	}
	
	// Checks if the husband is already married. Returns if he is.
	if(theHusband -> myWife != NULL)
	{
		cout << theHusband -> firstName << " " << theHusband -> lastName 
			<< " is already married! Adultery is bad! Shame on "
			<< first << " " << last << "." << endl;
		return;
	}

	WifePtr newWife = new Wife(wifeSSN, first, last);	// Creates the wife
	theHusband -> myWife = newWife;	// Sets the wife.
	newWife -> children = NULL;	// Should be done in constructor already.
	
	// Success message.
	cout << "I now pronounce " << first << " " << last << " and "
		<< theHusband -> firstName << " " << theHusband -> lastName 
		<< " husband and wife." << endl;
}

/***************************************************************************
 * RemoveWife                                                              *
 *                                                                         *
 * Is passed the SSN of her husband. Removes the wife of the husband that  *
 * has the associated SSN.                                                 *
 ***************************************************************************/
bool Family::RemoveWife(long husbandSSN)
{
	
	HusbandPtr theHusband = getHusband(husbandSSN);
	
	// Husband could not be found case.
	if(theHusband == NULL)
	{
		cout << "No wife to remove." << endl;
		return failure;
	}
	
	WifePtr theWife = theHusband -> myWife;
	
	// Checks if there is a wife to delete. Returns if there isn't.
	if(theWife == NULL)
	{
		cout << theHusband -> firstName << " " << theHusband -> lastName
			<< " is currently unmarried. Could not remove wife." << endl;
		return failure;
	}

	// Delete all children first
	RemoveAllChildrenInFamily(theHusband -> SSN);

	// Delete wife and set the wife pointer to NULL.		
	delete theWife;
	theHusband -> myWife = NULL;
	return success;
}	

//-----------------------------------------------------------------------------
	// Child
/***************************************************************************
 * AddAChild                                                               *
 *                                                                         *
 * Creates a new child under the husband that matches the passed SSN.      *
 ***************************************************************************/
void Family::AddAChild(long childSSN, string first, string last, long dadSSN)
{
	
	DadPtr theHusband = getDad(dadSSN);
	
	// Husband couldn't be found case.
	if(theHusband == NULL)
	{
		cout << "There is no dad for " << first << " " << last << endl;
		return;
	}
	
	WifePtr theWife = theHusband -> myWife; 	// Wife for reference
	
	// If there is no wife case.
	if(theWife == NULL)
	{
		cout << theHusband -> firstName << " " << theHusband -> lastName 
			<< " isn't married. He can't have a child." << endl;
		return;
	}
	
	ChildPtr newChild = new Child(childSSN, first, last);	// Creates the child
	
	// Adds the child to the top of the child list
	newChild -> mySibling = theWife -> children;	
	theWife -> children = newChild;

	// Output message.
	cout << first << " " << last << " has been added under "
		<< theHusband -> firstName << " " << theHusband -> lastName << endl;
}

/***************************************************************************
 * RemoveAChild                                                            *
 *                                                                         *
 * Given the SSN of the child and father, finds the corresponding husband  *
 * and then deletes the child from the list.                               *
 ***************************************************************************/
bool Family::RemoveAChild(long childSSN, long dadSSN)
{	
	
	DadPtr theDad = getDad(dadSSN);
	
	// The case where the dad doesn't exist or couldn't be found.
	if(theDad == NULL)
	{
		cout << "No child to remove." << endl;
		return failure;
	}
	
	// Case where there isn't a wife.
	if(theDad -> myWife == NULL)
	{
		cout << theDad -> firstName << " " << theDad -> lastName
			<< " does not have a wife. No child to remove." << endl;
		return failure;
	}
	
	// Create a child pointer and initialize to first child.
	ChildPtr currentChild = theDad -> myWife -> children;	
	ChildPtr previousChild = currentChild;	// Holds previous child
	
	// Case if the first child in list is the one being deleted
	// Wife class's children pointer must be changed rather than mySibling
	if(currentChild -> SSN == childSSN)
	{
		theDad -> myWife -> children = currentChild -> mySibling;
	}
	else
	{
		// Finds the correct child.
		while(currentChild -> SSN != childSSN)
		{
			// Cycling through the children.
			previousChild = currentChild;
			currentChild = currentChild -> mySibling;
			
			// 404 Child not found
			if(currentChild == NULL)
			{
				cout << "Child doesn't exist. Could not remove." << endl;
				return failure;
			}
		}
		
		// Has the child before the one being deleted point to the one after
		previousChild -> mySibling = currentChild -> mySibling;
	}
		
	delete currentChild;	// Deletes the child.
	return success;
}

/***************************************************************************
 * RemoveAllChildrenInFamily                                               *
 *                                                                         *
 * Deletes all the children of a family given the father's SSN.            *
 ***************************************************************************/
void Family::RemoveAllChildrenInFamily(long dadSSN)
{
	DadPtr theDad = getDad(dadSSN);
	if(theDad == NULL)	// Catch husband does not exist.
	{
		cout << "Could not find Dad. Children could not be removed." << endl;
		return;
	}
	
	WifePtr theWife = theDad -> myWife;
	
	if(theWife == NULL)	// Checks if there is a wife
	{
		cout << "This husband has no wife. No children to remove." << endl;
		return;
	}
	
	// Removes the children one at a time from the top of the list.
	while(theWife -> children != NULL)
	{
		RemoveAChild(theWife -> children -> SSN, dadSSN);
	}
	return;
}

//-----------------------------------------------------------------------------
// Print Functions
/***************************************************************************
 * PrintAFamily                                                            *
 *                                                                         *
 * Given an SSN for a husband, find the husband in the list and print all  *
 * the associated family members.                                          *
 ***************************************************************************/
void Family::PrintAFamily(long husbandSSN)
{	
	
	HusbandPtr theHusband = getHusband(husbandSSN);
	
	// Empty list case.
	if(theHusband == NULL)
	{
		cout << "Could not print family." << endl;
		return;
	}
	
	cout << "Husband" << endl << *theHusband << endl;	// Print husband info.
	
	// Checks if there is a wife, returns if there isn't.
	if(theHusband -> myWife == NULL)
		return;
	
	// If there is, print the wife's information.
	WifePtr theWife = theHusband -> myWife;
	cout << "Wife" << endl << *theWife << endl;
	
	// Checks if the wife has children, returns if there aren't.
	if(theWife -> children == NULL)
		return;
	
	ChildPtr theChild = theWife -> children;
	
	// Prints out all the children using a while loop.
	cout << "Children" << endl;
	
	while(theChild != NULL)
	{
		cout << *theChild << endl;
		theChild = theChild -> mySibling;
	}
	
}

/***************************************************************************
 * PrintAllFamilies                                                        *
 *                                                                         *
 * Prints all the husbands and their associated family members in the list.* ***************************************************************************/
void Family::PrintAllFamilies()
{
	// Checks if there are families
	if(top != NULL)
	{
		HusbandPtr theHusband = top;
		// If there are husbands, loop until the end of the list.
		while (theHusband != NULL)
		{
			if(theHusband != top)	// Don't print divider on the first print
			{
				cout << "---------------------------------------- \n\n";
			}
			PrintAFamily(theHusband -> SSN);	// Print using PrintAFamily
			theHusband = theHusband -> nextFamily;	// Cycles to next husband.
		}
	}
	// Case where list is empty.
	else
	{
		cout << "There are no families!" << endl;
	}
}

//-----------------------------------------------------------------------------
// List Initialization
/***************************************************************************
 * ReadTransactionFile                                                     *
 *                                                                         *
 * Reads a command and parameters from a designated input file and calls a *
 * corresponding method.                                                   *
 ***************************************************************************/
void Family::ReadTransactionFile()
{
	string command;	// To hold the command.
	ifstream fin;
	fin.open("data.txt");
	
	// Checks if file exists, returns if it doesn't.
	if(!fin)
	{
		cout << "File not found. " << endl;
		return;
	}
	
	// Keeps pulling in commands until end of file.
	while(fin >> command)
	{
		cout << "Command: " << command << endl;	// Prints the command.
		
		// Calls a method and imports more data depending on the command.
		if(command.compare("AddHusband") == 0)
		{
			long id;
			string first, last;
			fin >> id >> first >> last;
			AddHusband(id, first, last);
		}
		else if(command.compare("AddWife") == 0)
		{
			long wifeId, husbandId;
			string first, last;
			fin >> wifeId >> first >> last >> husbandId;
			AddWife(wifeId, first, last, husbandId);
		}
		else if(command.compare("RemoveHusband") == 0)
		{
			long id;
			fin >> id;
			string husbandName = getName(id, 0, "Husband");
			if(RemoveHusband(id))
				cout << husbandName << "'s family removed." << endl;
		}
		else if(command.compare("RemoveWife") == 0)
		{
			long husbandId;
			fin >> husbandId;
			string wifeName = getName(husbandId, 0, "Wife");
			if(RemoveWife(husbandId))
			{
				cout << wifeName << " and children removed from " 
					<< getName(husbandId, 0, "Husband") << "'s family" << endl;
			}
		}
		/* Note: Lower cased c because that's how Hadaegh had it in his example
				data file. Could potentially write a string formatter to insure
				uniform naming
		*/
		else if(command.compare("AddAchild") == 0)
		{
			long childId, dadId;
			string first, last;
			fin >> childId >> first >> last >> dadId;
			AddAChild(childId, first, last, dadId);
		}
		else if(command.compare("RemoveAchild") == 0)
		{
			long childId, dadId;
			fin >> dadId >> childId;
			string childName = getName(dadId, childId, "Child");
			if(RemoveAChild(childId, dadId))
			{
				cout << childName << " removed from " 
					<< getName(dadId, 0, "Dad") << "'s family" << endl;
			}
		}
		else if(command.compare("PrintAFamily") == 0)
		{
			long dadId;
			fin >> dadId;
			cout << endl;
			PrintAFamily(dadId);	
		}
		else if(command.compare("PrintAllFamilies") == 0)
		{
			cout << endl;
			PrintAllFamilies();
		}
		else
			cout << "Invalid command." << endl;
		
		// Divider
		cout << "______________________________________________________________"
			<< "_______________" << endl;
	
	}
	
}

//-----------------------------------------------------------------------------
// Helper Functions
/***************************************************************************
 * getHusband                                                              *
 *                                                                         *
 * Given the husband's SSN, returns the pointer to the husband's node.	   *
 ***************************************************************************/
HusbandPtr Family::getHusband(long husbandSSN)
{
	// Empty list case.
	if(top == NULL)
	{
		cout << "This list is empty! ";
		return NULL;
	}
	
	HusbandPtr theHusband = top; // Pointer to cycle through the list.
	
	// Cycle until you reach the node after the last family.
	while(theHusband != NULL)
	{
		// Returns true if SSN provided matches the husband's.
		if(theHusband -> SSN == husbandSSN)
			return theHusband;
		
		theHusband = theHusband -> nextFamily;	// Move to next family
	}
	
	cout << "Husband is not on the list. ";
	return NULL; // If not found then the above won't catch. Therefore false.
}
 
/***************************************************************************
 * getDad                                                                  *
 *                                                                         *
 * Another name for getHusband. For clarity in the case of children.       *
 ***************************************************************************/
 DadPtr Family::getDad(long dadSSN)
 {
	 return getHusband(dadSSN);
 }
 
/***************************************************************************
 * getName     		                                                       *
 *                                                                         *
 * Generic function that returns the name of a husband, wife, or child     *
 * given the dad/husband's ssn, the child's ssn if looking for child (0 if *
 * otherwise), and the string of the name of the family member (i.e. Dad,  *
 * Child, Husband, or Wife). 											   *
 *																		   *
 * Utilized primarily to allow Remove method calls to have a more		   *
 * descriptive return message since they do not have easy access to names. *
 *																		   *
 * [Note: If the getName function fails to find the name, it will return an*
 * empty string. This is okay since if it fails to find the name, then in  *
 * the ReadTransactionFile method, the message will never be displayed     *
 * since the primary method being called (RemoveWife, RemoveAChild, etc.)  *
 * will return false. So the string returned on failure doesn't matter.    *			 
 ***************************************************************************/
 string Family::getName(long husbandSSN, long childSSN, 
						string familyMember)
 {
	
	// Empty list case
	if(top == NULL)
	{
		return " ";
	}
	
	HusbandPtr theHusband = top;
	// Cycles through and finds the husband or hits NULL if it doesn't
	while(theHusband != NULL && theHusband -> SSN != husbandSSN)
	{
		theHusband = theHusband -> nextFamily;
	}
	
	// If the husband wasn't found, return "nothing".
	if(theHusband == NULL)
	{
		return " ";
	}
	
	// If the desired name is the husband's, return the husband's name.
	// Otherwise, it will fall through.
	if(familyMember.compare("Husband") == 0 || familyMember.compare("Dad") == 0)
	{
		return theHusband -> firstName + " " + theHusband -> lastName;
	}
	
	// Check if wife exists, return "nothing" if it doesn't
	if(theHusband -> myWife == NULL)
	{
		return " ";
	}
	
	// If the desired name is the wife's, then return the wife's name.
	WifePtr theWife = theHusband -> myWife;
	if(familyMember.compare("Wife") == 0)
	{
		return theWife -> firstName + " " + theWife -> lastName;
	}
	
	// Check if there are children, return if none.
	if(theWife -> children == NULL)
	{
		return " ";
	}
	
	// Cycle through the children until null is hit or if the SSN matches
	ChildPtr theChild = theWife -> children;
	while(theChild != NULL && theChild -> SSN != childSSN)
	{
		theChild = theChild -> mySibling;
	}
	
	// Checks if the childSSN provided doesn't match any child under the dad.
	// returns "nothing" if that's the case. (Prevents segmentation fault).
	if(theChild == NULL)
	{
		return " ";
	}
	
	// Checks if the SSN does match (it should at this point but just incase)
	if(theChild -> SSN == childSSN)
	{
		return theChild -> firstName + " " + theChild -> lastName;
	}
	
	// Catches if the method misses anything.
	return " ";
 }
 
  
/***************************************************************************
 * RemoveAllFamilies                                                       *
 *                                                                         *
 * Deletes all the families in the list.                                   *
 ***************************************************************************/
  
void Family::RemoveAllFamilies()
{	
	HusbandPtr headOfFamily = top;
	while(top != NULL)
	{
		headOfFamily = top -> nextFamily;	// Saves the next family.
		RemoveHusband(top -> SSN);	// Removes the husband using RemoveHusband
		top = headOfFamily;	// Shifts top down. This way top will end as NULL.
	}
}

#endif

