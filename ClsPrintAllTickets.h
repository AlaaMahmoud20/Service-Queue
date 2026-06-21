#pragma once
#include "ClsServiceQueue.h"
#include "ClsScreen.h"

class ClsPrintAllTickets : protected clsScreen
{
public:
   
    static void PrintAllTicketsScreen(ClsServiceQueue& Queue)
    {
        system("cls");
        string Title = "Print All Tickets Sceeen\n";
        int TotalTickets = Queue.GetTotalTicketsIssued();
        string SupTilel = " (" + (to_string(TotalTickets)) + ") Ticket(s).";
        clsScreen::_DrawScreenHeader(Title, SupTilel);
       
        if (TotalTickets == 0)cout << "\n\n \t\tNot Tickets yet !\n";

     
        else
        {
            Queue.PrintAllClientsTicket();
    
        }
    }
};