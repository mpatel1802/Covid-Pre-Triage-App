/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
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


#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

namespace sdds
{


	class Menu
	{

	private:

		char* m_text = nullptr; // holds the menu content dynamically
		int m_noOfSel = 0;  // holds the number of options displayed in menu content\

	public:

		Menu(const Menu& menu);
		Menu(const char* MenuContent, int NoOfSelections);
		int& operator>>(int& Selection);
		Menu& operator=(const Menu& menu);
		void display()const;

		virtual ~Menu();

	};

}
#endif