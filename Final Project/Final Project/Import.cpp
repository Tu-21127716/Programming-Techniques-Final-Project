#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "SinglyLinkedList.h"
#include "LibraryHeader.h"
#include "USER.h"
#include "Year.h"
#include "Term.h"

using namespace std;

void FirstImport(SinglyLinkedList <Year> &yearList, SinglyLinkedList <Teacher> &teacherList, int &numberOfYear, int &numberOfTerm, string yearFile ="Data/year.txt")
{
	fstream input;
	string academicYear;
	string className;
	input.open(yearFile, ios::in);
	input >> numberOfYear;
	input >> numberOfTerm;
	input.ignore();
	for(int j=0;j<numberOfYear;++j)
	{
		getline(input, academicYear);

		Year tmpYear(academicYear);

		int numberOfClass;
		input >> numberOfClass;
		input.ignore();
		for (int i = 0; i < numberOfClass; ++i)
		{
			getline(input, className);
			Class tmpClass(className);
			tmpClass.importStudentCSV("Data/year/class/" + className + ".csv");
			tmpYear.addClass(tmpClass);
		}
		
		yearList.append(tmpYear);

	}

	fstream inputAcademic;
	inputAcademic.open("Data/AcademicStaff.csv", ios::in);
	Teacher tmp;
	while (!inputAcademic.eof())
	{
		if (!tmp.importTeacherCSV(inputAcademic))
			break;
		teacherList.append(tmp);
		
	}
	inputAcademic.close();
	

}

void importTerm(SinglyLinkedList<Year> &yearList, SinglyLinkedList <Term>& termList, int numberOfTerm)
{
	fstream input;
	Date begin, end;
	string Temp;
	input.open("Data/term.txt", ios::in);
	for (int i = 0; i < numberOfTerm; ++i)
	{
		getline(input, Temp, '/'); // Day
		begin.day = Temp;
		getline(input, Temp, '/'); // Month
		begin.month = Temp;
		getline(input, Temp); // Year
		begin.year = Temp;

		getline(input, Temp, '/'); // Day
		end.day = Temp;
		getline(input, Temp, '/'); // Month
		end.month = Temp;
		getline(input, Temp); // Year
		end.year = Temp;

		Term tmpTerm(begin, end, i+1);

		
		fstream inputCourse;
		string termNum = "";
		termNum += i + 49;
		inputCourse.open("Data/term" + termNum + ".csv", ios::in);
		int j = 0;
		while (!inputCourse.eof())
		{
			++j;
			Course tmpCourse;
			if (tmpCourse.importCourseCSV(inputCourse))
			{
				fstream inputStudent;
				string courseNum = "";
				courseNum = to_string(j);
				inputStudent.open("Data/year/term" + termNum + "/course"+ courseNum +".csv", ios::in);
			
				string y="", s;
				string mid, fin, bon, tot;
				Year* tmpYear = nullptr;
				Student* pTmpStudent = nullptr;
				Score tmpScore;
				Score* pScore ;
				//cout << j << "\n";
				while (!inputStudent.eof())
				{
					//tmpCourse.showCourseInfo();
					getline(inputStudent, y,',');
					if (y == "" || y=="\n") break;
					getline(inputStudent, s,',');

					yearList.getAll(tmpYear, 1);
					while (yearList.getAll(tmpYear, 0))
					{
						if (tmpYear->getAcademicYear() == y)
							break;
						//cout << y << "\n";
					
					}
					pTmpStudent = tmpYear->findStudent(s);
					
					getline(inputStudent, mid, ',');
					getline(inputStudent, fin, ',');
					getline(inputStudent, bon, ',');
					getline(inputStudent, tot);

					Score tmpScore(stof(mid), stof(fin), stof(bon), stof(tot));
				
					//cout << tmpScore.getTotal();

					tmpCourse.getScoreList()->append(tmpScore);
					
					tmpCourse.addStudent(pTmpStudent);
					

					//pTmpStudent->showScoreBoard();
					//pScore->showScoreBoard();

					
					tmpCourse.updateCurMem();
					
					//pTmpStudent->getStudentInfo();
				}
				tmpTerm.addCourse(tmpCourse);
				inputStudent.close();
			}
			else
				break;
		}
		//cout << tmpTerm.getCourseList()->len();
		termList.append(tmpTerm); 
		
		Term* term = termList.getTailAddress();
		Course* course = nullptr;
		term->getCourseList()->getAll(course, 1);
		Student** studentInCourse = nullptr;
		Score* scoreInCourse = nullptr;
		//cout << course;
		
		while (term->getCourseList()->getAll(course, 0))
		{
			course->getScoreList()->getAll(scoreInCourse, 1);
			course->getStudentList()->getAll(studentInCourse, 1);
			while (course->getStudentList()->getAll(studentInCourse, 0))
			{
				course->getScoreList()->getAll(scoreInCourse, 0);
				(*studentInCourse)->addCourse(course);
				(*studentInCourse)->addScore(scoreInCourse);
			}
		}
		
		inputCourse.close();
	}
	input.close();
	//Term newTerm = termList.getTail()->value;
	//newTerm.printCourseList();

}


void Export(SinglyLinkedList <Year>& yearList,int numberOfYear, int numberOfTerm, string yearFile = "Data/year.txt")
{
	fstream out,studentFile;
	out.open(yearFile, ios::out);
	
	string academicYear;
	string className;
	
	out << numberOfYear << "\n";
	out << numberOfTerm << "\n";

	Year* tmpYear = nullptr;
	Class* tmpClass = nullptr;
	Student* tmpStudent = nullptr;
	yearList.getAll(tmpYear, 1);
	
	while (yearList.getAll(tmpYear, 0))
	{
		out << tmpYear->getAcademicYear() << "\n";
		out << tmpYear->getClassList()->len() << "\n";
		SinglyLinkedList <Class>* tmpClassList = tmpYear->getClassList();
		//tmpStudent.getStudentInfo();
		tmpClassList->getAll(tmpClass, 1);
		while (tmpClassList->getAll(tmpClass, 0))
		{
			out << tmpClass->getName() << "\n";
			studentFile.open("Data/year/class/"+ tmpClass->getName() + ".csv", ios::out);
			SinglyLinkedList <Student>* tmpStudentList = tmpClass->getStudentList();
			tmpStudentList->getAll(tmpStudent, 1);
			while (tmpStudentList->getAll(tmpStudent, 0))
			{
				tmpStudent->exportInfo(studentFile);
			}
			studentFile.close();

		}
	}
	out.close();
}


void exportTerm(SinglyLinkedList <Term>& termList, int numberOfTerm)
{
	fstream out;
	Term* tmpTerm;
	string Temp;
	out.open("Data/term.txt", ios::out);
	termList.getAll(tmpTerm, 1);
	for (int i = 0; i < numberOfTerm; ++i)
	{
		termList.getAll(tmpTerm, 0);
		tmpTerm->exportDay(out);
		fstream termData;
		string termNum = "";
		termNum += i + 49;
		termData.open("Data/term" + termNum + ".csv", ios::out);
		tmpTerm->exportInfo(termData);
		tmpTerm->exportCourse(termNum);
	}

	out.close();
}
