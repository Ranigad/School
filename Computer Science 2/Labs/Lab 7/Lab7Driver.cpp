#include <iostream>
#include <string>
//#include "CompSciProfessor.h"
#include "AdjunctProfessor.h"
#include "TenureTrackProfessor.h"
using namespace std;

int main ()
{
	AdjunctProf AdjProf('M', 2, 1, "Adam Smith", "asmith@csusm.edu", 12345);
	cout << "Salary of Adjunct Professor: $" << AdjProf.findSalary() << endl;
	AdjProf.print();
	
	TenureTrackProf TenProf('A', 8, "Jim Anderson", "janderson@csusm.edu", 54321);
	cout << "Salary of Tenure Track Professor: $" << TenProf.findSalary() << endl;
	TenProf.print();
	
	return 0;
}

