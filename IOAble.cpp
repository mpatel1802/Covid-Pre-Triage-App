/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.cpp
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

#include <iostream>
#include "IOAble.h"

using namespace std;

namespace sdds
{
	ostream& IOAble::csvWrite(ostream& os)const
	{
		return os;
	}

	istream& IOAble::csvRead(istream& is)
	{
		return is;
	}

	ostream& IOAble::write(ostream& os)const
	{
		return os;
	}

	istream& IOAble::read(istream& is)
	{
		return is;
	}

	ostream& operator<<(ostream& os, const IOAble& IO)
	{
		return IO.write(os);
	}

	istream& operator>>(istream& is, IOAble& IO)
	{
		return IO.read(is);
	}

	IOAble:: ~IOAble()
	{

	}

}