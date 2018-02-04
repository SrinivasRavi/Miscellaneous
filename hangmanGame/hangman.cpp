#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>

const int num=50;
char name[num][20];
char hint[num][40];
char remain[3][9];

static int n=0;
static int genbg=0;
static int winbg=2;//Green=2 or Light Green=10
static int losebg=4;//Red=4 or Light Red=12
void frame()
{
	setcolor(15);
	line(430,60,550,60);//horizontal
	line(440,60,440,320);//vertical
	line(420,320,600,320);//base
}
void rope()
{
	setcolor(15);
	line(520,60,520,120);
	ellipse(520,140,0,360,5,20);
}
void facecl()
{
	setcolor(14);
	circle(520,140,30);//head
	setfillstyle(1,14);
	floodfill(520,140,14);
	setcolor(0);
	circle(508,130,2);//left eye
	circle(532,130,2);//right eye
	setfillstyle(1,0);
	floodfill(508,130,0);
	floodfill(532,130,0);
}
void face()
{
	facecl();
	setfillstyle(1,15);
	sector(520, 140, 180, 360, 20, 20);//grin
}
void face1()
{
	facecl();
	arc(520,140,200,340,20);//big smile
}
void face2()
{
	facecl();
	arc(520,140,220,320,20);//small smile
}
void face3()
{
	facecl();
	line(508,154,532,154);
	line(508,155,532,155);
}
void face4()
{
	facecl();
	arc(520,165,40,140,20);
	arc(520,165,40,140,21);
}
void face5()
{
	setcolor(14);
	ellipse(524,160,0,360,20,30);
	setfillstyle(1,14);
	floodfill(524,160,14);
	setcolor(0);
	line(509,147,517,153);
	line(517,147,509,153);
	line(533,147,539,153);
	line(539,147,533,153);
	line(512,164,536,164);
	line(512,165,536,165);
	setcolor(4);
	sector(530,165,180,360,6,10);
	setfillstyle(1,4);
	floodfill(530,167,4);

}
void hand3()
{
	line(522,185,557,150);
	line(523,185,558,150);
	line(518,185,488,230);
	line(517,185,487,230);
}
void hand4()
{
	line(522,185,572,172);
	line(523,185,573,172);
	line(518,185,488,230);
	line(517,185,487,230);
}
void hands()//after win
{
	for(int i=0;i<4;i++)
	{
		setcolor(winbg);
		hand3();
		setcolor(14);
		hand4();
		delay(500);
		setcolor(winbg);
		hand4();
		setcolor(14);
		hand3();
		delay(500);
	}
}
void hands1()
{
	setcolor(14);
	line(522,185,557,230);
	line(523,185,558,230);
	line(518,185,483,230);
	line(517,185,482,230);
}
void legs1()
{
	setcolor(14);
	line(522,230,557,275);
	line(523,230,558,275);
	line(518,230,483,275);
	line(517,230,482,275);
}
void hands2()
{
	setcolor(14);
	line(522,205,527,259);
	line(523,205,528,259);
	line(518,205,513,259);
	line(517,205,512,259);
}
void legs2()
{
	setcolor(14);
	line(522,250,527,304);
	line(523,250,528,304);
	line(518,250,513,304);
	line(517,250,512,304);
}
void body(int q)
{
	setcolor(14);
	rectangle(518,167+q,522,230+q);
	setfillstyle(1,14);
	floodfill(520,200,14);
}
void bar(int c)
{
	setcolor(c);
	rectangle(430,330,450,350);
	rectangle(450,330,470,350);
	rectangle(470,330,490,350);
	rectangle(490,330,510,350);
	rectangle(510,330,530,350);
	rectangle(530,330,550,350);
	rectangle(550,330,570,350);
	int w=440;
	while(n)
	{
		setfillstyle(1,c);
		floodfill(w,340,c);
		w=w+20;
		n--;
	}
}
void drawhang()
{
	face2();
	body(0);
	hands1();
	legs1();
}
void win()
{
	face();
	body(0);
	legs1();
	hands();
}

void error(int count)
{
	n=count;
	switch(count)
	{
		case 1:
			frame();
			bar(2);
			break;
		case 2:
			frame();
			rope();
			bar(2);
			break;
		case 3:
			frame();
			rope();
			face1();
			bar(14);
			break;
		case 4:
			frame();
			rope();
			face2();
			body(0);
			bar(14);
			break;
		case 5:
			frame();
			rope();
			face3();
			body(0);
			hands1();
			bar(14);
			break;
		case 6:
			frame();
			rope();
			face4();
			body(0);
			hands1();
			legs1();
			bar(4);
			break;
		case 7:
			frame();
			setcolor(15);
			line(520,60,520,130);
			face5();
			body(20);
			hands2();
			legs2();
			bar(4);
			sleep(2.5);
			break;
	}
}

void initialize_remain() {
	char ch='a';
	for(int i=0;i<3;i++)
		for(int j=0;j<9;j++)  {
			remain[i][j]=ch;
			ch++;
		}
	remain[2][8]='.';
}

void initialize_names() {
	initialize_remain();
	strcpy(hint[0],"Machine that executes instructions!");
	strcpy(name[0],"computer");
	strcpy(hint[1],"Everything is stored here!");
	strcpy(name[1],"memory");
	strcpy(hint[2],"Heart of the CPU!");
	strcpy(name[2],"processor");
	strcpy(hint[3],"Memory management scheme!");
	strcpy(name[3],"paging");
	strcpy(hint[4],"Division of primary memory!");
	strcpy(name[4],"segmentation");
	strcpy(hint[5],"Aarthi mam's subject!");
	strcpy(name[5],"computergraphics");
	strcpy(hint[6],"Line clipping Algorithm!");
	strcpy(name[6],"cohensutherland");
	strcpy(hint[7],"Header file for graphics in c++");
	strcpy(name[7],"graphics.h");
	strcpy(hint[8],"Father of Java!");
	strcpy(name[8],"jamesgosling");
	strcpy(hint[9],"Our college's name!");
	strcpy(name[9],"vesit");
	strcpy(hint[10],"AOAD!");
	strcpy(name[10],"algorithm");
	strcpy(hint[11],"ADC!");
	strcpy(name[11],"sampling");
	strcpy(hint[12],"Father of modern computer!");
	strcpy(name[12],"charlesbabbage");
	strcpy(hint[13],"Founder of Facebook!");
	strcpy(name[13],"markzuckerberg");
	strcpy(hint[14],"Founder of Apple Inc.!");
	strcpy(name[14],"stevejobs");
	strcpy(hint[15],"Father of Physics!");
	strcpy(name[15],"issacnewton");
	strcpy(hint[16],"Stores bits of information!");
	strcpy(name[16],"register");
	strcpy(hint[17],"Rapid display of seq. of images!");
	strcpy(name[17],"animation");
	strcpy(hint[18],"A computing paradox!");
	strcpy(name[18],"bootstrapping");
	strcpy(hint[19],"Creator of C++!");
	strcpy(name[19],"bjarnestroustrup");
	strcpy(hint[20],"Founder of C");
	strcpy(name[20],"dennisritchie");
	strcpy(hint[21],"Sun and Apache");
	strcpy(name[21],"jakartaproject");
	strcpy(hint[22],"Computer n/w authentication protocol");
	strcpy(name[22],"kerberos");
	strcpy(hint[23],"Caching behavior");
	strcpy(name[23],"memoization");
	strcpy(hint[24],"A series of microprocessors");
	strcpy(name[24],"pentium");
	strcpy(hint[25],"A set of rules!");
	strcpy(name[25],"algorithm");
	strcpy(hint[26],"Value supplied to a procedure!");
	strcpy(name[26],"argument");
	strcpy(hint[27],"Process of establishing who you are!");
	strcpy(name[27],"authentication");
	strcpy(hint[28],"Turning on your computer!");
	strcpy(name[28],"booting");
	strcpy(hint[29],"Symbol that can be entered in PC!");
	strcpy(name[29],"character");
	strcpy(hint[30],"Tiny piece of semiconductive material!");
	strcpy(name[30],"chip");
	strcpy(hint[31],"Translator of programs!");
	strcpy(name[31],"compiler");
	strcpy(hint[32],"I follow you!");
	strcpy(name[32],"cursor");
	strcpy(hint[33],"When nothing I execute!");
	strcpy(name[33],"default");
	strcpy(hint[34],"Represented by collection of bits!");
	strcpy(name[34],"digital");
	strcpy(hint[35],"A local area network!");
	strcpy(name[35],"ethernet");
	strcpy(hint[36],"A feature of OOP!");
	strcpy(name[36],"encapsulation");
	strcpy(hint[37],"It's always free!");
	strcpy(name[37],"freeware");
	strcpy(hint[38],"I'm a part of this game!");
	strcpy(name[38],"hang");
	strcpy(hint[39],"I'm center of network activity!");
	strcpy(name[39],"hub");
	strcpy(hint[40],"Computer executes this!");
	strcpy(name[40],"instruction");
	strcpy(hint[41],"Exit a user account!");
	strcpy(name[41],"logoff");
	strcpy(hint[42],"Small yet powerful!");
	strcpy(name[42],"microprocessor");
	strcpy(hint[43],"I come after info processing!");
	strcpy(name[43],"output");
	strcpy(hint[44],"Word for securing computer!");
	strcpy(name[44],"password");
	strcpy(hint[45],"Add-ons of computer!");
	strcpy(name[45],"peripheral");
	strcpy(hint[46],"Smallest element of display space!");
	strcpy(name[46],"pixel");
	strcpy(hint[47],"You write me in all labs!");
	strcpy(name[47],"program");
	strcpy(hint[48],"Small picture on GUI!");
	strcpy(name[48],"icon");
	strcpy(hint[49],"I sense alterations of light & dark!");
	strcpy(name[49],"scanner");
}

int search(char* str,char* guess,int len,char ch) {
	int flag= -1;
	for(int i=0;i<len;i++) {
		if(str[i]==ch && guess[i]=='_') {
			guess[i]=ch;
			flag=1;
		}
	}
	return flag;
}

void search(char ch) {
	for(int i=0;i<3;i++)
		for(int j=0;j<9;j++) {
			if(remain[i][j]==ch)
				remain[i][j]=' ';
		}
}

void search(char* str,char* guess,char ch,int len) {
	for(int i=0;i<len;i++) {
		if(str[i]==ch && guess[i]=='_')
			guess[i]=ch;
	}
}

void show(char* string,int len) {
	cout<<"\n\n\t\t";
	for(int i=0;i<len;i++)
		cout<<string[i]<<" ";
	cout<<"\n\n\n\n\t\tAvailable letters!!\n";
	for(i=0;i<3;i++) {
		cout<<"\n\t\t ";
		for(int j=0;j<9;j++)
			cout<<remain[i][j]<<" ";
		cout<<"\n";
	}
}

int compare(char* str1,char* str2,int len) {
	for(int i=0;i<len;i++){
		if(str1[i]!=str2[i])
			return 0;
	}
	return 1;
}

int get_index() {
	time_t t;
	srand((unsigned) time(&t));
	return(rand() % num);
}

int get_index(int len) {
	time_t t;
	srand((unsigned) time(&t));
	return(rand() % len);
}

void disp(char* str,int len,int que)  {
	clrscr();
	cleardevice();
	cout<<"\n\n\n\n\t\t\t";
	cout<<"HANGMAN";
	cout<<"\n\n\n\tHint: "<<hint[que]<<"\n";
	show(str,len);
	rectangle(100,200,300,350);
}

void hangman() {
	initialize_names();      //generate names
	int over=0;	// flag to monitor gameover
	char ch,letter;
	int pos,ind,count=1,j,wrong=0;
	int que=get_index();  	//selects a word from list
	int len=strlen(name[que]);
	char* word=new char[len+1];
	strcpy(word,name[que]);

	char* guess=new char[len+1];

	for(int i=0;i<len;i++)
		guess[i]='_';

	if(len>4)
		count=2;
	if(len>8)
		count=3;

	for(j=0;j<count;j++)  {
		ind=get_index(len);
		letter=word[ind];
		guess[ind]=letter;
		search(word,guess,letter,len);
		search(letter);
		delay(100);
	}
	disp(guess,len,que);
	while(wrong!=7 && over!=1){
		ch=getch();
		search(ch);
		pos=search(word,guess,len,ch);
		if(pos== -1)
			wrong++;
		disp(guess,len,que);
		over=compare(guess,word,len);
		error(wrong);
	}
	sleep(1.5);
	cleardevice();
	graphdefaults();
	if(over) {
		setbkcolor(winbg);
		cout<<"\n\n\t\tCorrect guess!!\n";
		cout<<"\n\t\tYou won!!!";
		win();
		sleep(3);
	}
	else    {
		setbkcolor(losebg);
		cout<<"\n\t\t\tGAMEOVER";
		cout<<"\n\n\t\tThe word was '"<< word<<"'";
		error(7);
		sleep(2);
	}
}
void main() {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi\\");
	graphdefaults();
	char choice;
	do {
		clrscr();
		cleardevice();
		drawhang();
		setbkcolor(genbg);
		cout<<"\n\n\n\n\n\n\t\t";
		cout<<"WELCOME TO HANGMAN GAME";
		cout<<"\n\n\t\t1.Play Game";
		cout<<"\n\n\t\t2.Exit\n";
		cout<<"\n\t\t";
		cin>>choice;
		switch(choice) {
			case '1':
				hangman();
				break;
			case '2':
				exit(1);
				break;
			default:
				cout<<"\n\t\tWrong choice!!\n\t\tEnter Again!!";
				sleep(2);
				break;
		}

	}while(1);
}
