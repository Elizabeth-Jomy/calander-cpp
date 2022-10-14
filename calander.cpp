#include<iostream>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
using namespace std;
/*CALENDER APPLICATION -PROJECT (2019-2020) */
class calen
{
 int days,mm,k,z,p,yy,r,calen[5][7],i,j,mon;
 public:
 void calen_call(void);
 void display(void);
};
class day
{
 public:
 void calc(int,int,int);
 void dis(int);
  int k,m,y;
};
class user
{
  public:
  char username[10];
  char password[10];
  char* returnuser()
{ return username;
  }
  char* returnpass()
{ return password;
  }
}u1;

void login()
{ calen c;
  char username[10],password[10];
ifstream file;
file.open("uinfo.txt",ios::in);
cout<<" \t\t\tTO BEGIN WITH LOGIN"<<endl;
cout<<"\nENTER USERNAME:\t";
cin>>username;
cout<<"\nENTER PASSWORD:\t";
cin>>password;
  int v;
  while(file.read((char*)&u1,sizeof(u1)))
  {
    if(strcmp(u1.returnpass(),password)==0)
{  v=1;
       break;
     }
    else
{ v=0;
    }
  }
  if(v==1)
  {
c.calen_call();
c.display();
  }
  else
  {
cout<<"\nOOPSCANT LOGIN!!!\n"<<endl;
  }
file.close();
}

void signup()
{
fstream file;

file.open("uinfo.txt",ios::app);
cout<<"\nDONT HAVE AN ACCOUNT?....PLEASE SIGN UP"<<endl;
cout<<"\nENTER USERNAME:\t";
cin>>u1.username;
cout<<"\nENTER PASSWORD:\t";
cin>>u1.password;
file.write((char*)&u1,sizeof(u1));
  u1.returnuser();
file.close();
cout<<endl;
login();
}
 void main()
{ void find();
clrscr();
cout<<"\n\t\t\t            ***WELCOME!***                 \t\t\t";
cout<<"\n\t\t\t        LETS PLAY WITH DATES..           \t\t\t\n";

  int choice;
cout<<"ENTER YOUR CHOICE:"<<endl;
cout<<"1.SIGN UP"<<endl;
cout<<"2.LOGIN"<<endl;
  choose:
cin>>choice;
  if(choice==1)
    {signup();}
  else if(choice==2)
    {login();}
  else
    {cout<<"\nWRONG OPTION"<<endl;
cout<<"TRY AGAIN!!...ENTER YOUR CHOICE:"<<endl;
goto choose;
      }
cout<<"   \n\n\n\n\n\n\t\t\t   THANK YOU,SEE YOU NEXT TIME           "<<endl;

cout<<"   \n\n\n\n\t\t\t              THE END                      "<<endl;
getch();
}
 void find()
{  system("cls");
   day d;
cout<<"\n\n\n\n\n\n\t\t\t     FIND YOUR DAY!!       \n\n";
cout<<"ENTER DATE:";
cin>>d.k;
cout<<"\nENTER MONTH:";
cin>>d.m;
cout<<"\nENTER YEAR:";
cin>>d.y;
d.calc(d.k,d.m,d.y);
 }

void calen::calen_call(void)
{ cout<<"\n\t\t\tSUCCESSFULLY LOGGED IN!!"<<endl;
getch();
clrscr();
  int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
cout<<"\n\n\n\t\t\t***CALENDAR FROM YEAR 2000...***\n\n";
  repeat:
cout<<"\nENTER YEAR [2000 ...] : ";
cin>>yy;
  if(yy<=1999)
  {
cout<<"\n\nWRONG ENTRY";
goto repeat;
  }
  if(yy%4==0)
  {
    if(yy%100==0)
     {
      if(yy%400==0)
month[1]=29;

   else
month[1]=28;
     }
 else
month[1]=29;
  }
  again:
cout<<"\nENTER MONTH [1-12] :";
cin>>mon;
if(mon>12||mon<1)
  {
cout<<"\nWRONG ENTRY";
goto again;
  }
cout<<"\n\n\t\t\t\tYEAR "<<yy<<"\n\n";
  system("cls");
  switch(mon)
 {
    case 1:cout<<"\n\n\t\t\t\tJANUARY\n\n";break;
    case 2:cout<<"\n\n\t\t\t\tFEBRUARY\n\n";break;
    case 3:cout<<"\n\n\t\t\t\tMARCH\n\n";break;
    case 4:cout<<"\n\n\t\t\t\tAPRIL\n\n";break;
    case 10:cout<<"\n\n\t\t\t\tOCTOBER\n\n";break;
    case 11:cout<<"\n\n\t\t\t\tNOVEMBER\n\n";break;
    case 5:cout<<"\n\n\t\t\t\tMAY\n\n";break;
    case 6:cout<<"\n\n\t\t\t\tJUNE\n\n";break;
    case 7:cout<<"\n\n\t\t\t\tJULY\n\n";break;
    case 8:cout<<"\n\n\t\t\t\tAUGUST\n\n";break;
    case 9:cout<<"\n\n\t\t\t\tSEPTEMBER\n\n";break;
    case 12:cout<<"\n\n\t\t\t\tDECEMBER\n\n";break;
default:cout<<"\n\nWRONGENTRY";exit(0);

}

p=5;


for(r=1999;r<yy;r++)
 {
    if(r%4==0)
    {
     if(r%100==0)
     {
	if(r%400==0)
	p=p+2;
	else
	p++;
     }
     else
     p=p+2;
    }
    else
    p++;
    if(p==7)
    p=0;
    if(p==8)
    p=1;
 }
 for(mm=0;mm<12;mm++)
 {
    days=month[mm];
    k=0;
    for(z=0;z<7;z++)
calen[0][z]=0;
    for(i=0;i<5;i++,p=0)
    for(j=p;j<7&&k<days;j++)
    {

calen[i][j]=k+1;
     k++;
     if(k==days&&i==4&&j<7)
     {
	for(p=j+1;p<7;p++)

	calen[i][p]=0;
     }
     if(k<days&&i==4&&j==6)
     {
	for(p=0;p<7&&k<days;p++,k++)
	calen[0][p]=k+1;
	j=p-1;
     }

     if(k==days&&i==4&&j==6)
     {
	j=-1;
     }

     if(k==days&&i==3&&j==6)
     {

	for(p=0;p<7;p++)
	calen[4][p]=0;
     }
    }

    p=j;

    if(mm+1==mon)
    return;
 }
}

void calen::display()
{

cout<<"\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\n";

 for(i=0;i<5;i++)
 {

    for(j=0;j<7;j++)
cout<<"\t"<<calen[i][j];
cout<<"\n\n";
 }

getch();
find();

}

 void day::calc(int j,intl,int n)
 {
  int D,c,r,F;
 if(l>=3&&l<=10)
 {
  l=l-2;
  D=n%100;
 }
 else if(l==1 || l==2)
 {
  l=l+10;
  D=(n%100)-1;
 }
 c=n/100;
 F=j+((13*l-1)/5)+D+(D/4)+(c/4)-(2*c);
 if(F>0)
 {
 r=F%7;
 }
 if(F<0)
 {for(int i=1;i<=100;i++)
 {
 if(i*(-7)<F)
 {
  r=i*7+F;
  break;
  }
  }
  }
  dis(r);
  }
  void day::dis(int r)
  { 
cout<<"\t\tAND THE DAY IS....";
switch(r)
   {
 case 0:cout<<"\tSUNDAY\t\t\t\n\n";
	break;
     case 1:cout<<"\tMONDAY\t\t\t\n\n";
	    break;
     case 2:cout<<"\tTUESDAY\t\t\t\n\n";
	    break;
     case 3:cout<<"\tWEDNESDAY\t\t\t\n\n";
	    break;
     case 4:cout<<"\tTHURSDAY\t\t\t\n\n";
	    break;
     case 5:cout<<"\tFRIDAY\t\t\t\n\n";
	    break;
     case 6:cout<<"\tSATURDAY\t\t\t\n\n";
	    break;
default:cout<<"\tOOPS!\t\t\t\n\n";
   }
getch();
   system("cls");

}