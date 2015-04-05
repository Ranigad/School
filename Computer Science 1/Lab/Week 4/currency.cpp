/*	Name: Charles Li
	Date: 9/19/14
	Week: 4
	Class: CS 111 Lab
	Description: A program that allows the user to convert USD to Euros or vice versa
*/

#include <iostream>
#include <fstream>
using namespace std;

const float USDTOEURO = .78;
const float EUROTOUSD = 1.28;

int main()
{
	int menuNavigation;
	float moneyInput;
	
	while (1)
	{
	
	cout << "**************************************************" << endl
		 << "Enter 1 to convert USD to Euros" << endl 
		 << "Enter 2 to convert Euros to USD" << endl
		 << "Enter 3 to exit the program" << endl;
		 
	cin >> menuNavigation;
	
	if (menuNavigation == 1)
		{
			cout << "Enter number of USD: ";
			cin >> moneyInput;
			cout << endl << "$" << moneyInput << " is equal to " << "$" << moneyInput * USDTOEURO << "Euros" << endl << endl;
		}
	else if (menuNavigation == 2)
		{
			cout << "Enter number of Euros: ";
			cin >> moneyInput;
			cout << endl << "$" << moneyInput << " is equal to " << "$" << moneyInput * EUROTOUSD << " USD" << endl << endl;
		}
	else
		break;
	}
	
	cout << endl << "Thank you for using this program." << endl << endl;

	return 0;
}

