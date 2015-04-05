#ifndef STUDENT_CPP
#define STUDENT_CPP

#include <fstream>
#include <string>
#include <iostream>
#include "StudentCollection.h"
using namespace std;

	void StudentCollection::printCollections()
	{	
	for(int i = 0; i < stCollection.size(); i++)
		{
			stCollection[i].printAStudentProfile();
			for (int i = 0; i < 20; i++)
				cout << "_";
			cout << endl;
		}
	}

	void StudentCollection::getInfo()
		{
			
			long SSN, stNo, courseNum1, courseNum2, courseNum3;
			int age;
			char gender;
			string firstName, lastName, courseName1, courseName2, courseName3;
			
			StudentProfile sp;
			
			ifstream fin;
			fin.open("data.txt");
	
			if(fin)
			{
				while(!fin.eof())
				{
					fin >> SSN >> firstName >> lastName >> age >> gender >> stNo >> courseNum1 >> courseName1 >> courseNum2 >> courseName2 >> courseNum3 >> courseName3;
					
					sp.setAStudentProfile(SSN, firstName, lastName, age, gender, stNo, courseNum1, courseName1, courseNum2, courseName2, courseNum3, courseName3);
					
					stCollection.push_back(sp);
				}
			}
			else
				cout << "File Not Found." << endl;

			fin.close();
		}

#endif

