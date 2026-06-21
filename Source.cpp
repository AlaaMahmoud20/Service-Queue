#include<iostream>
#include"ClsTicket.h"
#include"ClsServiceQueue.h"
#include"ClsMainScreen.h"



using namespace std;



int main()
{
	ClsServiceQueue Q1("VIP", 6);
	
	ClsMainScreen::ShowMainMenu(Q1);
	//Q1.IssueTicket();
	//Q1.IssueTicket();
	//Q1.IssueTicket();
	//Q1.ServeNextClient();
	//Q1.PrintInfo();
	//Q1.PrintAllClientsTicket();
}