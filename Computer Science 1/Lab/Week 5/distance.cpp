/*	Name: Charles Li
	Date: 9/27/14
	Lab: CS111 Week 5
	Description: Calculates the distance between 2 given points.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float x1, y1, x2, y2;
	float distance;
	cout << "Enter x1: ";
	cin >> x1;
	cout << "Enter y1: ";
	cin >> y1;
	cout << "Enter x2: ";
	cin >> x2;
	cout << "Enter y2: ";
	cin >> y2;

	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	
	cout << "The distance between (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is " << distance << endl;
	
	return 0;
}


	
	
	