#pragma once

#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
#include "defineClass.h"
#include "USER.h"

using namespace std;


struct ClassID
{
	int yearCou;
	string quality;
	int classNum;
};

class Class : protected SinglyLinkedList<Class>
{
protected:
	ClassID classID;
	string name;
	int size;
	SinglyLinkedList<Student> studentList;

public:

	Class();
	~Class();
	Class(string name);
	void AddClassNewStudent();
	void addStudent(Student& newStudent);
	void addStudentCSV(string file);
	void importStudentCSV(string file);
	int classSize();
	string getName();
	SinglyLinkedList<Student>* getStudentList();
	Class& operator=(const Class& k);
	void DeleteStudent(string ID);
	Student* findStudent(string studentId);
	void extractClassID(ClassID& classid);
	void AddNewClass(SinglyLinkedList<Class>& Head);
	ClassID getClassID();
	
};
