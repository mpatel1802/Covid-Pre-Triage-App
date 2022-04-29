/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.h
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

#ifndef SDDS_TRIAGEPATIENT_H_
#define SDDS_TRIAGEPATIENT_H_

#include<iostream>
#include "Patient.h"

namespace sdds
{
	class TriagePatient :public Patient
	{

	private:

		char* m_triageSymptoms;

	public:

		TriagePatient();
		virtual char type() const;
		virtual std::ostream& csvWrite(std::ostream& ostr)const;
		virtual std::istream& csvRead(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
		~TriagePatient();

	};
}

#endif 
