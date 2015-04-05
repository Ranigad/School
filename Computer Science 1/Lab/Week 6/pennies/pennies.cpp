/*	Name: Charles Li
	Date: 10/3/14
	Class: CS111 Lab
	Description: Calculates how much a person would earn over a period of time their salary doubled each day.
	*/
	
	#include <iostream>
	#include <iomanip>
	using namespace std;
	
	int main()
	{
		double pennies = .01,
				sum = 0;
		int totalDays = 0,
			currentDay = 0;
		
		do{
		cout << "Enter the number of days you want to work: ";
		cin >> totalDays;
		if (totalDays <= 0)
		{cout << "That's not a valid input!" << endl;
		totalDays = 0;}
		} while (totalDays <= 0);
		
		cout << endl << right << setw(10) << "Day" << right << setw(10) << "Pay" << endl << endl;
		
		for (currentDay = 1; currentDay <= totalDays; currentDay++)
		{
		cout << setw(10) << right << currentDay 
		<< fixed << setprecision(2) << setw(10) << right << "$" << pennies << endl;
		sum += pennies;
		pennies *= 2;}

		cout << endl << "Total earnings: $" << sum << endl;
	
	return 0;
	
	}
	
	
	
	