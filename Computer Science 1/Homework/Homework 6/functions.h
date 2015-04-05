#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include "food.h"

/***************************************************************************
 * Functions Header                                                        *
 *                                                                         *
 * Responsible for the storage of all the extra functions of the program.  *
 * The constant utilized for max array capacity is held here. Further info *
 * for the functions can be found in functions.cpp.                        *
 ***************************************************************************/

const int listSize = 4;	// Constant for max array size.

void addFood(Food [listSize], int&);	// Adds a food to a given list. 
void changeFood(Food [listSize], int&);	// Changes an existing food on a given list.
void deleteFood(Food [listSize], int&);	// Deletes an existing food on a given list.
void displayFood(Food [listSize], int&);// Displays the list.
void showMenu();	// Displays the menu for user navigation.
void printDivider();	// Prints a divider for visual separation of the printed list.
void stringFormatter(std::string&);	// Reformats a passed string to capital first letter and lower case remaining letters.

#endif

