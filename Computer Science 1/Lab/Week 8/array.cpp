/*   Name: Charles Li
     Date: 10/17/14
	 Class: CS 111
	 Description: 
*/

#include <iostream>
using namespace std;

const int arraySize = 5;

void fillArray(int array[]);
void findHighest(int array[]);
void doubleArray(int array[]);
void printArray(int array[]);


int main()
{
	int intArray[arraySize];

	fillArray(intArray);
	findHighest(intArray);
	doubleArray(intArray);
	printArray(intArray);

	return 0;
}

void fillArray(int array[])
{
	for (int i = 0; i < arraySize; i++)
	{	cout << "Enter a number: ";
		cin >> array[i];}
		
	return;
}

void findHighest(int array[])
{
	int largestNum = array[0];

	for (int i = 1; i < arraySize; i++)
	{
		if (array[i] > largestNum) largestNum = array[i];
	}

	cout << "The largest number entered is " << largestNum << endl;
	
	return;
}

void doubleArray(int array[])
{
	for (int i = 0; i < arraySize; i++)
	array[i] *= 2;

	return;
}

void printArray(int array[])
{
	cout << "The new numbers in the array are ";
	for (int i = 0; i < arraySize; i++)
	{
	cout << array[i] << " ";
	}
	cout << endl;
	return;
}



