/*   Name: Charles Li
     Date: 10/17/14
	 Class: CS 111
	 Description: 
*/

#include <iostream>
#include <iomanip>
using namespace std;

void getCustomerInfo(int&, int&, int&, int&, char&);
void getItemsInfo(float&, int&);
float calcDiscount(int, float);
float calcSalesTax(char, float);
float calcShipping(int);
void outputInvoice(int, char, int, int, int, float, float, float, float, float);

int main()
{
	int accountNum = 0;
	int month = 0,
		day = 0,
		year = 0,
		weight = 0;
	char countyCode = '0';
	float basePrice = 0.0,
		discount = 0.0,
		tax = 0.0,
		shippingCost = 0.0,
		finalPrice = 0.0;
	
	getCustomerInfo(accountNum, month, day, year, countyCode);
	getItemsInfo(basePrice, weight);
	discount = calcDiscount(month, basePrice);
	finalPrice = basePrice - discount;
	tax = calcSalesTax(countyCode, finalPrice);
	finalPrice += tax;
	shippingCost = calcShipping(weight);
	finalPrice += shippingCost;
	
	outputInvoice(accountNum, countyCode, month, day, year, basePrice, discount, tax, shippingCost, finalPrice);

return 0;
}

void getCustomerInfo(int& accountNum, int& month, int& day, int& year, char& countyCode)
{
	char input;
	cout << "Account Number: ";
	cin >> accountNum;
	/*cout << "Month of shipping: ";
	cin >> month;
	cout << "Day of shipping: ";
	cin >> day; 
	cout << "Year of shipping: ";
	cin >> year;*/
	cout << "Enter the date of shipping (mm/dd/yyyy): ";
	cin >> month >> input >> day >> input >> year;
	cout << "County code " << endl 
		<< "S - San Diego County" << endl
		<< "O - Orange County" << endl
		<< "L - LA County" << endl;
	cin >> countyCode;
	countyCode = toupper(countyCode);
	return;
}

void getItemsInfo(float& price, int& weight)
{
	char purchaseDecision = 'Y';
	int weightInput = 0;
	float priceInput = 0.0;
	
	cout << "Would you like to make a purchase? Y/N: ";
	cin >> purchaseDecision;
	purchaseDecision = toupper(purchaseDecision);
	
	while (purchaseDecision == 'Y') {
		cout << "Enter the item price: ";
		cin >> priceInput;
		price += priceInput;
		
		cout << "Enter the item weight: ";
		cin >> weightInput;
		weight += weightInput;
		
		cout << "Would you like to make another purchase? Y/N: ";
		cin >> purchaseDecision;
		purchaseDecision = toupper(purchaseDecision);
	}
	
	return;
}

float calcDiscount(int month, float basePrice)
{
	float priceMultiplier = 0;
	if (month >= 1 && month <= 5) priceMultiplier = .05;
	else if (month >= 6 && month <= 8) priceMultiplier = .1;
	else if (month >= 8 && month <= 12) priceMultiplier = .15;
	else cout << "Not a valid month. No discount applied. ";

	return priceMultiplier * basePrice;
}

float calcSalesTax(char county, float price)
{
	float taxMultiplier = .1;
	switch(county) {
	case 'S': case 'O': taxMultiplier = .0775; break;
	case 'L': taxMultiplier = .0825; break;
	default: cout << "Invalid county specified. Applying 10% tax rate." << endl;
	}
		
	return taxMultiplier * price;

}

float calcShipping(int weight)
{
	float cost = 0.0;
	
	if (weight <= 25) cost = 5.00;
	else if (weight <= 50) cost = 5.00 + (weight - 25) * .1;
	else cost = 5.00 + 2.50 + (weight - 50) * .07;
	
	return cost;
}

void outputInvoice(int accNum, char county, int month, int date, int year, float basePrice, float discount, float tax, float shipping, float totalPrice)
{
	cout << "Account Number\t\tCounty" << endl;
	cout << setw(14) << right << accNum << "\t\t";
	switch (county){
	case 'S': cout << "San Diego"; break;
	case 'O': cout << "Orange"; break;
	case 'L': cout << "Los Angeles"; break;
	default: cout << "No valid county provided";
	}
	
	
	cout << endl << endl << "Date of Sale: " << month << "/" << date << "/" << year << endl << endl;
	
	cout << "Total Price of Items: \t $" << setw(8) << fixed << setprecision(2) << basePrice << endl
		 << "Discount: \t\t $" << setw(8) << discount << endl
		 << "Sales Tax: \t\t $" << setw(8) << tax << endl
		 << "Shipping: \t\t $" << setw(8) << shipping << endl
		 << "Total Due: \t\t $" << setw(8) << totalPrice << endl;
		 
	return;
	
}
	
	