/*	Name: Charles Li
	Date: 10/10/14
	Class: CS 111 Lab
	Description: This function sums up 2 numbers passed as parameters and returns the sum.
*/
#include <iostream>
#include <iomanip>
using namespace std;

const float LBTOKG = 0.453f;
const float INCHTOCM = 2.54f;

void showProgInfo();
double weightKG(int);
double heightCM(int);
double getBMI(int, int);
void showResult(int, double, int, double, double);

int main()
{
	int pounds; //in pounds
	int inches; //in inches
	double kilograms;
	double centimeters;
	double BMI;

	//call showProgInfo
	showProgInfo();

	cout << "Enter a weight in pounds: ";
	cin >> pounds;

	cout << "Enter a height in inches: ";
	cin >> inches;

	//call weightKG
	kilograms = weightKG(pounds);

		//call heightCM
	centimeters = heightCM(inches);
		
		//call getBMI
	BMI = getBMI(pounds, inches);
	
		//call showResult
	showResult(inches, centimeters, pounds, kilograms, BMI);

		return 0;
}

double weightKG(int pounds)
{
	return pounds*LBTOKG;
}

double heightCM(int inches)
{
	return inches*INCHTOCM;
}

void showProgInfo()
{
	cout << "***********************************************************************" << endl
		<< "This program will ask for your height (inches) and weight (pounds) and" << endl
		<< "convert them to centimeters and kilograms. It will also tell your BMI." << endl
		<< "***********************************************************************" << endl;
	
return;
}

double getBMI (int pounds, int inches)
{
return (float)(pounds*703)/(inches * inches);
}

void showResult(int inchHeight, double cmHeight, int lbWeight, double kgWeight, double BMI)
{
cout << "Your height: " << inchHeight << " inches (" << cmHeight << " centimeters)" << endl
	<< "Your weight: " << lbWeight << " pounds (" << kgWeight << " kilograms)" << endl
	<< "Your BMI: " << fixed << setprecision(2) << BMI << endl;
	
	return;
}
