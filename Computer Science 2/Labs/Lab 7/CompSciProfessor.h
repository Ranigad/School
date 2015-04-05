#ifndef COMPSCIPROFESSOR_H
#define COMPSCIPROFESSOR_H
#include <string>
using namespace std;

class CompSciProfessor{
	protected:
		string name;
		string email;
		long facultyID;
		
		
	public:
		CompSciProfessor();
		CompSciProfessor(string, string, long);
		
		void print() const;
};

#endif