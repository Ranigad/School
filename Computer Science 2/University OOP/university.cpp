/*
	Class implementation of the University Class
	Purpose: Utilize the Course, Student, Faculty, and Department classes to 
		model a functional university. This class holds a records of the
		various parts of the university inside vectors and interacts with them
		using methods called by ProcessTransactionFile.
*/

#ifndef UNIVERSITY_CPP
#define UNIVERSITY_CPP
#include "university.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//----------------------------------------------------------------------------	
// Static Initialization
// Initializing failure and success. Used for readability purposes.	
bool University::failure = false;
bool University::success = true;

//----------------------------------------------------------------------------
// Constructors / Destructors
/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * There is nothing to initialize since the vectors are created upon       *
 * object creation.                                                        *
 ***************************************************************************/
University::University()
{

}

/***************************************************************************
 * ~University                                                             *
 *                                                                         *
 * The destructor.                                                         *
 ***************************************************************************/
University::~University()
{

}

//----------------------------------------------------------------------------
// Creating and Deleting parts of the university

/***************************************************************************
 * CreateNewDepartment                                                     *
 *                                                                         *
 * Creates a new department in the university using a passed name,         *
 *		location, and chair id.                                            *
 * Exits with failure if the department chair isn't 0 (unknown chair) and  *
 * 		the chair passed is not a faculty member.						   *
 ***************************************************************************/
bool University::CreateNewDepartment(string depName, string depLoc, 
									long depChairId)
{
	
	if(depChairId != 0 && !isFaculty(depChairId))
	{
		cout << "[Error] Provided department chair is not a faculty member." 
			<< " Department could not be created. " << endl;
		return failure;
	}	
	
	// Create a new department object and adds it to the vector
	Department newDepartment(depName, depLoc, depChairId);
	departments.push_back(newDepartment);
	cout << "Department " << newDepartment << " successfully created" << endl;
	return success;
}

/***************************************************************************
 * RemoveADepartment                                                       *
 *                                                                         *
 * Given a long integer, deletes a department in the vector with a matching*
 * 		id.                                                                *
 * Exits with failure if the id does not match any department ids.		   *
 * Can only remove departments with no students, faculty, or courses.	   *
 ***************************************************************************/
bool University::RemoveADepartment(long depId)
{
	// Checks if department id is valid
	if(!isDepartment(depId))
	{
		cout << "[Error] Department " << depId << " does not exist!" << endl;
		return failure;
	}
	
	// Checks if department has no faculty.
	if(hasFaculty(depId))
	{
		cout << "[Error] Department " << getName(depId) << " has faculty." 
			<< " Could not be removed." << endl;
		return failure;
	}
	
	// Checks if department has no students.
	if(hasStudent(depId, "Department"))
	{
		cout << "[Error] Department " << getName(depId) << "has students with"
			<< " majors declared. Could not be removed" << endl;
		return failure;
	}
	
	// Checks if department has no courses.
	if(hasCourse(depId, "Department"))
	{
		cout << "[Error] Department " << getName(depId) << "has courses."
			<< " Could not be removed." << endl;
		return failure;
	}
	
	// Search the department vector and get the index
	int departmentIndex = getIndex(depId, "Department");
	if(departmentIndex >= 0)
	{
		// If a valid index is returned, delete the department
		cout << "Department " << departments.at(departmentIndex)
			<< " successfully removed." << endl;
		departments.erase(departments.begin() + departmentIndex);
		return success;
	}
	else
	{
		// if the index is -1, there was an error with the search
		cout << "Could not remove given department." << endl;
		return failure;
	}
}

/***************************************************************************
 * CreateNewStudent                                                        *
 *                                                                         *
 * Creates a new student in the university using many passed informations. *
 * Exits with failure if the major isn't 0 (unknown major) and the major   *
 * 		is not an existing department. Also fails if the advisor doesn't   * 
 *		exist. 															   *	
 ***************************************************************************/
bool University::CreateNewStudent(string sName, string sEmail, string sAddress, 
								string sDateOfBirth, string sGender,
								int sYearOfStudy, string sMajor, 
								long sAdvisorId)
{
	 if(sMajor.compare("0") != 0 && !isDepartment(sMajor))
	 {
		 cout << "[Error] Invalid major. Could not create student." << endl;
		 return failure;
	 }
	
	if (!isFaculty(sAdvisorId))
	{
		cout << "[Error] Advisor is not a valid faculty. "
			<< "Could not create student" << endl;
		return failure;
	}
	  
	// Creates a new student and adds it to the student list.
	Student newStudent(sName, sEmail, sAddress, sDateOfBirth, sGender, 
		sYearOfStudy, sMajor, sAdvisorId);
	students.push_back(newStudent);
	cout << "Student " << newStudent << " successfully created." << endl;
	return success;	
}

/***************************************************************************
 * RemoveAStudent                                                          *
 *                                                                         *
 * Given a long integer, deletes a student from the vector with a matching *
 * 		id.                                                                *
 * Exits with failure if the id does not match any student ids			   *
 * Removes all classes from the student	course list.					   *
 ***************************************************************************/
bool University::RemoveAStudent(long sStId)
{

	if(!isStudent(sStId))
	{
		cout << "[Error] Invalid student id provided. "
			<< "Could not remove student." << endl;
		return failure;
	}
	
	// Get the index for student	
	int studentIndex = getIndex(sStId, "Student");
	// Gets the list of courses being taken by student
	vector<Course> courseList = students.at(studentIndex).getCourseList();
	
	// If the index isn't an error
	if(studentIndex >= 0)
	{	
		// Drops all the courses being taken by student
			while(!courseList.empty())
			{
				DropACourseForAStudent(courseList.at(0).getCRN(), sStId);
				courseList.erase(courseList.begin());
			}
			cout << "Student " << students.at(studentIndex) 
				<< " successfully removed" << endl;
			students.erase(students.begin() + studentIndex);
			return success;
	}
	else
	{
		// Error checking
		cout << "[Error] Could not remove given student." << endl;
		return failure;
	}
}
 
/***************************************************************************
 * CreateNewCourse                                                         *
 *                                                                         *
 * Creates a new course in the university using a name, department id,     *
 * 		faculty id of the teacher, and a maximum seats allowed.			   *
 * Exits with failure if the teacher ID isn't 0 (unknown teacher) and the  *
 * 		teacher is not an existing faculty. Also fails if the department id* 
 *		is not an existing department at the university.				   *	***************************************************************************/
bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
	if(cTaughtBy != 0 && !isFaculty(cTaughtBy))
	{
		cout << "[Error] Teacher assigned to course is "
			<< "not a valid faculty member." << endl;
		return failure;
	}

	if(!isDepartment(cDepId))
	{
		cout << "[Error] This course does not have a valid department number." 
			<< endl;
		return failure;
	}
	
	// Create a new course and add it to the university course list.
	Course newCourse(cName, cMaxSeat, cDepId, cTaughtBy);
	courses.push_back(newCourse);
	cout << "Course " << newCourse << " successfully created" << endl;
	return success;
}

/***************************************************************************
 * RemoveACourse                                                           *
 *                                                                         *
 * Given a long integer, deletes a course in the vector with a matching id *
 * Exits with failure if the id does not match any course CRNs			   *
 * Can only remove courses with no students.		              		   *
 ***************************************************************************/
bool University::RemoveACourse(long cCRN)
{
	// Checks if the course exists.
	if(!isCourse(cCRN))
	{
		cout << "[Error] Course does not exist! Could not remove." << endl;
		return failure;
	}

	// Checks all the courses
	int courseIndex = getIndex(cCRN, "Course");
	
	// Checks if the course is empty.

	// Checks if it's a valid course
	if(courseIndex >= 0)
	{
		// Checks if there are people taking the course.
		if(courses.at(courseIndex).getAssignedSeats() > 0)
		{
			cout << "[Error] Course has registered students. Could not remove."
				<< endl;
			return failure;
		}
		else
		{
			// Removes the course from the existing courses vector.
			cout << "Course " << courses.at(courseIndex) 
				<< " successfully removed." << endl;
			courses.erase(courses.begin() + courseIndex);
			return success;		
		}
	}
	else
	{
		// If the index is invalid
		cout << "[Error] Could not remove given course." << endl;	
		return failure;
	}

}

/***************************************************************************
 * CreateNewFaculty                                                        *
 *                                                                         *
 * Creates a new faculty in the university using many passed informations. *
 * Exits with failure if the department given is not valid.                *
 ***************************************************************************/
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, 
								string fDateOfBirth, string fGender,
								float fSalary, int fYearOfExp, long fDepId)
{

	 if(!isDepartment(fDepId))
	 {
		 cout << "[Error] Invalid department specified, " 
		 << "could not add new faculty." << endl;
		 return failure;
	 }
	 
	// Create a new faculty member and add it to the list.
	Faculty newFaculty( fName, fEmail, fAddress, fDateOfBirth, fGender, 
		fSalary, fYearOfExp, fDepId);
	faculty.push_back(newFaculty);
	cout << "Faculty " << newFaculty << " successfully created." << endl;
	return success;
}

/***************************************************************************
 * RemoveAFaculty                                                          *
 *                                                                         *
 * Given a long integer, deletes a faculty in the vector with a matching   *
 * 		id.																   *	
 * Exits with failure if the id does not match any faculty IDs			   *
 * Can only remove faculty if they are not advising students, chairing     *
 * 		departments, or teaching any courses.							   *
 ***************************************************************************/
bool University::RemoveAFaculty(long fFactId)
{

	//check if the fFactId passed to this method is a valid existing faculty id.
	if(!isFaculty(fFactId))
	{
		cout << "[Error] Invalid faculty specified. Could not remove faculty." 
			<< endl;
		return failure;
	}
	
	// Checks if the faculty is advising any students.
	if(hasStudent(fFactId, "Faculty"))
	{
		cout << "[Error] Faculty " << getName(fFactId) 
			<< " is currently advising students. Could not remove." << endl;
		return failure;
	}
	
	// Checks if the faculty is teaching a course
	if(hasCourse(fFactId, "Faculty"))
	{
		cout << "[Error] Faculty " << getName(fFactId)
			<< " is currently teaching a course. Could not remove." << endl;
		return failure;
	}
	
	// Checks if the faculty is chairing a department.
	if(hasDepartment(fFactId))
	{
		cout << "[Error] Faculty " << getName(fFactId)
			<< " is currently the chair of a department. Could not remove." 
			<< endl;
		return failure;
	}
	
	int facultyIndex = getIndex(fFactId, "Faculty");

	if(facultyIndex >= 0)
	{
		cout << "Faculty " << faculty.at(facultyIndex) 
			<< " successfully removed." << endl;
		faculty.erase(faculty.begin() + facultyIndex);
		return success;
	}
	else
	{
		cout << "[Error] Could not remove given faculty." << endl;
		return failure;
	}
}

//----------------------------------------------------------------------------
// Print Functions

/***************************************************************************
 * ListCoursesTaughtByFaculty                                              *
 *                                                                         *
 * Lists all the courses taught by a given faculty id.                     *
 * Returns with a failure if the id passed is not a valid faculty.         *
 ***************************************************************************/
bool University::ListCoursesTaughtByFaculty(long facultyId)
{
	// Checks if the faculty id is valid.
	if(!isFaculty(facultyId))
	{
		cout << "[Error] Invalid Faculty ID provided. "
			<< "Could not list courses taught." << endl;
		return failure;
	}
	
	// Header + Vector search
	cout << "Courses taught by faculty " << getName(facultyId) << endl << endl;
	for(int i = 0; i < courses.size(); i++)
	{
		// If the professor of the course is the same as the passed id
		if(courses.at(i).getProfessor() == facultyId)
		{
			// Print the course.
			cout << courses.at(i) << endl;
		}
	}
	
	return success;
}

/***************************************************************************
 * ListCoursesTakenByStudent                                               *
 *                                                                         *
 * Lists all the courses that are being taken by a student in ID Name	   *
 * 		format.															   *
 * Returns with a failure if the id passed is not a valid student.         *
 ***************************************************************************/
bool University::ListCoursesTakenByStudent(long studentId)
{
	// Checks if the student is valid
	if(!isStudent(studentId))
	{
		cout << "[Error] Invalid student id provided. Could not list courses." 
			<< endl;
		return failure;
	}
	
	// Checks the student vector for the given student
	for(int i = 0; i < students.size(); i++)
	{
		// Checks if the individual student's id matches the one passed
		if(students.at(i).getID() == studentId)
		{
			// Prints all the courses taken by the student.
			cout << "Courses taken by student " << students.at(i) << endl 
				<< endl;
			students.at(i).printCourses();
			return success;
		}
	}

}

/***************************************************************************
 * ListFacultiesInDepartment                                               *
 *                                                                         *
 * Lists all the faculty that are part of a given department.              *
 * Returns with a failure if the id passed is not a valid department.      *
 ***************************************************************************/
bool University::ListFacultiesInDepartment (long departId)
{
	// Checks if the department is valid.
	if(!isDepartment(departId))
	{
		cout << "[Error] Invalid department id provided."
			<< " Could not list faculty." << endl;
		return failure;
	}
	
	// Header + Searching the faculty vector
	cout << "Faculties in department " << getName(departId) << endl << endl;
	for(int i = 0; i < faculty.size(); i++)
	{
		// Checks if the faculty's id is the same as the passed id
		if(faculty.at(i).getDepID() == departId)
		{
			// Prints out the faculty name and id if they match.
			cout << faculty.at(i) << endl;
		}
	}
	
	return success;
}

/***************************************************************************
 * ListStudentsOfAFaculty                                                  *
 *                                                                         *
 * Lists all the students being advised by a given faculty id.             *
 * Returns with a failure if the id passed is not a valid faculty.         *
 ***************************************************************************/
bool University::ListStudentsOfAFaculty(long facultyId)
{
	// Checks if the faculty id is valid
	if(!isFaculty(facultyId))
	{
		cout << "[Error] Invalid faculty id provided. Could not list students." 
			<< endl;
		return failure;
	}
	
	// Header + Student search
	cout << "Students of faculty " << getName(facultyId) << endl << endl;
	for(int i = 0; i < students.size(); i++)
	{
		// Checks if the advisor's id is the same as the one passed in
		if(students.at(i).getFacultyId() == facultyId)
			cout << students.at(i) << endl;	// Prints the student if so.
	}
	
	return success;
}

/***************************************************************************
 * ListCoursesOfADepartment                                                *
 *                                                                         *
 * Lists all the courses in a particular department.                       *
 * Returns with a failure if the id passed is not a valid department.      *
 ***************************************************************************/
bool University::ListCoursesOfADepartment(long departId)
{
	// Checks if the department is valid.
	if(!isDepartment(departId))
	{
		cout << "[Error] Invalid department id provided."
			<< " Could not list courses." << endl;
		return failure;
	}
	
	// Header + Checking the courses vector.
	cout << "Courses in department " << getName(departId) << endl << endl;
	for(int i = 0; i < courses.size(); i++)
	{
		// Compares the department id of each course to the one passed in.
		if(courses.at(i).getDepartID() == departId)
		{
			// If they match, print the course name and CRN.
			cout << courses.at(i) << endl;
		}
	}
	
	return success;
}

/***************************************************************************
 * ListDepartments                                                         *
 *                                                                         *
 * Lists all the departments of the university in name id format.          *
 ***************************************************************************/
bool University::ListDepartments()
{
	cout << "Departments" << endl << endl;	// Header

	for(int i = 0; i < departments.size(); i++)
	{
		cout << departments.at(i) << endl; //Print departments one at a time.
	}
	return success;
}

/***************************************************************************
 * ListStudents                                                            *
 *                                                                         *
 * Lists all the students of the university in name id format.   		   *
 ***************************************************************************/
bool University::ListStudents()
{
	cout << "Students" << endl << endl; // Header.
	
	for(int i = 0; i < students.size(); i++)
	{
		cout << students.at(i) << endl;	// Prints students one at a time.
	}
	return success;
}

/***************************************************************************
 * ListCourses                                                             *
 *                                                                         *
 * Lists all the courses of the university in name id format.     	       *
 ***************************************************************************/
bool University::ListCourses()
{
	cout << "Courses" << endl << endl;	// Header
	
	for(int i = 0; i < courses.size(); i++)
	{
		cout << courses.at(i) << endl;	// List courses one at a time.
	}
	return success;
}

/***************************************************************************
 * ListFaculties                                                           *
 *                                                                         *
 * Lists all the faculty of the university in name id format.    	       *
 ***************************************************************************/
bool University::ListFaculties()
{
	cout << "Faculty" << endl << endl;	// Header
	
	for(int i = 0; i < faculty.size(); i++)
	{
		cout << faculty.at(i) << endl;	// Lists faculty one at a time.
	}
	return success;
}

//----------------------------------------------------------------------------
// Changing parts of the university / Mutators
/***************************************************************************
 * AddACourseForAStudent                                                   *
 *                                                                         *
 * Adds a given course to the list of courses a student is taking (vector) *
 * Returns failure if the class is full, the student id is invalid, or the *
 * 		course id is invalid.											   *
 ***************************************************************************/
bool University::AddACourseForAStudent(long courseId, long stId)
{
	bool added = failure;	// Flag for when the assigned seats is incremented.
	
	// Check if student exists
	if(!isStudent(stId))
	{
		cout << "[Error] Invalid student id provided. Could not add course." 
			<< endl;
		return failure;
	}
	
	// Check if course exists
	if(!isCourse(courseId))
	{
		cout << "[Error] Invalid course id provided. "
			<< "Could not add student to course." << endl;
		return failure;
	}
	
	// Check if the course is full. If not, add one to the course roster.
	// Cannot go through loop without finding the course since we know it exists
	Course courseToAdd;	// Variable to hold the course
	
	// Goes through the course vector
	for(int i = 0; i < courses.size() && !added; i++)
	{
		if(courses.at(i).getCRN() == courseId) // Checks if the crns match
		{
			if(courses.at(i).isFull())
			{
				// Failure if the course is full.
				cout << courses.at(i) << " is full. Could not add student."
					<< endl;
				return failure;
			}			
			else
			{
				courseToAdd = courses.at(i);	// Stores the course
				courses.at(i)++;	// Adds one to the assignedSeats.
				added = true;	// Flag to get out of the loop.
			}
		}
	}
	
// Find the corresponding student and add the course to the coursesTaken list
	for(int i = 0; i < students.size(); i++)
	{
		if(students.at(i).getID() == stId)	// Checks which student matches.
		{
			// Add the course.
			students.at(i).addCourse(courseToAdd);
			cout << courseToAdd << " added to " << students.at(i) << endl;
			return success;
		}
	}
}

/***************************************************************************
 * DropACourseForAStudent                                                  *
 *                                                                         *
 * Removes a given course from the list of courses a student is taking     *
 * Returns failure if the class or the student id is invalid			   *
 ***************************************************************************/
bool University::DropACourseForAStudent(long courseId, long stId)
{
	bool removed = false;	// Flag triggered when the course is removed

	// Check if student exists
	if(!isStudent(stId))
	{
		cout << "[Error] Invalid student id provided. Could not drop course." 
			<< endl;
		return failure;
	}
	
	// Check if the course exists
	if(!isCourse(courseId))
	{
		cout << "[Error] Invalid course id provided. "
			<< "Could not drop course." << endl;
		return failure;
	}

	// Check if student is taking the course. If so, remove it.
	for(int i = 0; (i < students.size()) && !removed; i++)
	{
		if(students.at(i).getID() == stId)
		{
			// Found a matching student, check for course. Erase if exists.
			if(students.at(i).removeCourse(courseId))
			{
				cout << getName(courseId) << " removed from " 
				<< students.at(i).getName() << "'s schedule." << endl;
				removed = true;	// Flag to break loop
			}
		}
	}
	
	// Decrement the corresponding course.
	if(removed) 
	{
		for(int i = 0; i < courses.size(); i++)
		{
			if(courses.at(i).getCRN() == courseId)	// Checks for right course
			{	
				courses.at(i)--;	// Decrements assigned seats
				return success;
			}
		}
	}
	else
	{
		cout << getName(courseId) << " could not be removed from "
			<< getName(stId) << "'s schedule." << endl;
		return false;
	}
}

/***************************************************************************
 * AssignDepartmentChair                                                   *
 *                                                                         *
 * Assigns a faculty member to be the chair of a department                *
 * Returns failure if the class is the faculty id is invalid, or the       *
 * 		department id is invalid.										   *
 ***************************************************************************/
bool University::AssignDepartmentChair(long facultyId, long departId)
{
	// Check for faculty validity
	if(!isFaculty(facultyId))
	{
		cout << "[Error] Invalid faculty provided. Could not assign chair." 
			<< endl;
		return failure;
	}
	
	// Check for department validity.
	if(!isDepartment(departId))
	{
		cout << "[Error] Invalid department provided. Could not assign chair" 
			<< endl;
		return failure;
	}

	int departmentIndex = getIndex(departId, "Department");
	
	// If valid, checks all departments
	if(departmentIndex >= 0)
	{
		
		// Change the chair to the new chair.
		cout << "Successfully assigned " << getName(facultyId) << " to " 
			<< departments.at(departmentIndex).getName() << endl;
		departments.at(departmentIndex).setChair(facultyId);
		return success;
	}
	else
	{
		cout << "Could not assign professor to course." << endl;
		return failure;
	}

}

/***************************************************************************
 * AssignInstructorToCourse                                                *
 *                                                                         *
 * Assigns a faculty member to be the professor of a class.                *
 * Returns failure if the class is the faculty id is invalid, or the       *
 * 		course id is invalid.											   *
 ***************************************************************************/
bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
	// Checks for valid faculty
	if(!isFaculty(facultyId))
	{
		cout << "[Error] Invalid faculty id provided. "
			<< "Could not assign instructor." << endl;
		return failure;
	}
	
	// Checks for valid course.
	if(!isCourse(courseId))
	{
		cout << "[Error] Invalid course id provided. "
			<< "Could not assign instructor" << endl;
		return failure;
	}
	
	int courseIndex = getIndex(courseId, "Course");
	// Checks all courses.
	if(courseIndex >= 0)
	{
		// Assigns the faculty to the course.
		cout << "Successfully assigned " << getName(facultyId) << " to " 		
			<< courses.at(courseIndex).getName() << endl;
		courses.at(courseIndex).setProfessor(facultyId);
		return success;
	}
	else
	{
		// Error checking
		cout << "Could not assign instructor to course." << endl;
		return failure;
	}
}

//----------------------------------------------------------------------------
// Search Functions to check if a passed id is part of the university

/***************************************************************************
 * isFaculty                                                               *
 *                                                                         *
 * Checks to see if the passed id is a valid faculty.                      *
 ***************************************************************************/
bool University::isFaculty(long id)
{
	// Checks all faculty to see if the id given is among the list
	for (int i = 0; i < faculty.size(); i++)
	{
		if(id == faculty.at(i).getFacultyID())
			return success;
	}
	
	return false;
}

/***************************************************************************
 * hasFaculty                                                              *
 *                                                                         *
 * Checks to see if the passed department id has any faculty.              *
 ***************************************************************************/
bool University::hasFaculty(long depId)
{
	// Checks if a department has faculty
	for (int i = 0; i < faculty.size(); i++)
	{
		if(depId == faculty.at(i).getDepID())
			return success;	// If there is at least one faculty, return success
	}
	
	return failure;
}

/***************************************************************************
 * isDepartment                                                            *
 *                                                                         *
 * Checks to see if the passed id is a valid department.                   *
 * Utilizes a passed long integer id number to search.					   *
 ***************************************************************************/
bool University::isDepartment(long id)
{
	// Checks all departments to see if the id given is among the list
	for (int i = 0; i < departments.size(); i++)
	{
		if(id == departments.at(i).getDepartmentID())
			return success;
	}
	
	return false;
}//----------------------------------------------------------------------------

/***************************************************************************
 * isDepartment                                                            *
 *                                                                         *
 * Checks to see if the passed id is a valid faculty. Searches by name.    *
 ***************************************************************************/
bool University::isDepartment(string name)
{
	// Checks all departments to see if the name given is among the list
	for (int i = 0; i < departments.size(); i++)
	{
		if(name == departments.at(i).getName())
			return success;
	}
	
	return false;
}
/***************************************************************************
 * hasDepartment                                                           *
 *                                                                         *
 * Checks to see if the passed faculty id chairs any department.           *
 ***************************************************************************/
bool University::hasDepartment(long facId)
{
	// Checks if a faculty is chairing any department.
	for (int i = 0; i < departments.size(); i++)
	{
		if(facId == departments.at(i).getChairID())
			return success;	// If there is at least one dep, return success
	}
	
	return failure;
}

/***************************************************************************
 * isStudent                                                               *
 *                                                                         *
 * Checks to see if the passed id is a valid student.                      *
 ***************************************************************************/
bool University::isStudent(long id)
{
	// Checks all students to see if the id given is among the list
	for (int i = 0; i < students.size(); i++)
	{
		if(id == students.at(i).getID())
			return success;
	}
	
	return false;
}

/***************************************************************************
 * hasStudent                                                              *
 *                                                                         *
 * Checks to see if the passed department id has any students.             *
 * Also can check if the faculty id passed is advising any students.	   *
 ***************************************************************************/
bool University::hasStudent(long id, string partOfUni)
{
	if(partOfUni.compare("Department") == 0)
	{
		// Checks if a department has students
		for (int i = 0; i < students.size(); i++)
		{
			if(getName(id).compare(students.at(i).getMajor()) == 0)
				return success;	//There's at least one student with it as major
		}
		
		return failure;
	}
	else if(partOfUni.compare("Faculty") == 0)
	{
		// Checks if a faculty is advising any student.
		for (int i = 0; i < students.size(); i++)
		{
			if(id == students.at(i).getFacultyId())
				return success;	// is advising at least one student
		}
		
		return failure;
	}
	else
	{
		cout << "Invalid part of university specified." << endl;
		return failure;
	}
}

/***************************************************************************
 * isCourse                                                                *
 *                                                                         *
 * Checks to see if the passed id is a valid course.                       *
 ***************************************************************************/
bool University::isCourse(long id)
{
	// Checks all courses to see if the id given is among the list
	for (int i = 0; i < courses.size(); i++)
	{
		if(id == courses.at(i).getCRN())
			return success;
	}
	
	return false;
}

/***************************************************************************
 * hasCourse                                                               *
 *                                                                         *
 * Checks to see if the passed department id has any courses.              *
 * Also can check if a faculty member is teaching any courses.			   *
 ***************************************************************************/
bool University::hasCourse(long id, string partOfUni)
{
	// Checks if a department has courses
	if(partOfUni.compare("Department") == 0)
	{
		for (int i = 0; i < courses.size(); i++)
		{
			if(courses.at(i).getDepartID() == id)
				return success;	//There's at least one course in the department
		}
		
		return failure;
	}
	else if(partOfUni.compare("Faculty") == 0)
	{
		// Checks if a faculty is teaching a course
		for(int i = 0; i < courses.size(); i++)
		{
			if(id == courses.at(i).getProfessor())
				return success;	// Faculty is teaching at least one class
		}
		
		return failure;
	}
	else
	{
		// Error checking
		cout << "Invalid part of university specified." << endl;
		return failure;
	}
}

//----------------------------------------------------------------------------
// Method to read and execute a file with commands

/***************************************************************************
 * ProcessTransactionFile                                                  *
 *                                                                         *
 * Using a passed file name, this method reads in strings from the file    *
 * using ifstream. It first imports a command string which then tells it   *
 * which other methods to implement and how many more variables to import. *
 * Returns failure on inability to open file.							   *
 ***************************************************************************/
bool University::ProcessTransactionFile (string fileName)
{
	string command;		// Variable for the commands
	bool success;		// Whether the command was successful or not. Initially
						// Used for debugging 

	// Import stream.
	ifstream fin;
	fin.open(fileName.data());	// Open the file.

	// If the file does not exist.
	if(!fin)
	{
		cout << "This file does not exist." << endl;
		return failure;
	}

	// Loops while there is more to import.
	while(fin >> command)
	{
		printDivider(command);	// Prints a visual divider with the command.
		
		// Compares the command to all the possible commands and then executes
			// the corresponding method. 
		// Declares temporary variables inside of each if statement for further
			// imports.
		if(command == "CreateNewDepartment")
		{
			string depName;
			string departmentLocation;
			long depChairId;
			fin >> depName >> departmentLocation >>depChairId;
			success = CreateNewDepartment(depName, departmentLocation, depChairId);
		}
		else if(command == "RemoveADepartment")
		{
			long depId;
			fin >> depId;
			success = RemoveADepartment(depId);
		}
		else if(command == "CreateNewStudent")
		{
			string name, email, address, dateOfBirth, gender, major;
			int years;
			long advisor;
			fin >> name >> email >> address >> dateOfBirth >> gender 
				>> years >> major >> advisor;
			success = CreateNewStudent(name, email, address, dateOfBirth, 
										gender, years, major, advisor);
		}
		else if (command == "RemoveAStudent")
		{
			long id;
			fin >> id;
			success = RemoveAStudent(id);
		}
		else if(command == "CreateNewCourse")
		{
			string name;
			long depId, taughtBy;
			int maxSeat;
			fin >> name >> depId >> taughtBy >> maxSeat;
			success = CreateNewCourse(name, depId, taughtBy, maxSeat);
		}
		else if(command == "RemoveACourse")
		{
			long CRN;
			fin >> CRN;
			success = RemoveACourse(CRN);
		}
		else if(command == "CreateNewFaculty")
		{
			string name, email, address, dateOfBirth, gender;
			float salary;
			int years;
			long depId;
			fin >> name >> email >> address >> dateOfBirth >> gender >> salary 
				>> years >> depId;
			success = CreateNewFaculty(name, email, address, dateOfBirth, 
										gender, salary, years, depId);
		}
		else if(command == "RemoveAFaculty")
		{
			long id;
			fin >> id;
			success = RemoveAFaculty(id);
		}
		else if(command == "ListCoursesTaughtByFaculty")
		{
			long id;
			fin >> id;
			success = ListCoursesTaughtByFaculty(id);
		}
		else if(command == "ListCoursesTakenByStudent")
		{
			long id;
			fin >> id;
			success = ListCoursesTakenByStudent(id);
		}
		else if(command == "ListFacultiesInDepartment")
		{
			long id;
			fin >> id;
			success = ListFacultiesInDepartment(id);
		}
		else if(command == "ListStudentsOfAFaculty")
		{
			long id;
			fin >> id;
			success = ListStudentsOfAFaculty(id);
		}
		else if(command == "ListCoursesOfADepartment")
		{
			long id;
			fin >> id;
			success = ListCoursesOfADepartment(id);
		}
		else if(command == "AddACourseForAStudent")
		{
			long courseId, studentId;
			fin >> courseId >> studentId;
			success = AddACourseForAStudent(courseId, studentId);
		}
		else if(command == "DropACourseForAStudent")
		{
			long courseId, studentId;
			fin >> courseId >> studentId;
			success = DropACourseForAStudent(courseId, studentId);
		}
		else if(command == "AssignDepartmentChair")
		{
			long facultyId, depId;
			fin >> facultyId >> depId;
			success = AssignDepartmentChair(facultyId, depId);
		}
		else if(command == "AssignInstructorToCourse")
		{
			long facultyId, courseId;
			fin >> facultyId >> courseId;
			success = AssignInstructorToCourse(facultyId, courseId);
		}
		else if(command == "ListDepartments")
		{
			success = ListDepartments();
		}
		else if(command == "ListStudents")
		{
			success = ListStudents();
		}
		else if(command == "ListCourses")
		{
			success = ListCourses();
		}
		else if(command == "ListFaculties")
		{
			success = ListFaculties();
		}
		else
		{
			// If the command is not valid.
			cout << "Not a valid command!" << endl;
			success = failure;
		}
		
		cout << endl;	// Formatting end line.
	}

	return success;

}

//----------------------------------------------------------------------------
// Accessors and helper functions.

/***************************************************************************
 * printDivider                                                            *
 *                                                                         *
 * Prints a divider with the command being executed centered in the middle *
 ***************************************************************************/
void University::printDivider(const string command)
{
	// Calculates the amount of spaces to print after the command
	// Depends on how many spaces there are before the command
	int spacesAfterCommand = 30 - command.size();	
	
	// Calculates the number of dashes needed on each side.
	// Depends on how much space is spent on the command.
	int numDashes = (80 - (30 + spacesAfterCommand))/2;
	
	// Prints dashes
	for(int i = 0; i < numDashes; i++)
		cout << "-";
	
	// Prints the command and the parameter given
	cout << setw(30) << right << command;
	
	// Prints spaces to center the command
	for(int i = 0; i < spacesAfterCommand; i++)
		cout << " ";
		
	// Prints more dashes	
	for(int i = 0; i < numDashes; i++)
		cout << "-";
	
	cout << endl << endl;
}

/***************************************************************************
 * getName                                                                 *
 *                                                                         *
 * Returns the name of the faculty, student, course, or department if      *
 * provided with an id. Utilizes the range given by initialization.        *
 ***************************************************************************/

string University::getName(long id)
{
	// Utilizes only if statements in the case that there are a large amount
	// of one type such that the id numbers overflow into the next separated
	// section (i.e. student ids start going into the 600s.
	
	if(id >= 600)	// Faculty start at id 600.
		for(int i = 0; i < faculty.size(); i++)
			if(id == faculty.at(i).getID())
				return faculty.at(i).getName();
	
	if(id >= 500)	// Students start at id 500
		for(int i = 0; i < students.size(); i++)
			if(id == students.at(i).getID())
				return students.at(i).getName();
	
	if(id >= 200)	// Courses start at CRN 200
		for(int i = 0; i < courses.size(); i++)
			if(id == courses.at(i).getCRN())
				return courses.at(i).getName();
	
	if(id >= 100)	// Departments start at id 100
		for(int i = 0; i < departments.size(); i++)
			if(id == departments.at(i).getDepartmentID())
				return departments.at(i).getName();
			
	// Case if it is not found. Returns the string version of the id passed.
	return longToString(id);
}

/***************************************************************************
 * longToString                                                            *
 *                                                                         *
 * Function only used in the getName function in case the id passed does   *
 * not exist. Most likely unused since only ids that exist will be passed  *
 * due to catching in method calls.										   *
 * [Note]: to_string(long) method exists in c++11 but I could not get the  *
 * compiler to compile in c++11 so this was written as a temporary solution*
 * this method is most likely unused but serves as a catcher just incase   *
 * there was some error in the logic of other methods.					   *
 ***************************************************************************/
string University::longToString(long num)
{
	vector<char> reversed;	// First in, last out. 
	long tempNum = num;		// Saves a local copy of the number
	string stringnum = "";	// String to store the number
	string sign;			// String to hold the sign of the number
	if (num == 0)	// 0 case.
		return "0";
	if(num < 0)	// If the number is negative
	{
		sign = "-";
		tempNum *= -1;
	}
	
	while(tempNum != 0)
	{
		// Pushes each digit into the vector in ascii format.
		reversed.push_back((tempNum % 10) + '0');
		tempNum /= 10;
	}
	
	while(reversed.size() != 0)
	{
		// Appends each digit back in reverse order (since the one's digit was
		// pushed onto the vector)
		reversed.pop_back();
		stringnum.append(&reversed.back());
	}
	
	return stringnum;
}

/***************************************************************************
 * getIndex                                                                *
 *                                                                         *
 * Is passed the id number of a faculty, student, course, or department and* 
 * then searches the vector corresponding to the string passed for a       *
 * matching faculty, student, course, or department. Returns the index.    *
 ***************************************************************************/
int University::getIndex(long id, string partOfUni)
{
	if(partOfUni.compare("Faculty") == 0)	// Check the faculty vector
	{
		for(int i = 0; i < faculty.size(); i++)
		{
			if(id == faculty.at(i).getID())
				return i;
		}

		cout << "No faculty found" << endl;
		return -1;
	}
	else if(partOfUni.compare("Student") == 0)	// Check the student vector
	{
		for(int i = 0; i < students.size(); i++)
		{
			if(id == students.at(i).getID())
				return i;
		}
		cout << "No student found" << endl;
		return -1;
			
	}
	else if(partOfUni.compare("Course") == 0)	// Check the Course vector
	{
		for(int i = 0; i < courses.size(); i++)
		{
			if(id == courses.at(i).getCRN())
				return i;
		}		
		cout << "No Course found" << endl;
		return -1;
		
	}
	else if(partOfUni.compare("Department") == 0)	// Check the department vector
	{
		for(int i = 0; i < departments.size(); i++)
		{
			if(id == departments.at(i).getDepartmentID())
				return i;
		}
		cout << "No Department found" << endl;
		return -1;
	}
	else
	{
		cout << "Could not find that part of university." << endl;
		return -1;	// Error return. 
	}
}
#endif

