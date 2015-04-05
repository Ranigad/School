#ifndef TENURETRACKPROFESS_CPP
#define TENURETRACKPROFESS_CPP
#include <iostream>
#include "TenureTrackProfessor.h"
using namespace std;

TenureTrackProf::TenureTrackProf()
{
	rank = 'N';
	YearOfExp = 0;
}

TenureTrackProf::TenureTrackProf(char rnk, int years)
{
	rank = toupper(rnk);
	YearOfExp = years;
}

TenureTrackProf::TenureTrackProf(char rnk, int years, string nm, string em, long FID) : CompSciProfessor(nm, em, FID)
{
	rank = toupper(rnk);
	YearOfExp = years;
}

void TenureTrackProf::print() const
{
	CompSciProfessor::print();
	cout << "Rank: ";
	if ( rank == 'A') cout << "Assistant" << endl;
	else if ( rank == 'S') cout << "Associated" << endl;
	else if ( rank == 'F') cout << "Full Professor" << endl;
	else if ( rank == 'N') cout << "None provided" << endl;
	else cout << "Error: Invalid Character" << endl;
	
	cout << "Years of experience: " << YearOfExp << endl << endl;
}

float TenureTrackProf::findSalary() 
{
	float salary;
	
	if ( rank == 'A') salary = 65000 + 1500 * YearOfExp;
	else if ( rank == 'S') salary = 80000 + 1500 * YearOfExp;
	else if ( rank == 'F') salary = 90000 + 1500 * YearOfExp;
	else salary = 0;

	return salary;
}

#endif

