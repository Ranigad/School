/************************************************************
Name: Charles Li
Date: 9/5/14
Class: CS111
Week: Lab 2
Description: This program will read 3 numbers and output both the sum and the average.
*************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int num1, num2, num3; // The three numbers that will be user input.
	int sum; //the sum of three numbers
	float avg; //average of three numbers
	
	//INPUT: take 3 numbers from the keyboard
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
	cout << "Enter the third number: ";
	cin >> num3;
	
	//PROCESS: calculate the sum and avg
	sum = num1 + num2 + num3;
	avg = sum / 3.0;
	
	//OUTPUT: output the result
	cout << "The average is " << avg << " and the sum is " << sum << endl;
	
	return 0;

}

