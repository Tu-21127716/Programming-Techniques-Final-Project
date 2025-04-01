#include <iostream>
#include <string>
#include <conio.h>
#include "SinglyLinkedList.h"
#include "LibraryHeader.h"
#include "USER.h"
#include "Course.h";
#include "Year.h"
#include "Class.h"

//function

void importCourseStudent(Term* defaultTerm)
{
	Course* tmpCourse = nullptr;
	system("cls");
	int i = 0;
	defaultTerm->getCourseList()->getAll(tmpCourse, 1);
	Course::table();
	while (defaultTerm->getCourseList()->getAll(tmpCourse, 0))
	{
		cout << setw(5) << left << i + 1;
		tmpCourse->showCourseInfo();
		++i;
	}
	int choice2 = 0;
	cout << "\n\nYour choice: ";
	while (cin >> choice2 && (choice2 < 1 || choice2 > i))    //choose course
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid, please try again: ";
	}

	defaultTerm->getCourseList()->getAll(tmpCourse, 1);

	i = 0;
	for (; i < choice2; ++i)
	{
		defaultTerm->getCourseList()->getAll(tmpCourse, 0);
	}
	string s;
	
	cout << "Input the address of file in your computer: ";
	cin >> s;
	for (int j = 0; j < s.length(); ++j)
	{
		if (s[j] == '\\')
			s[j] = '/';
	}
	tmpCourse->importScore(s);
}

void exportCourseStudent(Term* defaultTerm)
{
	Course* tmpCourse = nullptr;
	system("cls");
	int i = 0;
	defaultTerm->getCourseList()->getAll(tmpCourse, 1);
	Course::table();
	while (defaultTerm->getCourseList()->getAll(tmpCourse, 0))
	{
		cout << setw(5) << left << i + 1;
		tmpCourse->showCourseInfo();
		++i;
	}
	int choice2 = 0;
	cout << "\n\nYour choice: ";
	while (cin >> choice2 && (choice2 < 1 || choice2 > i))    //choose course
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid, please try again: ";
	}

	defaultTerm->getCourseList()->getAll(tmpCourse, 1);

	i = 0;
	for (; i < choice2; ++i)
	{
		defaultTerm->getCourseList()->getAll(tmpCourse, 0);
	}

	tmpCourse->exportStudentList(i);
	cout << "Export Successfully At Data/Export/\n";
	system("pause");
}


void viewCourseStudent(SinglyLinkedList <Term>& termList, int numberOfTerm)
{

	system("cls");
	int choice = 0;
	Course* tmpCourse = nullptr;
	Term* tmpTerm = nullptr;

	cout << "Term\n";
	for (int i = 0; i < numberOfTerm; ++i)
		cout << setw(5) << left << i + 1;
	cout << "Choose Term has the Course that you want to view: ";           //choose term
	while (cin >> choice && (choice < 1 || choice >numberOfTerm))
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid, please try again: ";
	}

	termList.getAll(tmpTerm, 1);
	for (int i = 0; i < choice; ++i)
		termList.getAll(tmpTerm, 0);   //get the Term that the user has chosen


	system("cls");
	int i = 0;
	tmpTerm->getCourseList()->getAll(tmpCourse, 1);
	Course::table();
	while (tmpTerm->getCourseList()->getAll(tmpCourse, 0))
	{
		cout << setw(5) << left << i + 1;
		tmpCourse->showCourseInfo();
		++i;
	}
	int choice2 = 0;
	cout << "\n\nChoose Course you want to view list of students: ";
	while (cin >> choice2 && (choice2 < 1 || choice2 > i))    //choose course
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid, please try again: ";
	}

	tmpTerm->getCourseList()->getAll(tmpCourse, 1);
	for (int i = 0; i < choice2; ++i)
	{
		tmpTerm->getCourseList()->getAll(tmpCourse, 0);
	}

	system("cls");
	tmpCourse->showStudentBoard();
	system("pause");
}


void updateCourse(SinglyLinkedList <Term>& termList, int numberOfTerm)
{

	system("cls");
	int choice = 0;
	Course* tmpCourse = nullptr;
	Term* tmpTerm = nullptr;

	cout << "Term \n";
	for (int i = 0; i < numberOfTerm; ++i)
		cout << setw(5) << left << i + 1;
	cout << "Choose Term has the Course you want to update information: ";           //choose term
	while (cin >> choice && (choice < 1 || choice >numberOfTerm))
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid, please try again: ";
	}
	termList.getAll(tmpTerm, 1);
	for (int i = 0; i < choice; ++i)
		termList.getAll(tmpTerm, 0);   //get the Term that the user has chosen


	system("cls");
	int i = 0;
	tmpTerm->getCourseList()->getAll(tmpCourse, 1);
	Course::table();
	while (tmpTerm->getCourseList()->getAll(tmpCourse, 0))
	{
		cout << setw(5) << left << i + 1;
		tmpCourse->showCourseInfo();
		++i;
	}
	int choice2 = 0;
	cout << "\n\nChoose Course that you want to update information: ";
	while (cin >> choice2 && (choice2 < 1 || choice2 > i))    //choose course
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid, please try again: ";
	}

	tmpTerm->getCourseList()->getAll(tmpCourse, 1);
	for (int i = 0; i < choice2; ++i)
	{
		tmpTerm->getCourseList()->getAll(tmpCourse, 0);
	}

	system("cls");
	tmpCourse->updateCourseInfo();

	system("pause");
}

void updateStudentResult(SinglyLinkedList <Term>& termList, int numberOfTerm)
{
	system("cls");
	int choice = 0;
	Course* tmpCourse = nullptr;
	Term* tmpTerm = nullptr;

	cout << "Term\n";
	for (int i = 0; i < numberOfTerm; ++i)
		cout << setw(5) << left << i + 1 << "\n";
	cout << "Choose Term has the Course you want to update: ";           //choose term
	while (cin >> choice && (choice < 1 || choice >numberOfTerm))
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid, please try again: ";
	}
	termList.getAll(tmpTerm, 1);
	for (int i = 0; i < choice; ++i)
		termList.getAll(tmpTerm, 0);   //get the Term that the user has chosen
	system("cls");
	int i = 0;
	tmpTerm->getCourseList()->getAll(tmpCourse, 1);
	Course::table();
	while (tmpTerm->getCourseList()->getAll(tmpCourse, 0))
	{
		cout << setw(5) << left << i + 1;
		tmpCourse->showCourseInfo();
		++i;
	}
	int choice2 = 0;
	cout << "\n\nChoose Course has the student you want to update: ";
	while (cin >> choice2 && (choice2 < 1 || choice2 > i))    //choose course
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid, please try again: ";
	}

	tmpTerm->getCourseList()->getAll(tmpCourse, 1);
	for (int i = 0; i < choice2; ++i)
	{
		tmpTerm->getCourseList()->getAll(tmpCourse, 0);
	}

	tmpCourse->editScoreBoard();


	system("pause");
}

void viewCourse(SinglyLinkedList <Term>& termList, int numberOfTerm)
{
	system("cls");
	Term* tmpTerm;
	Course* tmpCourse;
	termList.getAll(tmpTerm, 1);
	while (termList.getAll(tmpTerm, 0))
	{
		tmpTerm->printCourseList();
	}
	system("pause");
}


void createNewTerm(SinglyLinkedList <Term>& termList, int& numberOfYear, int& numberOfTerm)
{
	system("cls");
	if (numberOfTerm == 3)
	{
		cout << "The current term is 3. Can not create more term\n";
		system("pause");
		return;
	}

	cout << "The next term is term number " << numberOfTerm + 1 << endl;
	cout << "Do you want to create? (y/n): ";

	char answer;
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		Date begin, end;
		string date;
		string tmp = "";
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Input the begin date(dd/mm/yyyy): ";
		getline(cin, date);
		int i = 0;

		for (; i < date.length() && date[i] != '/'; ++i)
			tmp += date[i];
		++i;
		begin.day = tmp;
		tmp = "";
		for (; i < date.length() && date[i] != '/'; ++i)
			tmp += date[i];
		++i;
		begin.month = tmp;
		tmp = "";
		for (; i < date.length(); ++i)
			tmp += date[i];
		++i;
		begin.year = tmp;
		tmp = "";

		i = 0;
		cout << "Input the end date(dd/mm/yyyy): ";
		getline(cin, date);
		for (; i < date.length() && date[i] != '/'; ++i)
			tmp += date[i];
		++i;
		end.day = tmp;
		tmp = "";
		for (; i < date.length() && date[i] != '/'; ++i)
			tmp += date[i];
		++i;
		end.month = tmp;
		tmp = "";
		for (; i < date.length(); ++i)
			tmp += date[i];
		++i;
		end.year = tmp;
		tmp = "";


		Term tmpTerm(begin, end, numberOfTerm + 1);

		++numberOfTerm;
		termList.append(tmpTerm);
	}
}

void createNewYear(SinglyLinkedList <Year>& yearList, int& numberOfYear)
{
	system("cls");
	string thisYear = yearList.getTail()->value.getAcademicYear();
	int year1;
	year1 = 2000 + (thisYear[1] - 48) * 10 + thisYear[2] - 48;

	thisYear[1] = year1 / 10 % 10 + 48;
	thisYear[2] = year1 % 10 + 49;

	cout << "The next year is for " << thisYear << " (" << year1 + 1 << "-" << year1 + 2 << ")" << endl;
	cout << "Do you want to create? (y/n): ";
	char answer;
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		++numberOfYear;
		Year newYear(thisYear);
		yearList.append(newYear);
		cout << "Create successfully\n";
	}
	else
		cout << "Cancelled\n";
	system("pause");
}

void createNewClass(SinglyLinkedList <Year>& yearList, int numberOfYear)
{
	system("cls");
	Year** tmpYearList = new Year * [numberOfYear];
	Year* tmpYear = nullptr;
	Class* tmpClass = nullptr;
	int i = 0;

	yearList.getAll(tmpYear, 1);
	while (yearList.getAll(tmpYear, 0))
	{
		tmpYearList[i] = tmpYear;
		cout << "[" << i + 1 << "]: " << tmpYear->getAcademicYear() << "\n";
		++i;
	}

	int choice = 0;
	string className = "";
	cout << "Which year:";
	while (cin >> choice && (choice <1 || choice>i))
	{
		cout << "Invalid choice, please try again: ";
	}
	--choice;
	cout << "Class name: ";
	cin >> className;
	Class newClass(className);
	tmpYearList[choice]->getClassList()->append(newClass);
	delete[] tmpYearList;
}

void addStudentToClass(SinglyLinkedList <Year>& yearList, int numberOfYear)
{
	system("cls");
	int select = 0;
	cout << "[1] Add students with a csv file\n";
	cout << "[2] Add students manually\n";
	cout << "Your choice: ";
	while (cin >> select && (select < 1 || select>2))
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid, please try again: ";
	}

	system("cls");
	Year** tmpYearList = new Year * [numberOfYear];
	Year* tmpYear = nullptr;
	int i = 0;

	yearList.getAll(tmpYear, 1);
	while (yearList.getAll(tmpYear, 0))
	{
		tmpYearList[i] = tmpYear;
		cout << "[" << i + 1 << "]: " << tmpYear->getAcademicYear() << "\n";
		++i;
	}

	int choice = 0;

	cout << "Which year: ";
	while (cin >> choice && (choice <1 || choice>i))
	{
		cout << "Invalid choice, please try again: ";
	}
	--choice;
	system("cls");
	Class** tmpClassList = new Class * [tmpYearList[choice]->numberOfClass()];
	Class* tmpClass = nullptr;

	i = 0;

	tmpYearList[choice]->getClassList()->getAll(tmpClass, 1);
	while (tmpYearList[choice]->getClassList()->getAll(tmpClass, 0))
	{
		tmpClassList[i] = tmpClass;
		cout << "[" << i + 1 << "]: " << tmpClass->getName() << "\n";
		++i;
	}

	choice = 0;
	string file = "";
	cout << "Which Class: ";
	while (cin >> choice && (choice <1 || choice>i))
	{
		cout << "Invalid choice, please try again: ";
	}
	tmpClass = tmpClassList[choice - 1];
	if (select == 1)
	{
		cout << "Address of the file in your computer: ";
		cin >> file;
		for (int j = 0; j < file.length(); ++j)
		{
			if (file[j] == '\\')
				file[j] = '/';
		}
		tmpClass->addStudentCSV(file);
		cout << "Add successfully\n";
		system("pause");
	}
	if (select == 2)
	{
		while (1)
		{
			system("cls");
			Student newStudent;
			newStudent.setStudentInfo(tmpClass->classSize()+1);
			tmpClass->addStudent(newStudent);
			cout << "Add successfully\n";
			char answer;
			cout << "Do you want to add more (y/n): ";
			cin >> answer;
			if (answer != 'y' && answer != 'Y')
				break;
		}
		
	}

	delete[] tmpClassList;
	delete[] tmpYearList;

}


void viewListOfClass(SinglyLinkedList <Year>& yearList, int numberOfYear)
{
	system("cls");
	Year** tmpYearList = new Year * [numberOfYear];
	Year* tmpYear = nullptr;
	Class* tmpClass = nullptr;
	int i = 0;

	yearList.getAll(tmpYear, 1);
	while (yearList.getAll(tmpYear, 0))
	{
		cout << tmpYear->getAcademicYear() << " classes: " << "\n";
		SinglyLinkedList <Class>* tmpClassList = tmpYear->getClassList();
		//tmpStudent.getStudentInfo();
		tmpClassList->getAll(tmpClass, 1);
		while (tmpClassList->getAll(tmpClass, 0))
		{
			cout << tmpClass->getName() << "\n";
		}
		cout << "\n\n";
	}
	delete[] tmpYearList;
	
	system("pause");
}



void viewStudentOfAClass(SinglyLinkedList <Year>& yearList, int numberOfYear)
{
	system("cls");
	Year** tmpYearList = new Year * [numberOfYear];
	Year* tmpYear = nullptr;
	int i = 0;

	yearList.getAll(tmpYear, 1);
	while (yearList.getAll(tmpYear, 0))
	{
		tmpYearList[i] = tmpYear;
		cout << "[" << i + 1 << "]: " << tmpYear->getAcademicYear() << "\n";
		++i;
	}

	int choice = 0;

	cout << "Which year:";
	while (cin >> choice && (choice <1 || choice>i))
	{
		cout << "Invalid choice, please try again: ";
	}
	--choice;
	system("cls");
	Class** tmpClassList = new Class * [tmpYearList[choice]->numberOfClass()];
	Class* tmpClass = nullptr;

	i = 0;

	tmpYearList[choice]->getClassList()->getAll(tmpClass, 1);
	while (tmpYearList[choice]->getClassList()->getAll(tmpClass, 0))
	{
		tmpClassList[i] = tmpClass;
		cout << "[" << i + 1 << "]: " << tmpClass->getName() << "\n";
		++i;
	}

	choice = 0;
	string file = "";
	cout << "Which Class:";
	while (cin >> choice && (choice <1 || choice>i))
	{
		cout << "Invalid choice, please try again: ";
	}
	--choice;
	Student* tmpStudent;
	system("cls");
	tmpClassList[choice]->getStudentList()->getAll(tmpStudent, 1);
	Student::studentInfoTable();
	
	while (tmpClassList[choice]->getStudentList()->getAll(tmpStudent, 0))
	{
		tmpStudent->getStudentInfo();
	}
	delete[] tmpYearList;
	delete[] tmpClassList;
	system("pause");
}

