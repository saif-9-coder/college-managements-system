#include<fstream>
#include<iostream>
#include<conio.h>
#include<process.h>
#include<stdio.h>
using namespace std;
class student
{
 public:
 int rollno;
 string name;
 string department;
 string semester;
 int Class;
 int marks;
 char grade;
 	void input()
		{
			ofstream file;
			file.open("student list.txt",ios::app);
			cout<<"\t<<<<<< Enter Roll No of Student >>>>>>"<<endl;
			cin>>rollno;
			cout<<"\t<<<<<< Enter Name of Student >>>>>>"<<endl;
			cin>>name;
			cout<<"\t<<<<<< Enter Department name of Student >>>>>>"<<endl;
			cin>>department;
			cout<<"\t<<<<<< Enter semester of Student >>>>>>"<<endl;
			cin>>semester;
//			cout<<"\t<<<<<< Enter Marks(in percentage) of Student >>>>>>"<<endl;
//			cin>>marks;		
			file<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl;	
		}
	void display()
	{  
	  ifstream file;
	  file.open("student list.txt",ios::in);
	  file>>rollno>>name>>department>>semester;
	  while(!file.eof())
	  {
	  	cout<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl;	
	    file>>rollno>>name>>department>>semester;
	  }	
	}	
  void del()
  {
  	int newroll;
  	cout<<"Enter student roll no =";
  	cin>>newroll;
  	ofstream filee;
	filee.open("newstudent list.txt",ios::app);
  	ifstream file;
	file.open("student list.txt",ios::in);
	file>>rollno>>name>>department>>semester;
	while(!file.eof())
	  {
	
	  	if(newroll==rollno)
	  	{
	  		cout<<"element found and delete"<<endl;
		}
		else
		{
	
	  	filee<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl;	
		}
		   file>>rollno>>name>>department>>semester;
	  }	
	  file.close();
	  filee.close();
  	remove("student list.txt");
  	rename("newstudent list.txt","student list.txt");
  }
  void modify()
  {
  	int newroll;
  	cout<<"Enter student roll no =";
  	cin>>newroll;
  	ofstream filee;
	filee.open("newstudent list.txt",ios::app);
  	ifstream file;
	file.open("student list.txt",ios::in);
	file>>rollno>>name>>department>>semester;
	while(!file.eof())
	  {
	
	  	if(newroll==rollno)
	  	{
	  		cout<<"\t<<<<<< Enter New Roll No of Student >>>>>>"<<endl;
			cin>>rollno;
			cout<<"\t<<<<<< Enter New Name of Student >>>>>>"<<endl;
			cin>>name;
			cout<<"\t<<<<<< Enter New Department name of Student >>>>>>"<<endl;
			cin>>department;
			cout<<"\t<<<<<< Enter New semester of Student >>>>>>"<<endl;
			cin>>semester;
	  		filee<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl;
	  		cout<<"Student details updates...."<<endl;
		}
		else
		{
	
	  	filee<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl;	
		}
		   file>>rollno>>name>>department>>semester;
	  }	
	  file.close();
	  filee.close();
  	remove("student list.txt");
  	rename("newstudent list.txt","student list.txt");
  }
  student_menu()
{
	student s;
	int ch;
	cout<<endl<<"\t\t<<<<<<<....(  << STUDENT MENU >>   )....>>>>>>>>"<<endl;
	cout<<"ENTER (1) >>>>>> Add New Stdent "<<endl;
	cout<<"ENTER (2) >>>>>> Watch All Student List"<<endl;
	cout<<"ENTER (3) >>>>>> Delete Student From List "<<endl;
	cout<<"ENTER (4) >>>>>> Modify Student Details in List "<<endl;
	cout<<"ENTER (5) >>>>>> Back To Main Menu "<<endl;
	cout<<"\nEnter Your choice >>>";
	cin>>ch;
	switch(ch)
    {
    	case 1:
    		s.input();
    	break;
		case 2:
	         s.display();	
			break;
			case 3:
				s.del();
				break;
			case 4:
				s.modify();
				break;
			case 5:
				
				break;
	}
}
};
