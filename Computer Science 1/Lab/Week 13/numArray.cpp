/*   Name: Charles Li
     Date: 11/21/14
	 Class: CS111
	 Description: Working with an array
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int arraySize = 7;

void fillArray(int []);
float getAverage(int []);
bool findNum(int[], int);
void output(int[]);

int main()
{
	int numArray[arraySize] = {0};
	fillArray(numArray);
	int searchNumber;
	cout << "Enter a number to search for: ";
	cin >> searchNumber;
	if(findNum(numArray, searchNumber))
		cout << "That number is in the array. " << endl;
	else
		cout << "That number is not in the array." << endl;
		
	output(numArray);

	cout << endl;
return 0;
}

void fillArray(int numArray[])
{	
	ifstream inputFile;
	inputFile.open("num.dat");
	for (int i = 0; i < arraySize; i++)
		inputFile >> numArray[i];
	inputFile.close();
	return;
}

float getAverage(int numArray[])
{
	int sum = 0;
	float average;
	for (int i = 0; i < arraySize; i++)
		sum += numArray[i];
		
	//average = ;
	return sum * 1.0f / arraySize;	
}

bool findNum(int numArray[], int search)
{
	bool result = false;
	for (int i = 0; i < arraySize; i++)
		if (search == numArray[i])
			result = true;
	
	return result;
}

void output(int numArray[])
{
	ofstream outputFile;
	outputFile.open("result.dat");
	
	for (int i = 0; i < arraySize; i++)
	{	
		cout << i << ":" << setw(4) << right << numArray[i] << endl;
		outputFile << i << ":" << setw(4) << right << numArray[i] << endl;
	}
	
	cout << endl << "The average number is " << fixed << setprecision(1) << getAverage(numArray);
	outputFile << endl << "The average number is " << fixed << setprecision(1) << getAverage(numArray);

	return;
}
