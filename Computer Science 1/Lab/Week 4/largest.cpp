/*	Name: Charles Li
	Date: 9/19/14
	Week: 4
	Class: CS 111 Lab
	Description: Reading 4 inputs and outputs the largest of the 4 numbers
*/

#include <iostream>
using namespace std;

int main()
{	
	int input1, input2, input3, input4, larger;
	
	cout << "Enter 4 numbers: ";
	cin >> input1 >> input2 >> input3 >> input4;

	if (input1 > input2)
		larger = input1;
	else
		larger = input2;
		
	if (input3 > larger)
		larger = input3;
		
	if (input4 > larger)
		larger = input4;
		
	cout << "The largest number entered is " << larger << endl;

return 0;
}

