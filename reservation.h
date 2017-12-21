#ifndef reservation
#define reservation
#include<iostream>
#include"utilities.h"
#include"atm.h"
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//FILE *ff,*fs,*fp;
int r,c;
struct data
{
    int seat_number;
    int status;
    int price;
    int account;
};
void scroll_note()	//welcome note
{
		system("color FC");
	int j,i,x,y;
	for(i=0;i<27;i++)
	{
		gotoxy(i,13);cout<<" ";
		cout<<"RESERVATION SYSTEM";
		Sleep(40);
	}

	for(j=67;j>44;j--)
	{
		gotoxy(j,13);
		cout<<"WELCOMES YOU";cout<<"            ";
		Sleep(40);
	}

	for (int c = 1; c <= 20; c++)  //randomly printing "$"
	{

		x = rand() % 70 + 1;  y = rand() % 20 + 1;
		gotoxy(x,y);cout<<"$";
		Sleep(180);gotoxy(x,y);cout<<" ";
	}

	gotoxy(27,13);cout<<"RESERVATION SYSTEM ";
	gotoxy(45,13);cout<<"WELCOMES YOU";
	for(int j=78;j>=0;j--)
	{
		gotoxy(j,20);cout<<"|";
		gotoxy(j,4);cout<<"|";
		Sleep(30);
	}
	gotoxy(56,23);cout<<"Sashank 2016103060";
	Sleep(2000);

}
class machine		//class for entire program
{
	private:
	int mbno,pcode,amt,prev;
	int adl;
	int day,month,year,hour,min,sec;
	string  fname,sname,p_name,city,email,dob,type;
	string acno,pin;

	public:
    struct data *s;
	void create_account();  //creates user accounts
	void help();            //help menu
	void main_menu();       //main menu
	void sub_menu();        //sub menu within main menu
    void admin();		//admin login for verification of user accounts
    void view();        //view arrangement details
    void book(machine);     //book tickets
	void ticket(machine);   //view ticket details
	void cancel(machine);   //cancel tickets
	void waitlist(machine);     //add wait list
	machine login_check();      //checks user login

};
machine machine::login_check()
{
	system("cls");
	system("COLOR 1F");
	frame();
	char aacno[7]={0};
	string apin;
	int cnt,e=0;
	char x,y;char p1,p2,p3,p4;p1=p2=p3=p4=0;
	char ans;
    ifstream fg;
	system("cls");
	gotoxy(24,12);
	cout<<" PLEASE ENTER YOUR ACCOUNT NUMBER ";
	gotoxy(37,16);
	cin>>aacno;
	system("cls");
	frame();
	gotoxy(34,2);
	cout<<"RESERVATION SYSTEM";
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
    fg.open("ticket_users.txt");
	machine b,q;
	while(!fg.eof())
	{
        fg>>b.acno>>b.fname>>b.sname>>b.dob>>b.city>>b.email>>b.pin;
    	if(strcmp(aacno,b.acno.c_str())==0)
    	{
			q=b;
			if(strcmp(apin.c_str(),b.pin.c_str())==0)
			{
				gotoxy(2,8);
               	cout<<"HELLO__MR."<<b.fname.c_str();
				Sleep(1000);
                fg.close();
				return q;
			}
			else
			{
				gotoxy(2,8);
				cout<<"INCORRECT PIN";
				fg.close();
				Sleep(1000);
				main_menu();
			}
		}
	}
    if(fg.peek()==EOF)
    {
        gotoxy(30,24);
        cout<<"ACCOUNT DOES NOT EXIST";
        Sleep(1000);
        fg.close();
        main_menu();
    }
    fg.close();
}
void machine:: main_menu()	//main menu for all functios included
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
		sub_menu();
	}
	else if(op=='a'||op=='A')
	{
		admin();
	}
	else if(op=='e'||op=='E')
	{
		system("cls");
		//note();
	}
	else
	{
		cout<<" \a\a\aINVALID OPTION ";
		Sleep(1000);
		main_menu();
	}

}
void machine::sub_menu()	//after user login the following fuctions are displayed
{
	system("cls");
	int cpin;
	machine r;
	r=login_check();
	while(1)
	{
			int i;
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(1,6);
			cout<<"1 VIEW ARRANGEMENT";
			gotoxy(1,10);
			cout<<"2 BOOK TICKET";
			gotoxy(1,14);
			cout<<"3 VIEW TICKET";
			gotoxy(1,18);
			cout<<"4 CANCEL TICKET";
			gotoxy(1,22);
			cout<<"5 APPLY WAITLIST";
            gotoxy(1,26);
            cout<<"6 LOGOUT";
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

						Sleep(1000);
						view();
						break;
					}
				case 2:
					{
						book(r);
						break;
					}

				case 3:
					{
						ticket(r);
						break;
					}
				case 4:
					{
						cancel(r);
						break;
					}
				case 5:
					{
						waitlist(r);
						break;
					}
                case 6:
                    {
                        Sleep(1000);
                        system("cls");
                        gotoxy(22,13);
                        cout<<"       LOGGING OUT...       \a\a";
                        Sleep(1000);
                        main_menu();
                    }
			}
		}
}
void machine::cancel(machine r)
{
    system("cls");
    system("COLOR 1A");
    gotoxy(10,9);
    ifstream in;int num;
    in.open("arrangement.txt");
    int i = 0,j = 0;
    in>>num;
    int row,col;
    row = num;
    in>>num;
    col = num;
    s = new struct data[row*col];
    for(int i=0;i<row*col;i++)
    {
        in>>(s+i)->seat_number>>(s+i)->price>>(s+i)->status>>(s+i)->account;
    }
    in.close();
    int seat;
    cout<<"\n ENTER SEAT NUMBER TO BE CANCELLED";
    cin>>seat;
    i = seat - 1;
    int y;
    sscanf(r.acno.c_str(), "%d", &y);
    if((s+i)->account != y)
     {
         cout<<"WRONG SEAT";
         Sleep(1000);
         return;
     }
    (s+i)->status = 1;
    (s+i)->account = 0;
    ifstream in1;
    in1.open("waitlist.txt");
    if(!in1.eof())
       {
            string accstr;
            in1>>accstr;

            if(accstr!="")
            (s+i)->status = 0;
           /* if((s+i)->price<100)
            {
                cout<<"REFUNDING WAITLIST RS"<<100 - (s+i)->price;
                Sleep(2000);
                machine1 m,m1;
                int x = m1.cash_deposit(m,100-(s+i)->price);
            }
             else
                if((s+i)->price>100)
            {
                cout<<"DEBITING WAITLIST RS"<< (s+i)->price -100;
                Sleep(2000);
                machine1 m,m1;
                int x = m1.cash_withdraw(m,(s+i)->price-100);
                if(x==1)
                {
                    (s+i)->status = 1;
                    (s+i)->account = 0;
                    return;
                }
            }*/
            int x;
            sscanf(accstr.c_str(), "%d", &x);
            (s+i)->account = x;
            string line[100];
            int j = 0;
            while ( !in1.eof() )
            {
                in1>>line[j];
                j++;
            }
            in1.close();
            ofstream fout;
            fout.open("waitlist.txt");
            for(int k = 0;k<j;k++)
            fout<<line[k].c_str()<<"\n";
            fout.close();
        }
    ofstream fo;
	fo.open("arrangement.txt");
	fo<<row<<"\n";
	fo<<col<<"\n";
    for(int i=0;i<row*col;i++)
    {
        fo<<(s+i)->seat_number<<"\t"<<(s+i)->price<<"\t"<<(s+i)->status<<"\t"<<(s+i)->account<<"\n";
    }
	fo.close();
    Sleep(1000);
	system("cls");
	gotoxy(22,13);
	cout<<"       CANCELLING TICKET...       \a\a";
	Sleep(1000);
    system("cls");
	gotoxy(22,13);
	cout<<"       REFUNDING RS"<<(s+i)->price<< " FOR CANCELLING ";
	machine1 m,m1;
	int x = m1.cash_deposit(m,(s+i)->price);
	Sleep(1000);
	return;
}
void machine::waitlist(machine r)
{
    system("cls");
    system("COLOR 1A");
    gotoxy(10,9);
    ifstream in;int num;
    in.open("arrangement.txt");
    int i = 0,j = 0;
    in>>num;
    int row,col;
    row = num;
    in>>num;
    col = num;
    s = new struct data[row*col];
    for(int i=0;i<row*col;i++)
    {
        in>>(s+i)->seat_number>>(s+i)->price>>(s+i)->status>>(s+i)->account;
    }
    in.close();
    for(i=0;i<row*col;i++)
    {
        if((s+i)->status == 1)
        break;
    }
    if(i!=row*col)
    {
        cout<<"SEATS ARE AVAILABLE";
        Sleep(1000);
        return;
    }
    cout<<"PAY RS 100";
    Sleep(1000);
    machine1 m,m1;
    int x = m1.cash_withdraw(m,100);
    cout<<"ADDING TO WAITLIST ....";
    ofstream fout;
	fout.open("waitlist.txt", ios::out | ios::app);
	fout<<r.acno.c_str()<<"\n";
    fout.close();

    Sleep(1000);
    return;
    getch();
}
void machine::ticket(machine r)
{
    system("cls");
    system("COLOR 1A");
    ifstream in;int num;
    in.open("arrangement.txt");
    int i = 0,j = 0;
    in>>num;
    int row,col;
    row = num;
    in>>num;
    col = num;
    s = new struct data[row*col];
    for(int i=0;i<row*col;i++)
    {
        in>>(s+i)->seat_number>>(s+i)->price>>(s+i)->status>>(s+i)->account;
    }
    in.close();int x =0;
    for(int i=0;i< row * col;i++)
    {
        stringstream ss;
        ss << (s+i)->account;
        string number = ss.str();
        if(strcmp(number.c_str(),r.acno.c_str())==0)
        {
            gotoxy(10,9+x);x++;
            cout<<(s+i)->seat_number<<"\t Rs."<<(s+i)->price;
        }
    }
    getch();
}
void machine::view()
{
    system("cls");
    system("COLOR 1A");
    gotoxy(10,9);
    ifstream in;
    int num;
    in.open("arrangement.txt");
    int i = 0,j = 0;
    in>>num;
    int row,col;
    row = num;
    in>>num;
    col = num;
    s = new struct data[row*col];
    for(int i=0;i<row*col;i++)
    {
        in>>(s+i)->seat_number>>(s+i)->price>>(s+i)->status>>(s+i)->account;
    }
    in.close();
    for(int i=0;i<row;i++)
    {
        gotoxy(10,9 + i*2);
        for(int j =0;j<col;j++)
        {
            if((s+i*row + j)->status == 0)
            {
              SetConsoleTextAttribute(console, FOREGROUND_RED);
              cout<<  (s+i*row + j)->seat_number<<"\t";
            }
            else
            {
              SetConsoleTextAttribute(console,FOREGROUND_GREEN);
              cout<<  (s+i*row + j)->seat_number<<"\t";
            }
        }
    }
    getch();
}
void machine::book(machine r)
{
    FILE *f1,*f2,*f3;		//declaring pointers in C style
	system("cls");
	int seat;
	frame_fix();
	gotoxy(22,6);
	cout<<"PLEASE ENTER SEAT NUMBER : ";
	cin>>seat;
	ifstream in;
	int num;
    in.open("arrangement.txt");
    int i = 0,j = 0;
    in>>num;
    int row,col;
    row = num;
    in>>num;
    col = num;
    s = new struct data[row*col];
    for(int i=0;i<row*col;i++)
    {
        in>>(s+i)->seat_number>>(s+i)->price>>(s+i)->status>>(s+i)->account;
    }
    in.close();
    gotoxy(22,8);
    i = seat -1;
    if((s+i)->status == 0)
    {
     cout<<"SEAT ALREADY BOOKED";
     Sleep(1000);
     return;
    }
    else
    {
        cout<<"PAY RS"<<(s+i)->price;
        int price;
        cin>>price;
        machine1 m,m1;
        int x = m1.cash_withdraw(m,price);
        if(x == 1)
        {
            gotoxy(22,10);
            cout<<"\n NOT ENOUGH FUNDS";
            return;
        }
        else
        if(price == (s+i)->price)
        {
            (s+i)->status = 0;
            stringstream geek(r.acno);
            int x;
            sscanf(r.acno.c_str(), "%d", &x);
            (s+i)->account = x;
            ofstream fout;
            fout.open("arrangement.txt");
            fout<<row<<"\n";
            fout<<col<<"\n";
            for(int i=0;i<row*col;i++)
            {
                fout<<(s+i)->seat_number<<"\t"<<(s+i)->price<<"\t"<<(s+i)->status<<"\t"<<(s+i)->account<<"\n";
            }
            fout.close();
            gotoxy(22,13);
            cout<<"	      PLEASE WAIT VALIDATING THE CASH		";
            Sleep(1000);
            system("cls");
            gotoxy(22,13);
            cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
            Sleep(1000);
        }
        else
        {
            gotoxy(22,10);
            cout<<"AMOUNT NOT CORRECT";
            Sleep(1000);
            int x = m1.sub_menu(price);
        }
    }
}
void machine::help()		//initial help notice in mainmenu on opening account
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
	cout<<"Inorder to use our reservation services be sure that,";
	gotoxy(3,2);
	cout<<"you might have already opened an account previously. ";
	gotoxy(3,5);
	flow("Reservation system");
	gotoxy(3,8);
	flow("VIEW ARRANGEMENT : Use this service to view seat arrangement");
	gotoxy(3,10);
	flow("BOOK TICKET : This enables to book tickets");
	gotoxy(3,12);
	flow("VIEW TICKET : Use this service to view ticket");
	gotoxy(3,14);
	flow("CANCEL TICKET : To cancel booked ticket");
	gotoxy(3,16);
	flow("APPLY WAITLIST : To apply incase seats are full.Once someone cancels seat will be be booked");
    getch();
	main_menu();
}
void machine::create_account()		//create account on selecting the option on main menu
{
	machine a;
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
	cout<<"Date Of Birth (dd/mm/yyyy) : ";
	cin>>a.dob;
	gotoxy(10,9);
	cout<<"City : ";
	cin>>a.city;
	gotoxy(10,11);
	cout<<"PINCODE : ";
	cin>>a.pcode;
	gotoxy(10,13);
	cout<<"Email Id : ";
	cin>>a.email;
    gotoxy(10,15);
    cout<<"Password  : ";
    cin>>a.pin;
    int r = rand() ;
	stringstream ss;
	ss << r;
	a.acno = ss.str();
	//inital account details posting to atm_users file
	ff=fopen("ticket_users.txt","a");
	fprintf(ff,"%s %s %s %s %s %s %s\n",a.acno.c_str(),a.fname.c_str(),a.sname.c_str(),a.dob.c_str(),a.city.c_str(),a.email.c_str(),a.pin.c_str());
	fclose(ff);
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
	cout<<"PASSWORD	      : "<<a.pin;
	gotoxy(8,19);
	cout<<"NOTE : THESE ARE THE ACCOUNT CREDENTIALS FOR USING BOOKING SERVICES.";
	gotoxy(28,23);
	cout<<"MAIN MENU : PRESS ENTER";
	char op;
	op=getche();
	main_menu();
}
void machine :: admin()
{
    system("COLOR 1A");
	char pass[8];
	char addname[15];
	char adname[2][15]={"sashank"};
	char password[]="password";
	system("cls");
	gotoxy(25,13);
	cout<<"Enter name of the admin : ";
	cin>>addname;
	if((strcmp(adname[0],addname)==0)||(strcmp(adname[1],addname)==0))
	{
		gotoxy(25,15);
		cout<<"Enter password : ";
		cin>>pass;
		if(strcmp(password,pass)==0)
		{
			while(1)
			{
				system("cls");
				system("COLOR 1A");
				int op;gotoxy(10,9);
				cout<<"1.ACCOUNT MEMBERS ";gotoxy(10,11);
				cout<<"2.CREATE SYSTEM ";gotoxy(10,13);
				cout<<"3.VIEW SYSTEM";gotoxy(10,15);
				cout<<"4.VIEW TICKETS BOOKED";gotoxy(10,17);
				cout<<"5.MAIN MENU ";gotoxy(10,19);
				cout<<"Select : ";
                cin>>op;
				if(op==1)
				{
					system("cls");
					FILE *fy;machine a;int i=3;
					fy=fopen("ticket_users.txt","r");//all information from accounts file
					gotoxy(0,1);
					cout<<"ACC NUM   FULL NAME   DOB      CITY     EMAIL      PIN";
  	  				string line;
                    ifstream myfile ("ticket_users.txt");
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
					gotoxy(10,9);
					cout<<"ENTER NO OF ROWS AND COLUMNS";
					cin>>r>>c;
					s = new struct data[r*c];
					int p[r];
					for(int i =0;i<r;i++)
                    {
                        gotoxy(10,11+(2*i));
                        cout<<"ENTER PRICE OF "<<i+1<<" ROW";
                        cin>>p[i];
                        for(int j = 0;j<c;j++)
                        {
                           (s+((i*r)+j))->seat_number = (i*r)+j+1;
                           (s+((i*r)+j))->price = p[i];
                           (s+((i*r)+j))->status = 1;
                            (s+((i*r)+j))->account = 0;
                        }

                    }
                    ofstream fout;
                    fout.open("arrangement.txt");
                    fout<<r<<"\n";
                    fout<<c<<"\n";
                    for(int i=0;i<r*c;i++)
                    {
                        fout<<(s+i)->seat_number<<"\t"<<(s+i)->price<<"\t"<<(s+i)->status<<"\t"<<(s+i)->account<<"\n";
                    }
                    fout.close();
					getch();
				}
				else if(op==3)
                {
                    system("cls");system("COLOR 1A");
                    gotoxy(10,9);
                    ifstream in;int num;
                    in.open("arrangement.txt");
                    int i = 0,j = 0;
                    in>>num;int row,col;
                    row = num;
                    in>>num;
                    col = num;
                    s = new struct data[row*col];
                    for(int i=0;i<row*col;i++)
                    {
                        in>>(s+i)->seat_number>>(s+i)->price>>(s+i)->status>>(s+i)->account;
                    }
                    in.close();
                    for(int i=0;i<row;i++)
                    {
                        gotoxy(10,9 + i*2);
                        for(int j =0;j<col;j++)
                            {
                                if((s+i*row + j)->status == 0)
                                {
                                  SetConsoleTextAttribute(console, FOREGROUND_RED);
                                  cout<<  (s+i*row + j)->seat_number<<"\t";
                                }
                                else
                                {
                                    SetConsoleTextAttribute(console,FOREGROUND_GREEN);
                                  cout<<  (s+i*row + j)->seat_number<<"\t";
                                }
                            }
                    }
                    getch();
                }
				else if(op==4)
                {

                    system("cls");system("COLOR 1A");
                    ifstream in;int num;
                    in.open("arrangement.txt");
                    int i = 0,j = 0;
                    in>>num;int row,col;
                    row = num;
                    in>>num;
                    col = num;
                    s = new struct data[row*col];
                    for(int i=0;i<row*col;i++)
                    {
                        in>>(s+i)->seat_number>>(s+i)->price>>(s+i)->status>>(s+i)->account;
                    }
                    gotoxy(10,7);
                    cout<<"SEAT  "<<"ACCOUNT  "<<"NAME           "<<"DOB   "<<"CITY    "<<"EMAIL        "<<"PIN";
                    in.close();
                    int x = 0;
                    for(int i=0;i<row*col;i++)
                    {
                        if((s+i)->status == 0)
                        {
                            gotoxy(10,9+x);x++;
                            stringstream ss;
                            ss << (s+i)->account;
                            string aacno = ss.str();
                            cout<<(s+i)->seat_number<<'\t';
                            string line;
                            ifstream myfile ("ticket_users.txt");
                            if (myfile.is_open())
                            {
                                while ( getline (myfile,line) )
                                {
                                    string delimiter = " ";
                                    string token = line.substr(0, line.find(delimiter));
                                    if(strcmp(aacno.c_str(),token.c_str())==0)
                                    {
                                        cout <<line << '\n';
                                    }
                                }
                                myfile.close();
                            }

                        }
                    }
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
			Sleep(1000);
			main_menu();
		}
	}
	else
    {
    gotoxy(25,17);
	cout<<"WRONG USER NAME ";
	Sleep(1000);
	main_menu();
    }

}
#endif // utilities
