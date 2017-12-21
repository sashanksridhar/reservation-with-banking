#ifndef utilities
#define utilities
#include<iostream>
#include<string>
using namespace std;
COORD coord = {0, 0};
char *date_time();
class date		//class current date and time of system
{


	public:
		int aday,amonth,ayear,ahour,amin,asec;
	void date_times()
	{
		SYSTEMTIME t;		//pre defined in time.h header
 		GetLocalTime(&t);
		aday=t.wDay,amonth=t.wMonth,ayear=t.wYear,ahour=t.wHour,amin=t.wMinute,asec=t.wSecond;

	}
};
void gotoxy (int x, int y)	//defining/initializing to predefined objects
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void frame()
{
	int i,j=79;
	for(i = 0;i<80,j>=0;i++,j--)
	{
		gotoxy(i,3);
		Sleep(10);
		cout<<"_";
		gotoxy(j,20);
		Sleep(10);
		cout<<"_";
	}
	gotoxy(56,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;		//every frame has date on the right top

}
void frame_fix()	//instead of flow line fixing the frame
{
	int i,j=79;
	for(i = 0;i<80,j>=0;i++,j--)
	{
		gotoxy(i,3);
		cout<<"_";
		gotoxy(j,20);
		cout<<"_";
	}
	gotoxy(56,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;
}
char *date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	//returns local time and date
}
void flow(char *ch)	//flow of instructions
{
	char *str=ch;
	for(int i=0;i<strlen(str);i++)
	{
		Sleep(20);
		cout<<str[i];
	}
}


void delr1()
{
	ofstream f;
	ifstream g;
	string line;
	f.open("atm_users.txt");
	g.open("temp.txt");
	while ( !g.eof() )
                        {
                            getline(g,line);
                            f<<line<<"\n";
                        }
    g.close();
    f.close();
    f.open("temp.txt");
    f.close();
}
void delr2()
{
	ofstream f;
	ifstream g;
	string line;
	f.open("transactions.txt");
	g.open("temp.txt");
	while ( !g.eof() )
                        {
                            getline(g,line);
                            f<<line<<"\n";
                        }
    g.close();
    f.close();
    f.open("temp.txt");
    f.close();
}
#endif // utilities
