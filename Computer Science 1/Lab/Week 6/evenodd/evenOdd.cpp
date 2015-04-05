#include <iostream>
using namespace std;

int main()
{
	int numberInput;
	int even = 0, odd = 0;
	int total = 0, totalNumbers = 0;
	//float average = 0.0;
	
	cout << "Input Number: ";
	cin >> numberInput;
	
	while(numberInput !=0)
	{
	
	if (numberInput %2 == 0) 
	{cout << "Even" << endl;
	even++;}
	else 
	{cout << "Odd" << endl;
	odd++;}

	total += numberInput;
	totalNumbers++;
	
	cout << "Input Next Number: ";
	cin >> numberInput;
	} 
		
	if (totalNumbers == 0) cout << "No numbers entered" << endl;
	else
	{cout << "Number of Even Numbers: " << even << endl	
		<< "Number of Odd Numbers: " << odd << endl
		<< "Average: " << float(total)/totalNumbers << endl;
}
		return 0;
}