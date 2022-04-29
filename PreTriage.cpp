/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: PreTriage.cpp
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
#include<fstream>

#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"

using namespace std;

namespace sdds
{

	PreTriage::PreTriage(const char* dataFileName) :m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{

		m_dataFilename = new char[strlen(dataFileName) + 1];
		strcpy(m_dataFilename, dataFileName);

		PreTriage::load();

	}

	PreTriage::~PreTriage()
	{
		ofstream openFile(m_dataFilename);

		if (openFile)
		{

			cout << "Saving Average Wait Times," << endl;
			cout << "   COVID Test: " << m_averCovidWait << endl;
			cout << "   Triage: " << m_averTriageWait << endl;

			openFile << m_averCovidWait << "," << m_averTriageWait << endl;
			cout << "Saving m_lineup..." << endl;

			for (int i = 0; i < m_lineupSize; i++)
			{
				cout << i + 1 << "- ";
				m_lineup[i]->csvWrite(cout) << endl;
				m_lineup[i]->csvWrite(openFile) << endl;

			}

			for (int i = 0; i < m_lineupSize; i++)
			{
				delete m_lineup[i];
			}

			delete[] m_dataFilename;
			m_dataFilename = nullptr;

			cout << "done!" << endl;
		}
	}


	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		unsigned int count = 0;

		Time product;

		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type())
			{
				count++;
			}
		}

		product = Time(p) * count;

		return product;

	}


	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		Time current = Time(getTime());
		Time patient = Time(p);

		unsigned int patient_ticket_num = p.number();

		if (p.type() == 'C')
		{
			m_averCovidWait = ((current - patient) + (m_averCovidWait * (patient_ticket_num - 1))) / patient_ticket_num;
		}
		else
		{
			m_averTriageWait = ((current - patient) + (m_averTriageWait * (patient_ticket_num - 1))) / patient_ticket_num;
		}
	}


	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int return_value = -1;
		bool loop = true;

		for (int i = 0; i < m_lineupSize && loop; i++)
		{
			if (m_lineup[i]->type() == type)
			{
				loop = false;
				return_value = i;
			}
		}

		return return_value;

	}


	void PreTriage::load()
	{
		Patient* patient_ptr;
		char type;

		ifstream openFile(m_dataFilename);

		cout << "Loading data..." << endl;

		openFile >> m_averCovidWait;
		openFile.ignore();
		openFile >> m_averTriageWait;
		openFile.ignore(100, '\n');

		for (int i = 0; i < maxNoOfPatients && openFile; i++)
		{
			type = 'x';
			openFile >> type;
			openFile.ignore();

			patient_ptr = nullptr;

			if (type == 'C')
			{
				patient_ptr = new CovidPatient();
			}
			else if (type == 'T')
			{
				patient_ptr = new TriagePatient();
			}

			if (patient_ptr)
			{
				patient_ptr->fileIO(true);
				openFile >> *patient_ptr;
				patient_ptr->fileIO(false);

				m_lineup[i] = patient_ptr;
				m_lineupSize++;
			}
		}

		if (openFile)
		{
			cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
		}

		if (m_lineupSize == 0)
		{
			cout << "No data or bad data file!" << endl;
		}
		else
		{
			cout << m_lineupSize << " Records imported..." << endl;
		}

		cout << endl;
	}

	void PreTriage::reg()
	{
		int selection = 0;

		if (m_lineupSize == maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			m_pMenu >> selection;
			switch (selection)
			{

			case 1:

				m_lineup[m_lineupSize] = new CovidPatient();
				break;

			case 2:

				m_lineup[m_lineupSize] = new TriagePatient();
				break;

			case 0:

				break;

			}

			m_lineup[m_lineupSize]->setArrivalTime();
			cout << "Please enter patient information: " << endl;

			m_lineup[m_lineupSize]->fileIO(false);
			m_lineup[m_lineupSize]->read(cin);

			cout << endl << "******************************************" << endl;
			m_lineup[m_lineupSize]->write(cout);
			cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
			cout << "******************************************" << endl << endl;

			m_lineupSize++;
		}
	}

	void PreTriage::admit()
	{

		char type = 'x';
		int selection = 0;

		m_pMenu >> selection;

		switch (selection)
		{
		case 1:

			type = 'C';
			break;

		case 2:

			type = 'T';
			break;

		case 0:

			break;
		}

		int nextPatient = indexOfFirstInLine(type);

		if (nextPatient == -1)
		{
			return;
		}
		else
		{
			m_lineup[nextPatient]->fileIO(false);

			cout << endl;
			cout << "******************************************" << endl;
			cout << "Calling for ";
			m_lineup[nextPatient]->write(cout);
			cout << "******************************************" << endl << endl;

			setAverageWaitTime(*m_lineup[nextPatient]);
			removePatientFromLineup(nextPatient);

		}

	}


	void PreTriage::run(void)
	{
		int selection = 0;
		bool flag = true;

		do
		{
			m_appMenu >> selection;
			switch (selection)
			{

			case 1:

				reg();
				break;

			case 2:

				admit();
				break;

			case 0:

				flag = false;
				break;

			}
		} while (flag);
	}


}


