#include <iostream>
using namespace std;

int gcd(int, int);

int main()
{
	int x, y;
	cout << "Enter a number: ";
	cin >> x;
	cout << "Enter a second number: ";
	cin >> y;
		cout << "The gcd of " << x << " and " << y << " is [" << gcd(x, y) << "]" << endl << endl;

	cout << "Exiting the program." << endl;

	return 0;
}

int gcd(int x, int y) {
	if(y == 0)
		return x;
	
	return gcd(y, x % y);
}

