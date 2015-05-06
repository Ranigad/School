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
	RemoveAllFamilies();
}
 
/***************************************************************************
 * AddAHusband                                                             *
 *                                                                         *
 * Adds a Node of Husband class to the end of the horizontal list.         *
 ***************************************************************************/
void Family::AddHusband(long social, string first, string last)
{
	// Make the new family
	HusbandPtr newFamily = new Husband(social, first, last);

	newFamily -> nextFamily = top;	// Prepares for insert at top
	top = newFamily;	// Inserts at top
	
	cout << first << " " << last << " has been added to the list!" << endl;
}
  
/***************************************************************************
 * RemoveHusband                                                           *
 *                                                                         *
 * Given a long SSN, delete the husband in the list with the corresponding *
 * SSN.                                                                    *
 ***************************************************************************/
void Family::RemoveHusband(long social)
{
	HusbandPtr current = getHusband(social);
	
	if(current == NULL)
	{
		cout << "Could not remove husband." << endl;
		return;
	}
	
	// If the husband has a wife, call RemoveWife.
	// RemoveWife automatically removes all children if applicable.
	if(current -> myWife != NULL)
		RemoveWife(social);
	
	if(top == current)
	{
		top = top -> nextFamily;	
	}
	else
	{
		HusbandPtr previous = top;	// Pointer to the family before current.
		
		// Cycle until you reach the correct Husband.
		while(previous -> nextFamily != current)
		{
			previous = previous -> nextFamily;
		}
		// Connects the previous and next node from the current.
		previous -> nextFamily = current -> nextFamily;	
	}
	

	
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
void Family::AddWife(long social, string first, string last, long husbandSSN)
{		
	
	HusbandPtr current = getHusband(husbandSSN);
	
	if(current == NULL)
	{
		cout << "There are no husbands for this wife!" << endl;
		return;
	}
	
	// Checks if the husband is already married.
	if(current -> myWife != NULL)
	{
		cout << current -> firstName << " " << current -> lastName 
			<< " is already married! Adultery is bad!" << endl;
		return;
	}

	WifePtr newWife = new Wife(social, first, last);	// Creates the wife
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
void Family::RemoveWife(long husbandSSN)
{
	
	HusbandPtr current = getHusband(husbandSSN);
	
	if(current == NULL)
	{
		cout << "Could not remove wife." << endl;
		return;
	}
	
	WifePtr theWife = current -> myWife;
	
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
void Family::AddAChild(long childSSN, string first, string last, long dadSSN)
{
	
	DadPtr current = getDad(dadSSN);
	
	if(current == NULL)
	{
		cout << "Could not add child." << endl;
		return;
	}
	
	WifePtr theWife = current -> myWife; 	// Wife for reference
	
	if(theWife == NULL)
	{
		cout << "This man is not married! He can't have a child." << endl;
		return;
	}
	
	ChildPtr newChild = new Child(childSSN, first, last);	// Creates the child
	
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
void Family::RemoveAChild(long childSSN, long dadSSN)
{	
	
	DadPtr current = getDad(dadSSN);
	
	if(current == NULL)
	{
		cout << "Could not remove child." << endl;
		return;
	}
	
	if(current -> myWife == NULL)
	{
		cout << current -> firstName << " " << current -> lastName
			<< " does not have a wife. Child could not be removed.";
		return;
	}
	
	// Create a child pointer and initialize to first child.
	ChildPtr currentChild = current -> myWife -> children;	
	ChildPtr previousChild = currentChild;	// Holds previous child
	
	// Case if the first child in list is the one being deleted
	// Wife class's children pointer must be changed rather than mySibling
	if(currentChild -> SSN == childSSN)
	{
		current -> myWife -> children = currentChild -> mySibling;
	}
	else
	{
		// Finds the correct child.
		while(currentChild -> SSN != childSSN)
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
	}
	
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
	
	HusbandPtr current = getHusband(husband);
	if(current == NULL)
	{
		cout << "Could not print family." << endl;
		return;
	}
	
	cout << "Husband" << endl << *current << endl;		// Print dad info.
	
	if(current -> myWife == NULL)
		return;
	
	WifePtr theWife = current -> myWife;
	cout << "Wife" << endl << *theWife << endl;
	
	if(theWife -> children == NULL)
		return;
	
	ChildPtr theChild = theWife -> children;
	
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
		HusbandPtr theHusband = top;
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
		else if(command.compare("RemoveAllFamilies") == 0)
			RemoveAllFamilies();
		else
			cout << "Invalid command." << endl;
		
		cout << "_______________________________" << endl;
	}
	
}

/***************************************************************************
 * RemoveAllChildrenInFamily                                               *
 *                                                                         *
 * Deletes all the children of a family given the father's SSN.            *
 ***************************************************************************/
void Family::RemoveAllChildrenInFamily(long dad)
{
	DadPtr theDad = getHusband(dad);
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
		RemoveAChild(theWife -> children -> SSN, dad);
	}
}

/***************************************************************************
 * getHusband                                                              *
 *                                                                         *
 * Given the husband's SSN, returns the pointer to the husband's node.	   *
 ***************************************************************************/
HusbandPtr Family::getHusband(long husbandSSN)
{
	if(top == NULL)
	{
		cout << "This list is empty! ";
		return NULL;
	}
	
	HusbandPtr current = top;		// Pointer to cycle through the list.
	
	// Cycle until you reach the node after the last.
	while(current != NULL)
	{
		// Returns true if found.
		if(current -> SSN == husbandSSN)
			return current;
		
		current = current -> nextFamily;	// Move to next family
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
 * RemoveAllFamilies                                                       *
 *                                                                         *
 * Deletes all the families in the list.                                   *
 ***************************************************************************/
  
void Family::RemoveAllFamilies()
{
	HusbandPtr headOfFamily = top;
	while(top != NULL)
	{
		headOfFamily = top -> nextFamily;
		RemoveHusband(top -> SSN);
		top = headOfFamily;
		cout << endl;
	}
}

#endif

