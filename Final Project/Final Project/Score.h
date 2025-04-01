#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Score
{
public:
	float midtermMark;
	float finalMark;
	float otherMark; // Diem cong
	float totalMark; // Lam tron 0,5 tu 0=>10

	Score()
	{
		midtermMark = 0;
		finalMark = 0;
		totalMark = 0;
		otherMark = 0; // Bonus
	}
	Score(float midMark, float finalMark, float bonusMark, float totalMark)
	{
		this->midtermMark = midMark;
		this->finalMark = finalMark;
		this->otherMark = bonusMark;
		this->totalMark = totalMark;
	}

	~Score() {
	}

	Score& operator=(const Score& k) 
	{
		this->midtermMark = k.midtermMark;
		this->finalMark = k.finalMark;
		this->otherMark = k.otherMark;
		this->totalMark = k.totalMark;
		return *this;
	}

	float calculateTotalMark(float midMark, float finalMark, float bonusMark)
	{
		int Temp = midMark * 0.3 + finalMark * 0.5 + bonusMark * 0.2;
		return formatRoundMark(Temp);
	}

	float calculateGPA(float midMark, float finalMark, float bonusMark)
	{
		int totalMark = calculateTotalMark(midMark, finalMark, bonusMark);
		return convertTotal2GPA(totalMark);
	}

	float formatRoundMark(float Mark) // Format round 0.5
	{
		if (Mark - int(Mark) < 0.25) // 4.17 => 4
		{
			return int(Mark);
		}
		else if (Mark - int(Mark) >= 0.75) // 4.78 => 5
		{
			return int(Mark) + 1;
		}
		else  // 4.43 => 4.5
		{
			return int(Mark) + 0.5;
		}
	}

	float convertTotal2GPA(float totalMark)
	{
		return formatRoundMark((totalMark * 4) / 10);
	}

	static void tableScore()
	{
		cout << setw(5) << left << "No";
		cout << setw(14) << left << "Student ID";
		cout << setw(20) << left << "First name";
		cout << setw(10) << left << "Last name";
		cout << setw(17) << left << "Mid-term Mark";
		cout << setw(15) << left << "Final Mark";
		cout << setw(15) << left << "Other Mark";
		cout << setw(15) << left << "Total Mark" << endl;
		cout << setfill('-');
		cout << setw(150) << "-" << endl;
		cout << setfill(' ');
	}

	void showScoreBoard()
	{
		cout << setw(17) << left << this->midtermMark;
		cout << setw(15) << left << this->finalMark;
		cout << setw(15) << left << this->otherMark;
		cout << setw(15) << left << this->totalMark << endl;
	}

	void editScore()
	{
		cout << "\n\nThis student's old result :\n";
		cout << setw(17) << left << "Mid-term Mark";
		cout << setw(15) << left << "Final Mark";
		cout << setw(15) << left << "Other Mark";
		cout << setw(15) << left << "Total Mark";

		cout << setw(17) << left << this->midtermMark;
		cout << setw(15) << left << this->finalMark;
		cout << setw(15) << left << this->otherMark;
		cout << setw(15) << left << this->totalMark << endl << endl << endl;

		float mtMark = 0, fnMark = 0, otMark = 0;
		cout << "Enter new score\n";
		cout << "New Mid-term Mark : ";
		cin >> mtMark;
		cout << "New Final Mark : ";
		cin >> fnMark;
		cout << "New Other Mark : ";
		cin >> otMark;
		float ttMark = calculateTotalMark(mtMark, fnMark, otMark);

		this->midtermMark = mtMark;
		this->finalMark = fnMark;
		this->otherMark = otMark;
		this->totalMark = ttMark;
		cout << "Update successfully !\n";
	}

	void editScore(Score newScore)
	{
		*this = newScore;
	}

	float getMid()
	{
		return midtermMark;
	}

	float getFinal()
	{
		return finalMark;
	}

	float getBonus()
	{
		return otherMark;
	}
	float getTotal()
	{
		return totalMark;
	}

};

