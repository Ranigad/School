#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int pascal[99] = { 1 };
	int row = 1, maxRow = 0;
	
	cout << "How many rows would you like to print? ";
	cin >> maxRow;
	
	do {
		for (int i = 0; i < row; i++)
			cout << setw(5) << left << pascal[i];
			
		cout << endl;
		
		for (int i = maxRow; i >= 1; i--)
			pascal[i] = pascal[i-1] + pascal[i];
		
		row++;
		
	} while(row <= maxRow+1);

	return 0;
}