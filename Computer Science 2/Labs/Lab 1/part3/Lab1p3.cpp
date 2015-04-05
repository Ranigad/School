#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 10;

void readIntoArray(int[], ifstream&);
void reverseArray(const int[], int[], int);
void printArray(const int[], int);
int checkBetween(const int[], int);	// Checks how many numbers are between 80 and 100;
int checkDivFive(const int[], int);
void printDivFive(const int[], int);
double arrayAverage(const int[], int);
int checkMin(const int[], int);
void checkKey(const int[], int);

int main()
{
	int arrayA[SIZE] = {0};
	int arrayB[SIZE] = {0};
	ifstream inputFile;
	
	inputFile.open("data.txt");
	
	readIntoArray(arrayA, inputFile);			// Part a
	reverseArray(arrayA, arrayB, SIZE);			// Part b
	printArray(arrayA, SIZE);					// Part c
	printArray(arrayB, SIZE);					// Part d
	cout << checkBetween(arrayA, SIZE) << endl;	// Part e
	cout << checkDivFive(arrayA, SIZE) << endl; // Part f
	printDivFive(arrayA, SIZE);					// Part g
	cout << arrayAverage(arrayA, SIZE) << endl;	// Part h
	cout << checkMin(arrayA, SIZE) << endl;		// Part i
	checkKey(arrayA, SIZE);						// Part j
	return 0;
}

void readIntoArray(int passedArray[], ifstream& sourceData)
{
	for (int i = 0; i < SIZE; i++)
	{
		sourceData >> passedArray[i];
	}
}

void reverseArray(const int arrayA[], int arrayB[], int sizeOfArray)
{
	for (int i = 0; i < SIZE; i++)
	{
		arrayB[i] = arrayA[sizeOfArray - 1 - i];
	}
}

void printArray(const int passedArray[], int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << setw(3) << passedArray[i];
	}
	cout << endl;
}

int checkBetween(const int passedArray[], int sizeOfArray)
{
	int tally = 0;
	for (int i = 0; i < sizeOfArray; i++)
	{
	if (passedArray[i] >= 80 && passedArray[i] <= 100)
		tally++;
	}
	return tally;
}

int checkDivFive(const int passedArray[], int sizeOfArray)
{
	int tally = 0;
	for (int i = 0; i < sizeOfArray; i++)
	{
	if (passedArray[i] % 5 == 0)
		tally++;
	}
	return tally;
}

void printDivFive(const int passedArray[], int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
	if (passedArray[i] % 5 == 0)
		cout << left << setw(3) << i;
	}
	cout << endl;
}

double arrayAverage(const int passedArray[], int sizeOfArray)
{
	int sum = 0;
	for (int i = 0; i < sizeOfArray; i++)
	{
		sum += passedArray[i];
	}
	return sum * 1.0 / sizeOfArray;
}

int checkMin(const int passedArray[], int sizeOfArray)
{
	int min = passedArray[0];
	for (int i = 1; i < sizeOfArray; i++)
	{
		if (passedArray[i] < min)
			min = passedArray[i];
	}
	return min;
}

void checkKey(const int passedArray[], int sizeOfArray)
{
	bool exist = false;
	int key;
	cout << "Enter an integer: ";
	cin >> key;
	
	for (int i = 0; !exist && i < sizeOfArray; i++)
	{
		if (passedArray[i] == key)
			exist = true;
	}
	
	if (exist)
		cout << "The entered key is in this array";
	else
		cout << "The entered key is not in this array";
	
	cout << endl;
}


