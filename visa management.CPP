//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<iomanip.h>
#include<dos.h>
#include<graphics.h>

//***************************************************************
//    	function declaration
//****************************************************************
void intro3(int m,int n,int o);	
void intro2();
void intro1();
void intro(int x);				
void details_menu();			//display detail menu on screen
void entry_edit_menu();		//display entry or edit menu on screen
void search_menu();			//display search menu on screen

void write_record();			//write the record in binary file
void modify_record();			//accept passport no. and update record of binary file
void delete_record();			//accept passport no. and delete a record from binary file
int check1(float s);
void read_record(int n,int flag);		// to read  records from binary file
void search(int n);			

void rect(int m,int n);			//functions for border of the page
void cir();
void rect2(int m,int n);


//***************************************************************
//                   STRUCTURE USED IN PROJECT
//****************************************************************
struct info
{
char name[20],nation[80],type[20],mobile[11];
int dd,yy,mm;
double  passport;
char t;
};

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
class visa
{
info r;

void type_assign()
{
switch(r.t)
	{
	rect2(4,5);
	case 's':
	strcpy(r.type,"student");
	break;
	case 't':
	strcpy(r.type,"tourist");
	break;
	case 'w':
	strcpy(r.type,"working");
	break;
	case 'm':
	strcpy(r.type,"medical");
	break;
	default:
	outtextxy(90,210,"enter wisely");
	type_function();
	}
}
//***************************************************************
//        This  function is used to assign visa type
//****************************************************************

void type_function()
{	   rect2(4,5);
	setcolor(8);
	settextstyle(1,0,3);
	outtextxy(90,110,"enter the type of visa");
	settextstyle(1,0,2);
	setcolor(13);
	outtextxy(90,130,"S - student visa  ");
	outtextxy(90,150,"W - working visa  ");
	outtextxy(90,170,"T - tourist visa  ");
	outtextxy(90,190,"M - medical visa =>>");
	gotoxy(60,14);
	cin>>r.t;
	type_assign();
}
public:

void input()
{
clrscr();
cleardevice();
struct date d;					//structure to get current date 
	getdate(&d);		
	r.dd=d.da_day;	
	r.mm=d.da_mon;
	r.yy=d.da_year+3;
	rect2(6,5);
	setcolor(3);
	settextstyle(3,0,4);
	outtextxy(50,30,"Enter the information");
	setcolor(7);
	settextstyle(1,0,3);
	outtextxy(90,80,"enter the name        =>>");
	gotoxy(60,7);gets(r.name);
	type_function();
	setcolor(7);
	settextstyle(1,0,3);
	outtextxy(90,250,"enter the country    =>>");
	gotoxy(60,17);gets(r.nation);
	outtextxy(90,290,"enter the mobile no. =>>");
	gotoxy(60,20);cin>>r.mobile;
	outtextxy(90,330,"enter the passport no.=>>");
	gotoxy(60,22);cin>>r.passport;
	xz:
	int flag=check1(r.passport);
	if(flag==0)
	{
	cleardevice();
	rect2(2,3);
	setcolor(15);
	settextstyle(1,0,1);
	outtextxy(50,150," passport no. already exist enter again");
	setcolor(7);
	settextstyle(1,0,3);
	outtextxy(90,200,"enter the passport no.=>>");
	gotoxy(60,15);cin>>r.passport;
	goto xz;
	}
	else
	return;
}
//***************************************************************
//         Function to input data
//****************************************************************

void input1(int choice)
{
	switch(choice)
	{
	case 1:
	outtextxy(90,325,"enter the name");
	gotoxy(60,22);
	gets(r.name);
	break;
	case 2:
	cleardevice();
	type_function();
	break;
	case 3:
	outtextxy(90,325,"enter the country");
	gotoxy(60,22);
	gets(r.nation);
	break;
	case 4:
	outtextxy(90,325,"enter the mobile no.");
	gotoxy(60,22);
	cin>>r.mobile;
	break;
	case 5:
	outtextxy(90,325,"enter the passport no.");
	gotoxy(60,22);
	cin>>r.passport;
	yz:
	int flag=check1(r.passport);
	if(flag==0)
	{
	cleardevice();
	rect2(2,3);
	setcolor(15);
	settextstyle(1,0,1);
	outtextxy(50,150," passport no. already exist enter again");
	setcolor(7);
	settextstyle(1,0,3);
	outtextxy(90,200,"enter the passport no.=>>");
	gotoxy(60,15);cin>>r.passport;
	goto yz;
	}
	break;
	default:
	outtextxy(90,325,"wrong choice");
	}
}
//***************************************************************
//            function to display data
//****************************************************************

void output(int flag)
{
cleardevice();
rect2(6,8);
settextstyle(1,0,5);
outtextxy(250,40,"DETAIL");
setcolor(11);
settextstyle(1,0,1);
outtextxy(90,110,"  name         =>>");
gotoxy(60,9);
cout<<r.name;
outtextxy(90,140,"  type         =>>");
gotoxy(60,11);
cout<<r.type;
outtextxy(90,180,"  country      =>>");
gotoxy(60,13);
cout<<r.nation;
outtextxy(90,220,"  mobile no.   =>>");
gotoxy(60,15);
cout<<r.mobile;
outtextxy(90,260,"  passport no. =>>");
gotoxy(60,17);
cout<<r.passport;
outtextxy(90,300,"  expiry  date =>>");
gotoxy(60,20);
cout<<r.dd<<"/"<<r.mm<<"/"<<r.yy;
if(flag==0)
getch();
}

void output1(int&d,int&x)
{
if(d==0)
{
setcolor(10);
settextstyle(1,0,1);
outtextxy(50,70,"Name");
outtextxy(150,70,"TYPE");
outtextxy(230,70,"MOBILE NO.");
outtextxy(350,70,"PASSPORT NO.");
outtextxy(500,70,"expiry date");
d++;
rect2(6,9);
}
gotoxy(6,x+11);cout<<r.name;
gotoxy(20,x+11);cout<<r.type;
gotoxy(33,x+11);cout<<r.mobile;
gotoxy(50,x+11);cout<<r.passport;
gotoxy(65,x+11);cout<<r.dd<<"/"<<r.mm<<"/"<<r.yy<<endl;
if(x==9)
{
d=0;
x=0;
setcolor(6);
settextstyle(2,0,6);
outtextxy(500,380,"PTO");
getch();
cleardevice();
}}

void output3()
{
cleardevice();
rect2(6,11);
setcolor(5);
settextstyle(3,0,4);
outtextxy(50,50,"Select the field to change");
setcolor(7);
settextstyle(1,0,1);
outtextxy(90,110,"1  name        =>>");
gotoxy(60,9);
cout<<r.name;
outtextxy(90,140,"2  type        =>>");
gotoxy(60,11);
cout<<r.type;
outtextxy(90,180,"3  country     =>>");
gotoxy(60,13);
cout<<r.nation;
outtextxy(90,220,"4  mobile no.  =>>");
gotoxy(60,15);
cout<<r.mobile;
outtextxy(90,260,"5  passport no.=>>");
gotoxy(60,17);
cout<<r.passport;
}
//***************************************************************
//                   function to return values
//****************************************************************

double passportno()
{	return r.passport;	}

char* return_name()
{	return r.name;		}

char* return_nation()
{	return r.nation;		}

char return_t()
{
	return r.t;
};
};

int a=0;		

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void main()
{
if(a==0)
{
intro(1);
intro2();
a++;}
int choice;
int gdriver = DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
cleardevice();
do
	{
		clrscr();
		cleardevice();
		rect(13,12);
		setcolor(5);
		settextstyle(3,0,4);
		outtextxy(180,70,"MAIN MENU");
		settextstyle(2,0,5);
		setcolor(9);
		outtextxy(180,140,"01. DETAILS MENU");
		outtextxy(180,180,"02. ENTRY/EDIT MENU");
		outtextxy(180,220,"03. SEARCH  MENU");
		outtextxy(180,260,"04. EXIT");
		setcolor(13);
		settextstyle(5,0,3);
		outtextxy(130,310,"Please Select Your Option (1-4) =>>");
		gotoxy(60,22);
		cin>>choice;
		switch(choice)
		{
			case 1:
			details_menu();
			break;
			case 2:
			entry_edit_menu();
			break;
			case 3:
			search_menu();
			break;
			case 4:
			intro(0);
			default:
			cout<<"wrong choice"<<endl;
			getch();
		}
	}while(choice!=5);
}
//***************************************************************
//                   DELTAIL MENU OF THE PROGRAM
//****************************************************************

void details_menu()
{
int choice;
do	{	clrscr();
		cleardevice();
		rect(7,12);
setcolor(5);
		settextstyle(3,0,4);
		outtextxy(180,70,"DETAILS MENU");
		settextstyle(2,0,5);
		setcolor(9);
		outtextxy(180,140,"01. DISPLAY ALL RECORDS ");
		outtextxy(180,160,"02. DISPLAY ALL STUNDENT VISA ");
		outtextxy(180,180,"03. DISPLAY ALL WORKING VISA");
		outtextxy(180,200,"04. DISPLAY ALL TOURISR VISA");
		outtextxy(180,220,"05. DISPLAY ALL MEDICAL VISA");
		outtextxy(180,240,"06. MAIN MENU");
		setcolor(13);
		settextstyle(5,0,3);
		outtextxy(130,300,"Please Select Your Option (1-6)=>>");
		gotoxy(60,22);
		cin>>choice;
		switch(choice)
		{
			case 1:
			read_record(1,0);
			break;
			case 2:
			read_record(2,0);
			break;
			case 3:
			read_record(3,0);
			break;
			case 4:
			read_record(4,0);
			break;
			case 5:
			read_record(5,0);
			break;
			case 6:
			main();
			default:
			cout<<"wrong choice"<<endl;
			getch();
		}
	}while(choice!=8);
}
//***************************************************************
//    	function to read  record from the file
//****************************************************************
void read_record(int n,int flag)
{
int d=0,x=0;
char c;
clrscr();
visa vis;
ifstream infile("visa.dat",ios::binary);
if(!infile)
{
rect2(6,8);
cleardevice();
clrscr();
settextstyle(3,0,5);
outtextxy(200,100,"file does not exits");
outtextxy(250,100,"press any key ..");
getch();
main();
}
infile.seekg(0,ios::beg);
if(n==1){	cleardevice();
		while(!infile.eof())
		{
		infile.read((char*)&vis,sizeof(vis));
		if(infile.eof())
		break;
		vis.output1(d,x);
		x++;
		}
		getch();
	}
else
	{
	if(n==2)
	{	c='s';
	goto xx;		}
	else
	if(n==3)
	{	c='w';
	goto xx;		}
	else
	if(n==4)
	{	c='t';
	goto xx;		}
	else
	if(n==5)
	{	c='m';
	goto xx;		}
	xx:
		infile.seekg(0,ios::beg);
		cleardevice();
		while(!infile.eof())
		{
		infile.read((char*)&vis,sizeof(vis));
		if(infile.eof())
		break;
		if(c==vis.return_t())
			{
			vis.output1(d,x);
			flag++;
			x++;
			}
		}
		if(flag==0)
		{
		cleardevice();
		settextstyle(3,0,5);
		outtextxy(200,100,"no records");
		}	getch();
	}
}
//***************************************************************
//                   ENTRY OR EDIT MENU
//****************************************************************

void entry_edit_menu()
{
int choice;
do	{
		clrscr();
		cleardevice();
		rect(4,13);
		setcolor(5);
		settextstyle(3,0,4);
		outtextxy(180,70,"ENTRY/EDIT MENU");
		settextstyle(2,0,5);
		setcolor(9);
		outtextxy(180,140,"01. ENTRY");
		outtextxy(180,180,"02. MODIFY");
		outtextxy(180,220,"03. DELETE");
		outtextxy(180,260,"04. MAIN MENU");
		setcolor(13);
		settextstyle(5,0,3);
		outtextxy(130,300,"Please Select Your Option (1-4)=>>");
		gotoxy(60,22);
		cin>>choice;
		switch(choice)
		{	case 1:
			write_record();
			break;
			case 2:
			modify_record();
			break;
			case 3:
			delete_record();
			break;
			case 4:
			main();
			default:
			cout<<"wrong choice"<<endl;
			getch();
		}

	}while(choice!=5);
}
//***************************************************************
//    	function to write a record in file
//****************************************************************
void write_record()
{
visa vis;
ofstream outfile("visa.dat",ios::binary|ios::ate);
vis.input();
outfile.write((char*)&vis,sizeof(vis));
outfile.close();
setcolor(9);
settextstyle(3,0,4);
outtextxy(50,370,"record created");
getch();
}
//***************************************************************
//    	function to modify record of file
//****************************************************************
void modify_record()
{
int choice;
char choice1;
float search;
float pos;
visa vis;
clrscr();
fstream file("visa.dat",ios::binary|ios::in|ios::out|ios::ate);
cleardevice();
rect2(4,5);
setcolor(5);
settextstyle(3,0,4);
outtextxy(180,100,"enter the passport no.");
outtextxy(180,130," to modify visa ");
gotoxy(50,17);
cin>>search;
file.seekp(0,ios::beg);
while(!file.eof())
{	pos=file.tellp();
	file.read((char*)&vis,sizeof(vis));
	if(file.eof())
	break;
	if(search==vis.passportno())
		{
		xx:
		cleardevice();
		vis.output3();
		outtextxy(90,300,"select to change =>>");
		gotoxy(60,20);
		cin>>choice;
		vis.input1(choice);
		outtextxy(90,360,"want more changes  y/n");
		gotoxy(60,24);
		cin>>choice1;
		if(choice1=='y')
		{
		goto xx;
		}
		file.seekp(pos,ios::beg);
		file.write((char*)&vis,sizeof(vis));
		setcolor(9);
		outtextxy(90,390,"record modify");
		break;
		}
		else
		{
		setcolor(9);
		outtextxy(90,300,"not found");
		}
}
file.close();
getch();
}

//***************************************************************
//    	function to delete record of file
//****************************************************************
void delete_record()
{
visa vis;
int flag=0;
float search;
cleardevice();
rect2(4,5);
settextstyle(3,0,4);
outtextxy(180,100,"enter the passport no.");
outtextxy(180,130," to delete visa ");
gotoxy(50,17);
cin>>search;
ifstream infile("visa.dat",ios::binary);
ofstream outfile("temp.dat",ios::binary);
if(!infile)
exit(0);
infile.seekg(0,ios::beg);
while(!infile.eof())
	{
	infile.read((char*)&vis,sizeof(vis));
	if(infile.eof())
	break;
	if(search!=vis.passportno())
	outfile.write((char*)&vis,sizeof(vis));
	else
	flag++;
	}
infile.close();
outfile.close();
remove("visa.dat");
rename("temp.dat","visa.dat");
if(flag!=0)
{
setcolor(9);
settextstyle(3,0,4);
outtextxy(150,275,"record deleted");
outtextxy(150,325," press any key...");
}
else
{
setcolor(9);
settextstyle(3,0,5);
outtextxy(150,275,"not found ");
outtextxy(150,325," press any key...");
}
getch();
}

int check1(float s)
{
visa vis;
ifstream infile("visa.dat",ios::binary);
	infile.seekg(0,ios::beg);
	while(!infile.eof())
		{
		infile.read((char*)&vis,sizeof(vis));
		if(infile.eof())
		break;
		if(s==vis.passportno())
			return 0;
		}
infile.close();
}


//***************************************************************
//    	FUNCTION TO SEARCH DETAIL
//***************************************************************
void search_menu()
{
int choice;
do	{       clrscr();
		cleardevice();
		rect(3,9);
		setcolor(5);
		settextstyle(3,0,4);
		outtextxy(180,70,"SEARCH MENU MENU");
		settextstyle(2,0,5);
		setcolor(9);
		outtextxy(180,140,"01. SEARCH BY NAME");
		outtextxy(180,180,"02. SEARCH BY PASSPORT NUMBER");
		outtextxy(180,220,"03. SEARCH BY NATION");
		outtextxy(180,260,"04. MAIN MENU");
		setcolor(13);
		settextstyle(5,0,3);
		outtextxy(130,300,"Please Select Your Option (1-4)=>>");
		gotoxy(60,22);
		cin>>choice;
		switch(choice)
		{
			case 1:
			search(1);
			break;
			case 2:
			search(2);
			break;
			case 3:
			search(3);
			break;
			case 4:
			main();
			default:
			cout<<"wrong choice"<<endl;
			getch();
		}
}while(choice!=5);
}

void search(int n)
{
int flag=0;
visa vis,vis1;
clrscr();
ifstream infile("visa.dat",ios::binary);
if(n==1)
	{
	char search[20];
	cleardevice();
	rect2(4,5);
	settextstyle(3,0,4);
	outtextxy(180,50,"enter the name ");
	outtextxy(180,90,"to search detail");
	gotoxy(50,17);
	cin>>search;
	infile.seekg(0,ios::beg);
	while(!infile.eof())
		{
		infile.read((char*)&vis,sizeof(vis));
		if(infile.eof())
		break;
		if(strcmpi(search,vis.visa::return_name())==0)
			{
			vis.output(0);
			flag++;
			}
		}
	}
else
if(n==2)
	{
	double search;
	cleardevice();
	rect2(4,5);
	settextstyle(3,0,3);
	outtextxy(180,50,"enter the passport ");
	outtextxy(180,90,"no to search detail");
	gotoxy(50,17);
	cin>>search;
	infile.seekg(0,ios::beg);
	while(!infile.eof())
		{
		infile.read((char*)&vis,sizeof(vis));
		if(infile.eof())
		break;
		if(search==vis.passportno())
			{
			vis.output(0);
			flag++;
			}
		}
	}
else
if(n==3)
	{
int d=0,x=0;
	char search[20];
	cleardevice();
	rect2(4,5);
	settextstyle(3,0,3);
	outtextxy(180,50,"enter the nation ");
	outtextxy(180,90," to search detail");
	gotoxy(50,17);
	cin>>search;
cleardevice();
	infile.seekg(0,ios::beg);
	while(!infile.eof())
		{
		infile.read((char*)&vis,sizeof(vis));
		if(infile.eof())
		break;
		if(strcmpi(search,vis.visa::return_nation())==0)
			{
			vis.output1(d,x);
			flag++;
			x++;
			}
		}  getch();
	}
infile.close();
if(flag==0)
{
cleardevice();
settextstyle(3,0,4);
outtextxy(200,100,"no result");
getch();
}}

//***************************************************************
//    		FUNCTIONS TO CREATE BORDER
//***************************************************************

void rect(int m,int n)
{
setcolor(15);
rectangle(0,0,635,445);
rectangle(8,8,628,438);
rectangle(35,35,600,410);
rectangle(42,42,593,403);
setfillstyle(1,m);
floodfill(5,5,15);
setfillstyle(1,m);
floodfill(40,40,15);
setfillstyle(6,n);
floodfill(10,10,15);
}

void cir()
{
int z=55,y=55;
setcolor(15);
for(int i=0;i<30;i++)
{
delay(50);
circle(70,10+y,10);
circle(570,10+z,10);
z=z+10;
y=y+10;
}}

void rect2(int m,int n)
{
setcolor(15);
rectangle(0,0,635,445);
rectangle(10,10,625,435);
rectangle(15,15,615,425);
setfillstyle(1,m);
floodfill(1,1,15);
setfillstyle(1,n);
floodfill(12,12,15);
}

//***************************************************************
//    	 FUNCTION TO CREATE FRONT PAGE OF PROGRAM
//****************************************************************
void intro(int x)
{
intro3(3,11,1);
intro1();
int y=20;
int p=2,o=2,v=0;
for(int i=0;i<20;i++)
{
delay(100);
setfillstyle(o,p);
floodfill(20+y,17,15);
floodfill(20+y,427,15);
y=y+30;
if(i==1+v)
{
v=v+2;
o++;
p++;
}}
p=12,o=12,v=0;
int z=20;
for(i=0;i<13;i++)
{
delay(100);
setfillstyle(o,p);
floodfill(615,20+z,15);
floodfill(20,20+z,15);
z=z+30;
if(i==1+v)
{
v=v+2;
o=o-1;
p=p-1;
}}
setfillstyle(1,11);
floodfill(41,41,15);
getch();
if(x==0)
{
exit(0);
closegraph();
}
cleardevice();
}

void intro1()
{
setcolor(1);
settextstyle(7,0,4);
outtextxy(90,40,"CHRIST  SR.  SEC.   SCHOOL");
setcolor(9);
settextstyle(6,0,2);
outtextxy(250,75,"GUNA(M.P.)");
outtextxy(235,100,"2016-2017");
setcolor(5);
settextstyle(3,0,3);
outtextxy(250,170,"PROJECT");
outtextxy(237,190,"REPORT ON");
outtextxy(220,210,"VISA RECORD");
setcolor(6);
settextstyle(1,0,2);
outtextxy(300,300,"MADE BY :");
outtextxy(300,320,"NITESH LODHA");
outtextxy(300,340,"JATIN SHRIVASTAVA");
outtextxy(300,360,"MANAV JAIN");}
void intro2()
{
intro3(8,7,0);
setcolor(CYAN);
settextstyle(3,0,5);
outtextxy(100,120,"WELCOME TO");
outtextxy(100,190,"VISA RECORD");
outtextxy(100,260,"MANEGEMENT PROTAL");
setcolor(BROWN);
settextstyle(3,0,3);
outtextxy(100,350,"PRESS ANY KEY TO CONTINUE");
getch();
closegraph();
}

void intro3(int m,int n,int o=1)
{
int gdriver = DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
cleardevice();
int z=20,y=20;
setcolor(15);
rectangle(0,0,635,445);
rectangle(5,5,630,440);
rectangle(35,35,600,410);
rectangle(40,40,595,405);
setfillstyle(1,m);
floodfill(6,6,15);
setfillstyle(1,n);
floodfill(41,41,15);
setcolor(15);
for(int i=0;i<13;i++)
{
if(o==1)
delay(100);
circle(615,20+z,10);
circle(20,20+z,10);
z=z+30;
}
for(i=0;i<20;i++)
{
if(o==1)
delay(100);
circle(20+y,427,10);
circle(20+y,17,10);
y=y+30;
}
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
