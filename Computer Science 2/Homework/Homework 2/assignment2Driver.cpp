/*   Name: Charles Li
     Date: 3/2/14
	 Class: CS 211
	 Email: Li.W.Charles@gmail.com
	 Description: This program maintains a dictionary in the local directory,
		storing words by their first letter in one of 26 text documents
		(A.txt, B.txt, ...). It then uses various methods to interact with the
		contents of these files.
*/

#include "Dictionary.h"
using namespace std;

int main()
{
	Dictionary DictForCS211;
	DictForCS211.ProcessTransactionFile();
	return 0;
}


