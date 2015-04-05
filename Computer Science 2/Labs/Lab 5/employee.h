#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
	friend void setSalary(Employee&);
private:
	std::string name;
	const long officeNo;
	const long empID;
	int deptNo;
	char empPosition; // ‘E’: entry level, ‘M’: manager, ‘D’: Director, ‘P’:Project_leader 
	int yearOfExp;
	float salary;
	static int totalNumofEmployees;
	static int nextEmpID;
	static int nextOfficeNo;

public:
	Employee();
	~Employee();
	Employee(std::string theName, int theDeptNo, char theEmpPosition, int theYearOfExp);
	void Print() const ;
	void GetInfo();
};

#endif


