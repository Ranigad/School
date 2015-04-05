#include <iostream>
#include "student.h"

Student::Student(string first, string last, int ssnum)
{
	firstName = first;
	lastName = last;
	SSN = ssnum;
	numClasses = 0;
	for (int i = 0; i < MAXDIGITS; i++)
		classes[i] = 0;
}

string Student::getName()
{
	return lastName + ", " + firstName;
}

void Student::addAClass(int CRN)
{
	if(numClasses >= MAXDIGITS)
		cout << "Your schedule is full" << endl;
	else
	{
		classes[numClasses] = CRN;
		numClasses++;
	}
	return;
}

void Student::printClass()
{
	if(numClasses == 0)
		cout << "None" << endl;
	else
	{
		for (int i = 0; i < numClasses; i++)
			{
				cout << classes[i];
				if (i != numClasses - 1) 
						cout << ", ";
			}
	}
	cout << endl;
	return;
}
