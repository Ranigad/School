/*   Name: Charles Li
     Date: 11/21/14
	 Class: CS 111
	 Description: Working with structures.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int totScores = 3;
const int totStudents = 3;

struct student{
	string firstName;
	int ID;
	int testScores[totScores];
	float average;
	};

void fillArray(struct student[]);
void fillAverage(struct student[]);
void bestStudent(struct student[]);
void reverseCopy(struct student[], struct student[]);
void combineArray(struct student[], struct student[], struct student[]);
void printArray(struct student[], int);
	
int main()
{
	struct student class1[totStudents], class2[totStudents];
	struct student combined[6];
	fillArray(class1);
	fillAverage(class1);
	bestStudent(class1);
	reverseCopy(class1, class2);
	combineArray(combined, class1, class2);
	printArray(combined, 6);
return 0;
}

void fillArray(struct student studentArray[])
{
	for (int i = 0; i < totStudents; i++)
	{
		cout << "Enter the student name: ";
		cin >> studentArray[i].firstName;
		
		cout << "Enter the student ID: ";
		cin >> studentArray[i].ID;
		
		cout << "Enter 3 test scores: ";
		for (int j = 0; j < totScores; j++)
			cin >> studentArray[i].testScores[j];
	}
}

void fillAverage(struct student studentArray[])
{
	int sum = 0;
	for (int i = 0; i < totStudents; i++)
		{
		sum = 0;
		for (int j = 0; j < totScores; j++)
			{sum += studentArray[i].testScores[j];}
		studentArray[i].average = sum * 1.0f / totScores;
		}
	return;
}

void bestStudent(struct student studentArray[])
{
	float highest = studentArray[0].average;
	string bestName;
	for (int i = 1; i < totStudents; i++)
	{
		if (studentArray[i].average > highest)
		{
			highest = studentArray[i].average;
			bestName = studentArray[i].firstName;
		}
	}
	
	cout << endl << "The student with the highest average is " << bestName
		 << " with a score of " << highest << endl << endl;
	
	return;

}

void reverseCopy(struct student copyFrom[], struct student copyTo[])
{
	copyTo[2] = copyFrom[0];
	copyTo[1] = copyFrom[1];
	copyTo[0] = copyFrom[2];

	return;
}

void combineArray(struct student combinedArray[], struct student array1[], struct student array2[])
{
	for (int i = 0; i < totStudents; i++)
	{
		combinedArray[i] = array1[i];
		combinedArray[i + 3] = array2[i];
	}
	return;
}

void printArray(struct student studentInfo[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Name: " << studentInfo[i].firstName << endl
			 << "Student ID: " << studentInfo[i].ID << endl
			 << "Test Scores: ";
			 
		for (int j = 0; j < totScores; j++)
			cout << studentInfo[i].testScores[j] << " ";
		
		cout << endl
			 << "Average: " << studentInfo[i].average << endl;
		cout << endl;
	}
		
		cout << endl;
	return;
}


