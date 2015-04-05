/*	Name: Charles Li
	Date: 9/27/14
	Lab: CS111 Week 5
	Description: Takes input of employee name, date, item, and price and prints out a receipt.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const float TAX = .0775;

int main()
{
	string name, date, item;
	float price; 
	
	// Inputs
	cout << "Enter the employee's name: ";
	cin >> name;
	cout << "Enter today's date: ";
	cin >> date;
	cout << "Enter the item being purchased: ";
	cin >> item;
	cout << "Enter the price of the item: ";
	cin >> price;

	// Calculations and output
	cout << endl << "------------------------------" << endl 
		 << "\"Your Friendly Neighbor Store\"" << endl << endl
		 << setw(30) << date << endl 	// Displays Date
		 << setw(30) << name << endl << endl	// Displays Name
		 << left << setw(20) << item << right << setw(10) << fixed << setprecision(2) << price << endl	// Displays Item and item price
		 << left << setw(20) << "Sales tax" << right << setw(10) << TAX * price << endl	// Displays Sales tax 
		 << left << setw(20) << "Total" << right << setw(10) << price * (1 + TAX) << endl	// Displays Total after tax
		 << endl << "------------------------------" << endl
		 << "Thank you for shopping with us!" << endl << endl;
	

	return 0;

}
