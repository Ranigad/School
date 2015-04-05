#ifndef COMPSCIPROFESSOR_CPP
#define COMPSCIPROFESSOR_CPP
#include <iostream>
#include "CompSciProfessor.h"
using namespace std;

CompSciProfessor::CompSciProfessor()
{
	name = "unknown";
	email = "n/a";
	facultyID = 0;
}

CompSciProfessor::CompSciProfessor(string nm, string em, long FID)
{
	name = nm;
	email = em;
	facultyID = FID;
}


void CompSciProfessor::print() const{
	cout << "Name: " << name << endl
		<< "Email: " << email << endl	
		<< "Faculty ID: " << facultyID << endl;
}

#endif



