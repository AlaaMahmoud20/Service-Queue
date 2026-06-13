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
	Q1.ServeNextClient();
	Q1.PrintInfo();
	Q1.PrintAllClientsTicket();
}