#include "roster.h"
void Roster::parse(string studentData)
{
	

	int rhs = studentData.find(",");
	string stuID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string fName = studentData.substr(lhs, rhs - lhs); /* first name*/

	lhs = rhs + 1; /*keep going*/
	rhs = studentData.find(",", lhs);
	string lName = studentData.substr(lhs, rhs - lhs); /*last name*/


	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string eAddress = studentData.substr(lhs, rhs - lhs); /*email address*/

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stod(studentData.substr(lhs, rhs - lhs)); /*age*/

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stod(studentData.substr(lhs, rhs - lhs)); /*Total days in course 1*/

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stod(studentData.substr(lhs, rhs - lhs)); /*Total days in course 2*/

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stod(studentData.substr(lhs, rhs - lhs)); /*Total days in course 3*/

	lhs = rhs + 1;
	string degree = studentData.substr(lhs);
	DegreeProgram dp = SOFTWARE;
	if (degree.compare("SECURITY") == 0) {
		dp = DegreeProgram::SECURITY;
	}
	else if (degree.compare("NETWORK") == 0) {
		dp = DegreeProgram::NETWORK;
	}
	

	
	
	add(stuID, fName, lName, eAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dp);



	
}

void Roster::add(string studentID, 
	string firstName, string lastName, 
	string emailAddress, 
	int age, int daysInCourse1, 
	int daysInCourse2, 
	int daysInCourse3, 
	DegreeProgram degreeProgram
)

{
	
	int darr[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, darr, degreeProgram);

}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string badEmails = (classRosterArray[i]->getEmailAddress());
		if (badEmails.find('@') == string::npos || (badEmails.find('.') == string::npos || (badEmails.find(' ')) != string::npos))
		{
			any = true;
				cout << classRosterArray[i]->getStudentID() << " " << badEmails << ":" <<  std::endl;
		}
	}
	if (!any) cout << "All emails are valid" << std::endl;
}


void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		cout << classRosterArray[i]->getStudentID() << ": ";
		cout << (classRosterArray[i]->getDaysInCourse()[0]
			+ classRosterArray[i]->getDaysInCourse()[1]
			+ classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << std::endl;
		}
	cout << std::endl;
}

void Roster::remove(string studentID) /* item to be removed comes in as parameter*/
{
	bool success = false; /*assume its not here*/
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true; /*found*/
			if (i < numClass - 1)
			{
				Student* temp = classRosterArray[i]; /* swap with last student*/
				classRosterArray[i] = classRosterArray[numClass - 1];
				classRosterArray[numClass - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << " removed." << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster()
{
	
	for (int i = 0; i < numClass; i++)
	{
		
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}

	
}