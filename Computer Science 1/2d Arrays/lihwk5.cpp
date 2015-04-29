/*   Name: Charles Li
     Date: 11/1/14
	 Class: CS 111
	 Description: This program will perform various functions on a predefined two dimensional array.
	 Expected functions include printing the rows, printing the row sums, finding the largest and smallest number.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int totRows = 6;
const int totCols = 5;

void printArray(int [][totCols]);	// Prints the array
void printSumRows(int [][totCols]);	// Prints the sum of the rows
void findLargest(int [][totCols]);	// Finds the largest number in the array and prints it
void findSmallest(int [][totCols]);	// Finds the smallest number in the array and prints it

int main()
{
	// Array declaration and initialization
	int numArray[totRows][totCols] = {{23, 5, 6, 15, 18},
									{4, 16, 24, 67, 10},
									{12, 54, 23, 76, 11},
									{1, 12, 34, 22, 8},
									{81, 54, 32, 67, 33},
									{12, 34, 76, 78, 9}};

	// End line to separate program run from program
	cout << endl;	
	
	// Function Calls							
	printArray(numArray);
	printSumRows(numArray);
	findLargest(numArray);
	findSmallest(numArray);

	// End lines at the end of the function so the prompt is separated
	cout << endl << endl;
	
	return 0;
}

/***************************************************************************
 * 								printArray    							   *
 *																		   *
 * This function is passed a two dimensional array of size 6 x 5 and  	   *
 * displays the contents of the array to the user                          *
 ***************************************************************************/
 
void printArray(int numArray[][totCols]) 
{
	for (int row = 0; row < totRows; row++) {
		for (int col = 0; col < totCols; col++) {
			cout << " " << setw(2) << right << setfill('0') << numArray[row][col];	// Assures each number is printed as a 2 digit number
		}
		cout << endl;	// Separates the rows
	}
	cout << endl; 		// For formatting, keeps the functions visibly separate
	return;
}

/***************************************************************************
 *                              printSumRows                               *
 *                                                                         *
 * This function is passed a two dimensional array of size 6 x 5 and 	   *
 * prints out the sum of each row                                          *
 ***************************************************************************/

void printSumRows(int numArray[][totCols]) 
{	
	int rowSum = 0;
	for (int row = 0; row < totRows; row++) {
		for (int col = 0; col < totCols; col++) {
			rowSum += numArray[row][col];
		}
		cout << "The sum of Row " << row + 1 << " is " << rowSum << endl;	// Prints the sum of the rows
		rowSum = 0;		// Resets the row sum to 0 for the next row
	}
	return;
}

/***************************************************************************
 *                              findLargest                                *
 *                                                                         *
 * This function finds the largest number in a passed 6 x 5 array and      *
 * prints the result                                                       *
 ***************************************************************************/

void findLargest(int numArray[][totCols])
{
	int largestNum = numArray[0][0];	// Initializes the largest number as the first number in the array
	for (int row = 0; row < totRows; row++) {
		for (int col = 0; col < totCols; col++) {
			if (numArray[row][col] > largestNum)	// Compares current index with the largest number
				largestNum = numArray[row][col];
		}		
	}
	cout << endl << "The largest number in the array is " 
		<< setw(2) << right << setfill('0') << largestNum;	// Assures the number printed is at least 2 digits
	return;
}

/***************************************************************************
 *                              findSmallest                               *
 *                                                                         *
 * This function finds the smallest number in a passed 6 x 5 array and     *
 * prints the result                                                       *
 ***************************************************************************/

void findSmallest(int numArray[][totCols])
{
	int smallestNum = numArray[0][0];	// Initializes the smallest number as the first number in the array.
	for (int row = 0; row < totRows; row++) {
		for (int col = 0; col < totCols; col++) {
			if (numArray[row][col] < smallestNum)	// Checks if the current number is smaller than the smallest number
				smallestNum = numArray[row][col];	// Replaces the smallest number if true
		}		
	}
	cout << endl << "The smallest number in the array is " 
		<< setw(2) << right << setfill('0') << smallestNum;	// Assures the number printed is at least 2 digits
	return;
}


