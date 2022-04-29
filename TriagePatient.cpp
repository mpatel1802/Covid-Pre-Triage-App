/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp
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

#include "TriagePatient.h"


using namespace std;

namespace sdds
{
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() :Patient(nextTriageTicket)
	{
		m_triageSymptoms = nullptr;
		nextTriageTicket += 1;
	}


	char TriagePatient::type() const
	{
		return 'T';
	}


	std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
	{
		Patient::csvWrite(ostr);
		ostr << "," << m_triageSymptoms;
		return ostr;
	}


	std::istream& TriagePatient::csvRead(std::istream& istr)
	{
		char symptoms[10000] = { 0 };
		delete[] m_triageSymptoms;
		m_triageSymptoms = nullptr;

		Patient::csvRead(istr);
		istr.ignore(1, ',');

		istr.getline(symptoms, 1000, '\n');
		m_triageSymptoms = new char[strlen(symptoms) + 1];
		strcpy(m_triageSymptoms, symptoms);

		nextTriageTicket = number() + 1;
		return istr;

	}

	std::ostream& TriagePatient::write(std::ostream& ostr)const
	{
		if (fileIO())
		{
			TriagePatient::csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr) << endl;
			ostr << "Symptoms: " << m_triageSymptoms << endl;
		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		if (fileIO())
		{
			TriagePatient::csvRead(istr);
		}
		else
		{
			char symptoms[10000] = { 0 };
			delete[] m_triageSymptoms;
			m_triageSymptoms = nullptr;

			Patient::read(istr);
			cout << "Symptoms: ";

			istr.getline(symptoms, 10000, '\n');
			m_triageSymptoms = new char[strlen(symptoms) + 1];
			strcpy(m_triageSymptoms, symptoms);


		}
		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_triageSymptoms;
		m_triageSymptoms = nullptr;
	}

}