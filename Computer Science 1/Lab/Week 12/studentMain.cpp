#include <iostream>
#include "student.h"

int main()
{
	Student stu1("Mike", "Scott", 111),	stu2("Kit", "Ross", 222), stu3("Kaz", "Slott", 333);
			
	stu1.addAClass(100);
	stu1.addAClass(200);
	stu2.addAClass(300);
	stu2.addAClass(400);
	stu2.addAClass(500);
	
	cout << stu1.getName();
	cout << " is taking classes: ";
	stu1.printClass();
	
	cout << stu2.getName();
	cout << " is taking classes: ";
	stu2.printClass();
	
	cout << stu3.getName();
	cout << " is taking classes: ";
	stu3.printClass();
}
