/* Citation and Sources...
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.h
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

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds
{
	class CovidPatient :public Patient
	{

	public:

		CovidPatient();
		virtual char type()const;
		virtual std::istream& csvRead(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);

	};
}


#endif