#pragma once
#include <iostream>
#include <string>
#include "defineClass.h"
#include "Score.h"

// - Chưa có methods Add Student vào 1 course



struct Schedule
{
	string dayOfWeek;
	string session;
	//constructor

	int exportDay()
	{
		if (dayOfWeek == "Monday")
			return 2;
			
		if (dayOfWeek == "Tuesday")
			return 3;
			
		if (dayOfWeek == "Wednesday")
			return 4;
			
		if (dayOfWeek == "Thursday")
			return 5;
			
		if (dayOfWeek == "Friday")
			return 6;
			
		if (dayOfWeek == "Saturday")
			return 7;

		return 0;
	}

	int exportSession()
	{
		
		if(session== "7:30 -> 9:10")
			return 1;
			
		if (session == "9:30 -> 11:10")
			return 2;
			
		if (session == "13:30 -> 15:10")
			return 3;
			
		if (session == "15:30 -> 17:10")
			return 4;
			
		return 0;
	}

	string setDayOfWeek(int x)
	{
		switch (x)
		{
		case 2:
			dayOfWeek = "Monday";
			break;
		case 3:
			dayOfWeek = "Tuesday";
			break;
		case 4:
			dayOfWeek = "Wednesday";
			break;
		case 5:
			dayOfWeek = "Thursday";
			break;
		case 6:
			dayOfWeek = "Friday";
			break;
		case 7:
			dayOfWeek = "Saturday";
			break;
		default:
			dayOfWeek = "";
			break;
		}
		return dayOfWeek;
	}
	string setSession(int n)
	{
		switch (n)
		{
		case 1:
			session = "7:30 -> 9:10";
			break;
		case 2:
			session = "9:30 -> 11:10";
			break;
		case 3:
			session = "13:30 -> 15:10";
			break;
		case 4:
			session = "15:30 -> 17:10";
			break;
		default:
			break;
		}
		return session;
	}
};

class Course
{
	private:
		string name, courseID;
		Schedule schedule1;
		Schedule schedule2;
		SinglyLinkedList <Student*> studentList;
		SinglyLinkedList <string> teacherList;
		int maxMember, year, curMember;
		SinglyLinkedList <Score> scoreList;

	public:
		Course();
		Course(string courseID, string name, int year, int maxMember, int DOW1, int session1, int DOW2, int session2);
		~Course();
		Course& operator=(const Course& k);
		void showStudentBoard();
		bool editScoreBoard();
		Score* getLastScore();
		bool importCourseCSV(fstream& input);
		int getYear();
		SinglyLinkedList <Student*>* getStudentList();
		SinglyLinkedList<Score>* getScoreList();
		void updateCourseInfo();
		void showCourseInfo();
		// void show
		Schedule getSchedule1();
		Schedule getSchedule2();
		string getCourseID();
		void exportInfo(fstream& out);
		string getName();
		void addStudent(Student* &student);
		Student** getLastStudent();
		void removeStudent(string id);
		void exportStudentList(int no,string file = "Data/Export/");
		void importScore(string file);

		// Show info about this course (not list of student in course)
		static void table()
		{
			cout << setw(5) << left << "No";
			cout << setw(10) << left << "Year";
			cout << setw(15) << left << "Course ID";
			cout << setw(45) << left << "Course name";
			cout << setw(20) << left << "Maximum member";
			cout << setw(20) << left << "Current member";
			cout << setw(10) << right << "Schedule" << endl;
			cout << setfill('-');
			cout << setw(170) << "-" << endl;
			cout << setfill(' ');
		}

		void updateCurMem()
		{
			curMember = studentList.len();

		}
		
};

