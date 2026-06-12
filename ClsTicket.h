#pragma once

//#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>


using namespace std;

class ClsTicket
{
private:
	string _Prefix;
	int _SequanceNumber;
	time_t _IssuedAt;

	
	string _ID;

	


public:
	ClsTicket(string Prefix, int SequanceNumber)
	{
		
		_Prefix = Prefix;
		_SequanceNumber = SequanceNumber;
		_IssuedAt = time(0);

		
		_ID = _Prefix + " " + to_string(_SequanceNumber);
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

	int GetWaitTime()
	{
		time_t CurrentTime = time(0);
		return (CurrentTime - _IssuedAt) / 60;
	}


	// Update your method signature from time_t to string
	string GetCreationTime()
	{
		// 1. Create a local structure directly (not a pointer)
		struct tm timeInfo;

		// 2. Pass the address of your structure and the address of your timestamp
		// (Microsoft syntax: structure first, timestamp second)
		localtime_s(&timeInfo, &_IssuedAt);

		// 3. Create the buffer
		char timeBuffer[80];

		// 4. Pass the address of timeInfo into strftime
		std::strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", &timeInfo);

		return string(timeBuffer);
	}

	void PrintTicketDetails()
	{
		cout << "\n\t---------------------------------";
		cout << "\n\t  TICKET ID    : " << GetTicketID();

		// Assuming you have a way to display the creation time string
		cout << "\n\t  ARRIVED AT   : " << GetCreationTime();

		// Displaying the dynamic clock math we built last time
		cout << "\n\t  ELAPSED TIME : " << GetWaitTime() << " Mins";
		cout << "\n\t---------------------------------\n";
	}
};