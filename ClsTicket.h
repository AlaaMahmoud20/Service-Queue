#pragma once



#include <string>
#include "ClsDate.h"



using namespace std;

class ClsTicket
{
private:
	string _Prefix;
	int _SequanceNumber;
	time_t _IssuedAt;
	string _ID;
	string _CreationDate;
	int _WaitingClientsBeforeMe;
	float _ExpectedWaitTime;

public:
	
	ClsTicket(string Prefix, int SequanceNumber, int WaitingClients, float ExpectedWait)
	{
		_Prefix = Prefix;
		_SequanceNumber = SequanceNumber;
		_IssuedAt = time(0);

		 _CreationDate = clsDate::GetFullCurrentDate(clsDate());

		_WaitingClientsBeforeMe = WaitingClients;
		_ExpectedWaitTime = ExpectedWait;

		
		if (_SequanceNumber < 10) {
			_ID = _Prefix + "0" + to_string(_SequanceNumber);
		}
		else {
			_ID = _Prefix + to_string(_SequanceNumber);
		}
	}
	string GetTicketID()
	{
		return _ID;
	}

	string GetPrefix()
	{
		return _Prefix;
	}

	int GetSequanceNumber()
	{
		return _SequanceNumber;
	}



	void PrintTicketDetails()
	{
		clsDate CurrentDate = clsDate::GetSystemDate();
		cout << "\n\t---------------------------------";
		cout << "\n\t\t    " << GetTicketID();
		cout << "\n\n\t  " << _CreationDate;
		cout << "\n\t  Waiting Clients : " << _WaitingClientsBeforeMe;
		cout << "\n\t  Serve Time In   : " << _ExpectedWaitTime << " Mins";
		cout << "\n\t---------------------------------\n";
	}
};