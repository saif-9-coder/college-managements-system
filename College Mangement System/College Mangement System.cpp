#include<fstream>
#include<iostream>
//#include<conio.h>
//#include<process.h>
//#include<stdio.h>
//#include<student.h>
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
  void bill()
  {
  	
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
class courses:public student
{
	private:
	string course1,course2;
	public:
		void addcourses()
  {
  	int newroll;
  	cout<<"Enter student roll no =";
  	cin>>newroll;
  	ofstream filee;
	filee.open("Courses list.txt",ios::app);
  	ifstream file;
	file.open("student list.txt",ios::in);
	file>>rollno>>name>>department>>semester;
	while(!file.eof())
	  {
	  	if(newroll==rollno)
	  	{
	  
	  		cout<<"Select 2 Courses"<<endl<<endl;
	  		cout<<"\tCSI-321"<<endl;
	  		cout<<"\tDSA-123"<<endl;
	  		cout<<"\tAI-111"<<endl;
	  		cout<<"\tSE-222"<<endl;
	  		cout<<"\tNE-333"<<endl;
	  		cout<<"\tJAVA-444"<<endl;
	  		cout<<"Enter 1st Course name-code=";
	  		cin>>course1;
	  		cout<<"Enter 2nd Course name-code=";
	  		cin>>course2;

	  		
	  		filee<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl<<"\t"<<course1<<endl<<"\t"<<course2<<endl;
	  		cout<<"\t\t\tCourses Update"<<endl;
		}
		   file>>rollno>>name>>department>>semester;
	  }	
	  file.close();
	  filee.close();
  }
  void coursesdisplay()
  {
  	ifstream file;
	  file.open("courses list.txt",ios::in);
	  file>>rollno>>name>>department>>semester>>course1>>course2;
	  while(!file.eof())
	  {
	  	cout<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl<<"\t"<<course1<<endl<<"\t"<<course2<<endl;	
	    file>>rollno>>name>>department>>semester>>course1>>course2;
	  }	
  }
};
class fee:public courses
{
	public:
	    string fee;
		void addfee()
		{
			coursesdisplay();
			int newroll;
  	cout<<"Enter student roll no =";
  	cin>>newroll;
  	ofstream filee;
	filee.open("fee list.txt",ios::app);
  	ifstream file;
	file.open("student list.txt",ios::in);
	file>>rollno>>name>>department>>semester;
	while(!file.eof())
	  {
	
	  	if(newroll==rollno)
	  	{
	  		cout<<"Enter Fee of Student=";
	  		cin>>fee;
	  		filee<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<fee<<endl;
		}
//		else
//		{
//	
//	  	cout<<"Roll NO not exist>>>>"<<endl;
//		}
		   file>>rollno>>name>>department>>semester;
	  }	
	  file.close();
	  filee.close();
	}
	void feedisplay()
	{
	  ifstream file;
	  file.open("fee list.txt",ios::in);
	  file>>rollno>>name>>department>>semester>>fee;
	  while(!file.eof())
	  {
	  	cout<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<fee<<endl;	
	    file>>rollno>>name>>department>>semester>>fee;
	  }		
	}
		void modifyfee()
  {
  	int newroll;
  	cout<<"Enter student roll no =";
  	cin>>newroll;
  	ofstream filee;
	filee.open("newfee list.txt",ios::app);
  	ifstream file;
	file.open("fee list.txt",ios::in);
	file>>rollno>>name>>department>>semester>>fee;
	while(!file.eof())
	  {
	
	  	if(newroll==rollno)
	  	{
	  	    cout<<"Enter Update fee=";
	  	    cin>>fee;
	  		filee<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<fee<<endl;
	  		cout<<"Student details updates...."<<endl;
		}
		else
		{
	
	  	filee<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl;	
		}
		   file>>rollno>>name>>department>>semester>>fee;
	  }	
	  file.close();
	  filee.close();
  	remove("fee list.txt");
  	rename("newfee list.txt","fee list.txt");
	}
	fee_menu()
	{
		int ch;
	cout<<endl<<"\t\t<<<<<<<....(  << FEE MENU >>   )....>>>>>>>>"<<endl;
	cout<<"ENTER (1) >>>>>> Add Fee "<<endl;
	cout<<"ENTER (2) >>>>>> Watch Fee List"<<endl;
	cout<<"ENTER (3) >>>>>> Modify Fee List "<<endl;
//	cout<<"ENTER (4) >>>>>> Modify Student Details in List "<<endl;
//	cout<<"ENTER (5) >>>>>> Back To Main Menu "<<endl;
	cout<<"\nEnter Your choice >>>";
	cin>>ch;
	switch(ch)
    {
    	case 1:
    		addfee();
    	break;
		case 2:
	        feedisplay();	
			break;
			case 3:
			feedisplay();
			 modifyfee();	
				break;
			case 4:
			
				break;
			case 5:

				break;
	}
	}
};
class attendence:public student
{
   public:
   	string attendence;
   	displayattendence()
	{
	  student s;
	  s.display();
	  ifstream file;
	  file.open("Attendence list.txt",ios::in);
	  file>>rollno>>name>>department>>semester>>attendence;
	  while(!file.eof())
	  {
	  	cout<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<attendence<<endl;	
	    file>>rollno>>name>>department>>semester>>attendence;
	  }	
	}
   	markattendence()
	{
		int newroll;
  	cout<<"Enter student roll no =";
  	cin>>newroll;
  	ofstream filee;
	filee.open("Attendence list.txt",ios::app);
  	ifstream file;
	file.open("student list.txt",ios::in);
	file>>rollno>>name>>department>>semester;
	while(!file.eof())
	  {
	
	  	if(newroll==rollno)
	  	{
	  		cout<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl;
	  		cout<<"Enter Attendence in % =";
	  		cin>>attendence;
	  		filee<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<attendence<<endl;
		}
		   file>>rollno>>name>>department>>semester;
	  }	
	  file.close();
	  filee.close();
	}	
   	attendence_menu()
   	{
   	int ch;
	cout<<endl<<"\t\t<<<<<<<....(  << ATTENDENCE MENU >>   )....>>>>>>>>"<<endl;
	cout<<"ENTER (1) >>>>>> Mark Attendence "<<endl;
	cout<<"ENTER (2) >>>>>> Watch Attendence record"<<endl;
//	cout<<"ENTER (3) >>>>>> Delete Student From List "<<endl;
//	cout<<"ENTER (4) >>>>>> Modify Student Details in List "<<endl;
//	cout<<"ENTER (5) >>>>>> Back To Main Menu "<<endl;
	cout<<"\nEnter Your choice >>>";
	cin>>ch;
	switch(ch)
    {
    	case 1:
    		markattendence();
    	break;
		case 2:
	        displayattendence();	
			break;
			case 3:
				
				break;
			case 4:
			
				break;
			case 5:

				break;
	}
	
}
};
class exam:public courses
{
	public:
	string course1,course2;
		addexam()
		{
			coursesdisplay();
		int newroll;
  	cout<<"Enter student roll no =";
  	cin>>newroll;
  	ofstream filee;
	filee.open("exam list.txt",ios::app);
  	ifstream file;
	file.open("student list.txt",ios::in);
	file>>rollno>>name>>department>>semester;
	while(!file.eof())
	  {
	  	if(newroll==rollno)
	  	{
	  
//	  		cout<<"Select 2 Courses"<<endl<<endl;
//	  		cout<<"\tCSI-321"<<endl;
//	  		cout<<"\tDSA-123"<<endl;
//	  		cout<<"\tAI-111"<<endl;
//	  		cout<<"\tSE-222"<<endl;
//	  		cout<<"\tNE-333"<<endl;
//	  		cout<<"\tJAVA-444"<<endl;
	  		cout<<"Enter 1st exam name=";
	  		cin>>course1;
	  		cout<<"Enter 2nd exam name-code=";
	  		cin>>course2;

	  		
	  		filee<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl<<"\t"<<course1<<endl<<"\t"<<course2<<endl;
	  		cout<<"\t\t\tCourses Update"<<endl;
		}
		   file>>rollno>>name>>department>>semester;
	  }	
	  file.close();
	  filee.close();	
			
		}
		examdisplay()
		{
			ifstream file;
	  file.open("exam list.txt",ios::in);
	  file>>rollno>>name>>department>>semester>>course1>>course2;
	  while(!file.eof())
	  {
	  	cout<<rollno<<"\t"<<name<<"\t"<<department<<"\t"<<semester<<"\t"<<endl<<"\t"<<course1<<endl<<"\t"<<course2<<endl;	
	    file>>rollno>>name>>department>>semester>>course1>>course2;
	  }	
		}
 exam_menu()
	{
	int ch;
	cout<<endl<<"\t\t<<<<<<<....(  << EXAM MENU >>   )....>>>>>>>>"<<endl;
	cout<<"ENTER (1) >>>>>> Add EXAM"<<endl;
	cout<<"ENTER (2) >>>>>> Watch EXAM list"<<endl;
//	cout<<"ENTER (3) >>>>>> Delete Student From List "<<endl;
//	cout<<"ENTER (4) >>>>>> Modify Student Details in List "<<endl;
//	cout<<"ENTER (5) >>>>>> Back To Main Menu "<<endl;
	cout<<"\nEnter Your choice >>>";
	cin>>ch;
	switch(ch)
    {
    	case 1:
    		addexam();
    	break;
		case 2:
	        examdisplay();	
			break;
			case 3:
				
				break;
			case 4:
			
				break;
			case 5:

				break;
	}	
 }
	
};
courses_menu()
{
	courses c;
	int ch;
	cout<<endl<<"\t\t<<<<<<<....(  << COURSES MENU >>   )....>>>>>>>>"<<endl;
	cout<<"ENTER (1) >>>>>> Add New Courses "<<endl;
	cout<<"ENTER (2) >>>>>> Watch Courses list"<<endl;
//	cout<<"ENTER (3) >>>>>> Delete Student From List "<<endl;
//	cout<<"ENTER (4) >>>>>> Modify Student Details in List "<<endl;
//	cout<<"ENTER (5) >>>>>> Back To Main Menu "<<endl;
	cout<<"\nEnter Your choice >>>";
	cin>>ch;
	switch(ch)
    {
    	case 1:
    		c.addcourses();
    	break;
		case 2:
	        c.coursesdisplay();	
			break;
			case 3:
				
				break;
			case 4:
			
				break;
			case 5:

				break;
	}
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
main_menu()
{
	exam e;
	fee f;
	student s;
	attendence a;
	int ch;
	cout<<endl<<"\t\t<<<<<<<....(  << MAIN MENU >>   )....>>>>>>>>"<<endl;
	cout<<"ENTER (1) >>>>>> Student Info Menu "<<endl;
	cout<<"ENTER (2) >>>>>> Courses Menu"<<endl;
	cout<<"ENTER (3) >>>>>> Fees Menu "<<endl;
	cout<<"ENTER (4) >>>>>> Attendence Menu "<<endl;
	cout<<"ENTER (5) >>>>>> Exam Menu "<<endl;
	cout<<"\nEnter Your choice >>>";
	cin>>ch;
	switch(ch)
    {
    	case 1:
    	s.student_menu()	;
    	break;
		case 2:
	         courses_menu();	
			break;
			case 3:
				f.fee_menu();
				break;
			case 4:
				a.attendence_menu();
				break;
			case 5:
			 e.exam_menu();
			 break;	
	}
	main_menu();
}
main()
{
	cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|      COLLEGE MENAGEMENT SYSTEMS          |"<<endl;
	cout<<"\t\t============================================"<<endl;
	main_menu();
}
