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
}
 
/***************************************************************************
 * AddAHusband                                                             *
 *                                                                         *
 * Adds a Node of Husband class to the end of the horizontal list.         *
 ***************************************************************************/
void Family::AddHusband(long social, string first, string last)
{
	// Make the new family
	Husband* newFamily = new Husband(social, first, last);

	newFamily -> nextFamily = top;	// Prepares for insert at top
	top = newFamily;	// Inserts at top
	
	cout << first << " " << last << " has been added to the list!" << endl;
	
	/*	Insert at bottom Case
	else
	{
		newFamily -> nextFamily = NULL;	// Already done in constructor
		Husband* current = top;		// Pointer to cycle through the list
		while(current -> nextFamily != NULL)
		{
			// Move the cycling pointer until you find the last Family
			current = current -> nextFamily;
		}
		current -> nextFamily = newFamily; // Add the new family to the end.
	}
	*/
}
  
/***************************************************************************
 * RemoveHusband                                                           *
 *                                                                         *
 * Given a long SSN, delete the husband in the list with the corresponding *
 * SSN.                                                                    *
 ***************************************************************************/
void Family::RemoveHusband(long social)
{		
	// No node case
	if(top == NULL)
	{
		cout << "This list is empty! Could not remove husband." << endl;
		return;
	}
	
	// Id not in the family list case
	if(!SearchForHusband(social)) 
	{
		cout << "Husband is not in this list. Could not remove husband." 
			<< endl;
		return;
	}

	
	Husband* current = top;		// Pointer to cycle through the list.
	Husband* previous = top;	// Pointer to the family before current.
	
	// Cycle until you reach the correct Husband.
	while(current -> SSN != social)
	{
		previous = current;
		current = current -> nextFamily;
	}
		
	if(top -> SSN == social)
	{
		top = top -> nextFamily;
		cout << current -> firstName << " " << current -> lastName << "'s family"
		<< " has been removed from the list." << endl;
		delete current;
		return;
	}
	// Connects the previous and next node from the current.
	previous -> nextFamily = current -> nextFamily;	
	
	// If there's only one node, set top equal to NULL and delete the one node.
	// We already know it exists from the search.
	if(top -> nextFamily == NULL)
		top = NULL;
	
	// If the husband has a wife, call RemoveWife.
	// RemoveWife automatically removes all children.
	if(top -> myWife != NULL)
		RemoveWife(social);
	
	cout << current -> firstName << " " << current -> lastName << "'s family"
		<< " has been removed from the list." << endl;
		
	delete current;
}

/***************************************************************************
 * AddAWife                                                                *
 *                                                                         *
 * Adds a Node of the Wife class below a Husband node. Is passed a husband *
 * SSN in order to identify the husband                                    *
 ***************************************************************************/
void Family::AddWife(long social, string first, string last, long husband)
{		
	// No node case
	if(top == NULL)
	{
		cout << "There are no husbands for this wife!" << endl;
		return;
	}
	
	// Husband not in the family list case
	if(!SearchForHusband(husband)) 
	{
		cout << "The husband could not be found! Try Canada?" 
			<< endl;
		return;
	}
	
	Wife* newWife = new Wife(social, first, last);	// Creates the wife
	Husband* current = top;		// Husband pointer used to search the list.
	
	// Cycle through the list to find the correct husband.
	while(current -> SSN != husband)
	{
		current = current -> nextFamily;
	}
	
	// Checks if the husband is already married.
	if(current -> myWife != NULL)
	{
		cout << current -> firstName << " " << current -> lastName 
			<< " is already married! Adultery is bad!" << endl;
		return;
	}

	current -> myWife = newWife;	// Sets the wife.
	newWife -> children = NULL;	// Should be done in constructor already.
	
	cout << "I now pronounce " << first << " " << last << " and "
		<< current -> firstName << " " << current -> lastName 
		<< " husband and wife." << endl;
}

/***************************************************************************
 * RemoveWife                                                              *
 *                                                                         *
 * Is passed the SSN of her husband. Removes the wife of the husband that  *
 * has the associated SSN.                                                 *
 ***************************************************************************/
void Family::RemoveWife(long husband)
{
	// No node case
	if(top == NULL)
	{
		cout << "This list is empty! Could not remove wife." << endl;
		return;
	}
	
	// Husband not in the family list case
	if(!SearchForHusband(husband)) 
	{
		cout << "Husband is not in this list. Could not remove wife." 
			<< endl;
		return;
	}

	Husband* current = top;	// Husband pointer to cycle through the list
	
	// Searches for the correct husband.
	while(current -> SSN != husband)
	{
		current = current -> nextFamily;
	}
	
	Wife* theWife = current -> myWife;
	
	// Checks if there is a wife to delete.
	if(theWife == NULL)
	{
		cout << current -> firstName << " " << current -> lastName
			<< " is currently unmarried. Could not remove wife." << endl;
		return;
	}

	// Delete all children
	RemoveAllChildrenInFamily(current -> SSN);
	
	cout << theWife -> firstName << " " << theWife -> lastName
		<< " removed from " << current -> firstName << " " 
		<< current -> lastName << "'s family." << endl;
		
	// Delete wife and set the wife to NULL.		
	delete theWife;
	current -> myWife = NULL;

}	

/***************************************************************************
 * AddAChild                                                               *
 *                                                                         *
 * Creates a new child under the husband that matches the passed SSN.      *
 ***************************************************************************/
void Family::AddAChild(long social, string first, string last, long dad)
{
	// Empty list case
	if(top == NULL)
	{
		cout << "This list is empty! Could not add child." << endl;
		return;
	}
	
	// Checks if the desired husband is in the list
	if(!SearchForHusband(dad))
	{
		cout << "Husband is not on the list. Could not add child." << endl;
		return;
	}
	
	Husband* current = top;		// Husband pointer to cycle through
	
	// Cycling through until the correct husband is found.
	while(current -> SSN != dad)
	{
		current = current -> nextFamily;
	}
	
	Wife* theWife = current -> myWife; 	// Wife for reference
	
	if(theWife == NULL)
	{
		cout << "This man is not married!" << endl;
		return;
	}
	
	Child* newChild = new Child(social, first, last);	// Creates the child
	
	// Adds the child to the top of the child list
	newChild -> mySibling = theWife -> children;	
	theWife -> children = newChild;

	cout << first << " " << last << " has been added under "
		<< current -> firstName << " " << current -> lastName << endl;
}

/***************************************************************************
 * RemoveAChild                                                            *
 *                                                                         *
 * Given the SSN of the child and father, finds the corresponding husband  *
 * and then deletes the child from the list.                               *
 ***************************************************************************/
void Family::RemoveAChild(long social, long dad)
{	
	// Empty list case
	if(top == NULL)
	{
		cout << "This list is empty! Could not remove child." << endl;
		return;
	}
	
	// Checks if the desired husband is in the list
	if(!SearchForHusband(dad))
	{
		cout << "Husband is not on the list. Could not remove child." << endl;
		return;
	}
	
	Husband* current = top;		// Husband pointer to cycle through
	
	// Cycling through until the correct husband is found.
	while(current -> SSN != dad)
	{
		current = current -> nextFamily;
	}
	
	if(current -> myWife == NULL)
	{
		cout << current -> firstName << " " << current -> lastName
			<< " does not have a wife. Child could not be removed.";
		return;
	}
	
	// Create a child pointer and initialize to first child.
	Child* currentChild = current -> myWife -> children;	
	Child* previousChild = currentChild;	// Holds previous child
	
	// Case if the first child in list is the one being deleted
	// Wife class's children pointer must be changed rather than mySibling
	if(currentChild -> SSN == social)
	{
		current -> myWife -> children = currentChild -> mySibling;
		delete currentChild;
		return;
	}
	
	// Finds the correct child.
	while(currentChild -> SSN != social)
	{
		previousChild = currentChild;
		currentChild = currentChild -> mySibling;
		
		// 404 Child not found
		if(currentChild == NULL)
		{
			cout << "Child doesn't exist. Could not remove." << endl;
			return;
		}
	}
	
	// Has the child before the one being deleted point to the one after
	previousChild -> mySibling = currentChild -> mySibling;
	
	cout << currentChild -> firstName << " " << currentChild -> lastName
		<< " has been deleted from " << current -> firstName << " " 
		<< current -> lastName << "'s family." << endl;
		
	delete currentChild;	// Deletes the child.
	
}

/***************************************************************************
 * PrintAFamily                                                            *
 *                                                                         *
 * Given an SSN for a husband, find the husband in the list and print all  *
 * the associated family members.                                          *
 ***************************************************************************/
void Family::PrintAFamily(long husband)
{	
	// Empty list case
	if(top == NULL)
	{
		cout << "This list is empty! Could not print family." << endl;
		return;
	}
	
	// Checks if the desired husband is in the list
	if(!SearchForHusband(husband))
	{
		cout << "Husband is not on the list. Could not print family." << endl;
		return;
	}
	
	Husband* current = top;		// Husband pointer to cycle through
	
	// Cycling through until the correct husband is found.
	while(current -> SSN != husband)
	{
		current = current -> nextFamily;
	}
	
	cout << "Husband" << endl << *current << endl;		// Print dad info.
	
	if(current -> myWife == NULL)
		return;
	
	Wife* theWife = current -> myWife;
	cout << "Wife" << endl << *theWife << endl;
	
	if(theWife -> children == NULL)
		return;
	
	Child* theChild = theWife -> children;
	
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
	if(top != NULL)
	{
		Husband* theHusband = top;
		while (theHusband != NULL)
		{
			PrintAFamily(theHusband -> SSN);
			theHusband = theHusband -> nextFamily;
		}
	}
	else
		cout << "There are no families!" << endl;
}

/***************************************************************************
 * ReadTransactionFile                                                     *
 *                                                                         *
 * Reads a command and parameters from a designated input file and calls a *
 * corresponding method.                                                   *
 ***************************************************************************/
void Family::ReadTransactionFile()
{
	string command;
	ifstream fin;
	fin.open("data.txt");
	
	if(!fin)
	{
		cout << "File not found. " << endl;
		return;
	}
	
	while(fin >> command)
	{
		cout << "Command: " << command << endl;
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
			RemoveHusband(id);
		}
		else if(command.compare("RemoveWife") == 0)
		{
			long id;
			fin >> id;
			RemoveWife(id);
		}
		else if(command.compare("AddAChild") == 0)
		{
			long childId, dadId;
			string first, last;
			fin >> childId >> first >> last >> dadId;
			AddAChild(childId, first, last, dadId);
		}
		else if(command.compare("RemoveAChild") == 0)
		{
			long childId, dadId;
			fin >> childId >> dadId;
			RemoveAChild(childId, dadId);
		}
		else if(command.compare("PrintAFamily") == 0)
		{
			long dadId;
			fin >> dadId;
			PrintAFamily(dadId);
		}
		else if(command.compare("PrintAllFamilies") == 0)
		{
			PrintAllFamilies();
		}
		else
			cout << "Invalid command." << endl;
		
		cout << "_______________________________" << endl;
	}
	
}
 

/***************************************************************************
 * SearchForHusband                                                        *
 *                                                                         *
 * Returns a boolean depending on whether or not the given SSN matches a   *
 * husband in the list.                                                    *
 ***************************************************************************/
bool Family::SearchForHusband(long social)
{
	Husband* current = top;		// Pointer to cycle through the list.
	
	// Cycle until you reach the node after the last.
	while(current != NULL)
	{
		// Returns true if found.
		if(current -> SSN == social)
			return true;
		
		current = current -> nextFamily;	// Move to next family
	}
	
	return false; // If not found then the above won't catch. Therefore false.
}

/***************************************************************************
 * RemoveAllChildrenInFamily                                               *
 *                                                                         *
 * Deletes all the children of a family given the father's SSN.            *
 ***************************************************************************/
void Family::RemoveAllChildrenInFamily(long dad)
{
	Husband* theDad = getHusband(dad);
	if(theDad == NULL)	// Catch husband does not exist.
	{
		cout << "Could not find Dad. Children could not be removed." << endl;
		return;
	}
	
	Wife* theWife = theDad -> myWife;
	
	if(theWife == NULL)	// Checks if there is a wife
	{
		cout << "This husband has no wife. No children to remove." << endl;
		return;
	}
	
	// Removes the children one at a time from the top of the list.
	while(theWife -> children != NULL)
	{
		RemoveAChild(theWife -> children -> SSN, dad);
	}
}

/***************************************************************************
 * getHusband                                                              *
 *                                                                         *
 * Given the husband's SSN, returns the pointer to the husband's node.	   *
 ***************************************************************************/
Husband* Family::getHusband(long husbandSSN)
{
	if(top == NULL)
		return NULL;
	if(!SearchForHusband(husbandSSN))
		return NULL;
	
	Husband* theHusband = top;
	while(theHusband -> SSN != husbandSSN)
	{
		theHusband = theHusband -> nextFamily;
	}
	return theHusband;
}
 
/***************************************************************************
 * RemoveAllFamilies                                                       *
 *                                                                         *
 * Deletes all the families in the list.                                   *
 ***************************************************************************/
  
bool Family::RemoveAllFamilies()
{
	
	Husband* headOfFamily = top;
	while (top -> nextFamily != NULL)
	{
		cout << top -> firstName << " " << top -> lastName 
			<< " has been removed from this list." << endl;
		top = top -> nextFamily;
		RemoveHusband(headOfFamily -> SSN);
		headOfFamily = top;
	}
	
	top = NULL;
	return true;
}

#endif

