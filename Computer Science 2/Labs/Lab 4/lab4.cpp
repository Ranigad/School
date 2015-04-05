#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "StudentCollection.h"
using namespace std;

int main()
{
	// Vector to store student profiles
	// vector<StudentProfile> stCollection;
	StudentCollection sc;

	// Importing and storing data
	sc.getInfo();
	
	// Printing data
	sc.printCollections();
	
	return 0;
}

