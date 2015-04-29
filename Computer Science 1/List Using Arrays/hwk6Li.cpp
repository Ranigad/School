/*   Name: Charles Li
     Date: 11/16/14
	 Class: CS 111
	 Description: A function that maintains a list of foods (class objects) and allows the user to manipulated the list through various means
*/

#include <iostream>
#include <string>
#include "food.h"
#include "functions.h"
using namespace std;

int main()
{
	Food list[listSize];	// Declares an array of Food objects. listSize is defined in functions.h as 4.
	int navigation;			// Used to take in the user's menu selection
	int numFoods = 0;		// Keeps track of the total number of foods and is used as an index
	
	// Loop to allow user to keep entering options once the action is completed
	do {
		showMenu();			// Displays the menu options for the user
		
		cout << "Enter your selection: "; 
		cin >> navigation;
		
		switch(navigation) {
		case 0: break;		// Exit option.
		case 1: addFood(list, numFoods); break;		// Adds a new food to the list
		case 2: changeFood(list, numFoods); break;	// Changes a food on the list (using the addFood function)
		case 3: deleteFood(list, numFoods); break;	// Deletes a food off the list
		case 4: displayFood(list, numFoods); break;	// Shows the list
		default: cout << "Not a valid option!" << endl;	// Informs the user that they entered an incorrect number for the menu selection
		}
		} while (navigation != 0);	// Checks if the user entered 0
		cout << endl << "Thank you for using this program!" << endl << endl;	// Exit message
		
	return 0;
}



