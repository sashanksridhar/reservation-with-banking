#ifndef atm
#define atm
#include "utilities.h"
#include<iostream>
FILE *ff,*fs,*fp,*fg;
using namespace std;
void scroll_note1()	//welcome note
{
		system("color FC");
	int j,i,x,y;
	for(i=0;i<27;i++)
	{
		gotoxy(i,13);cout<<" ";
		cout<<"CBIT ATM SERVICES";
		Sleep(40);
	}

	for(j=67;j>44;j--)
	{
		gotoxy(j,13);
		cout<<"WELCOMES YOU";cout<<"            ";
		Sleep(40);
	}
//	play(1);
	for (int c = 1; c <= 20; c++) //randomly printing "$"
	{
		x = rand() % 70 + 1;  y = rand() % 20 + 1;
		gotoxy(x,y);cout<<"$";
		Sleep(180);gotoxy(x,y);cout<<" ";
	}

	gotoxy(27,13);cout<<"CBIT ATM SERVICES";
	gotoxy(45,13);cout<<"WELCOMES YOU";
	for(int j=78;j>=0;j--)
	{
		gotoxy(j,20);cout<<"|";
		gotoxy(j,4);cout<<"|";
		Sleep(30);
	}
	gotoxy(56,23);cout<<"Sashank    2016103060";
	//gotoxy(56,24);cout<<"SaiCharan 160114737051";
	Sleep(2000);

}
class machine1			// class for entire program
{
	private:
	int mbno,pcode,amt,prev;
	int adl;
	int day,month,year,hour,min,sec;
	char  fname[10],sname[10],p_name[20],city[15],email[20],dob[15],type;
	char acno[7],pin[5];

	public:

	void create_account();
	void help();
	int main_menu();
	int sub_menu(int c);

	int cash_deposit(machine1,int x);
	void fund_transfer(machine1);
	void change_pin(machine1);
	void other_services(machine1);

	void fast_cash(machine1);
	int cash_withdraw(machine1,int x);
	void balance_enquiry(machine1);
	void mini_statement(machine1);

	void admin();		//admin login for verification of user accounts

	machine1 login_check();

};
int machine1:: main_menu()	//main menu for all functios included
{
	system("cls");
	system("COLOR 2F");
	frame();

	gotoxy(33,10);
	cout<<"CREATE ACCOUNT";
	gotoxy(20,14);
	cout<<"ALREADY HAVE ACCOUNT PRESS P TO PROCEED ";
	gotoxy(74,19);
	cout<<"HELP";
	char op;
	gotoxy(1,21);
	cout<<"C : Create account H : Help P : Proceed to account ";
	gotoxy(5,2);
	cout<<"ADMIN ";
	gotoxy(1,22);
	cout<<"E : Exit ";
	gotoxy(54,21);cout<<"";
	op=getch();

	if(op=='c'||op=='C')
	{
		create_account();
	}
	else if(op=='h'||op=='H')
	{
		cout<<"h";
		help();
	}
	else if(op=='p'||op=='P')
	{
		int x = sub_menu(0);
		return x;
	}
	else if(op=='a'||op=='A')
	{
		admin();
	}
	else if(op == 'e' || 'E')
    {
        return 0;
    }
	else
	{
		cout<<" \a\a\aINVALID OPTION ";
		Sleep(1000);
		main_menu();
	}

}

int machine1::sub_menu(int c)	//after user login the following fuctions are displayed
{
	system("cls");

	int cpin;




	machine1 r;
	r=login_check();
	fclose(fg);
		while(1)
		{

			int i;
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(1,6);
			cout<<"CASH DEPOSIT";
			gotoxy(1,10);
			cout<<"FUND TRANSFER";
			gotoxy(1,14);
			cout<<"PIN CHANGE";
			gotoxy(1,18);
			cout<<"OTHER SERVICES";

			gotoxy(64,6);
			cout<<"FAST CASH";
			gotoxy(64,10);
			cout<<"CASH WITHDRAWL";
			gotoxy(64,14);
			cout<<"BALANCE ENQUIRY";
			gotoxy(64,18);
			cout<<"MINI STATEMENT";
            gotoxy(28,4);
			char*s="Select your transaction";
			for(int i=0;i<24;i++)
			{
				cout<<s[i];
				Sleep(100);
			}

			int op;
			gotoxy(38,24);
			cout<<" ";
			cin>>op;
			switch(op)
			{
				case 1:
					{
						int x;
						if(c!=0)
                            x = cash_deposit(r,c);
                        else
                            x = cash_deposit(r,0);
						return x;
						break;
					}
				case 2:
					{
						fund_transfer(r);
						break;
					}
				case 3:
					{
						change_pin(r);
						break;
					}
				case 4:
					{
						other_services(r);
						break;
					}
				case 5:
					{
						fast_cash(r);
						break;
					}
				case 6:
					{
						int x;
						if(c!=0)
                             x = cash_withdraw(r,c);
                        else
                            x = cash_withdraw(r,0);
						return x;
						break;
					}
				case 7:
					{
						balance_enquiry(r);
						break;
					}
				case 8:
					{
						mini_statement(r);
						break;
					}
				default:
					{
						gotoxy(64,24);
						cout<<"Invalid Input ";
						cout<<"\a\a\a";		//terminating to mainmenu
						Sleep(1000);
						main_menu();
					}

			}
		}

}
void machine1::help()		//initial help notice in mainmenu on opening account
{
	system("cls");
	system("COLOR 70");
		for(int i=0;i<25;i++)
	{
		gotoxy(2,i);
		cout<<"|";
		gotoxy(77,i);
		cout<<"|";
	}
	gotoxy(3,0);
	cout<<"Inorder to use our ATM services be sure that,";
	gotoxy(3,2);
	cout<<"you might have already opened an account previously. ";

	gotoxy(3,22);
	cout<<"For more information, contact:";
	gotoxy(3,23);
	cout<<"Call our 24x7 helpline through toll free 1800 100 2400.";
	gotoxy(3,24);


	gotoxy(3,5);
	flow("ATM Services");
	gotoxy(3,8);
	flow("Cash Withdrawal : Use this service to withdraw amount (40,000/-per day).");
	gotoxy(3,10);
	flow("Fast Cash : This enables to withdraw your preferred amounts with a touch.");
	gotoxy(3,12);
	flow("Pin Change : Use this service to change your ATM password.");
	gotoxy(3,14);
	flow("Balance Enquiry : To check the current balance in your account.");
	gotoxy(3,16);
	flow("Ministatement : Keep track of the transactions in your account.");
	gotoxy(3,18);
	flow("Fund Transfer : Transfers amount instantly to your loved ones.");

	getch();
	main_menu();
}
void machine1::create_account()		//create account on selecting the option on main menu
{
	machine1 a;
	system("cls");
	system("COLOR F5");
	for(int i=0;i<25;i++)
	{
		gotoxy(5,i);
		cout<<"|";
		gotoxy(75,i);
		cout<<"|";
	}
	gotoxy(34,2);
	cout<<"APPLICATION FORM";
	gotoxy(10,5);
	cout<<"Enter Full Name : ";
	cin>>a.fname>>a.sname;
	gotoxy(10,7);
	cout<<"Father/Guardian : ";
	cin>>a.p_name;
	gotoxy(10,9);
	cout<<"Date Of Birth (dd/mm/yyyy) : ";
	cin>>a.dob;
	gotoxy(10,11);
	cout<<"PINCODE : ";
	cin>>a.pcode;
	gotoxy(10,15);
	cout<<"Email Id : ";
	cin>>a.email;
	gotoxy(10,17);
	cout<<"Enter initial amount( >= 500) ";
	cin>>a.amt;

	strcpy(a.pin,"6235");
    int r = rand() ;
    sprintf(a.acno, "%d", r);
	ff=fopen("atm_users.txt","a");
	fprintf(ff,"%s %s %s %s %s %s %d %s %d \n",a.acno,a.pin,a.fname,a.sname,a.p_name,a.dob,a.pcode,a.email,a.amt);
	fclose(ff);

	//initialize amount,time & date of account opened and APPENDING to transactions file
	a.adl=a.amt;	//adl = additional amount either deposit/credit
	a.prev=0;		//prev = available balance before transaction
	date d;
	d.date_times();
	a.day=d.aday;a.month=d.amonth;a.year=d.ayear;
	a.hour=d.ahour;a.min=d.amin;a.sec=d.asec;
	//to transactions file
	fp=fopen("transactions.txt","a");
	fprintf(fp,"%s %s %d %d %d %d %d %d %d %d %d \n",a.acno,a.fname,a.prev,a.adl,a.amt,a.day,a.month,a.year,a.hour,a.min,a.sec);
	fclose(fp);

	gotoxy(35,21);
	cout<<" SUBMIT";
	char c;
	c=getche();
	gotoxy(10,23);
	cout<<"Loading";
	Sleep(400);
	cout<<".";
	Sleep(400);
	cout<<".";
	Sleep(400);
	cout<<".";
	Sleep(400);

	system("cls");
	system("COLOR B0");
	frame_fix();
	gotoxy(22,5);
	cout<<"YOUR ACCOUNT HAS SUCCESSFULLY CREATED ";
	gotoxy(29,8);		//giving account deatails on that particular user
	cout<<"ACCOUNT NUMBER  : "<<a.acno;
	gotoxy(29,12);
	cout<<"ATM PIN	      : "<<a.pin;
	gotoxy(8,19);
	gotoxy(28,23);
	cout<<"MAIN MENU : PRESS ENTER";
	char op;
	op=getche();
	main_menu();
}


void machine1:: balance_enquiry(machine1 r)	//argument object recieved from login_check function
{
	system("cls");
	frame_fix();
	gotoxy(22,10);
	cout<<"ACCOUNT HOLDER NAME  : "<<r.fname;
	gotoxy(22,13);
	cout<<"CURRENT BALANCE      : "<<r.amt;
	Sleep(3000);

    system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
	main_menu();
}


int machine1:: cash_deposit(machine1 r,int x)	//argument object recieved from login_check function
{
	FILE *f1,*f2,*f3;		//declaring pointers in C style
	system("cls");
	int cash;
	frame_fix();
	gotoxy(22,6);
	if(x==0)
    {
    cout<<"PLEASE ENTER AMOUNT : ";
	cin>>cash;
    }
    else
        {
            r = login_check();
            cash = x;
        }
	machine1 g;
	g.prev=r.amt;		//holding available balance before transaction which equals to present previous amount
	g.amt=r.amt+cash;	//present amount equals to amount sum of current transaction + prevs avilable balance
	strcpy(g.acno,r.acno);strcpy(g.fname,r.fname);strcpy(g.sname,r.sname);
	strcpy(g.pin,r.pin);
	g.adl=cash;			// additional amount will be currents transaction amount



	date d;
	d.date_times();
	g.day=d.aday;g.month=d.amonth;g.year=d.ayear;
	g.hour=d.ahour;g.min=d.amin;g.sec=d.asec;

	//transacton APPENDING to transactions file
	machine1 a;
    ifstream fk;
    ofstream fl;
    fk.open("transactions.txt");
		fl.open("temp.txt");
	machine1 b,q;
	fk>>b.acno;
    while(!fk.eof())
	{
         fk>>b.fname>>b.prev>>b.adl>>b.amt>>b.day>>b.month>>b.year>>b.hour>>b.min>>b.sec;
         if(strcmp(g.acno,b.acno)==0)
    		{
    		   b.prev = g.prev;
    		   b.adl = g.adl;
    		   b.amt = g.amt;
    		   b.day = g.day;
    		   b.month = g.month;
    		   b.year = g.year;
    		   b.hour = g.hour;
    		   b.min = g.min;
    		   b.sec = g.sec;
    		}
        fl<<"\n"<<b.acno<<" "<<b.fname<<" "<<b.prev<<" "<<b.adl<<" "<<b.amt<<" "<<b.day<<" "<<b.month<<" "<<b.year<<" "<<b.hour<<" "<<b.min<<" "<<b.sec;
        fk>>b.acno;
    }
    fk.close();
    fl.close();
    delr2();
    fk.open("atm_users.txt");
    fl.open("temp.txt");
    fk>>b.acno;
    while(!fk.eof())
	{
	       fk>>b.pin>>b.fname>>b.sname>>b.p_name>>b.dob>>b.pcode>>b.email>>b.amt;
         if(strcmp(g.acno,b.acno)==0)
    		b.amt = g.amt;
        fl<<"\n"<<b.acno<<" "<<b.pin<<" "<<b.fname<<" "<<b.sname<<" "<<b.p_name<<" "<<b.dob<<" "<<b.pcode<<" "<<b.email<<" "<<b.amt;
        fk>>b.acno;
    }
    fk.close();
    fl.close();
    delr1();
    system("cls");
    frame_fix();
    gotoxy(18,12);
	cout<<"AMOUNT DEPOSITED  : "<<g.adl<<" FINAL BALANCE : "<<g.amt;
	Sleep(3000);
    system("cls");
	gotoxy(18,13);
	cout<<"	      PLEASE WAIT VALIDATING THE CASH		";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
    //delr2();	//calling file delete function bottom section of the code
    if(x!=0)
        return 0;
    main_menu();
}

int machine1:: cash_withdraw(machine1 r,int x)	//argument object recieved from login_check function
{
	FILE *f1,*f2,*f3;		//declaring pointers in C style
	system("cls");
	int cash;
	frame_fix();
	gotoxy(22,6);
	if(x==0)
	{
	    cout<<"PLEASE ENTER AMOUNT : ";
	cin>>cash;
	}
	else
        {
            r = login_check();
            cash = x;

        }
	if(cash>r.amt)
	{
		gotoxy(15,13);
		cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
		Sleep(1000);
		return 1;
		main_menu();
	}

	machine1 g;
	g.prev=r.amt;
	g.amt=r.amt-cash;		//present amount equals to amount sum of current transaction - prevs avilable balance
	strcpy(g.acno,r.acno);strcpy(g.fname,r.fname);strcpy(g.sname,r.sname);
	strcpy(g.pin,r.pin);
	g.adl=cash;


	date d;
	d.date_times();
	g.day=d.aday;g.month=d.amonth;g.year=d.ayear;
	g.hour=d.ahour;g.min=d.amin;g.sec=d.asec;
	//transacton APPENDING to transactions file
	machine1 a;
	ifstream fk;
    ofstream fl;
    fk.open("transactions.txt");
		fl.open("temp.txt");
	machine1 b,q;
	fk>>b.acno;
    while(!fk.eof())
	{
         fk>>b.fname>>b.prev>>b.adl>>b.amt>>b.day>>b.month>>b.year>>b.hour>>b.min>>b.sec;
         if(strcmp(g.acno,b.acno)==0)
    		{
    		   b.prev = g.prev;
    		   b.adl = g.adl;
    		   b.amt = g.amt;
    		   b.day = g.day;
    		   b.month = g.month;
    		   b.year = g.year;
    		   b.hour = g.hour;
    		   b.min = g.min;
    		   b.sec = g.sec;
    		}
        fl<<"\n"<<b.acno<<" "<<b.fname<<" "<<b.prev<<" "<<b.adl<<" "<<b.amt<<" "<<b.day<<" "<<b.month<<" "<<b.year<<" "<<b.hour<<" "<<b.min<<" "<<b.sec;
        fk>>b.acno;
    }
    fk.close();
    fl.close();
    delr2();
    fk.open("atm_users.txt");
    fl.open("temp.txt");
    fk>>b.acno;
    while(!fk.eof())
	{
	       fk>>b.pin>>b.fname>>b.sname>>b.p_name>>b.dob>>b.pcode>>b.email>>b.amt;
         if(strcmp(g.acno,b.acno)==0)
    		b.amt = g.amt;
        fl<<"\n"<<b.acno<<" "<<b.pin<<" "<<b.fname<<" "<<b.sname<<" "<<b.p_name<<" "<<b.dob<<" "<<b.pcode<<" "<<b.email<<" "<<b.amt;
        fk>>b.acno;
    }
    fk.close();
    fl.close();
    delr1();

    system("cls");
    frame_fix();
    gotoxy(18,12);
	cout<<"AMOUNT WITHDRAWN  : "<<g.adl<<" FINAL BALANCE : "<<g.amt;
	Sleep(3000);
    system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       ";
	Sleep(100);
	gotoxy(30,16);//play(2);
	cout<<"PLEASE COLLECT CASH \a\a";
	Sleep(1000);
	if(x!=0)
	return 0;
	//delr1();	//calling file delete function bottom section of the code
    main_menu();getch();
}


void machine1:: mini_statement(machine1 r)	//argument object recieved from login_check function
{
	system("cls");
	FILE *fm;		//declaring pointer in C style
	int l;
		system("COLOR E0");
	for(int i=0;i<24;i++)
	{
		gotoxy(2,i);
		cout<<"|";
		gotoxy(77,i);
		cout<<"|";
	}
	gotoxy(6,1);
	cout<<"DATE";
	gotoxy(17,1);
	cout<<"TIME";
	gotoxy(27,1);
	cout<<"TRANSACTION  TYPE";
	gotoxy(51,1);
	cout<<"AMOUNT";
	gotoxy(62,1);
	cout<<"FINAL BALANCE";
	machine1 n;			//checking account numer of current and to trasactions file
						//whenever it returns true it prints the transaction
	fm=fopen("transactions.txt","r");
	l=3;
	while(fscanf(fm,"%s %s %d %d %d %d %d %d %d %d %d \n",n.acno,n.fname,&n.prev,&n.adl,&n.amt,&n.day,&n.month,&n.year,&n.hour,&n.min,&n.sec)!=EOF)
	{
		if(strcmp(r.acno,n.acno)==0)
		{
			gotoxy(3,l);
			if(n.amt>n.prev&&n.prev!=0)	//for first , to the user prev amt = 0
			{
			cout<<setw(2)<<n.day<<"/"<<setw(2)<<n.month<<"/"<<n.year<<"   "<<setw(2)<<n.hour<<":"<<setw(2)<<n.min<<":"<<setw(2)<<n.sec;
			cout<<setw(18)<<"CASH DEPOSITED"<<setw(15)<<n.adl<<setw(18)<<n.amt;
			}
			else if(n.amt<n.prev)
			{
			cout<<setw(2)<<n.day<<"/"<<setw(2)<<n.month<<"/"<<n.year<<"   "<<setw(2)<<n.hour<<":"<<setw(2)<<n.min<<":"<<setw(2)<<n.sec;
			cout<<setw(19)<<"CASH WITHDRAWAL"<<setw(14)<<n.adl<<setw(18)<<n.amt;
			}
			else if(n.amt>n.prev&&n.prev==0)	//for first , to the user prev amt = 0
			{
			cout<<setw(2)<<n.day<<"/"<<setw(2)<<n.month<<"/"<<n.year<<"   "<<setw(2)<<n.hour<<":"<<setw(2)<<n.min<<":"<<setw(2)<<n.sec;
			cout<<setw(18)<<"ACCOUNT OPENED"<<setw(15)<<n.adl<<setw(18)<<n.amt;
			}
			l=l+2;
		}
	}

	fclose(fm);
	getch();
	system("cls");
	frame_fix();
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"      TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
	main_menu();

}

void machine1::fast_cash(machine1 r)	//argument object recieved from login_check function
{

	FILE *fr,*fs,*ft;		//declaring pointers in C style
	system("cls");
	frame_fix();
	int choice;
	machine1 g;
	g.prev=r.amt;
	strcpy(g.acno,r.acno);strcpy(g.fname,r.fname);strcpy(g.sname,r.sname);
	strcpy(g.pin,r.pin);
	gotoxy(26,5);
	flow("SELECT YOUR TRANSACTION AMOUNT");
	gotoxy(11,7);
	cout<<"100";
	gotoxy(11,12);
	cout<<"500";
	gotoxy(10,17);
	cout<<"1000";
	gotoxy(64,7);
	cout<<"1500";
	gotoxy(64,12);
	cout<<"2500";
	gotoxy(64,17);
	cout<<"5000 ";
	gotoxy(38,24);
	cout<<"";
	cin>>choice;
	switch(choice)
	{
		case 1:
			g.adl=100;

			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-100;
			break;
		case 2:
			g.adl=500;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-500;
			break;
		case 3:
			g.adl=1000;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-1000;
			break;
		case 4:
			g.adl=1500;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-1500;
			break;
		case 5:
			g.adl=2500;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-2500;
			break;
		case 6:
			g.adl=5000;
			if(g.adl>r.amt)
			{
				system("cls");
				gotoxy(15,13);
				cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
				Sleep(1000);main_menu();
			}
			g.amt=r.amt-5000;
			break;
		default:
			cout<<"INVALID OPTION \a\a\a";
			Sleep(1000);
			main_menu();
	}



	date d;
	d.date_times();
	g.day=d.aday;g.month=d.amonth;g.year=d.ayear;
	g.hour=d.ahour;g.min=d.amin;g.sec=d.asec;
	//transacton APPENDING to transactions file
	machine1 a;
    ifstream fk;
    ofstream fl;
    fk.open("transactions.txt");
		fl.open("temp.txt");
	machine1 b,q;
	fk>>b.acno;
    while(!fk.eof())
	{
         fk>>b.fname>>b.prev>>b.adl>>b.amt>>b.day>>b.month>>b.year>>b.hour>>b.min>>b.sec;
         if(strcmp(g.acno,b.acno)==0)
    		{
    		   b.prev = g.prev;
    		   b.adl = g.adl;
    		   b.amt = g.amt;
    		   b.day = g.day;
    		   b.month = g.month;
    		   b.year = g.year;
    		   b.hour = g.hour;
    		   b.min = g.min;
    		   b.sec = g.sec;
    		}
        fl<<"\n"<<b.acno<<" "<<b.fname<<" "<<b.prev<<" "<<b.adl<<" "<<b.amt<<" "<<b.day<<" "<<b.month<<" "<<b.year<<" "<<b.hour<<" "<<b.min<<" "<<b.sec;
        fk>>b.acno;
    }
    fk.close();
    fl.close();
    delr2();
    fk.open("atm_users.txt");
    fl.open("temp.txt");
    fk>>b.acno;
    while(!fk.eof())
	{
	       fk>>b.pin>>b.fname>>b.sname>>b.p_name>>b.dob>>b.pcode>>b.email>>b.amt;
         if(strcmp(g.acno,b.acno)==0)
    		b.amt = g.amt;
        fl<<"\n"<<b.acno<<" "<<b.pin<<" "<<b.fname<<" "<<b.sname<<" "<<b.p_name<<" "<<b.dob<<" "<<b.pcode<<" "<<b.email<<" "<<b.amt;
        fk>>b.acno;
    }
    fk.close();
    fl.close();
    delr1();

    system("cls");
    frame_fix();
    gotoxy(20,13);
	cout<<"AMOUNT WITHDRAWN : "<<g.adl<<" FINAL BALANCE : "<<g.amt;
	Sleep(3000);
    system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       ";
	Sleep(100);
    gotoxy(32,16);//play(2);
	cout<<"PLEASE COLLECT CASH \a\a";
	Sleep(1000);
	//delr1();	//calling file delete function bottom section of the code
    main_menu();getch();

}

void machine1::fund_transfer(machine1 r)	//argument object recieved from login_check function
{
	system("cls");
	frame_fix();

	FILE *fk,*fl,*fm,*fn;		//declaring pointers in C style
	char racno[7],rracno[7];
	int famt;
	gotoxy(22,6);
	cout<<"ENTER RECEPIENT'S ACCOUNT NUMBER : ";
	cin>>racno;
	gotoxy(22,8);
	cout<<"CONFIRM ACCOUNT NUMBER           : ";
	cin>>rracno;
	if(strcmp(racno,rracno)==0)
	{}
	else
	{
		system("cls");
		gotoxy(24,14);
		cout<<"GIVEN ACCOUNT NUMBER DOES NOT MATCH \a\a\a";
		Sleep(1000);
		main_menu();
	}
	gotoxy(22,11);
	cout<<"PLEASE ENTER AMOUNT              : ";
	cin>>famt;
	if(famt>r.amt)
	{
		gotoxy(15,13);
		cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
		Sleep(1000);
		main_menu();
	}

	machine1 g;
	g.prev=r.amt;g.amt=r.amt-famt;g.adl=famt;
	strcpy(g.acno,r.acno);strcpy(g.fname,r.fname);
	strcpy(g.pin,r.pin);

	date d;
	d.date_times();
	g.day=d.aday;g.month=d.amonth;g.year=d.ayear;
	g.hour=d.ahour;g.min=d.amin;g.sec=d.asec;
		//transacton APPENDING to transactions file
	machine1 a,b;
	fl=fopen("transactions.txt","a");
	fprintf(fl,"%s %s %d %d %d %d %d %d %d %d %d \n",g.acno,g.fname,g.prev,g.adl,g.amt,g.day,g.month,g.year,g.hour,g.min,g.sec);
	fclose(fl);
		//finding current account details to accounts file for changing amount and also transfer account
	fm=fopen("accounts.txt","r");
    fn=fopen("temp.txt","w");
    while(fscanf(fm,"%s %s %s %s %d \n",a.acno,a.pin,a.fname,a.sname,&a.amt)!=EOF)
    {
    	if(strcmp(g.acno,a.acno)==0)		//transfer account
    	a.amt=g.amt;

    	else if(strcmp(racno,a.acno)==0)	//currnet account
    	{

    		b=a;
    		b.prev=a.amt;b.amt=a.amt+famt;b.adl=famt;	//transacton APPENDING to transactions file
    			fk=fopen("transactions.txt","a");
				fprintf(fk,"%s %s %d %d %d %d %d %d %d %d %d \n",b.acno,b.fname,b.prev,b.adl,b.amt,g.day,g.month,g.year,g.hour,g.min,g.sec);
				fclose(fk);

			a.amt=a.amt+famt;

    	}

    	fprintf(fn,"%s %s %s %s %d \n",a.acno,a.pin,a.fname,a.sname,a.amt);
    }
	fclose(fn);
	fclose(fm);

	system("cls");
	frame_fix();

	gotoxy(18,13);
	cout<<"AMOUNT TRANSFERRED : "<<famt<<" FINAL BALANCE : "<<g.amt;
    Sleep(3000);
	system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
    delr1();	//calling file delete function bottom section of the code
    main_menu();getch();



}

void machine1::change_pin(machine1 g)	//argument object recieved from login_check function
{

	system("cls");
	frame_fix();

	ifstream fk;
	ofstream fl;
	char npin1[5],npin2[5];
	gotoxy(2,11);
	cout<<"YOUR PIN IS CONFIDENTIAL";
	gotoxy(2,13);
	cout<<"NOBODY SHOULD SEE THE PIN";
	gotoxy(2,15);
	cout<<"WHILE YOU ARE ENTERING IT.";
	gotoxy(2,17);
	cout<<"MAKE YOUR PIN MORE SECURE BY";
	gotoxy(2,19);
	cout<<"CHANGING IT FREQUENTLY.";
	gotoxy(30,6);
	cout<<"ENTER NEW PIN : ";
	cin>>npin1;
	gotoxy(30,8);
	cout<<"CONFIRM PIN   : ";
	cin>>npin2;
	machine1 a;
	if(strcmp(npin1,npin2)==0)
	{
		fk.open("atm_users.txt");
		fl.open("temp.txt");
	machine1 b,q;
	fk>>b.acno;
    while(!fk.eof())
	{
         fk>>b.pin>>b.fname>>b.sname>>b.p_name>>b.dob>>b.pcode>>b.email>>b.amt;
         if(strcmp(g.acno,b.acno)==0)
    		strcpy(b.pin,npin1);
        fl<<"\n"<<b.acno<<" "<<b.pin<<" "<<b.fname<<" "<<b.sname<<" "<<b.p_name<<" "<<b.dob<<" "<<b.pcode<<" "<<b.email<<" "<<b.amt;
        fk>>b.acno;
    }
    fk.close();
    fl.close();
	}
	else
	{
		gotoxy(40,16);
		cout<<"Password do not match try after some time \a\a\a";
		Sleep(1000);
		main_menu();
	}
	system("cls");
	frame_fix();
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"      TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
	delr1();	//calling file delete function bottom section of the code
	main_menu();

}
void machine1::other_services(machine1 r)	//argument object recieved from login_check function
{
	system("cls");
	system("COLOR 70");
	for(int i=0;i<25;i++)
	{
		gotoxy(2,i);
		cout<<"|";
		gotoxy(77,i);
		cout<<"|";
	}

	gotoxy(3,0);
	cout<<"Good to see here ";
	gotoxy(59,0);
	cout<<"Mr."<<r.fname<<"_"<<r.sname;//name of user on top right
	gotoxy(32,1);
	cout<<"POINTS TO NOTE";gotoxy(3,3);
	flow("Ensure that you change the PIN number after first using your card also");gotoxy(3,4);
	flow("frequently change PIN number");
	gotoxy(3,6);
	flow("Ensure that nobody else can see you entering your PIN number at the ATM.");
	gotoxy(3,8);
	flow("Do not use the ATM machine when strangers are inside the ATM counter.");
	gotoxy(3,10);
	flow("Do not seek the assistance of strangers while operating the ATM machine.");
	gotoxy(3,12);
	flow("Should you notice anything strange or suspicious at the ATM counter please");
	gotoxy(3,13);
	flow("refrain from using  the same.");
	gotoxy(3,15);
	flow("Ensure that you check your account statement from time to time.");
	gotoxy(3,17);
	flow("In case you lose your ATM card call 1800-425-3800 to block your card and ");
	gotoxy(3,18);
	flow("this avoid misuse of the card.");
	gotoxy(3,20);
	flow("Do not disclose your PIN number to others IBO/RBI or any other Government,");
	gotoxy(3,21);
	flow("Banking institutions will never require you to disclose your PIN number.");
//	play(3);
	gotoxy(3,23);
	flow("-------------------------------");
	gotoxy(45,23);
	flow("--------------------------------");
	gotoxy(35,23);
	cout<<" THANK YOU ";Sleep(1000);
	gotoxy(78,24);cout<<"";
	system("cls");
	system("color 2F");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESFSFULLY       \a\a";
	Sleep(1000);
	main_menu();
}

//different function than all functions till
//access of all details of every user account
void machine1 :: admin()
{
	char addname[15],pass[8];
	char adname[]="sashank";
	char password[]="password";
	system("cls");
	gotoxy(25,13);
	cout<<"Enter name of the admin : ";
	cin>>addname;
	if(strcmp(adname,addname)==0)
	{
		gotoxy(25,15);
		cout<<"Enter password : ";
		cin>>pass;
		if(strcmp(password,pass)==0)
		{
			while(1)
			{
				system("cls");
				int op;gotoxy(10,9);
				cout<<"1.ACCOUNT MEMBERS ";gotoxy(10,11);
				cout<<"2.ACCOUNT TRANSACTIONS ";gotoxy(10,13);
				cout<<"3.MAIN MENU ";gotoxy(10,16);
				cout<<"Select : ";
				cin>>op;

				if(op==1)
				{
					system("cls");
					FILE *fy;machine1 b;int i=3;
					fy=fopen("atm_users.txt","r");//all information from accounts file
					gotoxy(0,1);
					cout<<"ACC NUM   FULL NAME   DOB      CITY     EMAIL      PIN";
  	  				string line;
                    ifstream myfile ("atm_users.txt");
                    if (myfile.is_open())
                    {
                        while ( getline (myfile,line) )
                        {
                            cout << '\n'<<line << '\n';
                        }
                        myfile.close();
                    }
  	  				getch();
				}
				else if(op==2)
				{
					system("cls");
					FILE *fz;machine1 z;int l;
					gotoxy(6,1);
					cout<<"DATE";
					gotoxy(17,1);
					cout<<"TIME";
					gotoxy(27,1);
					cout<<"TRANSACTION  TYPE";
					gotoxy(51,1);
					cout<<"AMOUNT";
					gotoxy(62,1);
					cout<<"FINAL BALANCE";

					fz=fopen("transactions.txt","r");	//all information from transactions file
					l=3;
					while(fscanf(fz,"%s %s %d %d %d %d %d %d %d %d %d \n",z.acno,z.fname,&z.prev,&z.adl,&z.amt,&z.day,&z.month,&z.year,&z.hour,&z.min,&z.sec)!=EOF)
					{
							gotoxy(3,l);
							if(z.amt>z.prev&&z.prev!=0)
							{
								cout<<setw(2)<<z.acno<<" "<<z.fname<<" "<<z.day<<"/"<<setw(2)<<z.month<<"/"<<z.year<<"   "<<setw(2)<<z.hour<<":"<<setw(2)<<z.min<<":"<<setw(2)<<z.sec;
								cout<<setw(18)<<"CASH DEPOSITED"<<setw(15)<<z.adl<<setw(18)<<z.amt;
							}
							else if(z.amt<z.prev)
							{
								cout<<setw(2)<<z.acno<<" "<<z.fname<<" "<<z.day<<"/"<<setw(2)<<z.month<<"/"<<z.year<<"   "<<setw(2)<<z.hour<<":"<<setw(2)<<z.min<<":"<<setw(2)<<z.sec;
								cout<<setw(19)<<"CASH WITHDRAWAL"<<setw(14)<<z.adl<<setw(18)<<z.amt;
							}
							else if(z.amt>z.prev&&z.prev==0)
							{
								cout<<setw(2)<<z.acno<<" "<<z.fname<<" "<<z.day<<"/"<<setw(2)<<z.month<<"/"<<z.year<<"   "<<setw(2)<<z.hour<<":"<<setw(2)<<z.min<<":"<<setw(2)<<z.sec;
								cout<<setw(18)<<"ACCOUNT OPENED"<<setw(15)<<z.adl<<setw(18)<<z.amt;
							}
							l=l+2;
					}

					fclose(fz);
					getch();
				}
				else
				{
					system("cls");gotoxy(35,13);
					cout<<"INVALID OPTION \a\a\a";
					main_menu();
				}
			}
		}
		else
		{
			system("cls");
			gotoxy(25,17);
			cout<<"INVALID USERNAME OR PASSWORD \a\a\a";
			getch();main_menu();
		}
	}
}
machine1 machine1::login_check()
{
	system("cls");
	system("COLOR 1F");
	frame();
	string apin,aacno;
	int cnt,e=0;
	char x,y;char p1,p2,p3,p4;p1=p2=p3=p4=0;
	char ans;
	system("cls");
	gotoxy(24,12);
	cout<<" PLEASE ENTER YOUR ACCOUNT NUMBER ";
	gotoxy(37,16);
	cin>>aacno;
	system("cls");
	frame();
	gotoxy(34,2);
	cout<<"CITY BANK OF CBIT";
	gotoxy(56,2);
	cout<<"                        ";
	gotoxy(32,5);
	cout<<"PLEASE ENTER YOUR PIN";

	gotoxy(2,11);
	cout<<"YOUR PIN IS CONFIDENTIAL";
	gotoxy(2,13);
	cout<<"NOBODY SHOULD SEE THE PIN";
	gotoxy(2,15);
	cout<<"WHILE YOU ARE ENTERING IT.";
	gotoxy(2,17);
	cout<<"MAKE YOUR PIN MORE SECURE BY";
	gotoxy(2,19);
	cout<<"CHANGING IT FREQUENTLY.";

	gotoxy(38,22);
cin>>apin;
ifstream f;
   	f.open("atm_users.txt");
	machine1 b,q;
    while(!f.eof())
	{
         f>>b.acno>>b.pin>>b.fname>>b.sname>>b.p_name>>b.dob>>b.pcode>>b.email>>b.amt;
    	if(strcmp(aacno.c_str(),b.acno)==0)
    	{
			q=b;
			if(strcmp(apin.c_str(),b.pin)==0)
			{
				gotoxy(2,8);

				cout<<"HELLO__MR."<<b.fname;
				Sleep(1000);
				return q;
			}
			else
			{
				Sleep(1000);
				cout <<"\a\a\aINCORRECT PIN";
				Sleep(1000);
				login_check();
			}

		}
		cnt++;
		e++;

	}

	if(cnt==0&&e<3)
	{
		gotoxy(30,24);
		cout<<"No account  exits of given data. ";
		sub_menu(0);
	}
		else if(cnt==0&&e==3)
		{
			gotoxy(30,24);
			cout<<"\nThe service for respective account is temporarily stopped. Please try again later.";
			main_menu();
		}

	fclose(fg);
}
#endif
