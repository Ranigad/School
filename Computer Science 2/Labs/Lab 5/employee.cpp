#ifndef EMPLOYEE_CPP
#define EMPLOYEE_CPP
#include <iostream>
#include "employee.h"
using namespace std;
	
	int Employee::totalNumofEmployees = 0;
	int Employee::nextEmpID = 1000;
	int Employee::nextOfficeNo = 10;
	
	Employee::Employee() : officeNo(nextOfficeNo), empID(nextEmpID)
	{
		name = "Unknown";
		deptNo = 0;
		empPosition = 'E';
		yearOfExp = 0;
		salary = 0.0f;
		totalNumofEmployees++;
		nextEmpID++;
		nextOfficeNo++;
	}
	
	Employee::~Employee()
	{
		totalNumofEmployees--;
	}
	
	Employee::Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp) : officeNo(nextOfficeNo), empID(nextEmpID)
	{
		name = theName;
		deptNo = theDeptNo;
		empPosition = theEmpPosition;
		yearOfExp = theYearOfExp;
		salary = 0.0f;
		
		totalNumofEmployees++;
		nextEmpID++;
		nextOfficeNo++;
	}
	
	void Employee::Print() const{
		cout << "Name: " << name << endl
			 << "Office Number: " << officeNo << endl
			 << "Employee ID: " << empID << endl
			 << "Department Number: " << deptNo << endl
			 << "Position: ";
		if(empPosition == 'E')
			cout << "Entry level";
		else if (empPosition == 'M')
			cout << "Manager";
		else if (empPosition == 'D')
			cout << "Director";
		else if (empPosition == 'P')
			cout << "Project Leader";
		else
			cout << "Not Available";
		
		cout << endl
			 << "Years of Experience: " << yearOfExp << endl
			 << "Salary: $" << salary << endl << endl << endl;
	}
	
	void Employee::GetInfo() {
		cout << "Enter a name: ";
		getline(cin, name);
		cout << "E: entry level | M: manager | D: Director | P:Project Leader"
			 << endl << "Enter the employee position: ";
		empPosition = getchar();
		cout << "Enter years of experience: ";
		cin >> yearOfExp;
	}	
	
#endif


