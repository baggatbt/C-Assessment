// wguAssessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "roster.h"

int main()
{
    //Strings to parse
    const string studentData[] =

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Brandon,Baggatta,bbaggat@wgu.edu,26,22,30,32,SOFTWARE"
    };

    cout << "Scripting and Programming - Applications - C867 " << "C++ " << "#001251176 " << "Brandon Baggatta" << std::endl;

    const int numStudents = 5;
    Roster classRoster; //creates using default parameterless constructor

    for (int i = 0; i < numStudents; i++)classRoster.parse(studentData[i]);
    cout << "Displaying all students" << std::endl;
    classRoster.printAll();
    cout << std::endl;

    cout << "Displaying invalid email addresses: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    cout << "Displaying average days in the course: " << std::endl;
    classRoster.printAverageDaysInCourse("student ID");

    for (int i = 0; i < 3; i++)
    {
        cout << "Displaying degree program: " << degreeProgramStrings[i] << std::endl;
        classRoster.printByDegreeProgram((DegreeProgram)i);
    }

   

    cout << "Removing student with ID A3: " << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    cout << "Removing student with ID A3: " << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    classRoster.~Roster();
    system("pause");
    return 0;
}






