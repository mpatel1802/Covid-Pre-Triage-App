/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.cpp
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



#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds
{
	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	Time& Time::setToNow()
	{
		this->m_min = getTime();
		return *this;
	}


	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hours = 0;
		int minutes = 0;

		hours = m_min / 60;
		minutes = m_min % 60;

		ostr.setf(ios::fixed);
		if (hours >= 0 && hours < 10)
		{
			ostr.fill('0');
			ostr.width(2);
			ostr << hours;

		}
		else
		{
			ostr << hours;
		}
		ostr << ":";
		if (minutes >= 0 && minutes < 10)
		{
			ostr.fill('0');
			ostr.width(2);
			ostr << minutes;
		}
		else
		{
			ostr << minutes;
		}
		ostr.unsetf(ios::fixed);
		return ostr;

	}

	std::istream& Time::read(std::istream& istr)
	{
		int hour = 0, mins = 0;
		char colon = 'X';

		istr >> hour;
		istr >> colon;

		if (colon != ':')
		{
			istr.setstate(ios::failbit);
		}
		else
		{
			istr >> mins;
			m_min = hour * 60 + mins;
		}

		return istr;
	}

	Time& Time::operator-= (const Time& D)
	{
		int fixHour = 24 * 60;
		int multiplier = 0;

		if (m_min > (unsigned)int(D))
		{
			m_min -= int(D);
		}
		else
		{
			multiplier = (int(D) / fixHour) + 1;

			m_min = (m_min + (fixHour * multiplier)) - int(D);
		}

		return *this;
	}

	Time Time :: operator-(const Time& D)const
	{
		Time T;

		int fixHour = 24 * 60;
		int multiplier = 0;
		if (m_min > (unsigned)int(D))
		{
			T.m_min = m_min - int(D);
		}
		else
		{
			multiplier = (int(D) / fixHour) + 1;

			T.m_min = (m_min + (fixHour * multiplier)) - int(D);
		}

		return T;

	}

	Time& Time ::operator+=(const Time& D)
	{
		m_min += int(D);
		return *this;
	}

	Time Time ::operator+(const Time& D)const
	{
		Time T;
		T.m_min = m_min + int(D);
		return T;
	}

	Time& Time ::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}

	Time& Time :: operator *= (unsigned int val)
	{
		m_min *= val;
		return *this;
	}

	Time Time :: operator * (unsigned int val)const
	{
		Time T;
		T.m_min = m_min * val;
		return T;
	}

	Time& Time :: operator /= (unsigned int val)
	{
		m_min /= val;
		return *this;
	}

	Time Time :: operator/ (unsigned int val)const
	{
		Time T;
		T.m_min = m_min / val;
		return T;
	}

	Time :: operator int()const
	{
		return m_min;
	}

	Time::operator unsigned int()const
	{
		return m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);
		return istr;
	}

}