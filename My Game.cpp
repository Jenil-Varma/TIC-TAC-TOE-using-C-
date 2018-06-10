#include<iostream>
using namespace std;
char sq[10]={'0','1','2','3','4','5','6','7','8','9'};
void board();
int win();
main()
{
	int player=1,ch,i;
	char mark;
	do
	{
		board();
		player=(player%2)?1:2;
		mark=(player==1)?'X':'O';
		cout<<"\n\tPlayer "<<player<<":Enter Your Choice- ";
		cin>>ch;
		if (ch==1 && sq[1]=='1')
			{sq[1]=mark;}
		else if(ch==2 && sq[2]=='2')
		sq[2]=mark;
		else if(ch==3 && sq[3]=='3')
		sq[3]=mark;
		else if(ch==4 && sq[4]=='4')
		sq[4]=mark;
		else if(ch==5 && sq[5]=='5')
		sq[5]=mark;
		else if(ch==6 && sq[6]=='6')
		sq[6]=mark;
		else if(ch==7 && sq[7]=='7')
		sq[7]=mark;
		else if(ch==8 && sq[8]=='8')
		sq[8]=mark;
		else if(ch==9 && sq[9]=='9')
		sq[9]=mark;
		else
		{
			cout<<"\n\t\t\aInvalid Choice";
			player--;
			cin.ignore();
			cin.get();
		}
		player++;
		i=win();
	}while(i==-1);
	board();
	if(i==1)
	{
		cout<<"\n\t\aCongretulations Player:"<<--player<<"\n\
	  \aYou Are Winner!!!!";
	}
	else
	{
		cout<<"\n\t\t\aNo Winner (Dreaw Match)";
	}
	return 0;
}
int win()
{
	if(sq[1]==sq[2] && sq[2]==sq[3])
	return 1;
	else if(sq[4]==sq[5] && sq[5]==sq[6])
	return 1;
	else if (sq[7]==sq[8] && sq[8]==sq[9])
	return 1;
	else if (sq[1]==sq[4] && sq[4]==sq[7])
	return 1;
	else if (sq[2]==sq[5] && sq[5] == sq[8])
	return 1;
	else if (sq[3]==sq[6] && sq[6]==sq[9])
	return 1;
	else if (sq[1]==sq[5] && sq[5]==sq[9])
	return 1;
	else if (sq[3]==sq[5] && sq[5]==sq[7])
	return 1;
	else if (sq[1]!='1' && sq[2]!='2' && sq[3]!='3' && sq[4]!='4' && sq[5]!='5' && sq[6]!='6' && sq[7]!='7' && sq[8]!='8' && sq[9]!='9')
	return 0;
	else
	return -1;
}
void board()
{
	system("cls");
	cout<<"\n\n\t\tTic Tac Toe \n\tPlayer:1(X) & Player:2(O)\n";
	cout<<"\n\t\t    |    |    "<<endl;
	cout<<"\t\t "<<sq[1]<<"  | "<<sq[2]<<"  | "<<sq[3]<<"  "<<endl;
	cout<<"\t\t____|____|____"<<endl;
	cout<<"\t\t    |    |    "<<endl;
	cout<<"\t\t "<<sq[4]<<"  | "<<sq[5]<<"  | "<<sq[6]<<"  "<<endl;
	cout<<"\t\t____|____|____"<<endl;
	cout<<"\t\t    |    |    "<<endl;
	cout<<"\t\t "<<sq[7]<<"  | "<<sq[8]<<"  | "<<sq[9]<<"  "<<endl;
	cout<<"\t\t    |    |    "<<endl;
	
}
