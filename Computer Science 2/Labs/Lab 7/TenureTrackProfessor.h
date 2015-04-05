#ifndef TENTURETRACKPROF_H
#define TENTURETRACKPROF_H
#include <string>
#include "CompSciProfessor.h"
using namespace std;

class TenureTrackProf : public CompSciProfessor {
	private:
		char rank;	// A - Assistant, S - Associated, F - Full Professor
		int YearOfExp;
	
	public: 
		TenureTrackProf();
		TenureTrackProf(char, int);
		TenureTrackProf(char, int, string, string, long);
		void print() const;
		float findSalary();
	
};

#endif

