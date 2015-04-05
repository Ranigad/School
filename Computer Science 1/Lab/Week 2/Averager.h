/*****************************************************************
Name: Charles Li
Class: CS111
Week: Lab 2
Date: 9/5/14

This program will get 2 numbers from the keyboard and output the average number.
*****************************************************************/

#include <iostream>
using namespace std; 

int main()
{
	int num1; //first number
	int num2; //second number
	int sum; //the sum of two numbers
	float avg; //average of two numbers
	
	//INPUT: take 2 numbers from the keyboard
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
	
	//PROCESS: calculate the sum and avg
	sum = num1 + num2;
	avg = sum / 2.0;
	
	//OUTPUT: output the result
	cout << "The average is " << avg << endl;
	
	return 0;
}