#ifndef ADJUNCTPROF_H
#define ADJUNCTPROF_H
#include <string>
#include "CompSciProfessor.h"
using namespace std;

class AdjunctProf : public CompSciProfessor {
	private:
		char degree;	// B/M/P
		int NoOfTA;		// TA for how many courses
		int NoOfCourses;// Teaching for how many courses
	
	public:
		AdjunctProf();
		AdjunctProf(char, int, int);
		AdjunctProf(char, int, int, string, string, long);
		void print() const;	
		float findSalary();
};

#endif

