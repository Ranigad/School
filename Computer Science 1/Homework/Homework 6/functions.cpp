#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

/***************************************************************************
 * addFood                                                                 *
 *                                                                         *
 * Takes in the list of Foods and the total number of foods, then adds a   *
 * new Food object to the list.		                                       *
 ***************************************************************************/
 
void addFood(Food list[], int& numFoods) 
{
	string name, foodType, subType;		// Used to pass into the setFood method.
	bool validEntry = true;	// Used to check if the user input is valid or not.
	
	if (numFoods >= listSize)	// Checks if the current number of foods in the list is already at maximum capacity
		cout << "You cannot add any more foods, the list is full!" << endl << endl;
	else
	{
	cout << "Name of food: ";
	cin >> name;		// User input of the name of the new food
	stringFormatter(name);	// Reformats the entry
	
	// Loop used to check for valid user inputs
	do {
		cout << "Enter the food type (Basic/Prepared): ";
		cin >> foodType;	// User input of the food type
		stringFormatter(foodType);	// Reformats entry
		
		if(foodType.compare("Basic") == 0)	// Condition of the food type being Basic
		{
			// Loop used to check for valid user input for sub food type
			do {
					cout << "Enter the sub food type" << endl
						 << "(Dairy/Meat/Fruit/Vegetable/Grain): ";
					cin >> subType;		// User input of the sub food type
					stringFormatter(subType);	// Reformats entry
					
					// Checks the sub food type to ensure it is valid
					if(subType.compare("Dairy") == 0 || subType.compare("Meat") == 0 || subType.compare("Fruit") == 0 || subType.compare("Vegetable") == 0 || subType.compare("Grain") == 0)
						validEntry = true;
					else
					{
						cout << "Not a valid choice" << endl << endl;
						validEntry = false;
					}
				} while(!validEntry);	// If the user entry is not an accepted input, validEntry is flagged false and it forces another iteration of the loop
		}
		
		else if(foodType.compare("Prepared") == 0)	// Condition of the food type being Prepared
		{
			subType = "None";	// Sets the food type to be None
			validEntry = true;
		}
		else	// Condition of an incorrect entry
		{
			cout << "Not a valid choice" << endl << endl;
			validEntry = false;
		}
		} while (validEntry == false);	// Forces another iteration if the entry for the food type was not valid
	// Still part of the else statement
	list[numFoods].setFood(name, foodType, subType);	// Sets the next food on the list with the given (and valid) attributes
	numFoods++;		// Adds one to the count for total number of foods.
	cout << endl;
	}
	return;
}

/***************************************************************************
 * changeFood                                                              *
 *                                                                         *
 * Takes in the list of Foods and the total number of foods, then changes  *
 * an existing entry.                                                      *
 ***************************************************************************/
 
void changeFood(Food list[], int& numFoods)
{
	string search;	// String used to search the list
	
	if (numFoods)	// If there are foods in the list (i.e. if (numFoods >= 0))
	{
		cout << "Which food would you like to change? ";
		cin >> search;	// User defined search
		stringFormatter(search);	// Formats the string to allow for matching
		
		for (int i = 0; i < listSize; i++)	// Searches entire array
		{	// Checks if the given index of the array contains a Food object with a name that matches the search string	
			if(list[i].showName().compare(search) == 0) 
			{
				addFood(list, i);	// Changes the specific index with the addFood function
				cout << search << " was successfully modified." << endl << endl;	// Gives user a message signalling it has changed the object
				break;	// Exits the search. Prevents problems with multiple changes if there are multiple foods of the same name.
			}
			// If the search reaches the final index of the array and does not find an instance, this message is displayed
			else if(i == listSize - 1) cout << endl << search << " is not in this list!" << endl << endl;	
		}
	}
	else cout << endl << "There is nothing to change!" << endl << endl;	// Displays message if there is nothing on the list.
	
	return;
}

/***************************************************************************
 * deleteFood                                                              *
 *                                                                         *
 * Takes in the list of Foods and the total number of foods, then deletes  *
 * a user-specified element of the list.                                   *
 ***************************************************************************/
 
void deleteFood(Food list[], int& numFoods)
{
	string search;	// String used to search through the list

	if (numFoods)	// If there are foods in the list (i.e. if (numFoods >= 0))
	{
		cout << "Which food would you like to delete? ";
		cin >> search;	// User enters the desired name of the food to be deleted
		stringFormatter(search);	// Formats the string to allow for matching
		
		for (int i = 0; i < listSize; i++)	// Searches the array/list.
		{	// Checks if the given index of the array contains a Food object with a name that matches the search string	
			if(list[i].showName().compare(search) == 0) 
			{	
				for (int j = i; j < numFoods - 1; j++)	// Moves all items on the list from the deleted item to the end of the list down one index
					list[j] = list[j+1];
				numFoods--;		// Decrements the count of total number of foods.
				cout << endl << search << " was successfully removed from the list." << endl << endl;	// Message to indicate the item has been deleted.
				break;	// Exits the search. Prevents problems with multiple changes if there are multiple foods of the same name.
			}
			// If the search reaches the final index of the array and does not find an instance, this message is displayed
			else if(i == listSize - 1) cout << endl << search << " is not in this list!" << endl << endl;
		 } 
	}
	else cout << endl << "There is nothing to delete!" << endl << endl;	// Displays message if there is nothing on the list.
	
	return;
}

/***************************************************************************
 * displayFood                                                             *
 *                                                                         *
 * Prints out all the foods on a given list.                               *
 ***************************************************************************/
 
void displayFood(Food list[], int& numFoods)
{
	printDivider();	// Prints a visual divider
	if (numFoods == 0) cout << endl << "This list is empty!" << endl << endl;	// Prints a message if the list is empty
	else
		for(int i = 0; i < numFoods; i++)	// Otherwise, calls the showFood method to print out the list.
			list[i].showFood();
	printDivider();	// Prints a visual divider
	cout << endl;
	return;
}

/***************************************************************************
 * showMenu                                                                *
 *                                                                         *
 * Prints out a menu for the user. Displays the options for the program.   *
 ***************************************************************************/
 
void showMenu()
{
	cout << "Choose one of the following" << endl
		 << "1 - Add a food item" << endl
		 << "2 - Modify a food item" << endl
		 << "3 - Delete a food item" << endl
		 << "4 - Display all items" << endl
		 << "0 - Exit" << endl;
	return;
}

/***************************************************************************
 * printDivider                                                            *
 *                                                                         *
 * Displays a visual divider to visually separate the list display.        *
 ***************************************************************************/
 
void printDivider()
{
	for (int i = 0; i < 60; i++)	// Prints 60 "="s
		cout << "=";
	return;
}

/***************************************************************************
 * stringFormatter                                                         *
 *                                                                         *
 * Takes a given string and changes it so the first letter is capitalized  *
 * and the rest of the word is lower case.                                 *
 ***************************************************************************/
 
void stringFormatter(string& word)
{
	for (int i = 0; i < word.length(); i++)	// Changes all of the letters to lower case one by one
		word[i] = tolower(word[i]);
	
	word[0] = toupper(word[0]);	// Changes the first letter to upper case
	return;	
}

