#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void ProcessARow(int, int, int, int&, int&, double&);

int main()
{
	int id;
	int grade1, grade2, grade3;
	
	int min, max;
	double avg;

	ifstream inputFile;
	
	inputFile.open("data.txt");
	
	// Check for file existance
	if(!inputFile)
			cout << "The input file doesn't exist!" << endl;
	else
		{
			// Header
			cout << left << setw(10) << "Std-ID" << left << setw(5) << "A1" 
				<< left << setw(5) << left << "A2" << setw(5) << "A3"
				<< left << setw(5) << "Min" << left << setw(5) << "Max" 
				<< left << setw(8) << "Average" << endl;
			for(int i = 0; i < 45; i++)
				cout << "-";
			cout << endl;
				
			// Calculations and output	
			while(!inputFile.eof())
			{
			inputFile >> id >> grade1 >> grade2 >> grade3;
			
			ProcessARow(grade1, grade2, grade3, min, max, avg);
			
			cout << left <<  setw(10) << id << setw(5) << grade1 << setw(5) << grade2 << setw(5) << grade3 << setw(5) << min << setw(5) << max << fixed << setprecision(1) << setw(8) << avg << endl;
			}
		}
		
	inputFile.close();
	
	return 0;
}

void ProcessARow(int grade1, int grade2, int grade3, int& min, int& max, double& avg)
{
	min = grade1;
	max = grade1;
	
	if(grade2 > max)
		max = grade2;
	else if(grade2 < min)
		min = grade2;
		
	if(grade3 > max)
		max = grade3; 
	else if(grade3 < min)
		min = grade3;
	
	avg = (grade1 + grade2 + grade3 * 1.0) / 3.0;
}

