#pragma once
#include <iostream>
#include "SinglyLinkedList.h"
#include "defineClass.h"
#include "Course.h"
#include "USER.h"
using namespace std;

class Term
{
protected:
	Date begin;
	Date end;
	int number;
	SinglyLinkedList <Course> courseList;
public:
	Term(Date begin, Date end, int number);
	Term();
	Term& operator=(const Term& k);
	SinglyLinkedList <Course>* getCourseList();
	Course* getLastCourse();
	void addCourse(Course& newCourse);
	void addCourse();
	void printCourseList();
	void removeCourse();
	void exportDay(fstream& out);
	void exportInfo(fstream& out);
	void removeACourse(int num);
	void exportCourse(string termNum);
};
