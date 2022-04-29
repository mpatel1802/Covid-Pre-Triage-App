/* Citation and Sources...
Final Project Milestone 5
Module: utils
Filename: utils.cpp
Version 1.0
Author	Mann Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/08/02  Preliminary release
2021/08/02 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/



#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include "utils.h"
#include "Time.h"

using namespace std;

namespace sdds
{
	bool debug = false;  // made global in utils.h

	int getTime() {
		int mins = -1;
		if (debug) {
			Time t(0);
			cout << "Enter current time: ";
			do {
				cin.clear();
				cin >> t;   // needs extraction operator overloaded for Time
				if (!cin) {
					cout << "Invlid time, try agian (HH:MM): ";
					cin.clear();
				}
				else {
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		}
		else {
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}

	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
	{
		bool success = false;
		int enteredValue = 0;
		if (prompt)
		{
			cout << prompt;
		}
		while (!success)
		{
			enteredValue = getInt();
			if (enteredValue >= min && enteredValue <= max)
			{
				success = true;
			}
			else if (errorMessage != nullptr)
			{
				if (showRangeAtError)
				{
					cout << errorMessage << "[" << min << " <= value <= " << max << "]: ";
				}
				else
				{
					cout << errorMessage;
				}
			}
		}
		return enteredValue;
	}

	int getInt(const char* prompt)
	{
		int enteredValue = 0;
		bool success = true;
		char nextChar = 0;

		if (prompt)
		{
			cout << prompt;
		}

		while (success)
		{
			success = false;
			cin >> enteredValue;

			if (cin.fail())
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(10000, '\n');
				success = true;
			}
			else
			{
				nextChar = cin.get();
				if (nextChar != '\n')
				{
					cout << "Enter only an integer, try again: ";
					cin.clear();
					cin.ignore(10000, '\n');
					success = true;
				}
			}
		}
		return enteredValue;

	}

	char* getcstr(const char* prompt, std::istream& istr, char delimiter)
	{
		if (prompt)
		{
			cout << prompt;
		}
		char str[1000];
		istr.getline(str, 100000, delimiter);
		char* str2 = new char[strlen(str) + 1];
		strcpy(str2, str);

		return str2;
	}




}