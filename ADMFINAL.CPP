#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <fstream.h>

int cls;
char ch1;
int adm=0;
void init()
{
fstream if10("admno.txt",ios::in|ios::out|ios::app);
//if10.seekp(0);
//if10<<999;
if10.seekg(0);
if10>>adm;
if10.close();
}


struct dt
	{
	 int dt2;
	 int month;
	 int year;
	};

dt fixed={1,6,2018};


int calc_age(dt&obj)
{
 char date1[11];
 int age2;
 enter:
 cout<<"\nEnter date of birth: DD/MM/YYYY:\t";
 gets(date1);
 obj.dt2=((date1[0]-48)*10 + (date1[1]-48));
 obj.month=((date1[3]-48)*10 + (date1[4]-48));
 obj.year=((date1[6]-48)*1000 + (date1[7]-48)*100 + (date1[8]-48)*10 + (date1[9]-48));
 if(obj.month<0 || obj.month>12 || obj.dt2>31 || obj.dt2<0 || obj.year<2000 || obj.year>2017)
  {
   cout<<"\nInvalid date: ";
   goto enter;
  }

 switch(obj.month)
  {
   case 2: if(obj.dt2>29)
	    {
	     cout<<"\nInvalid date: ";
	     goto enter;
	    }
	   if(obj.year%4!=0)
	    {
	     if(obj.dt2>28)
	      {
	       cout<<"\nInvalid date: ";
	       goto enter;
	      }
	    }
	   break;

   case 4: if(obj.dt2>30)
	    {
	     cout<<"\nInvalid date: ";
	     goto enter;
	    }
	   break;
   case 6: if(obj.dt2>30)
	    {
	     cout<<"\nInvalid date: ";
	     goto enter;
	    }
	   break;
   case 9: if(obj.dt2>30)
	    {
	     cout<<"\nInvalid date: ";
	     goto enter;
	    }
	   break;
   case 11: if(obj.dt2>30)
	    {
	     cout<<"\nInvalid date: ";
	     goto enter;
	    }
	   break;
  }


 if(obj.month>=fixed.month)
  {
   age2=fixed.year-obj.year-1;
  }
 else if(obj.month<fixed.month)
  {
   age2=fixed.year-obj.year;
  }

 return age2;
}


class student1
	     {
	      char name[25];
	      int class1;
	      dt dob;
	      int admin;
	      char phoneno[11];
	      char *ptr;          //Pointer
	      char address[50];
	      char gender;

	      public:

	      int age;

	      student1()
	       {
		strcpy(name,"N.I");
		age=admin=0;
		class1=0;
		strcpy(phoneno,"N.I");
		ptr=name;
		strcpy(address,"N.I");
		dob.dt2=dob.month=dob.year=0;
		gender='n';
	       }
	      void assignclass(int cls)
	       {
		class1=cls;
		admin=admno();
	       }
	      void change_phone(char ph[])
	       {
		strcpy(phoneno,ph);
	       }
	      void change_add(char add[])
	       {
		strcpy(address,add);
	       }
	      int comproll()
	       {
		return admin;
	       }

	      void getdata();

	      int admno();

	      void display();

	      ~student1()
	       {
		cout<<"Destructor";
	       }
	     };

	       int student1::admno()
	       {

		   adm++;
		   return adm;
	       }
	     void student1::getdata()
	       {
		cout<<"Enter name: ";
		gets(name);
		ptr=name;
		cout<<"Gender: ";
		glabel:
		cin>>gender;
		gender=tolower(gender);
		if(gender=='m'|| gender=='f')
		 {
		 }
		else
		 {
		  cout<<"Enter a valid gender:\t";
		  goto glabel;
		 }
		cout<<"Enter phone number (10 digit):\t";
		eph:
		cin>>phoneno;
		if(strlen(phoneno)!=10)
		 {
		  cout<<"Enter 10 digit phone number:\t";
		  goto eph;
		 }
		cout<<"Enter address:\t";
		gets(address);
		age=calc_age(dob);
	       }


	      void student1::display()
	       {
		cout<<"\nName: "<<ptr;
		cout<<"\nAge on 1st June, 2018 =  "<<age<<" years "<<"\nClass: "<<class1;
		cout<<"\nGender: "<<gender;
		cout<<"\nAdmission number: "<<admin;
		cout<<"\nAddress: "<<address;
		cout<<"\nPhone number: "<<phoneno;
	       }

student1 grader;

void admission(int grade)
{
 init();
 char str[20];
 int flag=0;

    grader.getdata();
    while(grader.age<(grade+4))
     {
      if(flag==0)
       {
	cout<<"\nYou are not eligible to be admitted into class "<<grade;
	flag=1;
       }
      if(grade==9)
       {
	break;
       }
      else
       {
	grade--;
       }
     }

    cout<<"\nYou are eligible to be admitted into class "<<grade<<endl<<endl;
    cout<<"\nWould you like to join class "<<grade<<"? (y/n):\t";
    char ch10;
    cin>>ch10;
    if(ch10=='y'||ch10=='Y')
    {
    grader.assignclass(grade);
    switch(grade)
    {
     case 9:  strcpy(str,"g9");
	      break;
     case 10: strcpy(str,"g10");
	      break;
     case 11: strcpy(str,"g11");
	      break;
     case 12: strcpy(str,"g12");
	      break;
    }
    fstream f1(str,ios::in|ios::out|ios::app|ios::binary);
    f1.write((char*)&grader, sizeof(grader));
    f1.read((char*)&grader, sizeof(grader));

    clrscr();
    grader.display();
    f1.close();
    fstream if9("admno.txt",ios::out);
    if9.seekp(0);
    if9<<grader.comproll();
    if9.close();
    cout<<endl<<endl;
    system("pause");
   }
    else
    cout<<"\n-------------------Thanks----------------------\n";
 }

 void delete1(int grade)
 {
  char str[20];
  int roller,
  flag=0;
  switch(grade)
    {
     case 9: strcpy(str,"g9");
	     break;
     case 10: strcpy(str,"g10");
	     break;
     case 11: strcpy(str,"g11");
	     break;
     case 12: strcpy(str,"g12");
	     break;
    }
  cout<<"Enter the admission number of the student:  ";
  cin>>roller;
  fstream obj1(str,ios::in|ios::out|ios::app|ios::binary);
  fstream obj10("temp",ios::in|ios::out|ios::app);

  obj1.seekg(0);
  while(1)
     {
      obj1.read((char*)&grader,sizeof(grader));
      if(obj1.eof())
       {
	break;
       }
      if(roller!=grader.comproll())
       {
	obj10.write((char*)&grader,sizeof(grader));
       }
      else
       {
	flag=1;
       }
     }

 obj1.close();
 obj10.close();
 remove(str);
 rename("temp",str);
  ifstream obj11(str,ios::in|ios::binary);

  if(flag==0)
   {
    cout<<"Record not found: ";
   }
  else
   {
    obj11.seekg(0);
   while(1)
    {
     obj11.read((char*)&grader,sizeof(grader));
     if(obj11.eof())
	break;
     else
	grader.display();
    }
  }

  obj11.close();
 }

void modify(int grade)
{
  char str[20],newadd[50],newph[11],choice;
  int roller,flag=0,pos=0;
  switch(grade)
    {
     case 9:  strcpy(str,"g9");
	      break;
     case 10: strcpy(str,"g10");
	      break;
     case 11: strcpy(str,"g11");
	      break;
     case 12: strcpy(str,"g12");
	      break;
    }
  cout<<"Enter the admission number of the student: ";
  cin>>roller;
  fstream obj7(str,ios::in|ios::out|ios::ate|ios::binary);
  obj7.seekg(0);
 while(1)
 {
  pos=obj7.tellg();
  obj7.read((char*)&grader,sizeof(grader));
  if(obj7.eof())
   {
    break;
   }
  else
   {
    if(roller==grader.comproll())
     {
      flag=1;
      break;
     }
   }
 }
    if(flag==0)
    {
     cout<<"Record not found:\n";
    }
  else if(flag==1)
    {
     cout<<"Would you like to modify phone number or address or both? (p/a/b) ";
      modif:
      cin>>choice;
      if(choice=='p'||choice=='P')
       {
	cout<<"Enter new phone number: ";
	enewph:
	cin>>newph;
	if(strlen(newph)!=10)
	 {
	  cout<<"Enter 10 digit phone number:\t";
	  goto enewph;
	 }
	grader.change_phone(newph);
       }
      else if(choice =='a'||choice=='A')
       {
	cout<<"Enter new address: ";
	gets(newadd);
	grader.change_add(newadd);
       }
      else if(choice=='b'||choice=='B')
       {
	cout<<"Enter new phone number (10 digit): ";
	enewph1:
	cin>>newph;
	if(strlen(newph)!=10)
	 {
	  cout<<"Enter 10 digit phone number:\t";
	  goto enewph1;
	 }

	grader.change_phone(newph);
	cout<<"Enter new address: ";
	gets(newadd);
	grader.change_add(newadd);
       }
     else
      {
       cout<<"Enter a valid choice:\t";
       goto modif;
      }
     obj7.seekp(pos);
     obj7.write((char*)&grader,sizeof(grader));
     obj7.clear();
     obj7.seekg(pos);
     obj7.read((char*)&grader,sizeof(grader));
     cout<<"\nModified record\n";
     grader.display();
     obj7.close();
    }
}


void search(int grade)
{
    int roller, flag=0;
    char str[20];

    switch(grade)
    {
     case 9: strcpy(str,"g9");
	     break;
     case 10: strcpy(str,"g10");
	     break;
     case 11: strcpy(str,"g11");
	     break;
     case 12: strcpy(str,"g12");
	     break;
    }
    cout<<"Enter the admission number of the student: ";
    cin>>roller;
    fstream f2(str,ios::in|ios::out|ios::app|ios::binary);
    f2.seekg(0);

while(1)
{
 f2.read((char*)&grader,sizeof(grader));
 if(f2.eof())
  {
   break;
  }
 else
  {
   if(roller==grader.comproll())
    {
     flag=1;
     grader.display();
     break;
    }
  }
}

 if(flag==0)
  {
   cout<<"Record not found: ";
  }
f2.close();
}

void disp(int grade)
{
  char str[20];

    switch(grade)
    {
     case 9:  strcpy(str,"g9");
	      break;
     case 10: strcpy(str,"g10");
	      break;
     case 11: strcpy(str,"g11");
	      break;
     case 12: strcpy(str,"g12");
	      break;
    }

    fstream obj3(str,ios::in|ios::out|ios::app|ios::binary);
    obj3.seekg(0);
    while(1)
     {
      obj3.read((char*)&grader,sizeof(grader));
      if(obj3.eof())
       {
	break;
       }

      else
       {

	grader.display();
	cout<<endl<<endl;
	system("pause");
       }
     }
  obj3.close();
}


void main()
{
 clrscr();
 char ch='y';
 int choice1, grade;

 label:
 while(ch=='y' || ch=='Y')
 {
 clrscr();
 cout<<"------------------------------SCHOOL ADMISSION RECORDS--------------------------"<<endl;
 cout<<"1.ADD RECORD\n";
 cout<<"2.MODIFY RECORD\n";
 cout<<"3.DELETE RECORD\n";
 cout<<"4.DISPLAY SORTED RECORDS\n";
 cout<<"5.SEARCH RECORD\n";
 cout<<"6.EXIT\n\n";
 enterch:
 cin>>choice1;
 if(choice1==1)
   {
    clrscr();
    cout<<"Enter grade (9-12): ";
    entercls:
    cin>>grade;
    if(grade<9||grade>12)
     {
      cout<<"Enter grade 9, 10, 11 or 12:\t";
      goto entercls;
     }
    else
     {
      admission(grade);
     }
   }

  else if(choice1==2)
   {
    clrscr();
    cout<<"Enter grade (9-12): ";
    enterg:
    cin>>grade;
    if(grade<9||grade>12)
     {
      cout<<"Enter grade 9, 10, 11 or 12:\t";
      goto enterg;
     }
    else
     {
      modify(grade);
     }
   }
  else if(choice1==3)
   {
    clrscr();
    cout<<"Enter grade (9-12): ";
    entergrade:
    cin>>grade;
    if(grade<9||grade>12)
     {
      cout<<"Enter grade 9, 10, 11 or 12:\t";
      goto entergrade;
     }
    else
     {
      delete1(grade);
     }
   }
  else if(choice1==4)
   {
    clrscr();
    cout<<"Enter grade (9-12): ";
    entergr:
    cin>>grade;
    if(grade<9||grade>12)
     {
      cout<<"Enter grade 9, 10, 11 or 12:\t";
      goto entergr;
     }
    else
     {
      disp(grade);
     }
   }
  else if(choice1==5)
   {
    clrscr();
    enterg1:
    cout<<"Enter grade (9-12): ";
    cin>>grade;
    if(grade<9||grade>12)
     {
      cout<<"Enter grade 9, 10, 11 or 12:\t";
      goto enterg1;
     }
    search(grade);
   }
 else if(choice1==6)
  {
   exit(0);
  }
 else
  {
   cout<<"\nEnter choice 1 to 6: ";
   goto enterch;
  }
  cout<<"\n\nDo you want to go to the main menu? (y/n): ";
  option:
  cin>>ch;
  ch=tolower(ch);
  if(ch=='y'||ch=='n')
   {
   }
  else
   {
    cout<<"Enter a valid choice:\t";
    goto option;
   }
 }
 getche();
}





