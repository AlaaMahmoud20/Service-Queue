#include<iostream>
#include"ClsTicket.h"
#include"ClsServiceQueue.h"


using namespace std;



int main()
{
	ClsServiceQueue Q1("VIP", 6);
	Q1.IssueTicket();
	Q1.IssueTicket();
	Q1.IssueTicket();
	Q1.PrintAllClientsTicket();
	Q1.ServeNextClient();
	cout<<"\nServed Client:"<<Q1.GetServedClientsCount()<<"\n";
	cout<<"\nWating clients:"<<Q1.GetWaitingClientsCount() << "\n";
	cout << "All tickets : " << Q1.GetTotalTicketsIssued() << "\n";
	//cout << "hi";
}