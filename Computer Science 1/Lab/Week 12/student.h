#include <string>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

const int MAXDIGITS = 5;

class Student 
{
	private:
	string firstName;
	string lastName;
	int SSN;
	int classes[MAXDIGITS];
	int numClasses;
	
	public:
	Student(string=" ", string=" ", int = 0);
	string getName();
	void addAClass(int);
	void printClass();
};

#endif

