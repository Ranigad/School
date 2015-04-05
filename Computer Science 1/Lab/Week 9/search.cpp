/*   Name: Charles Li
     Date: 10/24/14
	 Class: CS 111
	 Description: 
*/

#include <iostream>
using namespace std;

const int ARRAYSIZE = 10;

bool findNum1(int list[], int size, int key);
void findNum2(int list[], int size, int key);

int main()
{
	int userInput[ARRAYSIZE] = {0};
	int searchKey;
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		cout << "Enter a number: ";
		cin >> userInput[i];
		}
	cout << endl << "What number would you like to search for? ";
	cin >> searchKey;
	if(findNum1(userInput, ARRAYSIZE, searchKey)) cout << "The key was found by findNum1!" << endl;
	else cout << "The key wasn't found by findNum1" << endl;
	findNum2(userInput, ARRAYSIZE, searchKey);
return 0;
}

bool findNum1(int list[ARRAYSIZE], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (list[i] == key) return true;
	}

	return false;
}

void findNum2(int list[ARRAYSIZE], int size, int key)
{
	bool found = false;
	for (int i = 0; i < size && !found; i++)
	{
		if (list[i] == key) found = true;
	}
	
	if (found) cout << "The key was found by findNum2!" << endl;
	else cout << "The key was not found by findNum2." << endl;

}
