#pragma once
#include <iostream>
#include "defineClass.h"
#include "Year.h"
#include "Term.h"
#include <string>

void Login(SinglyLinkedList <Year>& yearList, SinglyLinkedList <Teacher>& teacherList, SinglyLinkedList <Term>& termList, int& numberOfYear, int& numberOfTerm, bool& RegistrationSession, bool& ShowScoreBoard);
void studentMenu(Student* studentLogin, SinglyLinkedList <Term>& termList, int& numberOfYear, int& numberOfTerm, Year* yearOfStudent, bool RegistrationSession, bool ShowScoreBoard);
void teacherMenu(Teacher* teacher, SinglyLinkedList <Year>& ,SinglyLinkedList <Term> &termList, int& numberOfYear, int& numberOfTerm, bool &RegistrationSession, bool& ShowScoreBoard);


void updateStudentResult(SinglyLinkedList <Term>& termList, int numberOfTerm);
void importCourseStudent(Term* defaultTerm);
void updateCourse(SinglyLinkedList <Term>& termList, int numberOfTerm);
void exportCourseStudent(Term* defaultTerm);
void viewCourseStudent(SinglyLinkedList <Term>& termList, int numberOfTerm);
void viewCourse(SinglyLinkedList <Term>& termList, int numberOfTerm);
void createNewYear(SinglyLinkedList <Year>& yearList, int& numberOfYear);
void createNewTerm(SinglyLinkedList <Term>& termList, int& numberOfYear, int& numberOfTerm);
void createNewClass(SinglyLinkedList <Year>& yearList, int numberOfYear);
void addStudentToClass(SinglyLinkedList <Year>& yearList, int numberOfYear);
void viewListOfClass(SinglyLinkedList <Year>& yearList, int numberOfYear);
void viewStudentOfAClass(SinglyLinkedList <Year>& yearList, int numberOfYear);