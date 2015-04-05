/*   Name: Charles Li
     Date: 10/17/14
	 Class: CS 111
	 Description: 
*/

#include <iostream>
#include <string>
using namespace std;

void getInfo(string&, string&, int&);
bool verifyEligibility(string, int);
void printLetter(bool, string);

int main()
{
	string name = " ";
	string gender = " ";
	int age = 0;
	bool eligibility = 0;
	
	getInfo(name, gender, age);
	//eligibility = verifyEligibility(gender, age);
	printLetter(verifyEligibility(gender, age), name);

return 0;
}

void getInfo(string& name, string& gender, int& age)
{
	cout << "Name: ";
	cin >> name;
	cout << "Gender (m/f): ";
	cin >> gender;
	cout << "Age: ";
	cin >> age;

	return;
}

bool verifyEligibility(string gender, int age)
{
	bool eligibility = 1;
	gender[0] = toupper(gender[0]);
	if (gender[0] == 'F') eligibility = 0;
	else if (age <= 18) eligibility = 0;

	return eligibility;
}

void printLetter(bool eligibility, string name)
{
	if (eligibility) cout << "Dear " << name << ". Please join the military" << endl;
	else cout << "Thank you for applying." << endl;
	return;
}


