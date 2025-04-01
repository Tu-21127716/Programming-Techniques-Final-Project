#include <iostream>
#include <string>
#include <conio.h>
#include "SinglyLinkedList.h"
#include "LibraryHeader.h"
#include "USER.h"
#include "Course.h";
#include "Year.h"
#include "Class.h"

using namespace std;

int dem = 0;
void Login(SinglyLinkedList <Year> &yearList, SinglyLinkedList <Teacher> &teacherList,SinglyLinkedList<Term> &termList, int &numberOfYear, int &numberOfTerm, bool& RegistrationSession, bool &ShowScoreBoard)
{
	system("cls");
	bool retry = 1;
	do 
	{
		retry = 1;
		cout << "LOGIN\n";
		cout << "(username = 0 to exit)\n";
		string userName, password;
		cout << "UserName: ";
		cin >> userName;
		if (userName == "0")
			return;
		cin.clear();
		cin.ignore(1000, '\n');
		
		//cin.ignore(1000, '\n');
		cout << "Password: ";
		cin >>  password ;

		cin.clear();
		cin.ignore(1000, '\n');

		Teacher* tmpTeacher = nullptr;
		Year* tmpYear = nullptr;
		Class* tmpClass = nullptr;
		Student* tmpStudent = nullptr;

		yearList.getAll(tmpYear, 1);

		
		while (yearList.getAll(tmpYear, 0))
		{
			SinglyLinkedList <Class>* tmpClassList = tmpYear->getClassList();
			//tmpStudent.getStudentInfo();
			tmpClassList->getAll(tmpClass, 1);
			while (tmpClassList->getAll(tmpClass, 0))
			{
				SinglyLinkedList <Student>* tmpStudentList = tmpClass->getStudentList();
				tmpStudentList->getAll(tmpStudent, 1);
				while (tmpStudentList->getAll(tmpStudent, 0))
				{
					/*cout << tmpClass->name << "\n";
					tmpStudent->getStudentInfo();
					cout << "\n";*/
					//tmpStudent->getStudentInfo();
					if (tmpStudent->checkAccount(userName, password))
					{
					
						retry = 0;
						yearList.getAll(tmpYear, 1);
						tmpClassList->getAll(tmpClass, 1);
						tmpStudentList->getAll(tmpStudent, 1);
						studentMenu(tmpStudent, termList, numberOfYear, numberOfTerm, tmpYear, RegistrationSession, ShowScoreBoard);

						goto finishLogin;
					}
				}
				
			}
		}

		
		while (teacherList.getAll(tmpTeacher, 0))
		{
			//tmpStudent.getStudentInfo();
			if (tmpTeacher->checkAccount(userName, password))
			{
				system("cls");
				retry = 0;
				teacherList.getAll(tmpTeacher, 1);
				teacherMenu(tmpTeacher, yearList, termList, numberOfYear, numberOfTerm, RegistrationSession, ShowScoreBoard);
				goto finishLogin;
			}
		}
		//system("pause");
		finishLogin:;
		if (retry == 1)
		{
			system("cls");
			cout << "Invalid username or password, please try again.\n";
		}
		
	} while (1);

}

void studentMenu(Student* studentLogin, SinglyLinkedList <Term>& termList, int& numberOfYear, int& numberOfTerm, Year* yearOfStudent,bool RegistrationSession, bool ShowScoreBoard)
{
	int student_ans;

	Term* defaultTerm;
	termList.getAll(defaultTerm, 1);
	for (int i = 0; i < numberOfTerm; ++i)
		termList.getAll(defaultTerm, 0);

	while (1)
	{
		system("cls");
		cout << string(6,'\n');
		cout << string(20,' ') << string(25,'=') << " STUDENT MENU " << string(25,'=') << endl;
		cout << string(20,' ') << "#                                                              #" << endl;
		cout << string(20,' ') << "#        ------------ Information methods -------------        #" << endl;
		cout << string(20,' ') << "#            [1] View information                              #" << endl;
		cout << string(20,' ') << "#            [2] Change password                               #" << endl;
		cout << string(20,' ') << "#                                                              #" << endl;
		cout << string(20,' ') << "#        -------------- Managing methods --------------        #" << endl;
		cout << string(20,' ') << "#            [3] Enroll in courses                             #" << endl;
		cout << string(20,' ') << "#            [4] View list of enrolled courses                 #" << endl;
		cout << string(20,' ') << "#            [5] View score board                              #" << endl;
		cout << string(20,' ') << "#            [6] Remove course from the enrolled list          #" << endl;
		cout << string(20,' ') << "#            [7] Log out                                       #" << endl;
		cout << string(20,' ') << string(64,'=') << endl << endl;
		cout << string(20,' ') << string(17,' ') << "Your choice: ";
		
		cin >> student_ans;
		cin.clear();
		cin.ignore(1000, '\n');
		
		switch (student_ans)
		{
			case 1:
			{
				system("cls");
				Student::studentInfoTable();
				studentLogin->getStudentInfo();
				system("pause");
				break;
			}
			case 2:
			{
				studentLogin->changePassword();
				break;
			}
			case 3:
			{
				system("cls");
				if (!RegistrationSession)
				{
					cout << "It is not the time to enroll course !!!\n";
					system("pause");
				}
					
				else
					enrollCourse(defaultTerm, numberOfTerm, studentLogin, yearOfStudent);
				
				break;
			}
			case 4:
			{
				system("cls");
				studentLogin->showCourseEnrolled();
				system("pause");
				break;
			}
			case 5:
			{
				system("cls");
				if (!RegistrationSession)
					cout << "It is not the time to view your score board !!!\n";
				else
					studentLogin->showScoreBoard();
				system("pause");
				break;
			}
			case 6:
			{
				system("cls");
				if (!RegistrationSession)
				{
					cout << "It is not the time to remove course !!!\n";
					system("pause");
				}
					
				else 
				{
					system("cls");
					while (1)
					{
						studentLogin->showCourseEnrolled();
						if (studentLogin->getenrolledCourses()->len() == 0)
						{
							cout << "No course enrolled !";
							system("pause");
							break;
						}

						int choice;
						cout << "Number of course that want to remove: ";
						cin >> choice;
						studentLogin->removeACourseInEnrolledList(choice);
						char answer;
						cout << "Do you want to continue (y/n): ";
						cin >> answer;
						if (answer != 'y' && answer != 'Y')
							break;
					}
					
				}
				break;
				
			}
			case 7:
			{
				system("cls");
				return;
			}
			default:
			{
				cout << "Invalid choice, please try again: " << endl;
				break;
			}

		}
	}
}
			
		

void teacherMenu(Teacher* teacherLogin, SinglyLinkedList <Year> &yearList,SinglyLinkedList <Term> &termList , int& numberOfYear, int& numberOfTerm, bool &RegistrationSession, bool &ShowScoreBoard)
{
	int answer = 0;

	Term* defaultTerm;
	termList.getAll(defaultTerm, 1);
	for (int i = 0; i < numberOfTerm; ++i)
		termList.getAll(defaultTerm, 0);
	while (1)
	{
		string registration = (RegistrationSession) ? "Off" : "On";
		string scoreBoard = (ShowScoreBoard) ? "Off" : "On";
		system("cls");
		cout << string(6,'\n');
		cout << string(20,' ') << string(25,'=') << " TEACHER MENU " << string(25,'=') << endl;
		cout << string(20,' ') << "#                                                              #" << endl;
		cout << string(20,' ') << "#        ------------ Information methods -------------        #" << endl;
		cout << string(20,' ') << "#               [1] View information                           #" << endl;
		cout << string(20,' ') << "#               [2] Change information                         #" << endl;
		cout << string(20,' ') << "#               [3] Change password                            #" << endl;
		cout << string(20,' ') << "#                                                              #" << endl;
		cout << string(20,' ') << "#        -------------- Managing methods --------------        #" << endl;
		cout << string(20,' ') << "#               [4] Create new school year                     #" << endl;
		cout << string(20,' ') << "#               [5] Create new term                            #" << endl;
		cout << string(20,' ') << "#               [6] Create new class                           #" << endl;
		cout << string(20,' ') << "#               [7] View list of classes                       #" << endl;
		cout << string(20,' ') << "#               [8] Add students to a class                    #" << endl;
		cout << string(20,' ') << "#               [9] View student list of a class               #" << endl;
		cout << string(20,' ') << "#               [10] Add courses                               #" << endl;
		cout << string(20,' ') << "#               [11] View list of courses                      #" << endl;
		cout << string(20,' ') << "#               [12] Update course information                 #" << endl;
		cout << string(20,' ') << "#               [13] View list of students in course           #" << endl;
		cout << string(20,' ') << "#               [14] Update student result in course           #" << endl;
		cout << string(20,' ') << "#               [15] Import course score board                 #" << endl;
		cout << string(20,' ') << "#               [16] Export course score board                 #" << endl;
		cout << string(20,' ') << "#               [17] Turn " << registration << " Registration Session             #" << endl;
		cout << string(20,' ') << "#               [18] Turn " << scoreBoard << " Show Student Score Board         #" << endl;
		cout << string(20,' ') << "#                                                              #" << endl;
		cout << string(20,' ') << "#               [19] Log out                                   #" << endl;
		cout << string(20,' ') << "#                                                              #" << endl;
		cout << string(20,' ') << string(64,'=') << endl << endl;
		cout << string(20,' ') << string(17,' ') << "Your choice: ";

		cin >> answer;
		cin.clear();
		cin.ignore(1000, '\n');

		switch (answer)
		{
			case 1: //Show info
			{
				system("cls");
				teacherLogin->getInfo();
				system("pause");
				break;
			}
			case 2: //Change Info
			{
				teacherLogin->getInfo();
				teacherLogin->editInfo();
				break;
			}
			case 3: //Change password
			{
				teacherLogin->changePassword();
				break;
			}
			case 4: //Create new school year
			{
				createNewYear(yearList, numberOfYear);
				break;
			}
			case 5: //Create new term
			{
				createNewTerm(termList, numberOfYear, numberOfTerm);
				break;
			}
			case 6: //Create new class
			{
				createNewClass(yearList, numberOfYear);
				break;
				
			}
			case 7: //
			{
				viewListOfClass(yearList, numberOfYear);
				break;
				
			}
			case 8: //add student to class by .csv file
			{
				addStudentToClass(yearList, numberOfYear);
				break; 
				
			}
			case 9: // view students list of a class
			{
				viewStudentOfAClass(yearList, numberOfYear);
				break; 
			}
			case 10: // Add course
			{
				system("cls");
				defaultTerm->addCourse();
				break; 
			}
			case 11: // View list of courses
			{
				viewCourse(termList, numberOfTerm);
				break; 
			}
			case 12: //Update courses
			{
				updateCourse(termList, numberOfTerm);
				break; 
			}
			case 13: // View board of a course
			{
				viewCourseStudent(termList, numberOfTerm);
				break; 
			}
			case 14://
			{
				updateStudentResult(termList, numberOfTerm); 
				break;
			}
			case 15:
			{
				importCourseStudent(defaultTerm);
				break; 
			}
			case 16:
			{
				exportCourseStudent(defaultTerm);
				break;
			}
			case 17:
			{
				system("cls");
				cout << "Turn " << registration << " Registration Session Successfully\n";
				RegistrationSession = 1 - RegistrationSession;
				system("pause");
				break;
			}
			case 18:
			{
				system("cls");
				cout << "Turn " << scoreBoard << " Show Score Board Successfully\n";
				ShowScoreBoard = 1 - ShowScoreBoard;
				system("pause");
				break;
			}
			case 19:
			{
				system("cls");
				return;
			}
			default:
			{
				cout << "Error!" << endl;
				break;
			}
		}
	}
}

