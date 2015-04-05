/*   Name: Charles Li
     Date: 10/31/14	
	 Class: CS 111
	 Description: Calculate the type of triangle given points
*/

#include <iostream>
#include <cmath>
using namespace std;

const int NUMPOINTS = 3;

void checkTriangle(double side1, double side2, double side3);
double calcLength(int x1, int y1, int x2, int y2);
void inputPoints(int x[], int y[], int i);
void printInstructions();

int main()
{
	int xArray[NUMPOINTS] = {0},
		yArray[NUMPOINTS] = {0};
	double sideLength[NUMPOINTS] = {0};
	printInstructions();
	for (int i = 0; i < NUMPOINTS; i++)
	{
		cout << "Point " << i + 1 << endl;
		inputPoints(xArray, yArray, i);
	}
	
	for (int i = 0; i < NUMPOINTS; i++)
	{	
		if (i == 2)
		{sideLength[i] = calcLength(xArray[i], yArray[i], xArray[0], yArray[0]);
		}
		else
		sideLength[i] = calcLength(xArray[i], yArray[i], xArray[i+1], yArray[i+1]);
	}

	checkTriangle(sideLength[0], sideLength[1], sideLength[2]);
	
}

void printInstructions()
{
cout << "**************************************************" << endl
	<< "This program will ask you to enter 3 points of a triangle and" << endl
	<< "tell what kind of triangle it is. Please hit ENTER to continue." << endl
	<< "**************************************************" << endl;


return;
}

void inputPoints(int x[], int y[], int i)
{
	cout << "Enter x coordinate: ";
	cin >> x[i];
	cout << "Enter y coordinate: ";
	cin >> y[i];

return;
}

double calcLength(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}

void checkTriangle(double side1, double side2, double side3)
{
	int equalSides = 0;
	if(fabs(side1 - side2) < 0.00001) equalSides++;
	if(fabs(side2 - side3) < 0.00001) equalSides++;
	if(fabs(side3 - side1) < 0.00001) equalSides++;

	switch(equalSides) {
	case 3: cout << "This triangle is an equilateral triangle"; break;
	case 1: cout << "This triangle is an isosceles triangle"; break;
	case 0: cout << "This triangle is a scalene triangle"; break;
	default: cout << "Error, not a valid triangle"; break;
	}

	return;
}




