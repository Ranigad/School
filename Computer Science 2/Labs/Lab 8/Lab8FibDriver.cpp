#include <iostream>
using namespace std;

int fib(int);
bool isFib(int);

int main()
{
	int input;
	cout << "Enter a number (enter a negative number to quit): ";
	cin >> input;
	
	while(input >= 0) {
		if(isFib(input))
			cout << input << " IS a Fibonacci number." << endl << endl;
		else
			cout << input << " is NOT a Fibonacci number." << endl << endl;
		cout << "Enter a number (enter a negative number to quit): ";cin >> input;		
	}

	cout << "Exiting the program." << endl;
	return 0;
}

int fib(int numInSeries)
{
	if (numInSeries == 1 || numInSeries == 2)
		return 1;
	
	return fib(numInSeries - 1) + fib(numInSeries - 2);
}

bool isFib(int numToCheck)
{
	int fibNum = 1;
	for(int i = 1; fibNum <= numToCheck; i++)
	{
		if(fibNum == numToCheck)
			return true;
		fibNum = fib(i + 1);
	}
	return false;
}

