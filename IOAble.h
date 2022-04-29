/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.h
Version 1.0
Author	Mann Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/08/02  Preliminary release
2021/08/02  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_

#include <iostream>

namespace sdds
{
	class IOAble
	{

	public:
		virtual std::ostream& csvWrite(std::ostream& os) const = 0;
		virtual std::istream& csvRead(std::istream& is) = 0;
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual ~IOAble();
	};

	std::ostream& operator<<(std::ostream& os, const IOAble& IO);
	std::istream& operator>>(std::istream& is, IOAble& IO);
}



#endif