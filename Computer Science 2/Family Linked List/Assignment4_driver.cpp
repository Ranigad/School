/*   Name: Charles Li
     Start Date: 4/30/15
	 Last Edit Date: 5/7/15
	 Class: CS 211
	 Description: Utilizes object oriented programming and linked lists to model a list of families. 
	 
	 Visual example below.
	 
	 Family(top)
	 Husband ->  Husband ->  Husband...
		|			|			|
		Wife		Wife		Wife
		|			|			|
		Child		Child		Child
		| 
		Child
*/

#include "Family.h"

int main()
{
	Family USAFamilies;
	USAFamilies.ReadTransactionFile();
	return 0;
}

