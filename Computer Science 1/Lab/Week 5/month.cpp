/*	Name: Charles Li
	Date: 9/27/14
	Lab: CS111 Week 5
	Description: Takes an input from user and calculates result of adding, subtracting, multiplying, and dividing the two numbers.
*/

#include <iostream>
using namespace std;

int main()
{
	int month;
	
	cout << "Enter a month (1-12): ";
	cin >> month;
	
	switch(month) {
	case 3: case 4: case 5:
		cout << "It's Spring!" << endl;
		break;
	case 6: case 7: case 8:
		cout << "It's Summer!" << endl;
		break;
	case 9: case 10: case 11:
		cout << "It's Fall!" << endl;
		break;
	case 12: case 1: case 2:
		cout << "It's Winter!" << endl;
		break;
	default:
		cout << "That's not a valid month!" << endl;
	}
return 0;

}

