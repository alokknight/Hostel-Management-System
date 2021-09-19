#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctime>

using namespace std;

struct student
{
    long long ID;
    string mobileno;
	string firstname;
	string lastname;
	int age;
	string room;
	string city;
	string fathername;
	string department;
	string sem;
	string feestatus;

    struct student *next;
};

class linkedqueue
{
	student *head,*last;
	public:
	linkedqueue() //constructor
	{
		head=NULL;
		last=NULL;
	}
    student input();
    void insert();
    void insertatbeg();
    void getout();
    void listofstudents();
    int search(int);

    char switch_case[50];
};

class admin{public :
	void password();
}A;

class stu{public:
	void password();
}S;

void admin::password()
{  int flag =1;
   string pass ="";
   alok:
   char ch='\0';
   { if (flag ==1)
        cout << "Enter password   :: " ;
     else
       { exit (0);
		//cout << "Renter password   :: ";
        }
   ch = _getch();
   while(ch!= 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();}
   }
   if(pass=="alok"){flag =885;}
   else {flag =0;}
   if(flag==885)
    {cout << "\nAccess granted :P\n";}
   else
    {cout << "\nUnathurized Access\n so    Access aborted...\n";
    goto alok;}

}
void stu::password()
{ int flag =1;
   string pass ="";
   alok:
   char ch='\0';
   { if (flag ==1)
        cout << "Enter password   :: " ;
     else
       { exit (0);
		//cout << "Renter password   :: ";
        }
   ch = _getch();
   while(ch!= 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();}
   }
   if(pass=="student"){flag =885;}
   else {flag =0;}
   if(flag==885)
    {cout << "\nAccess granted :as a valid student \n";getchar();}
   else
    {cout << "\nUnathurized Access\nso    Access aborted...\n";
    goto alok;}
}


int linkedqueue :: search(int item)
{
	 if(head==NULL)
     return false;
     else
     {
     int flag=0;
      student *p=new student();
     p=head;

     while( p->next!=NULL && p->ID!=item )
     {
        p=p->next;
     }
     if(p->ID==item)
     {
	 	flag=1;
	 	return true;
     }
     if(flag==0)
     return false;
     }
     return 0;
}

int readnumber()
{
	int n;
	cin>>n;
	return n;
}

student linkedqueue :: input()
{
    int flag=0;
    student *p=new student();
    cout << "\n\tPlease enter data for student\n";
   cout<<"\trollno.         : ";getchar();
   cin>>p->ID;
   cout<<"\tFirst name      : ";getchar();
   getline(cin,p->firstname);
   cout << "\tLast name      : ";
   getline(cin,p->lastname);
   cout << "\tfather         : ";
   getline(cin,p->fathername);
   cout<<"\tmobileno.        : ";
   getline(cin,p->mobileno);
   cout<<"\troom alloted     : ";
   getline(cin,p->room);
   cout << "\tDepartment     : ";
   getline(cin,p->department);
   cout << "\tsem            : ";
   getline(cin,p->sem);
   cout << "\tcity           : ";
   getline(cin,p->city);
   cout<<"\tfee status       :(y/n)  ";
   cin>>p->feestatus;
   cout<<"\tAge              : ";
   cin>>p->age;


	if(search(p->ID))
	{
		/*//// p->ID=NULL;*/
        p->ID=0;
		cout << "\n\tData not valid. Operation cancelled.";
	}
	return *p;
}

void output(student *p)
{
	cout<<"\n**********************************";
	cout<<"\n\nstudent data:";
	cout<<"\n\nrollno.          : "<<p->ID<<endl;
	cout<<"\n\nFirst Name       : "<<p->firstname;
 	cout<<"\nLast Name          : "<<p->lastname;
	cout<<"\nroom alloted       : "<<p->room;
	cout<<"\nAge                : "<<p->age;
	cout<<"\nfather name        : "<<p->fathername;
	cout<<"\ncity               : "<<p->city;
	cout<<"\nDepartment         : "<<p->department;
	cout<<"\nsemester           : "<<p->sem;
	cout<<"\nMobile Number      : "<<p->mobileno;
	cout<<"\nfeestatus          : "<<p->feestatus;
	cout<<"\n\n**********************************";
}

void linkedqueue :: insertatbeg()
{
     student*p=new student();
     *p=input();
     if(p->ID==0)
      return;

     if(head==NULL)

     {
         head=p;
         last=p;
         p->next=NULL;
     }
     else
     {
        p->next=head;
        head=p;
     }
     system("cls");
     cout << "\n\tStudent added:";
     output(p);
}

void linkedqueue:: insert()
{
     student*p=new student();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)
     {
     	head=p;
        last=p;
        p->next=NULL;
     }
     else
     {
     	p->next=NULL;
        last->next=p;
        last=p;
     }
     system("cls");
     cout << "\n\tstudent added:";
     output(p);
}

void linkedqueue :: getout()
{
	 system("cls");
     if(head==NULL)
     {
     	cout<<"\n\tNo student to operate";
     }
     else
     {
     	student*p=new student();
     	p=head;
     	head=head->next;
 	    cout << "\n\tStudent to remove:";
        output(p);
 	 }
}

void linkedqueue :: listofstudents()
{
     if(head==NULL)
     {
     	cout<<"\n\tNo student";
 	 }
     student *p=new student;
     p=head;
     while(p!=NULL)
     {
        cout<<"\nstudent data:";
    cout<<"\n\nrollno.          : "<<p->ID;
	cout<<"\n\nFirst Name       : "<<p->firstname;
 	cout<<"\nLast Name          : "<<p->lastname;
	cout<<"\nroom alloted       : "<<p->room;
	cout<<"\nAge                : "<<p->age;
	cout<<"\nfather name        : "<<p->fathername;
	cout<<"\ncity               : "<<p->city;
	cout<<"\nDepartment         : "<<p->department;
	cout<<"\nsemester           : "<<p->sem;
	cout<<"\nMobile Number      : "<<p->mobileno;
	cout<<"\nfeestatus          : "<<p->feestatus;
	cout<<"\n**********************************\n";
    p=p->next;
     }
     cout<<"\n";
}


void action(linkedqueue * q)
{
    int choice = 0, success;
    student p;
    while (choice != 5)
	{
    system("cls");
	cout<<"\n\n\tWelcome To hostel manegement  : " << q->switch_case<<endl;
	cout<<"\n\t\t[1] Add student\n";
	cout<<"\t\t[2] Add student first \n";
	cout<<"\t\t[3] Remove from hostel\n";
	cout<<"\t\t[4] Display list\n";
	cout<<"\t\t[5] exit\n";
	cout<<"\n\tPlease enter your choice : ";
	choice=readnumber();

    switch (choice)
	{
	  case 1:	q->insert();
				cout << "\n\tPress any key";
	    		getch();
	 			break;

      case 2:	q->insertatbeg();
	    		cout << "\n\tPress any key";
	    		getch();
				break;

      case 3:	q->getout();
	 			cout<<"\n\tPress any key";
     			getch();
	      		break;

      case 4:	system("cls");
	 			q->listofstudents();
	 			cout<<"\n\tPress any key";
	 			getch();
				break;
	 }
    }
}

int main ()
{
    int i=0, choice = 0;
	linkedqueue login;
	system("COLOR 5F");
    strcpy(login.switch_case,"login\n");
	while(choice!=2)
	{

		system("cls");
		cout<<"\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>";
		cout<<"\n\tHOSTEL MANAGEMENT SYSTEM\t";
		cout<<"\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		{
			cout<<"\t"<<1<<": "<<login.switch_case;
		}
		cout<<"\t2: Exit";
		cout<<"\n\n\tPlease enter your 1 to proceed for login : ";
		choice=readnumber();
		if(choice==1)
		{   int x=0;
		    cout<<"\tenter 1 of admin login; \n\t2 for student login;\n"<<endl;
			cin>>x;
			switch(x)
		    {case 1:
			{cout<<"admin login"<<endl;
		    A.password();}break;
		    case 2:
			{cout<<"student login"<<endl;
		    S.password();}}
			action(&login);

		}

	}
	if(choice==2)
	cout<<"\n\t\tThanks by cs2018021018 alok patel\n";
	cout<<"\t\tBrought To You By alokpatel";
	exit(0);
}
