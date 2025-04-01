
// Hehe test
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "SinglyLinkedList.h"
#include "defineClass.h"
#include "Score.h"
#include "Course.h"
using namespace std;


struct Date
{
	string day;
	string month;
	string year;
};

class User 
{
	protected:
		int no;
		string firstName, lastName;
		bool isFemale;
		Date DOB;
		string socialId ;
		string username;
		string password;
	public:
		User()
		{
			no = 0;
			firstName = "";
			lastName = "";
			isFemale = true;
			password = "a";
		}
		User(int no, string fN, string lN, bool gender, Date DOB, string socialID)
		{
			this->no = no;
			this->firstName = fN;
			this->lastName = lN;
			this->isFemale = gender;
			this->DOB = DOB;
			this->socialId = socialID;
			string dayTemp = DOB.day;
			string monthTemp = DOB.month;
			string yearTemp = DOB.year;
			this->password = dayTemp + monthTemp + yearTemp;

		}
		void editInfo()
		{
			cout << endl;
			cout << "Which infomation you want to change ?\n";
			cout << "[1] Change Name" << endl;
			cout << "[2] Change Date of birth" << endl;
			cout << "[3] Change Gender" << endl;
			cout << "[4] Exit" << endl;
			cout << "Enter key number [1->4] : ";
			int key;
			string Temp;
			cin >> key;
			cin.ignore();
			switch (key)
			{
			case 1:
				cout << "\nEnter your new First name : ";
				getline(cin, this->firstName);
				cout << "Enter your new Last name : ";
				getline(cin, this->lastName);
				cout << "Successfully updated !\n";
				system("pause");
				break;
			case 2:
				cout << "\nEnter your new Date of birth (Example \"31/01/2003\") : ";
				getline(cin, Temp, '/'); // Day
				DOB.day = Temp;
				getline(cin, Temp, '/'); // Month
				DOB.month = Temp;
				getline(cin, Temp, '\n'); // Year
				DOB.year = Temp;
				cout << "Successfully updated !\n";
				system("pause");
				break;
			case 3:
				cout << "\nEnter your new Gender (Female-'x' or 'X') : ";
				getline(cin, Temp, '\n');
				if (Temp == "x" || Temp == "X") {
					this->isFemale = true;
				}
				else {
					this->isFemale = false;
				}
				cout << "Successfully updated !\n";
				system("pause");
				break;
			case 4:
			{
				break;
			}
			default:
				cout << "Invalid choice !\n";
				break;
			}
		}

		bool checkAccount(string username, string password)
		{
			if (this->username == username && this->password == password)
				return 1;
			return 0;
		}

		void changePassword()
		{
			system("cls");
			bool conti = true;
			while (conti)
			{
				cout << "Changing Password\n";
				string currentPassword;
				cout << "Enter your current password : ";
				getline(cin, currentPassword, '\n');
				while (currentPassword == this->password) {
					string newPass, newPassConfirm;
					cout << "Enter new pass word : ";
					getline(cin, newPass, '\n');
					cout << "Confirm again new pass word : ";
					getline(cin, newPassConfirm, '\n');
					if (newPass == newPassConfirm) {
						this->password = newPass;
						conti = false;
						break;
					}
					else {
						cout << "Invalid ! Try again\n";
					}
				}
				if (conti == false) break;
				cout << "Incorrect ! Do you want to try again ?\n";
				cout << "Press y/Y to try again\n";
				char key;
				cin >> key;
				cin.ignore(100, '\n');
				if (key == 'y' || key == 'Y') {
					conti = true;
				}
				else {
					conti = false;
				}
			}
		}

};





class Teacher: public User
{
	public:
		string mail = "";
		SinglyLinkedList <Course*> enrolledCourses;
		Teacher()
		{

		}
		Teacher(string a, string b, string c)
		{
			this->username = a;
			this->password = b;
			this->firstName = c;
		}

		void getenrolledCourses()
		{

		}

		void setTeacherMail(string TeacherMail)
		{
			this->mail = TeacherMail;
		}

		void getInfo()
		{
			system("cls");
			cout << setw(5) << left << "No";
			cout << setw(20) << left << "First name";
			cout << setw(10) << left << "Last name";
			cout << setw(8) << left << "Gender";
			cout << setw(10) << left << "Date of birth";
			cout << setw(20) << right << "Social ID";
			cout << setw(25) << right << "Mail" << endl;

			cout << setfill('-');
			cout << setw(100) << "-" << endl;
			cout << setfill(' ');

			cout << setw(5) << left << this->no;
			cout << setw(20) << left << this->firstName;
			cout << setw(10) << left << this->lastName;
			if (this->isFemale) {
				cout << setw(8) << left << "Female";
			}
			else {
				cout << setw(8) << left << "Male";
			}
			cout << setw(5) << right << this->DOB.day << "/" << this->DOB.month << "/" << this->DOB.year;
			cout << setw(20) << right << this->socialId;
			cout << setw(25) << right << this->mail << endl;
		}

		bool importTeacherCSV(fstream& input)
		{
			string Temp;

			getline(input, Temp, ','); // No
			if (Temp == "")
				return 0;
			no = stoi(Temp);

			getline(input, Temp, ','); // First name
			firstName = Temp;

			getline(input, Temp, ','); // Last name
			lastName = Temp;

			getline(input, Temp, ','); // Gender
			if (Temp == "x" || Temp == "X")
				isFemale = true;
			else
				isFemale = false;


			getline(input, Temp, ','); // username
			username = Temp;

			getline(input, Temp, ','); // password
			password = Temp;

			getline(input, Temp); // Social ID
			socialId = Temp;

			return 1;
		}


};


class Student: public User
{
	protected:
		string studentId ="";
		SinglyLinkedList <Course*> enrolledCourses;
		SinglyLinkedList <Score*> individualScoreList;
		int year;
	public:
		Student()
		{

		}

		Student(string a, string b,string c)
		{
			this->username = a;
			this->password = b;
			this->firstName = c;
		}

		~Student()
		{
			enrolledCourses.~SinglyLinkedList();
			individualScoreList.~SinglyLinkedList();
		}
		string getId()
		{
			return this->studentId;
		}

		Student& operator=(const Student& k)
		{
			this->no = k.no;
			this->firstName =k.firstName;
			this->lastName =k.lastName;
			this->isFemale=k.isFemale;
			this->DOB=k.DOB;
			this->socialId = k.socialId;
			this->username = k.username;
			this->password=k.password;
			this->studentId = k.studentId;
			this->enrolledCourses = k.enrolledCourses;
			this->individualScoreList = k.individualScoreList;
			this->year=k.year;
			return *this;
		}
		static void studentInfoTable()
		{
			cout << setw(5) << left << "NO";
			cout << setw(15) << left << "Student ID";
			cout << setw(20) << left << "First name";
			cout << setw(10) << left << "Last name";
			cout << setw(8) << left << "Gender";
			cout << setw(10) << left << "Date of birth";
			cout << setw(20) << right << "Social ID\n";

			cout << setfill('-');
			cout << setw(105) << "-" << endl;
			cout << setfill(' ');
		}
		
		void setStudentInfo(int no)
		{
			string date,tmp="";
			this->no = no;
			cout << "Student ID: ";
			cin >> studentId;
			cin.ignore();
			cout << "Last name: ";
			getline(cin, firstName);
			
			cout << "First name: ";
			getline(cin, lastName);
			cout << "Enter your new Gender (Female - 'x' or 'X') : ";
			
			getline(cin, tmp, '\n');
			if (tmp == "x" || tmp == "X") {
				this->isFemale = true;
			}
			else {
				this->isFemale = false;
			}
		
			cout << "Date of birth (dd/mm/yyyy): ";
			
			getline(cin, date);
			tmp = "";
			int i = 0;
			for (; i < date.length() && date[i] != '/'; ++i)
				tmp += date[i];
			if (tmp[0] == '0')
				tmp = tmp[1];

			++i;
			DOB.day = tmp;
			tmp = "";
			for (; i < date.length() && date[i] != '/'; ++i)
				tmp += date[i];
			if (tmp[0] == '0')
				tmp = tmp[1];
			++i;
			DOB.month = tmp;
			tmp = "";
			for (; i < date.length(); ++i)
				tmp += date[i];
			++i;
			DOB.year = tmp;
			cout << "Social ID: ";
			cin >> socialId;
			username = studentId;
			password = "";
			password = DOB.day + DOB.month + DOB.year;
		}

		void setStudentNo (int no)
		{
			this->no = no;
		}
		void setStudentID(string studentID)
		{
			this->studentId = studentID;
		}
		void setStudentFN(string fN)
		{
			this->firstName = fN;
		}
		void setStudentLN(string lN)
		{
			this->lastName = lN;
		}
		void setStudentgender(bool gender)
		{
			this->isFemale=gender;
		}

		bool setStudentCSV(fstream &input)
		{
			string Temp; // Chỉ cần tạo 1 biến tạm để đọc
						 // Rồi ép kiểu cho đúng kiểu dữ liệu
			year = 1;
			getline(input, Temp, ','); // No
			if (Temp == "")
				return 0;
			no = stoi(Temp);

			getline(input, Temp, ','); // Student ID
			studentId = Temp;
			username = studentId;
			getline(input, Temp, ','); // First name
			firstName = Temp;

			getline(input, Temp, ','); // Last name
			lastName = Temp;

			getline(input, Temp, ','); // Gender
			if (Temp == "x" || Temp == "X") {
				isFemale = true;
			}
			else {
				isFemale = false;
			}

			getline(input, Temp, '/'); // Day
			DOB.day = Temp;
			password = Temp; // Password day
			getline(input, Temp, '/'); // Month
			DOB.month = Temp;
			password += Temp; // + Password month
			getline(input, Temp, ','); // Year
			DOB.year = Temp;
			password += Temp; // + Password year
			
			getline(input, Temp); // Social ID
			socialId = Temp;
			return 1;
		}

		bool importStudentCSV(fstream& input)
		{
			string Temp; // Chỉ cần tạo 1 biến tạm để đọc
						 // Rồi ép kiểu cho đúng kiểu dữ liệu
			getline(input, Temp, ','); // No
			if (Temp == "")
				return 0;
			no = stoi(Temp);

			getline(input, Temp, ','); // Student ID
			studentId = Temp;
			username = studentId;
			getline(input, Temp, ','); // First name
			firstName = Temp;

			getline(input, Temp, ','); // Last name
			lastName = Temp;

			getline(input, Temp, ','); // Gender
			if (Temp == "x" || Temp == "X") {
				isFemale = true;
			}
			else {
				isFemale = false;
			}

			getline(input, Temp, '/'); // Day
			DOB.day = Temp;
			password = Temp; // Password day
			getline(input, Temp, '/'); // Month
			DOB.month = Temp;
			password += Temp; // + Password month
			getline(input, Temp, ','); // Year
			DOB.year = Temp;
			password += Temp; // + Password year

			getline(input, Temp,','); // Social ID
			socialId = Temp;
			getline(input, Temp); // Social ID
			password = Temp;

			return 1;
		}


		Student(int no, string fN, string lN, bool gender, Date DOB, string socialID, string studentID) //Constructor
		{
			this->no = no;
			this->firstName = fN;
			this->lastName = lN;
			this->isFemale = gender;
			this->DOB = DOB;
			this->socialId = socialID;

			this->studentId = studentID;
			this->username = studentID;

			string dayTemp = DOB.day;
			string monthTemp = DOB.month;
			string yearTemp = DOB.year;
			this->password = dayTemp + monthTemp + yearTemp;
		}

		void getStudentInfo() {
			//system("cls");
			
			cout << setw(5) << left << this->no;
			cout << setw(15) << left << this->studentId;
			cout << setw(20) << left << this->firstName;
			cout << setw(10) << left << this->lastName;
			if (this->isFemale) {
				cout << setw(8) << left << "Female";
			}
			else {
				cout << setw(8) << left << "Male";
			}
			cout << setw(5) << right << this->DOB.day << "/" << this->DOB.month << "/" << this->DOB.year;
			cout << setw(20) << right << this->socialId;
			
			cout << "\n\n" ;
		}

		void getStudentInfo(int no) { // Có no
			//system("cls");
			cout << setw(5) << left << "NO";
			cout << setw(15) << left << "Student ID";
			cout << setw(20) << left << "First name";
			cout << setw(10) << left << "Last name";
			cout << setw(8) << left << "Gender";
			cout << setw(10) << left << "Date of birth";
			cout << setw(20) << right << "Social ID\n";

			cout << setfill('-');
			cout << setw(115) << "-" << endl;
			cout << setfill(' ');

			cout << setw(5) << left << no;
			cout << setw(15) << left << this->studentId;
			cout << setw(20) << left << this->firstName;
			cout << setw(10) << left << this->lastName;
			if (this->isFemale) {
				cout << setw(8) << left << "Female";
			}
			else {
				cout << setw(8) << left << "Male";
			}
			cout << setw(5) << right << this->DOB.day << "/" << this->DOB.month << "/" << this->DOB.year;
			cout << setw(20) << right << this->socialId;

			cout << "\n\n";
		}

		int getYear()
		{
			return year;
		}

		void exportInfo(fstream &out) 
		{
			out << no << ","
				<< studentId << ","
				<< firstName << ","
				<< lastName << ",";
				
			if (this->isFemale) 
				out << "x,";
			else 
				out << ",";
			out << DOB.day << "/" << DOB.month << "/" << DOB.year << ","
				<< socialId << ","
				<< password <<"\n";
		}

		bool checkStudentID(string temp) // Tôi cần hàm này để thêm học sinh vào lớp nha - Tú
		{
			if (temp == this->studentId) return true;
			else return false;
		}

		Student GetData()
		{
			Student temp;
			temp.no = this->no;
			temp.studentId = this->studentId;
			temp.firstName = this->firstName;
			temp.lastName = this->lastName;
			temp.socialId = this->socialId;
			temp.DOB = this->DOB;
			temp.isFemale = this->isFemale;

			temp.enrolledCourses = this->enrolledCourses;
			temp.individualScoreList = this->individualScoreList;

			temp.year = this->year;
			return temp;
		}
		SinglyLinkedList<Course*>* getenrolledCourses()
		{
			return &enrolledCourses;
		}
		SinglyLinkedList<Score*>* getScoreList()
		{
			return &individualScoreList;
		}
		
		bool courseRegistration(Course* &course)
		{
			bool isConflicted = 0;
			Course** tmpChosen = nullptr;
			//Login --> open the course class in order for student to choose
			int attemp = 0;
			int num = 0;
			enrolledCourses.getAll(tmpChosen, 1);
			while (enrolledCourses.len() != 0 && enrolledCourses.getAll(tmpChosen, 0))
			{
				if ((*tmpChosen)->getCourseID() == course->getCourseID())
				{
					cout << "Your choice was existing before! Please try again!" << endl;
					isConflicted = true;
					break;
				}
				else if ((*tmpChosen)->getSchedule1().dayOfWeek == course->getSchedule1().dayOfWeek && (*tmpChosen)->getSchedule1().session == course->getSchedule1().session)
				{
					cout << "\t\tYour choice was conflicted with another existing course. Please try another one for better time management!" << endl;
					isConflicted = true;
					break;
				}
				else if ((*tmpChosen)->getSchedule2().dayOfWeek == course->getSchedule2().dayOfWeek && (*tmpChosen)->getSchedule2().session == course->getSchedule2().session)
				{
					cout << "\t\tYour choice was conflicted with another existing course. Please try another one for better time management!" << endl;
					isConflicted = true;
					break;
				}
				else if ((*tmpChosen)->getSchedule1().dayOfWeek == course->getSchedule2().dayOfWeek && (*tmpChosen)->getSchedule1().session == course->getSchedule2().session)
				{
					cout << "\t\tYour choice was conflicted with another existing course. Please try another one for better time management!" << endl;
					isConflicted = true;
					break;
				}
				else if ((*tmpChosen)->getSchedule2().dayOfWeek == course->getSchedule1().dayOfWeek && (*tmpChosen)->getSchedule2().session == course->getSchedule1().session)
				{
					cout << "\t\tYour choice was conflicted with another existing course. Please try another one for better time management!" << endl;
					isConflicted = true;
					break;
				}
			}
			if (isConflicted == false)
			{
				Score score(0, 0, 0, 0);
				
				course->getScoreList()->append(score);

				Score* pScore = course->getLastScore();
				enrolledCourses.append(course);
				SinglyLinkedList<Student*>* studentList = course->getStudentList();
				this->addScore(pScore);
				Student* tmpStudent = this;
				studentList->append(tmpStudent);
				course->updateCurMem();
			}
				//enrolledCourses.append(course);
			if (!isConflicted)
				cout << "Enrolled successfully\n";
			return 1;
		}


		// Score
		void addScore (Score* &score)
		{
			//score->showScoreBoard();
			individualScoreList.append(score);
			
		}

		void addCourse(Course* &course)
		{
			enrolledCourses.append(course);
		}

		// Dùng để showCourseBoard bên Course.h
		void showStudentInfoInBoard ()
		{
			cout << setw(14) << left << this->studentId;
			cout << setw(20) << left << this->firstName;
			cout << setw(10) << left << this->lastName;
		}
		
		float getOverallGPA()
		{
			float sumTotal = 0;
			int n = 0;
			
			Score** tmpScore;
			individualScoreList.getAll(tmpScore, 1);

			while (individualScoreList.getAll(tmpScore, 0))
			{
				sumTotal += (*tmpScore)->totalMark;
				n++;
			}
			float overallGPA = (n==0) ? sumTotal : sumTotal/n; 

			return overallGPA ;
		}

		void showScoreBoard()
		{
			showStudentInfoInBoard();
			cout << "\n";
			cout << setw(10) << "ID";
			cout << setw(30) << "Name";
			cout << setw(10) << "Midterm";
			cout << setw(10) << "Final";
			cout << setw(10) << "Other";
			cout << setw(10) << "Total";
			cout << "\n";
			Course** tmpCourse;
			Score** tmpScore;
			enrolledCourses.getAll(tmpCourse, 1);
			individualScoreList.getAll(tmpScore, 1);
			while (enrolledCourses.getAll(tmpCourse, 0))
			{
				individualScoreList.getAll(tmpScore, 0);
				cout << setw(10) << (*tmpCourse)->getCourseID();
				cout << setw(30) << (*tmpCourse)->getName();
				cout << setw(10) << (*tmpScore)->getMid();
				cout << setw(10) << (*tmpScore)->getFinal();
				cout << setw(10) << (*tmpScore)->getBonus();
				cout << setw(10) << (*tmpScore)->getTotal();
				cout << "\n";
			}
			/*cout << "\n\n";
			cout << enrolledCourses.len() << "    " << individualScoreList.len();*/
			cout << "OVERALL GPA : " << getOverallGPA() << endl;
		}
		
		void removeACourseInEnrolledList(int x)
		{
			if (x < 0) return;
		
			if (x <= individualScoreList.len())
			{
				Course** tmpCourse;
				Score** tmpScore;
				enrolledCourses.getAll(tmpCourse, 1);
				individualScoreList.getAll(tmpScore, 1);
				for (int i = 0; i < x; ++i)
				{
					enrolledCourses.getAll(tmpCourse, 0);
					individualScoreList.getAll(tmpScore, 0);
				}
				(*tmpCourse)->removeStudent(studentId);
				(*tmpCourse)->updateCurMem();
			}
			
			enrolledCourses.erase(x - 1, 1);
			individualScoreList.erase(x - 1, 1);
		}

		void showCourseEnrolled()
		{
			Course::table();
			int serialNum = 1;

			Course** tmpCourse;
			enrolledCourses.getAll(tmpCourse, 1);

			while (enrolledCourses.getAll(tmpCourse, 0))
			{
				cout << setw(5) << left << serialNum;
				serialNum++;
				(*tmpCourse)->showCourseInfo();
			}
		}



};
