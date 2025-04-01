#pragma once
#include <iostream>
#include "Year.h"


Year::Year(Date begin, Date end)
{
	this->begin = begin;
	this->end = end;
}
Year::Year(string year)
{
	this->academicYear = year;
}
Year::Year()
{

}

Year::~Year()
{

	classList.~SinglyLinkedList();
}

string Year::getAcademicYear()
{
	return academicYear;
}

void Year::addClass(Class& newClass)
{
	this->classList.append(newClass);
}

SinglyLinkedList<Class>* Year::getClassList()
{
	return &classList;
}

Student* Year::findStudent(string studentId)
{
	Student* tmpStudent = nullptr;
	Class* tmpClass = nullptr;
	classList.getAll(tmpClass, 1);
	while (classList.getAll(tmpClass, 0))
	{
		tmpStudent = tmpClass->findStudent(studentId);
		if (tmpStudent != nullptr)
			break;
	}

	return tmpStudent;
}

Year& Year::operator=(const Year& k)
{
	if (this != &k)
	{
		this->academicYear = k.academicYear;
		this->begin = k.begin;
		this->end = k.end;
		this->classList = k.classList;
	}
	return *this;
}
int Year::numberOfClass()
{
	return classList.len();
}