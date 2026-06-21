#pragma once
#include <iostream>
#include <queue>
#include <string>
#include "ClsTicket.h"

using namespace std;

class ClsServiceQueue
{
private:
    string _Prefix;                
    float _ServiceTime;
    int _TicketCounter;
    int _ServedClientsCount;

    queue<ClsTicket> _QueueLine;   

  

    float _ExpectedWatingTime()
    {
       
        return _QueueLine.size() * _ServiceTime;
    }

public:
   
    ClsServiceQueue(string Prefix, float ServiceTime)
    {
        _Prefix = Prefix;
        _ServiceTime = ServiceTime;
        _TicketCounter = 1;        
        _ServedClientsCount = 0;
    }

   

    void IssueTicket()
    {
        ClsTicket Ticket(_Prefix, _TicketCounter,_QueueLine.size(), _ExpectedWatingTime());
        _QueueLine.push(Ticket);
        _TicketCounter++;

    }

    ClsTicket ServeNextClient()
    {
        if (_QueueLine.empty()) return ClsTicket{"",0,0,0};
        ClsTicket CurrentTicket = _QueueLine.front();
        _QueueLine.pop();
        _ServedClientsCount++;
        return CurrentTicket ;
       
    }
    int GetServedClientsCount()
    {
        return _ServedClientsCount;
    }

    int GetWaitingClientsCount()
    {
        return _QueueLine.size();
    }
    int GetTotalTicketsIssued()
    {
        return GetServedClientsCount() + GetWaitingClientsCount();
    }

    void PrintAllClientsTicket()
    {
        int totalClients = _QueueLine.size();
        if (totalClients == 0) return;
        for (int i = 0; i < totalClients; i++)
        {
         
            _QueueLine.front().PrintTicketDetails();

            
            ClsTicket Temp = _QueueLine.front();
            _QueueLine.pop();
            _QueueLine.push(Temp);
        }
    }

    void PrintInfo()
    {
        cout << "\n\tQueue Info";

        cout << "\n\t-----------------------";
        cout << "\n\tQueue Prefix    : " << _Prefix;
                                     
                                     
        cout << "\n\tTotal Tickets   : " << GetTotalTicketsIssued();
                                     
        cout << "\n\tServed Clients  : " << _ServedClientsCount;

        cout << "\n\tWaiting Clients : " << _QueueLine.size();
        cout << "\n\t-----------------------\n";
    }
    

};