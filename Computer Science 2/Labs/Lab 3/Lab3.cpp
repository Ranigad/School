#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


class Course{
	public:
	string courseNum;
	string courseName;
};

class Student{
	public:
	long studentNum;
	Course course1;
	Course course2;
	Course course3;
};

class Person{
	public:
	long SSN;
	string firstName;
	string lastName;
	int age;
	char gender; 	// M for male, F for female;
};

class StudentProfile{
	public: 
	Person personalInfo;
	Student stdInfo;
};

void printStudentProfile(const vector<StudentProfile>&);
void getInfo(vector<StudentProfile>&);

int main()
{
	vector<StudentProfile> stCollection;
	getInfo(stCollection);
	printStudentProfile(stCollection);
	
	return 0;
}

void printStudentProfile(const vector<StudentProfile>& profiles)
{
	for (int i = 0; i < profiles.size(); i++)
	{
		cout << "Student ID: " << profiles[i].personalInfo.SSN << endl
			<< "Name: " << profiles[i].personalInfo.firstName << " "
			<< profiles[i].personalInfo.lastName << endl
			<< "Age: " << profiles[i].personalInfo.age << endl;
			
		cout << "Gender: ";
		
		if (profiles[i].personalInfo.gender == 'M')
			cout << "Male" << endl;
		else if (profiles[i].personalInfo.gender == 'F')
			cout << "Female" << endl;
		else
			cout << "N/A" << endl;
		
		cout << "Student ID: " << profiles[i].stdInfo.studentNum << endl
			<< "Course 1: (" << profiles[i].stdInfo.course1.courseNum << ") " << profiles[i].stdInfo.course1.courseName << endl
			<< "Course 2: (" << profiles[i].stdInfo.course2.courseNum << ") " << profiles[i].stdInfo.course2.courseName << endl
			<< "Course 3: (" << profiles[i].stdInfo.course3.courseNum << ") " << profiles[i].stdInfo.course3.courseName << endl;
			
		for (int i = 0; i < 20; i++)
			cout << "_";
		
		cout << endl;
			
	
}
}

void getInfo(vector<StudentProfile>& profiles)
{
	int count = 0;	
	ifstream fin;
	fin.open("data.txt");
	StudentProfile tempProfile;
	
	if (fin){
		while (!fin.eof())
		{
			fin >> tempProfile.personalInfo.SSN
			>> tempProfile.personalInfo.firstName
			>> tempProfile.personalInfo.lastName
			>> tempProfile.personalInfo.age
			>> tempProfile.personalInfo.gender
			>> tempProfile.stdInfo.studentNum
			>> tempProfile.stdInfo.course1.courseNum
			>> tempProfile.stdInfo.course1.courseName
			>> tempProfile.stdInfo.course2.courseNum
			>> tempProfile.stdInfo.course2.courseName
			>> tempProfile.stdInfo.course3.courseNum
			>> tempProfile.stdInfo.course3.courseName;
			
			profiles.push_back(tempProfile);
		}
	}
	else
	{
		cout << "No such file exists! \n";
		exit(1);
}
	fin.close();
}



