#include"stdafx.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
static char sq[12][29];
char mark,choice;
const int width=50,hight=15;
int x,y,player=1,score1,score2;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
void setup()
{
	for(int i=0;i<=12;i++)
	{
		for(int j=0;j<=29;j++)
		{
			sq[i][j]='\0';
		}
	}
	x=5;
	y=14;
}
void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
				if(y<15)
				{
					break;
				}
				else
					y-=6;
				break;
			case 'd':
				if(y>=21)
				{
					break;
				}
				else
					y+=6;
				break;
			case 'w':
				if(x<=5)
				{
					break;
				}
				else
					x-=3;
				break;
			case 's':
				if(x>=11)
				{
					break;
				}
				else
					x+=3;
				break;
			case 'x':
			case 'X':
			case 'o':
			case 'O':
				y++;
				SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				sq[x][y]=mark;
				y--;
				player++;
				break;
			default:
				cout<<"ENTERED WRONG BUTTON";
				break;
		}
	}
}
int win()
{
	if(sq[5][15]==sq[5][21] && sq[5][21]==sq[5][27] && (sq[5][15] & sq[5][21] & sq[5][27])!='\0')
	return 1;
	else if(sq[8][15]==sq[8][21] && sq[8][21]==sq[8][27] && (sq[8][15] & sq[8][21] & sq[8][27])!='\0')
	return 1;
	else if(sq[11][15]==sq[11][21] && sq[11][21]==sq[11][27] && (sq[11][15] & sq[11][21] & sq[11][27])!='\0')
	return 1;
	else if (sq[5][15]==sq[8][15] && sq[8][15]==sq[11][15] && (sq[5][15] & sq[8][15] & sq[11][15])!='\0')
	return 1;
	else if (sq[5][21]==sq[8][21] && sq[8][21]==sq[11][21] && (sq[5][21] & sq[8][21] & sq[11][21])!='\0')
	return 1;
	else if (sq[5][27]==sq[8][27] && sq[8][27]==sq[11][27] && (sq[5][27] & sq[8][27] & sq[11][27])!='\0')
	return 1;
	else if (sq[5][15]==sq[8][21] && sq[8][21]==sq[11][27] && (sq[5][15] & sq[8][21] & sq[11][27])!='\0')
	return 1;
	else if (sq[5][27]==sq[8][21] && sq[8][21]==sq[11][15] && (sq[5][27] & sq[8][21] & sq[11][15])!='\0')
	return 1;
	else if ((sq[5][15]& sq[5][21]& sq[5][27]& sq[8][15]& sq[8][21]& sq[8][27]& sq[11][15]& sq[11][21]& sq[11][27])!='\0')
	return 0;
	else
	return -1;
}
void draw()
{
	system("cls");
	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout<<"LOSER GET THE FIRST CHANCE & IN DRAW MATCH NEXT PLAYER GET FIRST CHANCE"<<endl;
	cout<<endl;
	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	for(int i=0;i<=width+1;i++)
	cout<<"#";
	cout<<endl;
	for(int i=0;i<hight;i++)
	{
		for(int j=0;j<width;j++)
		{
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			if(j==0)
			cout<<"#";
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
			if(i==1 && j==16)
				cout<<'T';
			else if(i==1 && j==17)
				cout<<'I';
			else if(i==1 && j==18)
				cout<<'C';
			else if(i==1 && j==19)
				cout<<' ';
			else if(i==1 && j==20)
				cout<<'T';
			else if(i==1 && j==21)
				cout<<'A';
			else if(i==1 && j==22)
				cout<<'C';
			else if(i==1 && j==23)
				cout<<' ';
			else if(i==1 && j==24)
				cout<<'T';
			else if(i==1 && j==25)
				cout<<'O';
			else if(i==1 && j==26)
				cout<<'E';
			else if(i==4 && j==18)
				cout<<"|";
			else if(i==4 && j==24)
				cout<<"|";
			else if(i==x && j==y)
				cout<<"|";
			else if(i==5 && j==15)
				cout<<sq[5][15];
			else if(i==5 && j==18)
				cout<<"|";
			else if(i==5 && j==21)
				cout<<sq[5][21];
			else if(i==5 && j==24)
				cout<<"|";
			else if(i==5 && j==27)
				cout<<sq[5][27];
			else if(i==6 && (j==13||j==14||j==15||j==16||j==17))
				cout<<"_";
			else if(i==6 && j==18)
				cout<<"|";
			else if(i==6 && (j==19||j==20||j==21||j==22||j==23))
				cout<<"_";
			else if(i==6 && j==24)
				cout<<"|";
			else if(i==6 && (j==25||j==26||j==27||j==28||j==29))
				cout<<"_";
			else if(i==7 && j==18)
				cout<<"|";
			else if(i==7 && j==24)
				cout<<"|";
			else if(i==8 && j==15)
				cout<<sq[8][15];
			else if(i==8 && j==18)
				cout<<"|";
			else if(i==8 && j==21)
				cout<<sq[8][21];
			else if(i==8 && j==24)
				cout<<"|";
			else if(i==8 && j==27)
				cout<<sq[8][27];
			else if(i==9 && (j==13||j==14||j==15||j==16||j==17))
				cout<<"_";
			else if(i==9 && j==18)
				cout<<"|";
			else if(i==9 && (j==19||j==20||j==21||j==22||j==23))
				cout<<"_";
			else if(i==9 && j==24)
				cout<<"|";
			else if(i==9 && (j==25||j==26||j==27||j==28||j==29))
				cout<<"_";
			else if(i==10 && j==18)
				cout<<"|";
			else if(i==10 && j==24)
				cout<<"|";
			else if(i==11 && j==15)
				cout<<sq[11][15];
			else if(i==11 && j==18)
				cout<<"|";
			else if(i==11 && j==21)
				cout<<sq[11][21];
			else if(i==11 && j==24)
				cout<<"|";
			else if(i==11 && j==27)
				cout<<sq[11][27];
			else if(i==12 && j==18)
				cout<<"|";
			else if(i==12 && j==24)
				cout<<"|";
			else
			cout<<" ";
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			if(j==width-1)
			cout<<"#";
		}	
		cout<<endl;
	}
	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	for(int i=0;i<=width+1;i++)
	cout<<"#";
	cout<<endl;
	player=(player%2)?1:2;
	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout<<"\n\tNOW TURN OF PLAYER-"<<player;
	mark=(player==1)?'X':'O';
	cout<<"  "<<mark;
	SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"\n\n\t\tSCORES:";
	cout<<"\n\t\t-------";
	cout<<"\n\tPLAYER-1\tPLAYER-2";
	cout<<"\n\t  "<<score1<<"\t\t   "<<score2;
}
void score()
{
	if(player==1)
		score1++;
	else
		score2++;
}
int main()
{
	int i=-1;
	do
	{
	setup();
	do
	{
		draw();
		input();
		i=win();
		Sleep(75);
	}while(i==-1);
	if(i==1)
	{	
		if(player==2)
		{
			player--;
		}
		else 
		{
			player++;
		}
			mark=(player==1)?'X':'O';
			score();
			draw();
			cout<<"\n\n\t\a\"WINNER IS PLAYER-"<<player<<"  "<<mark<<" !!!!\"";
			player++;
	}
	else
	{
		draw();
		cout<<"\n\t\a\"No Winner\"(Draw Match)";
	}
	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout<<"\n\n\t\aDO YOU WANT TO PLAY AGAIN???";
	cout<<"\n\tY FOR YES & N FOR NO";
	cin>>choice;
	}while(choice=='y'||choice=='Y');
	return 0;
}
