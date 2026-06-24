#pragma once
#include"ClsServiceQueue.h"
#include"ClsInputValidate.h"
#include"ClsPrintAllTickets.h"
#include<iomanip>

class ClsMainScreen
{
private:

	enum MainScreenOptions 
	{ 
		eIsueNewTicket = 1,
		eServeNextClient = 2,
		ePrintAllTickets = 3,
		eExit = 4

	};
	static short _GetChoice()
	{
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 4);
		return Choice;
	}
	static void _BackToMainScreen(ClsServiceQueue& Queue)
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenu(Queue);

	}
	static void _DrawMainMenu(ClsServiceQueue& Queue)
	{
		// 1. Clear the screen so it looks clean every time
		system("cls");

		// 2. Print the Header and Live Stats
		cout << "\n\t===================================";
		cout << "\n\t        ATMOS BANK QUEUE";
		cout << "\n\t===================================";

	
		Queue.PrintInfo();

		
		cout << "\n\t===================================";
		cout << "\n\t  [1] Issue New Ticket";
		cout << "\n\t  [2] Serve Next Client";
		cout << "\n\t  [3] Print All Waiting Tickets";
		cout << "\n\t  [4] Exit Program";
	
		
		cout << "\n\t===================================";
		cout << "\n\tPlease enter your choice [1-4]: ";
	}
	static void _PerformIssueTicketOption(ClsServiceQueue&Queue)
	{
		Queue.IssueTicket();
	
	}

	static void _PerformServeNextClientOption(ClsServiceQueue& Queue)
	{
		Queue.ServeNextClient();
	}

	static void _PerformPrintAllTicketsOption(ClsServiceQueue& Queue)
	{
		ClsPrintAllTickets::PrintAllTicketsScreen(Queue);
	}

	static void _PerformOptions(MainScreenOptions Option, ClsServiceQueue& Queue)
	{
		switch (Option)
		{
			case MainScreenOptions::eIsueNewTicket:
			{
				_PerformIssueTicketOption(Queue);
				ShowMainMenu(Queue);
				break;


			}

			case MainScreenOptions::eServeNextClient:
			{
				_PerformServeNextClientOption(Queue);
				ShowMainMenu(Queue);
				break;


			}
			case MainScreenOptions::ePrintAllTickets:
			{
				_PerformPrintAllTicketsOption(Queue);
				_BackToMainScreen(Queue);
				break;

			}
		}
	}
public :
	static void ShowMainMenu(ClsServiceQueue& Queue)
	{
		while (true)
		{
			_DrawMainMenu(Queue);
			MainScreenOptions Choice = (MainScreenOptions)_GetChoice();

			if (Choice == MainScreenOptions::eExit)
			{
				system("cls");
				cout << "\n\n\t\tClosing the system. Have a great day!\n\n";
				return;
			}

			_PerformOptions(Choice, Queue);
		}
	}

};

/*[1] Issue New Ticket
  [2] Serve Next Client
  [3] Print All Waiting Tickets
  [4] Exit Program
 */