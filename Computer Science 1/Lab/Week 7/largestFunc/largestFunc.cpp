/*	Name: Charles Li
*/

#include <iostream>
using namespace std;

void showProgInfo();
int numInput();
void largestNum(int, int, int);

int main()
{

showProgInfo();

largestNum(numInput(), numInput(), numInput());

return 0;
}

void showProgInfo()
{
cout << "************************************************************************" << endl
	<< "Enter three numbers. This program will find the largest number entered." << endl
	<< "************************************************************************" << endl;

return;
}

int numInput()
{
int input = 0;
cout << "Enter a number: ";
cin >> input;

return input;
}

void largestNum(int num1, int num2, int num3)
{
int largestNum = 0;
if (num1 > num2) largestNum = num1;
else largestNum = num2;

if (num3 > largestNum) largestNum = num3;

cout << "The largest number is " << largestNum << endl;

return;
}


