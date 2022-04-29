/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
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


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Patient.h"
#include "utils.h"

using namespace std;

namespace sdds
{
	Patient::Patient(int ticketNumber, bool fileIO) : ticket_Obj(ticketNumber)
	{
		file = fileIO;
	}

	Patient::~Patient()
	{
		delete[] m_patientName;
		m_patientName = nullptr;
	}

	bool Patient::fileIO() const
	{
		return file;
	}

	void Patient::fileIO(bool value)
	{
		file = value;
	}

	bool Patient::operator==(char char_type) const
	{
		bool success = false;
		if (type() == char_type)
		{
			success = true;
		}
		return success;
	}

	bool Patient::operator==(const Patient& P) const
	{
		bool success = false;
		if (this->type() == P.type())
		{
			success = true;
		}
		return success;
	}

	void Patient::setArrivalTime()
	{
		ticket_Obj.resetTime();
	}

	Patient::operator Time() const
	{
		return Time(ticket_Obj);
	}

	int Patient::number() const
	{
		return ticket_Obj.number();
	}

	std::istream& Patient::csvRead(std::istream& istr)
	{
		char name[10000];
		istr.get(name, 10000, ',');

		delete[] m_patientName;
		m_patientName = nullptr;

		m_patientName = new char[strlen(name) + 1];
		strcpy(m_patientName, name);

		istr.ignore(10000, ',');

		istr >> m_OHIP;

		istr.ignore(10000, ',');

		return ticket_Obj.csvRead(istr);
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type() << "," << m_patientName << "," << m_OHIP << ",";

		return ticket_Obj.csvWrite(ostr);
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
		char name[26];
		ticket_Obj.write(ostr) << endl;
		strncpy(name, m_patientName, 25);
		name[25] = '\0';

		ostr << name << ", OHIP: " << m_OHIP;
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr) {

		cout << "Name: ";

		delete[] m_patientName;
		m_patientName = nullptr;

		char name[10000] = { 0 };
		istr.get(name, 10000, '\n');

		m_patientName = new char[strlen(name) + 1];
		strcpy(m_patientName, name);
		istr.ignore(1000, '\n');

		cout << "OHIP: ";

		m_OHIP = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ", true);

		return istr;
	}


}