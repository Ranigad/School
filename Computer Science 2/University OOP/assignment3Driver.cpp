/*   Name: Charles Li
     Date of last edit: 4/22/15 
	 Email: li.w.charles@gmail.com
	 Class: CS 211
	 Description: Utilizes various elements of object oriented programming
		to implement a university with various components such as faculty,
		students, departments, and courses.
*/
#include <iostream>
#include "university.h"
using namespace std;

int main()
{
	string transactionFile;		// Variable to store the name of the file
	cout << "Name of the transaction file: ";
	cin >> transactionFile;
	
	University CSUSM;	// Creating a university class.
	CSUSM.ProcessTransactionFile(transactionFile);

return 0;
}