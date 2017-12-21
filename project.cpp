#include<iostream>		//input/output objects c++
#include<stdio.h>		//standard input/output c
#include<stdlib.h>		//standard library
#include<conio.h>		//getch function
#include<dos.h>			//delay function
#include<windows.h>		//Sleep,gotoxy coordinate functions
#include<iomanip>		//output manipulatons
#include<fstream>		//file handling
#include<string.h>		//string abstract datatype
#include<math.h>		//mathematical operations
#include<time.h>		//system current time and date
#include<sstream>
#include"utilities.h"
#include"reservation.h"
 //to convert string to integer
using namespace std;
char loc[20];
void delr1();			//delete file
void delr2();			//rename file
void gotoxy (int x, int y);	//handle output on screen
void frame ();			//frame for every dialog box
void frame_fix();
char *date_time ();
void scroll_note();
void flow(char *ch);
void main_menu();		// main part of the program
void sub_menu();

class date;

int main()
{
	scroll_note();		//welcome note
	machine m;			//object of machine class
	m.main_menu();		//calling menu function for making simple for our program MAIN
	return 0;
}
