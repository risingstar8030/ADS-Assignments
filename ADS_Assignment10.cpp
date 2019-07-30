#include<iostream>
#include<fstream>
using namespace std;
class student 
{
	int roll_no;
	string name,address,div;
public:
	void getdata();
	void display();
	void show_info();
	void delete_data();
};
void student::getdata()
{
	fstream file;
	file.open("Student_Data.txt",ios::out|ios::app);

	cout<<"\nEnter the name of student :";
	cin>>name;
	cout<<"Enter the roll no student :";
	cin>>roll_no;
	cout<<"Enter the division of student :";
	cin>>div;
	cout<<"Enter the address of student :";
	cin>>address;

	file<<name<<"\t"<<roll_no<<"\t"<<div<<"\t"<<address<<"\n";
	file.close();
}
void student::display()
{
	fstream file;
	file.open("Student_Data.txt",ios::in);

	if(!file)
	{
		cout<<"Error in file opening\n";
		return;
	}
	else
	{
		while(file)
		{
			file>>name>>roll_no>>div>>address;
			cout<<"\nName:"<<name<<"\nRoll No:"<<roll_no<<"\nDivision:"<<div<<"\nAddress:"<<address<<"\n";

		}
	}
	file.close();
}
void student::show_info()
{
	string s;
	fstream file;
	file.open("Student_Data.txt",ios::in);

	cout<<"\nEnter the name of student to be searched:";
	cin>>s;

	if(!file)
	{
		cout<<"Error in file opening\n";
		return;
	}
	else
	{
		while(file)
		{
			file>>name>>roll_no>>div>>address;
			if(s==name)
			{
				break;
			}
		}
		if(s==name)
		{
			cout<<"Name:"<<name<<"\nRoll No:"<<roll_no<<"\nDivision:"<<div<<"\nAddress:"<<address;
		}
		else
		{
			cout<<"Information of this student is not available\n";
		}
	}
}
void student::delete_data()
{
	string s;

	cout<<"Enter the name of student whose data to be deleted :";
	cin>>s;

	fstream file;
	fstream file1;
	file.open("Student_Data.txt",ios::in);
	file1.open("xyz.txt",ios::out | ios::app);
	if(!file)
	{
		cout<<"Unable to open file\n";
	}
	else
	{
		while(!file.eof())
		{
			file>>name>>roll_no>>div>>address;
			if(s!=name)
			{
				file1<<name<<"\t"<<roll_no<<"\t"<<div<<"\t"<<address<<"\n";

			}
		}

	}
	file1.close();
	file.close();
	remove("Student_Data.txt");
	rename("xyz.txt","Student_Data.txt");

}

int main()
{
	student s;
	int num;
	char ch='y';
	cout<<"Enter the no of students :";
	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		s.getdata();
	}

	while(ch=='y' || ch=='Y')
	{
		cout<<"1:Display file\n2:Student_Data\n3:Add Student\n4:Delete data\n";
		cin>>num;
		switch(num)
		{
			case 1:s.display();
					break;
			case 2:s.show_info();
					break;
			case 3: s.getdata();
					break;
			case 4:s.delete_data();
					break;
			default:cout<<"Invalid Input\n";
		}
		cout<<"Do you want to continue(y/n) ? :";
		cin>>ch;
	}
}
