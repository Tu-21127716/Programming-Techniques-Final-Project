#pragma once
#include <iostream>
#include "SinglyLinkedList.h"
#include "Class.h"
#include "USER.h"

using namespace std;

class Year
{
private:
	string academicYear;
	Date begin, end;
	SinglyLinkedList <Class> classList;
public:
	Year(Date begin, Date end);
	Year(string year);
	Year();
	~Year();
	string getAcademicYear();
	void addClass(Class& newClass);
	SinglyLinkedList<Class>* getClassList();
	Student* findStudent(string studentId);
	Year& operator=(const Year& k);
	int numberOfClass();
};