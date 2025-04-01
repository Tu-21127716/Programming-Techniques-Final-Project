#pragma once
#include "Term.h"
#include<iostream>

Term::Term(Date begin, Date end, int number)
{
	this->begin = begin;
	this->end = end;
	this->number = number;
}

Term::Term()
{

}

Term& Term::operator=(const Term& k)
{
	this->begin = k.begin;
	this->end = k.end;

	this->number = k.number;
	this->courseList = k.courseList;
	return *this;
}

SinglyLinkedList <Course>*Term:: getCourseList()
{
	return &courseList;
}

Course* Term:: getLastCourse()
{
	return &courseList.getTail()->value;
}

void Term :: addCourse(Course& newCourse)
{
	courseList.append(newCourse);
}
void Term:: addCourse()
{
	string name, courseID;
	int n1, n2, n3, n4;
	Schedule schedule1;
	Schedule schedule2;
	int maxMember, year, curMember;

	cout << "\nEnter course ID: "; getline(cin, courseID);
	cout << "Enter course name: "; getline(cin, name);
	cout << setw(17) << left << "Day of week :" << "|  Session :" << endl;
	cout << setw(17) << left << "[2] Monday" << "|  [1] 7:30 -> 9:10" << endl;
	cout << setw(17) << left << "[3] Tuesday" << "|  [2] 9:30 -> 11:10" << endl;
	cout << setw(17) << left << "[4] Wednesday" << "|  [3] 13:30 -> 15:10" << endl;
	cout << setw(17) << left << "[5] Thursday" << "|  [4] 15:30 -> 17:10" << endl;
	cout << setw(17) << left << "[6] Friday" << "|" << endl;
	cout << setw(17) << left << "[7] Saturday" << "|" << endl;
	cout << "Schedule 1" << endl;
	cout << "Enter day of week of schedule 1 :  ";
	cin >> n1;
	cout << "Enter session of schedule 1 : ";
	cin >> n2;
	cout << "Schedule 2" << endl;
	cout << "Enter day of week of schedule 2 :  ";
	cin >> n3;
	cout << "Enter session of schedule 2 : ";
	cin >> n4;

	while (n1 == n3 && n2 == n4) {
		cout << "Schedule 2 was conflicted to Schedule 1! Please try again.\n";
		cout << "Enter new day of week of schedule 2 : ";
		cin >> n3;
		cout << "Enter the new session of schedule 2 : ";
		cin >> n4;
	}

	cout << "Enter maxMember: "; cin >> maxMember;
	cout << "Enter year: "; cin >> year;
	Course course1(courseID, name, year, maxMember, n1, n2, n3, n4);
	courseList.append(course1);
}
void Term:: printCourseList()
{
	//table of course
	Course::table();
	int serialNum = 1;
	//Node<Course>* pCur1 = List.getHead();
	Course* tmpCourse;
	courseList.getAll(tmpCourse, 1);

	while (courseList.getAll(tmpCourse, 0))
	{
		cout << setw(5) << left << serialNum;
		tmpCourse->showCourseInfo();
		serialNum++;
	}
}
void Term:: removeCourse()
{
	printCourseList();
	int choice;
	bool cont = true;
	char c;
	while (cont)
	{
		cout << "Enter a course you want to remove: "; cin >> choice;
		courseList.erase(choice - 1, 1);
		cout << "Do you want to continue? [Y/N] "; cin >> c;
		if (c == 'Y')
			cont = true;
		else
			cont = false;
	}
	cout << setw(30) << left << "ALL THE COURSES AFTER REMOVING" << endl;
	printCourseList();
}
void Term::exportDay(fstream& out)
{
	out << this->begin.day << "/" << this->begin.month << "/" << this->begin.year << "\n";
	out << this->end.day << "/" << this->end.month << "/" << this->end.year << "\n";
}

void Term::exportInfo(fstream& out)
{
	Course* tmpCourse;
	courseList.getAll(tmpCourse, 1);

	while (courseList.getAll(tmpCourse, 0))
	{
		tmpCourse->exportInfo(out);
	}
}
void Term:: removeACourse(int num)
{
	int temp = 1;
	Course* tmpCourse;
	courseList.getAll(tmpCourse, 1);
	while (temp <= num && courseList.getAll(tmpCourse, 0))
	{
		++temp;
	}
	SinglyLinkedList<Student*>* studentList = tmpCourse->getStudentList();
	Student** tmpStudent;
	studentList->getAll(tmpStudent, 1);
	while (studentList->getAll(tmpStudent, 0))
	{
		SinglyLinkedList<Course*>* classSession = tmpStudent[0]->getenrolledCourses();
		Course** tmpCourse2;
		classSession->getAll(tmpCourse2, 1);
		int step = 0;
		while (classSession->getAll(tmpCourse2, 0))
		{
			if (*tmpCourse2 == tmpCourse)
			{
				classSession->erase(step, 1);
				break;
			}
			step++;
		}
	}
	courseList.erase(num - 1, 1);
}

void Term:: exportCourse(string termNum)
{
	fstream out;
	Course* tmpCourse = nullptr;
	Score* tmpScore = nullptr;
	Student** tmpStudent = nullptr;
	courseList.getAll(tmpCourse, 1);
	//cout << courseList.len();
	//system("pause");
	for (int i = 0; i < courseList.len(); ++i)
	{
		string courseNum = "";

		courseNum = to_string(i + 1);
		out.open("Data/year/term" + termNum + "/course" + courseNum + ".csv", ios::out);
		courseList.getAll(tmpCourse, 0);
		tmpCourse->getStudentList()->getAll(tmpStudent, 1);
		tmpCourse->getScoreList()->getAll(tmpScore, 1);
		while (tmpCourse->getStudentList()->getAll(tmpStudent, 0))
		{
			tmpCourse->getScoreList()->getAll(tmpScore, 0);
			out << "K" << tmpCourse->getYear() / 10 % 10 << tmpCourse->getYear() % 10
				<< ',' << (*tmpStudent)->getId() << ','
				<< tmpScore->getMid() << ','
				<< tmpScore->getFinal() << ','
				<< tmpScore->getBonus() << ','
				<< tmpScore->getTotal() << "\n";
		}
		out.close();
	}
}