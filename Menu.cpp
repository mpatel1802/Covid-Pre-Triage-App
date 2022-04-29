/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Mann Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/08/02 Preliminary release
2021/08/02  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Menu.h"
#include "utils.h"

using namespace std;

namespace sdds
{
	void Menu::display() const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}

	Menu::Menu(const Menu& menu)
	{
		if (menu.m_text != nullptr && menu.m_noOfSel != 0)
		{
			m_text = new char[strlen(menu.m_text) + 1];
			strcpy(m_text, menu.m_text);
			m_noOfSel = menu.m_noOfSel;
		}
	}

	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}


	Menu& Menu::operator=(const Menu& menu)
	{
		if (menu.m_text != nullptr && menu.m_noOfSel != 0)
		{
			delete[] m_text;
			m_text = nullptr;

			m_text = new char[strlen(menu.m_text) + 1];
			strcpy(m_text, menu.m_text);
			m_noOfSel = menu.m_noOfSel;
		}

		return *this;
	}


	int& Menu::operator>>(int& Selection)
	{
		int option = 0;
		display();
		option = getInt(0, m_noOfSel, "> ", "Invalid option ", true);
		Selection = option;
		return Selection;
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}
}

