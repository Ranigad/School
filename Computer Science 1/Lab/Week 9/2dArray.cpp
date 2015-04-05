/*   Name: Charles Li
     Date: 10/24/14
	 Class: CS 111
	 Description: 
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int numStudents = 5;
const int numTests = 3;

void fillArray(int scoreList[numTests][numStudents]);
void printScores(int scoreList[numTests][numStudents]);

int main()
{
	int testScores[numTests][numStudents] = { 0 };

	fillArray(testScores);
	printScores(testScores);

return 0;
}

void fillArray(int scoreList[numTests][numStudents])
{
for (int test = 0; test < numTests; test++){
	cout << "Enter scores for Test #" << test + 1 << endl;
		{
		for (int student = 0; student < numStudents; student++)
			{
			cout << "\t Student #" << student + 1 << ": ";
			cin >> scoreList[test][student];
			}
		}
		}
	return;
}

void printScores(int scoreList[numTests][numStudents])
{		
float testAverage = 0.0f,
	studentAverage = 0.0f;
//int studentTotal[numStudents] = {0};
	
	// Header
	cout << setw(10) << right << "Test #";
	for (int i = 1; i <= 5; i++) {
	cout << setw(9) << right << "Stu " << i; }
	cout << setw(10) << right << "Average" << endl;
	
	// Printing Test Scores and Average test score per test
for (int test = 0; test < numTests; test++)
	{
	cout << setw(10) << right << test + 1;
		for (int student = 0; student < numStudents; student++)
		{
			cout << setw(10) << right << scoreList[test][student];
			testAverage += scoreList[test][student];
			//studentTotal[student] += scoreList[test][student];
		}
		cout << setw(10) << right << fixed << setprecision(1) << 1.0 * testAverage / numStudents << endl;
		testAverage = 0;
	}
	
	// Printing student averages

	/*for (int i = 0; i < numStudents; i++)
	{
		studentAverage = 1.0f * studentTotal[i] / numTests;
		cout << setw(10) << right << studentAverage;
}		*/

	studentAverage = 0;
	cout << setw(10) << right << "Average";
	for (int student = 0; student < numStudents; student++)
	{
		for (int test = 0; test < numTests; test++) {
			studentAverage += scoreList[test][student];
			}
		cout << setw(10) << fixed << setprecision(1) << right << studentAverage / numTests;
		studentAverage = 0.0f;
		}
	cout << endl;
	return;
}


