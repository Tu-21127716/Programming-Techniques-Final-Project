#include "LibraryHeader.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

void FirstImport(SinglyLinkedList<Year>& yearList, SinglyLinkedList <Teacher>& teacherList, int &numberOfYear, int &numberOfTerm ,string yearFile = "Data/year.txt");
void importTerm(SinglyLinkedList<Year>& yearList, SinglyLinkedList <Term>& termList, int numberOfTerm);
void Export(SinglyLinkedList <Year>& yearList, int numberOfYear, int numberOfTerm, string yearFile = "Data/year.txt");
void exportTerm(SinglyLinkedList <Term>& termList, int numberOfTerm);



int main()
{
	int numberOfTerm = 0;
	int numberOfYear = 0;
	bool RegistrationSession = 0;
	bool ShowScoreBoard = 0;
	SinglyLinkedList <Teacher> teacherList;
	SinglyLinkedList <Year> yearList;
	SinglyLinkedList <Term> termList;
	cout << "Welcome To Moodle\n";

	fstream f;
	f.open("Data/bool.txt", ios::in);
	f >> RegistrationSession >> ShowScoreBoard;
	f.close();

	FirstImport(yearList, teacherList, numberOfYear,numberOfTerm);
	importTerm(yearList, termList, numberOfTerm);

	Login(yearList, teacherList, termList, numberOfYear, numberOfTerm,RegistrationSession,ShowScoreBoard);
	
	Export(yearList, numberOfYear, numberOfTerm);
	exportTerm(termList, numberOfTerm);
	
	f.open("Data/bool.txt", ios::out);
	f << RegistrationSession << " " << ShowScoreBoard;
	f.close();
	
	teacherList.clear();
	termList.clear();
	yearList.clear();
	
	return 0;
	
}