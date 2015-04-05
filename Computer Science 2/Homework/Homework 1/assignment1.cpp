/*   Name: Charles Li
     Date: February 20th, 2015
	 Class: CS 211
	 Description: A program that takes an input message from a given file, 
		encrypts/decrypts it using either caesar/rotation or cryptogram method,
		and sends the result to an output file. 
	 Email: Li.W.Charles@gmail.com
*/

#include "Security.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	Security encrypter;
	char selection;	// For menu navigation
	int shift;	// For the rot/Caesar transformation
	
	do
	{
		encrypter.printMenu();	// Prints the menu
		cout << "Enter a selection: ";	// Asks user for menu selection
		cin >> selection;
		selection = tolower(selection);	// formatting for the switch case
		
		// Asks user to set the shift from the rot method
		if(selection == '1' || selection == '3') 
		{
			cout << "How much would you like to shift by? ";
			cin >> shift;
		}
		
		switch(selection)
		{
			case '1': encrypter.encryptFileCaesar(shift); break; 
			case '2': encrypter.encryptFileCrypto(); break;
			case '3': encrypter.decryptFileCaesar(shift); break;
			case '4': encrypter.decryptFileCrypto(); break;
			case '0': encrypter.assignment1(); break;
			case 'm': encrypter.setInputFileName(); break;       
			case 'o': encrypter.setOutputFileName(); break;
			case 'k': encrypter.setKey(); break;
			case 'q': cout << "Exiting program. " << endl; break;
			default:
				cout << endl << endl;
				cout << " ************************************************ \n";
				cout << " * " << setw(44) << "Not a valid menu option" << " * ";
		}
	} while (selection != 'q');

	return 0;
}




