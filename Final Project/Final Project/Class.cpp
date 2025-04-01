#include <iostream>
#include "Class.h"
#include <string>


Class :: Class()
{
	name = "";
	size = 0;
}

Class :: ~Class()
{
	studentList.~SinglyLinkedList();
}

Class::Class(string name)
{
	this->name = name;
}

void Class::AddClassNewStudent()
{
	cout << "Type the student ID who you want to add to this class!" << endl;
	cout << "Type 0 to stop!" << endl;
	string temp = ""; int i = 1; bool number = true;
	while (number)
	{
		cout << "Student ID #" << i << ": "; cin >> temp; i++;
		if (temp == "0")
			number = 0;

		if (number)
		{
			Student* tmp;
			while (studentList.getAll(tmp, 0))
			{
				Student tmpStu = tmp->GetData();
				if (tmp->checkStudentID(temp)) addStudent(tmpStu);
			}

		}
	}
}

void Class::addStudent(Student& newStudent)
{
	studentList.append(newStudent);
}

void Class::addStudentCSV(string file)
{
	fstream input;
	input.open(file, ios::in | ios::beg);

	Student studentTemp;

	while (!input.eof())
	{
		if (studentTemp.setStudentCSV(input))
			studentList.append(studentTemp);
		else
			break;
	}
	
	input.close();
}

void Class::importStudentCSV(string file)
{
	fstream input;
	input.open(file, ios::in);

	Student studentTemp;

	while (!input.eof())
	{
		if (studentTemp.importStudentCSV(input))
			studentList.append(studentTemp);
		else
			break;
	}

	input.close();
}


// Class size or /number of studnets in this class
int Class::classSize()
{
	return this->studentList.len();
}
string Class::getName()
{
	return this->name;
}
SinglyLinkedList<Student>* Class::getStudentList()
{
	return &studentList;
}

Class& Class::operator=(const Class& k)
{
	if (this != &k)
	{
		this->classID = k.classID;
		this->name = k.name;
		this->size = k.size;
		this->studentList = k.studentList;
	}
	return *this;
}

void Class::DeleteStudent(string ID) // Hmm hàm trên này với cái kế dưới cái nào tốt hơn ta
{
	int n = this->size;
	Student* temp = new Student[n];
	Student* tmp = nullptr;
	int i = 0;
	studentList.getAll(tmp, 1);
	while (studentList.getAll(tmp, 0))
	{
		temp[i] = tmp->GetData();
		if (temp[i].checkStudentID(ID))
		{
			this->studentList.erase(i, 1);
			break;
		}
	}
	delete[]temp;
}

Student* Class::findStudent(string studentId)
{
	Student* tmpStudent = nullptr;
	studentList.getAll(tmpStudent, 1);
	while (studentList.getAll(tmpStudent, 0))
		if (tmpStudent->getId() == studentId)
			return tmpStudent;

	return nullptr;
}

void Class::extractClassID(ClassID& classid)
{
	string Temp = "";
	string K = "";
	string qua = "";
	string C_num = "";
	int mark = 0;
	cout << "Enter the class ID (Example: 21CLC09): "; cin >> Temp;
	for (int i = 0; i < Temp.size(); i++)
	{
		if (isdigit(Temp[i]) != 0) K = K + Temp[i];
		else
		{
			mark = i;
			break;
		}
	}
	for (int i = mark; i < Temp.size(); i++)
	{
		if (isdigit(Temp[i] == 0)) qua = qua + Temp[i];
		else
		{
			C_num = C_num + Temp[i];
		}
	}
	classid.yearCou = atoi(K.c_str()); classid.quality = qua; classid.yearCou = atoi(C_num.c_str());
}
void Class::AddNewClass(SinglyLinkedList<Class>& Head)
{
	char answer;
	cout << "Add students? (Y/N): "; cin >> answer;
	do
	{
		cout << "Error! Please type 'Y' for yes and 'N' for no!" << endl;
		cout << "Add students? (Y/N): "; cin >> answer;
	} while (answer != 'Y' && answer != 'N');
	if (answer == 'Y')
	{
		string classID = "";
		ClassID Temp; extractClassID(Temp);
		Class Tempo; Tempo.classID = Temp;
		Head.append(Tempo);
	}
}
ClassID Class::getClassID()
{
	return this->classID;
}
