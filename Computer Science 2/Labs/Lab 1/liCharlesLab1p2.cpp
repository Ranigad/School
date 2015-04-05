#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int calculateMin(int grade1, int grade2, int grade3);
int calculateMax(int grade1, int grade2, int grade3);
double calculateAvg(int grade2, int grade2, int grade3);

int main()
{
	int id;
	int grade1, grade2, grade3;
	
	int min, max;
	double avg;

	ifstream inputFile;

	inputFile.open("data.txt");
	
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
			
			while(!inputFile.eof())
			{
			inputFile >> id >> grade1 >> grade2 >> grade3;
			max = calculateMax(grade1, grade2, grade3);
			min = calculateMin(grade1, grade2, grade3);	
			avg = calculateAvg(grade1, grade2, grade3);
			
			cout << left <<  setw(10) << id << setw(5) << grade1 << setw(5) << grade2 << setw(5) << grade3 << setw(5) << min << setw(5) << max << fixed << setprecision(1) << setw(8) << avg << endl;
			}
		}
		
	inputFile.close();
	
	return 0;
}

int calculateMin(int grade1, int grade2, int grade3)
{
	int min;
	
	min = grade1;
	
	if(grade2 < min)
		min = grade2;
	if(grade3 < min)
		min = grade3;
		
	return min;
}

int calculateMax(int grade1, int grade2, int grade3)
{
	int max;
	
	max = grade1;
	
	if(grade2 > max)
		max = grade2;
	if(grade3 > max)
		max = grade3; 
	
	return max;
}

double calculateAvg(int grade1, int grade2, int grade3)
{
	return (grade1 + grade2 + grade3 * 1.0) / 3.0;
}


