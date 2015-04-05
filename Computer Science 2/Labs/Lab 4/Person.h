#ifndef PERSON_H
#define PERSON_H

class Person{
	private:
	long SSN;
	std::string firstName;
	std::string lastName;
	int age;
	char gender; 	// M for male, F for female;
	
	public:
	void setAPerson(long, std::string, std::string, int, char);
	void printAPerson();
};

#endif


