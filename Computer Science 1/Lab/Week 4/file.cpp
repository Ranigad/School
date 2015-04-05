/*	Name: Charles Li
	Date: 9/19/14
	Week: 4
	Class: CS 111 Lab
	Description: Write a program that utilizes a file input and output. 
*/

#include <iostream>
#include <fstream>	// Library for file in and output
using namespace std;

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	
	inputFile.open("stu.dat");
	outputFile.open("result.dat");
	
	if (inputFile.fail())
		{
		cout << "The file could not be found!" << endl;
		exit(1);
		}
	
	int input1 = 0,
		input2 = 0, 
		input3 = 0;
	string name;
	
	inputFile >> name >> input1 >> input2 >> input3;
	
	outputFile << name << "'s average score is " << (input1 + input2 + input3) / 3.0f << endl;
	
	inputFile >> name >> input1 >> input2 >> input3;
	
	outputFile << name << "'s average score is " << (input1 + input2 + input3) / 3.0f << endl;
	
	inputFile.close();
	outputFile.close();
	return 0;
}

