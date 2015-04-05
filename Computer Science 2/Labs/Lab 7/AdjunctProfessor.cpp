#ifndef ADJUNCTPROFESSOR_CPP
#define ADJUNCTPROFESSOR_CPP

#include <iostream>
#include "AdjunctProfessor.h"
using namespace std;

AdjunctProf::AdjunctProf() 
{
	degree = 'N';
	NoOfTA = 0;
	NoOfCourses = 0;
}

AdjunctProf::AdjunctProf(char deg, int ta, int courses)
{
	degree = toupper(deg);
	NoOfTA = ta;
	NoOfCourses = courses;
}

AdjunctProf::AdjunctProf(char deg, int ta, int courses, string nm, string em, long FID) : CompSciProfessor(nm, em, FID)
{
	degree = toupper(deg);
	NoOfTA = ta;
	NoOfCourses = courses;
}

void AdjunctProf::print() const
{
	CompSciProfessor::print();
	cout << "Degree Held : ";
	if (degree == 'B') cout << "Bachelors" << endl;
	else if ( degree == 'M') cout << "Masters" << endl;
	else if ( degree == 'P') cout << "PhD" << endl;
	else if ( degree == 'N') cout << "None recorded" << endl;
	else cout << "Error: Invalid Character" << endl;
	
	cout << "Number of classes TAing for: " << NoOfTA << endl
		<< "Number of classes teaching: " << NoOfCourses << endl << endl;
}

float AdjunctProf::findSalary()
{
	float salary;
	
	if(degree == 'B') salary = NoOfTA * 1500 + NoOfCourses * 3000;
	else if (degree == 'M') salary = NoOfTA * 2000 + NoOfCourses * 4000;
	else if (degree = 'P') salary = NoOfTA * 2500 + NoOfCourses * 5000;
	else salary = 0;
	
	return salary;
}

#endif

