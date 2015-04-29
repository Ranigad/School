/*
	Class declaration of the University Class
*/
#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "department.h"
#include "course.h"
#include "student.h"
#include "faculty.h"
#include <string>
#include <vector>
using namespace std;

class University {
	protected:
	// List of departments, students, faculty, and courses.
	vector<Department> departments;
	vector<Course> courses;
	vector<Student> students;
	vector<Faculty> faculty;
	
	// Utilized for clarity of code
	static bool failure;
	static bool success;

	public:
	// Constructor / Destructors
	University();
	~University();
	
	// Creating and Deleting parts of the university
	// Departments
	bool CreateNewDepartment(string depName, string depLoc, long depChairId);
	bool RemoveADepartment(long depId);
	
	// Students
	bool CreateNewStudent(string sName, string sEmail, string sAddress, 
						string sDateOfBirth, string sGender, int sYearOfStudy, 
						string sMajor, long sAdvisorId);
	bool RemoveAStudent(long sStId);
	
	// Courses
	bool CreateNewCourse(string cName, long cDepId, long cTaughtBy,
						int cMaxSeat);
	bool RemoveACourse(long cCRN);
	
	// Faculty
	bool CreateNewFaculty(string fName, string fEmail, string fAddress, 
						string fDateOfBirth, string fGender, float fSalary, 
						int fYearOfExp, long fDepId);
	bool RemoveAFaculty(long fFactId);
	
	// Print Functions
	bool ListCoursesTaughtByFaculty(long facultyId);
	bool ListCoursesTakenByStudent(long studentId);
	bool ListFacultiesInDepartment (long departId);
	bool ListStudentsOfAFaculty(long facultyId);
	bool ListCoursesOfADepartment(long departId);
	bool ListDepartments();
	bool ListStudents();
	bool ListCourses();
	bool ListFaculties();

	// Changing parts of the university / Mutators
	bool AddACourseForAStudent(long courseId, long stId);
	bool DropACourseForAStudent(long courseId, long stId);
	bool AssignDepartmentChair(long facultyId, long departId);
	bool AssignInstructorToCourse (long facultyId, long courseId);
	
	// Search Functions to check if a passed id is part of the university
	bool isFaculty(long);
	bool hasFaculty(long);
	bool isDepartment(long);	
	bool isDepartment(string);
	bool hasDepartment(long);
	bool isStudent(long);
	bool hasStudent(long, string);
	bool isCourse(long);
	bool hasCourse(long, string);
	
	// Method to read and execute a file with commands
	bool ProcessTransactionFile(string fileName);	
	
	// Accessors and helper functions
	void printDivider(string);
	string getName(long);
	string longToString(long);
	int getIndex(long, string);
};

#endif

