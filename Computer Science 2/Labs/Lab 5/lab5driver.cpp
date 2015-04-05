#include <iostream>
#include "employee.h"

using namespace std;

int main(){
	Employee emp1;
	emp1.Print();
	Employee emp2("unknown", 10, '?', 0);
	emp2.GetInfo();
	setSalary(emp2);
	emp2.Print();
	Print()

return 0;
}

void setSalary(Employee& theEmployee)
{
	if(theEmployee.empPosition == 'E' && theEmployee.yearOfExp < 2)
		theEmployee.salary = 50000.00f;
	else if(theEmployee.empPosition == 'E' && theEmployee.yearOfExp >= 2)
		theEmployee.salary = 55000.00f;
	else if(theEmployee.empPosition == 'P' && theEmployee.yearOfExp < 4)
		theEmployee.salary = 60000.00f;
	else if(theEmployee.empPosition == 'P' && theEmployee.yearOfExp >= 4)
		theEmployee.salary = 65000.00f;
	else if(theEmployee.empPosition == 'M')
		theEmployee.salary = 70000.00f;
	else if(theEmployee.empPosition == 'D')
		theEmployee.salary = 80000.00f;
}


