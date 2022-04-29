/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.h
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

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

#include "IOAble.h"
#include "Ticket.h"

namespace sdds
{
	class Patient :public IOAble
	{

	private:

		char* m_patientName{};
		int m_OHIP = 0;
		Ticket ticket_Obj;
		bool file = false;

	public:

		Patient(int ticket_num = 0, bool fileIO = false);
		virtual ~Patient();
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;

		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(bool value);


		void setArrivalTime();
		operator Time()const;
		bool operator==(char compareType) const;
		bool operator==(const Patient&) const;
		int number()const;

		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);

		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};


}

#endif