/*	Name: Charles Li
	Date: 9/12/14
	Class: CS111
	Week: 3
	Description: This program converts a length in cm to yards, feet, and inches.
*/

#include <iostream>
using namespace std;

#define CM_TO_INCH_RATE 0.393701		// Declaring your conversion rate

int main()
{
float convertedInches = 0;
int cm = 0, inchesLeft = 0, roundedInches = 0, yard = 0, feet = 0;	
/* 	convertedInches is used to store the exact number of inches after converting
	inchesLeft is used in calculating the feet, yard, and inches and is equal to roundedInches
	roundedInches is used to round the inches value
*/

// Display at the top of the screen
cout << "******************************************************************************" << endl;
cout << " This program will convert a length in centimeters to yards, feet, and inches." << endl;
cout << "******************************************************************************" << endl << endl << endl;

// Asking for the input
cout << "Please enter a length in centimeters: ";
cin >> cm;

// Calculating the converted inches and the rounded number.
convertedInches = CM_TO_INCH_RATE * cm;
roundedInches = (cm * CM_TO_INCH_RATE + .5);

// Displays the line that informs the user how much distance in inches both rounded and unrounded.
cout << endl << cm << " cm is about " << convertedInches << " inches rounded to " << roundedInches << " inches." << endl;

// Calculating distances
inchesLeft = roundedInches;

yard = inchesLeft / 36;
inchesLeft = inchesLeft % 36;

feet = inchesLeft / 12;
inchesLeft = inchesLeft % 12;

// Final output
cout << roundedInches << " inches = " << yard << " yards, " << feet << " feet, and " << inchesLeft << " inches.";
cout << endl << endl << "Thank you for using the program. Good bye." << endl << endl;

// End of program
return 0;
}

