#include <iostream>
#include <string>
#include <conio.h>
#include "SinglyLinkedList.h"
#include "LibraryHeader.h"
#include "USER.h"
#include "Course.h";
#include "Year.h"
#include "Class.h"

void enrollCourse(Term* defaultTerm, int numberOfTerm, Student*& student, Year* yearOfStudent)
{
	Course* tmpCourse = nullptr;
	defaultTerm->getCourseList()->getAll(tmpCourse, 1);
	int i = 0;
	Course::table();
	while(defaultTerm->getCourseList()->getAll(tmpCourse, 0))
	{
		string courseYear = "K";
		courseYear += tmpCourse->getYear() / 10 % 10 + 48;
		courseYear += tmpCourse->getYear() % 10 + 48;
		if (courseYear == yearOfStudent->getAcademicYear())
		{
			cout << setw(5) << left << ++i;
			tmpCourse->showCourseInfo();
		}
	}

	int choice;
	bool cont = 1;
	while(cont)
	{
		cout << "Your choice: ";
		while (cin >> choice && (choice <1 || choice >i))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid, please try again: ";
		}
		int i = 0;
		defaultTerm->getCourseList()->getAll(tmpCourse, 1);
		while (i!=choice&&defaultTerm->getCourseList()->getAll(tmpCourse, 0))
		{
			string courseYear = "K";
			courseYear += tmpCourse->getYear() / 10 % 10 + 48;
			courseYear += tmpCourse->getYear() % 10 + 48;
			if (courseYear == yearOfStudent->getAcademicYear())
			{
				++i;
			}
		}
		student->courseRegistration(tmpCourse);
		tmpCourse->updateCurMem();
		cout << "Do you want to continue (y/n):";
		char answer;
		cin >> answer;
		if (answer != 'y' && answer != 'Y')
			cont = 0;
	}
	

	system("pause");
}
