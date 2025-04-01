#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "defineClass.h"
#include "Score.h"
#include "USER.h"
#include "Course.h"

Course::Course()
{
	courseID = "";
	name = "";
	schedule1.dayOfWeek = "";
	schedule1.session = "";
	schedule2.dayOfWeek = "";
	schedule2.session = "";
	maxMember = 50;
	curMember = 0;
	year = 0;
}

Course::Course(string courseID, string name, int year, int maxMember, int DOW1, int session1, int DOW2, int session2)
{
	this->courseID = courseID;
	this->name = name;
	this->schedule1.setDayOfWeek(DOW1);
	this->schedule1.setSession(session1);
	this->schedule2.setDayOfWeek(DOW2);
	this->schedule2.setSession(session2);
	this->maxMember = maxMember;
	this->curMember = 0;
	this->year = year;
}
Course::~Course()
{

}

Course& Course::operator=(const Course& k)
{
	this->name = k.name;
	this->courseID = k.courseID;
	this->schedule1 = k.schedule1;
	this->schedule2 = k.schedule2;
	this->teacherList = k.teacherList;
	this->year = k.year;
	this->maxMember = k.maxMember;
	this->curMember = k.curMember;
	this->scoreList = k.scoreList;
	this->studentList = k.studentList;
	return *this;
}

void Course::showStudentBoard()
{
	system("cls");
	//Score board
	Score::tableScore(); // Heading table
	int serialNum = 1;

	Student** tmpStudent;
	studentList.getAll(tmpStudent, 1);

	Score* tmpScore;
	scoreList.getAll(tmpScore, 1);

	while (studentList.getAll(tmpStudent, 0))
	{
		scoreList.getAll(tmpScore, 0);
		cout << setw(5) << left << serialNum;
		(*tmpStudent)->showStudentInfoInBoard();
		tmpScore->showScoreBoard();
		serialNum++;
	}
}

bool Course::editScoreBoard()
{
	system("cls");
	showStudentBoard();
	int choice;
	bool cont = true;
	char c;
	while (cont)
	{
		cout << "Choose the student that you want to update result: ";
		while (cin >> choice && (choice <= 0 || choice > curMember)) {
			cout << "Invalid, please try again : ";
		}

		int count = 0;
		Score* tmpScore;
		scoreList.getAll(tmpScore, 1);

		while (scoreList.getAll(tmpScore, 0))
		{
			count++;
			if (count == choice) {
				tmpScore->editScore();
				break;
			}
		}

		showStudentBoard();
		cout << "\n\nDo you want to continue? [Y/N] "; cin >> c;
		if (c == 'Y')
			cont = true;
		else
			cont = false;
	}
	return 1;
}


bool Course::importCourseCSV(fstream& input)
{
	string Temp;

	getline(input, Temp, ','); // Course ID
	if (Temp == "")
		return 0;
	courseID = Temp;

	getline(input, Temp, ','); // Course Name
	name = Temp;

	int session;

	getline(input, Temp, ','); // Day Of Session 1
	session = stoi(Temp);
	schedule1.setDayOfWeek(session);

	getline(input, Temp, ','); // Time Of Session 1
	session = stoi(Temp);
	schedule1.setSession(session);

	getline(input, Temp, ','); // Day Of Session 2
	session = stoi(Temp);
	schedule2.setDayOfWeek(session);

	getline(input, Temp, ','); // Time Of Session 2
	session = stoi(Temp);
	schedule2.setSession(session);

	getline(input, Temp); // Year
	session = stoi(Temp);
	year = session;

	return 1;
}

int Course::getYear()
{
	return year;
}

string Course::getName()
{
	return name;
}

SinglyLinkedList <Student*>* Course::getStudentList()
{
	return &studentList;
}

SinglyLinkedList<Score>* Course::getScoreList()
{
	return &scoreList;
}

void Course::updateCourseInfo()
{

	cout << "[1] Change Course ID" << endl;
	cout << "[2] Change Course Name" << endl;
	cout << "[3] Change Schedule" << endl;
	cout << "[4] Change Max Members" << endl;
	cout << "[5] Change Year" << endl;
	int key;
	bool cont = 1;
	while (cont)
	{
		cout << "Which infomation you want to change ? (Enter number [1->5]): ";
		cin >> key;
		cin.ignore();
		switch (key)
		{
		case 1:
			cout << "\nYour old course ID is " << this->courseID;
			cout << "\nEnter your new course ID: ";
			getline(cin, courseID);
			cout << "Successfully updated !\n";
			break;
		case 2:
			cout << "\nYour old course name is " << this->name;
			cout << "\nEnter your new course name: ";
			getline(cin, name);
			break;
		case 3:
			cout << "\n-------------------------------------\n";
			cout << setw(17) << left << "Day of week :" << "|  Session :" << endl;
			cout << setw(17) << left << "[2] Monday" << "|  [1] 7:30 -> 9:10" << endl;
			cout << setw(17) << left << "[3] Tuesday" << "|  [2] 9:30 -> 11:10" << endl;
			cout << setw(17) << left << "[4] Wednesday" << "|  [3] 13:30 -> 15:10" << endl;
			cout << setw(17) << left << "[5] Thursday" << "|  [4] 15:30 -> 17:10" << endl;
			cout << setw(17) << left << "[6] Friday" << "|" << endl;
			cout << setw(17) << left << "[7] Saturday" << "|" << endl;
			cout << "-------------------------------------\n";

			int temp;
			cout << "\nEnter the new day of week of schedule 1 (Just number. For example: Monday --> 2): ";
			cin >> temp;
			this->schedule1.setDayOfWeek(temp);
			cout << "Enter the new session of schedule 1 (Just number. For example: (7:30)--> 1): ";
			cin >> temp;
			this->schedule1.setSession(temp);

			cout << "\nEnter the new day of week of schedule 2 : ";
			cin >> temp;
			this->schedule2.setDayOfWeek(temp);
			cout << "Enter the new session of schedule 2 : ";
			cin >> temp;
			this->schedule2.setSession(temp);

			while (schedule1.dayOfWeek == schedule2.dayOfWeek && schedule1.session == schedule2.session) {
				cout << "Schedule 2 was conflicted to Schedule 1! Please try again.\n";
				cout << "Enter new day of week of schedule 2 : ";
				cin >> temp;
				this->schedule2.setDayOfWeek(temp);
				cout << "Enter new session of schedule 2 : ";
				cin >> temp;
				this->schedule2.setSession(temp);
			}
			cout << "Successfully updated !\n";
			break;
		case 4:
			cout << "\nEnter the new maximum members: ";
			cin >> this->maxMember;
			cout << "Successfully updated !\n";
			break;
		case 5:
			cout << "\nEnter the new year: ";
			cin >> this->year;
			cout << "Successfully updated !\n";
			break;
		default:
			cout << "Invalid choice !\n";
			break;
		}
		char answer;
		cout << "Do you want to continue (y/n): ";
		cin >> answer;
		if (answer != 'y' && answer != 'Y')
			cont = 0;

	}
	
}

// Show danh sách Khóa học trong 1 Term (Term.h)
void Course::showCourseInfo()
{
	cout << setw(10) << left << this->year;
	cout << setw(15) << left << this->courseID;
	cout << setw(45) << left << this->name;
	cout << setw(20) << left << maxMember;
	cout << setw(20) << left << curMember;
	cout << setw(10) << left << this->schedule1.dayOfWeek;
	cout << setw(18) << left << schedule1.session;
	cout << setw(10) << left << this->schedule2.dayOfWeek;
	cout << setw(18) << left << schedule2.session << "\n";
}

// Show 1 phần thông tin khóa học trong bảng điểm cá nhân học sinh (User.h)
// void Course::s

Schedule Course::getSchedule1()
{
	return schedule1;
}
Schedule Course::getSchedule2()
{
	return schedule2;
}
string Course::getCourseID()
{
	return courseID;
}

Score* Course::getLastScore()
{
	return &(scoreList.getTail()->value);
}

Student** Course::getLastStudent()
{
	return &(studentList.getTail()->value);
}

void Course::addStudent(Student* &student)
{
	studentList.append(student);
}

void Course::exportInfo(fstream& out)
{
	out << courseID << ","
		<< name << ","
		<< schedule1.exportDay() << ","
		<< schedule1.exportSession() << ","
		<< schedule2.exportDay() << ","
		<< schedule2.exportSession() << ","
		<< year << ","
		<< maxMember << "\n";

}

void Course::removeStudent(string id)
{
	Student** tmp;
	studentList.getAll(tmp, 1);
	int i = 0;
	while (studentList.getAll(tmp, 0))
	{
		if ((*tmp)->getId() == id)
			break;
	}
	studentList.erase(i, 1);
	scoreList.erase(i, 1);

}

void Course::exportStudentList(int i, string file)
{
	file += name +" " + to_string(i) + ".csv";
	Student** tmpStudent = nullptr;
	studentList.getAll(tmpStudent, 1);
	fstream out;
	out.open(file, ios::out);
	out << "No,ID,First Name,Last Name,Gender,Date Of Birth\n";
	while (studentList.getAll(tmpStudent, 0))
	{
		(*tmpStudent)->exportInfo(out);
	}	
}

void Course::importScore(string file)
{
	fstream f;
	f.open(file, ios::in);
	//No, Student ID, Student Full Name, Total Mark, Final Mark, Midterm Mark, Other Mark.
	string tmp, id;
	string total, fin, mid, other;
	Student** student = nullptr;
	Score* score = nullptr;
	while (!f.eof())
	{
		getline(f, tmp, ',');
		getline(f, id, ','); 
		studentList.getAll(student, 1);
		scoreList.getAll(score, 1);
		scoreList.getAll(score, 0);
		getline(f, tmp, ',');
		getline(f, tmp, ',');
		while (studentList.getAll(student, 0))
		{
			scoreList.getAll(score, 0);
			if ((*student)->getId() == id)
			{
				getline(f, total, ',');
				getline(f, fin, ',');
				getline(f, mid, ',');
				getline(f, other);
				Score newScore(stof(mid), stof(fin), stof(other), stof(total));
				score->editScore(newScore);
				break;
			}
		}
	}
	system("pause");

}