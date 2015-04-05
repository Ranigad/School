#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H

#include <vector>
#include "StudentProfile.h"
using namespace std;

class StudentCollection {
	private:
		vector<StudentProfile> stCollection;

	public:
		void printCollections();
		void getInfo();

};

#endif

