/* 	Name: Charles Li
	Date: 9/14/14/
	Description: Program that finds the median of a user-determined number of inputs without the use of arrays.
*/

#include <iostream>
using namespace std;

int main()
{
	int totalInputs;
	int inputCount;
	double middle1;
	double middle2;
	double input1;
	double input2;
	double evenAverage;
	
	cout << "How many inputs are there?";
	cin >> totalInputs;
	
	if (totalInputs % 2 == 1)
	{
	cout << "Enter your first number: ";
	cin >> input1;
	cout << "Enter your second number: ";
	cin >> input2;
	cout << "Enter your third number: ";
	cin >> middle1;
	
	for (inputCount = 3; inputCount < totalInputs;)
	{
		if ((input1 > input2 && input1 < middle1) || (input1 < input2 && input1 > middle1))
			{
			middle1 = input1;
		}
		else if ((input2 > input1 && input2 < middle1) || (input2 < input1 && input2 > middle1))
			{
			middle1 = input2;
		}
		else
			{
			middle1 = middle1;
		}
		cout << "Enter your next number: ";
		cin >> input1;
		cout << "Enter your next number: ";
		cin >> input2;
		inputCount += 2;
	}
}

	else
	{
		cout << "Enter your first number: ";
		cin >> input1;
		cout << "Enter your second number: ";
		cin >> input2;
		cout << "Enter your third number: ";
		cin >> middle1;
		cout << "Enter your fourth number: ";
		cin >> middle2;
		
		for (inputCount = 4; inputCount < totalInputs;)
		{
			if ((input1 > input2 && input1 < middle1) || (input1 < input2 && input1 > middle1))
				{
				middle1 = input1;
			}
			else if ((input2 > input1 && input2 < middle1) || (input2 < input1 && input2 > middle1))
				{
				middle1 = input2;
			}
			else
				{
				middle1 = middle1;
			}
			cout << "Enter your next number: ";
			cin >> input1;
			cout << "Enter your next number: ";
			cin >> input2;
			inputCount += 2;
		}
	}
	
	cout << "Your median is: " << middle1;
return 0;
}

