#include <iostream>
#include <string>
#include "food.h"
using namespace std;

/***************************************************************************
 * Food                                                                    *
 *                                                                         *
 * Constructor for the Food class                                          *
 ***************************************************************************/
 
Food::Food(string nm, string tf, string stf)
{
	name = nm;
	typeFood = tf;
	subTypeFood = stf;
}

/***************************************************************************
 * setFood                                                                 *
 *                                                                         *
 * Sets the name, food type, and sub food type of the food                 *
 ***************************************************************************/
 
void Food::setFood(string nm, string ft, string sft)
{	
	name = nm;
	typeFood = ft;
	subTypeFood = sft;
	return;
}

/***************************************************************************
 * showFood                                                                *
 *                                                                         *
 * Displays the food's name, food type, and sub food type given that the   *
 * food name exists. Also displays "None" if the sub food type is nothing. *
 ***************************************************************************/
 
void Food::showFood()
{
	if (name.compare(" ") != 0) 
	{
	cout << endl << name << endl
		<< "Food Type: " << typeFood << endl
		<< "Sub Food Type: ";
		
	if (subTypeFood.compare(" ") == 0) 
		cout << "None" << endl;
	else
		cout << subTypeFood << endl;
	}
	return;
}

/***************************************************************************
 * showName                                                                *
 *                                                                         *
 * Accessor for the name of the food. Used for string comparisons when     *
 * searching the Food array for a particular food.                         *
 ***************************************************************************/
 
string Food::showName()
{
	return name;
}

/***************************************************************************
 * showTypeFood & showSubTypeFood                                          *
 *                                                                         *
 * Accessors for the type and sub type of the food. Currently unused.      *
 *                                                                         *
 ***************************************************************************/
 
string Food::showTypeFood()
{
	return typeFood;
}

string Food::showSubTypeFood()
{
	return subTypeFood;
}

