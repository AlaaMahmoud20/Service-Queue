#pragma once
#include <iostream>
#include <queue>
#include <string>
#include "ClsTicket.h" // Make sure to include your Ticket blueprint

using namespace std;

class ClsServiceQueue
{
private:
    string _Prefix;                 // Added: The manager must remember its own prefix (e.g., "VIP")
    float _ServiceTime;
    int _TicketCounter;
    int _ServedClientsCount;

    queue<ClsTicket> _QueueLine;    // Fixed: Tells C++ this queue specifically holds ClsTickets

    // Notice: We completely removed 'ClsTicket _Ticket;'

    float _WatingTime()
    {
        return _QueueLine.size() * _ServiceTime;
    }

public:
    // The Constructor
    ClsServiceQueue(string Prefix, float ServiceTime)
    {
        _Prefix = Prefix;
        _ServiceTime = ServiceTime;
        _TicketCounter = 1;         // Always start the counter at 1 when a new queue opens
        _ServedClientsCount = 0;
    }

   

    float IssueTicket()
    {
        ClsTicket Ticket(_Prefix, _TicketCounter);
       float ExpectedWait = _WatingTime();
        _QueueLine.push(Ticket);
        _TicketCounter++;
        return ExpectedWait;

    }

    ClsTicket ServeNextClient()
    {
        if (_QueueLine.empty()) return ClsTicket{"",0};
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
            // 1. Read the front ticket and tell it to print itself!
            _QueueLine.front().PrintTicketDetails();

            // 2. Rotate it safely to the back of the line
            ClsTicket Temp = _QueueLine.front();
            _QueueLine.pop();
            _QueueLine.push(Temp);
        }
    }

};