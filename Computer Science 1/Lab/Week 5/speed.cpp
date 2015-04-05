/*	Name: Charles Li
	Date: 9/27/14
	Lab: CS111 Week 5
	Description: Takes an input from user and calculates result of adding, subtracting, multiplying, and dividing the two numbers.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int AIRSPEED = 1100; // feet per second
const int WATERSPEED = 4900;
const int STEELSPEED = 16400;

int main()
{
	
	int medium;
	float distance, speed;
	
	cout << "Enter the distance travelled in feet: ";
	cin >> distance;
	
	cout << endl << "Choices of Medium" << endl
		 << "1. Air" << endl
		 << "2. Water" << endl
		 << "3. Steel" << endl
		 << "Enter your choice (1-3): ";
	cin >> medium;
	
	switch(medium) {
	case 1:
		speed = distance / AIRSPEED;
		cout << endl;
		break;
	case 2:
		speed = distance / WATERSPEED;
		cout << endl;
		break;
	case 3:
		speed = distance / STEELSPEED;
		cout << endl;
		break;
	default:
		cout << "That's not a valid medium!" << endl;
	}	
	
	cout << "The amount of seconds it will take is " << fixed << setprecision(5) << speed << endl << endl;
	
return 0;

}

