/*
 * c.cpp
 *
 *  Created on: 19-Mar-2018
 *      Author: suraj
 *
*/

#include<iostream>
using namespace std;
#define max 10
class node
{
	string word,mean;

public:
	node()
	{
	}
	friend class hash;
};
class hash
{
	string word,mean;
	node *head;
	int link[max];
	int occupied[max];
public:
	hash()
	{
		head=NULL;
		for(int i=0;i<max;i++)
		{
			link[i]=-1;
			occupied[i]=0;
		}
	}
	void without_replacement();
	void with_replacement();
	int  search();
	int hashing(string s);
	void display();
	void Delete();
	void search_word();
};
void hash::without_replacement()
{
	head=new node[max];
	node *p=head;
	char ch='y';
	while(ch=='y' ||  ch=='Y')
	{
		cout<<"Enter the word :";
		cin>>word;
		cout<<"Enter the meaning :";
		cin>>mean;

		int j=hashing(word);
		int val=j;
		int i=0;
		while(occupied[j]==1 && i<max)
		{
			if(val==hashing(p[j].word))
			{
				break;
			}
			i++;
			j=(j+1)%max;
		}
		if(i==max)
		{
			cout<<"Table is full \n";
			return;
		}
		while(link[j]!=-1)
		{
			j=link[j];
		}
		int prev=j;
		while(occupied[j]==1 && i<max)
		{
			j=(j+1)%max;
			i++;
		}
		p[j].word=word;
		p[j].mean=mean;
		occupied[j]=1;
		if(prev!=j)
		{
			link[prev]=j;
		}

		cout<<"Do you want to add another word (y/n)? :";
		cin>>ch;
	}

}
int hash::search()
{
	cout<<"Enter the word to be searched :";
	cin>>word;

	int j=hashing(word);
	int val=j,i=0;
	node *p=head;

	while(i<max && occupied[j]==1 && val!=hashing(p[j].word) )
	{
		i++;
		j=(j+1)%max;
	}
	if(occupied[j]==0 || i==max)
	{
		return -1;
	}
	while(j!=-1)
	{
		if(p[j].word==word)
		{
			return j;
		}
		j=link[j];
	}
	return -1;
}
int hash::hashing(string s)
{
	int l=s.size();
	int val,j;
	for(int i=0;i<l;i++)
		{
			val=val+(int)s[i];
		}
	j=val%max;
	return j;
}
void hash::display()
{
	node *p=head;
	for(int i=0;i<max;i++)
	{
		if(occupied[i]==0)
		{
			cout<<"\t"<<"\t"<<link[i]<<"\n";
		}
		else
		{
			cout<<p[i].word<<"\t"<<p[i].mean<<"\t"<<link[i]<<"\n";
		}
	}
}
void hash::search_word()
{
	node *p=head;
	int pos=search();

	if(pos==-1)
	{
		cout<<"Word Not Found :\n";
		return;
	}

	cout<<"Word has been found at position :"<<pos+1<<"\n";
	cout<<p[pos].word<<"\t"<<p[pos].mean<<"\n";
}
void hash::Delete()
{
	node *p=head;
	int pos=search();
	if(pos==-1)
	{
		cout<<"Word Not Found :\n";
		return;
	}
	int next=link[pos];

	p[pos].word=p[next].word;
	p[pos].mean=p[next].mean;
	link[pos]=link[next];

	 p[next].word="NULL";
	 p[next].mean="NULL";
	occupied[next]=0;
	link[next]=-1;
}
void hash::with_replacement()
{
	head=new node[max];
	node *p=head;
	char ch='y';
	while(ch=='y' || ch=='Y')
	{
		cout<<"Enter the word :";
		cin>>word;
		cout<<"Enter the meaning :";
		cin>>mean;

		int j=hashing(word);
		int val=j;

		if(occupied[j]==0)
		{
			p[j].word=word;
			p[j].mean=mean;
			occupied[j]=1;
		}
		else if(val!=hashing(p[j].word))
		{
			int i=0,pos=j;
			while(i<max && occupied[j]==1)
			{
				i++;
				j=(j+1)%max;
			}
			if(i==max)
			{
				cout<<"Table is full \n";
				return ;
			}
			i=hashing(p[val].word);
			while(link[i]!=val)
			{
				i=link[i];
			}
			link[i]=link[val];
			while(link[i]!=-1)
			{
				i=link[i];
			}
			link[i]=j;
			p[j].word=p[pos].word;
			p[j].mean=p[pos].mean;
			occupied[j]=1;
			link[j]=-1;

			p[pos].word=word;
			p[pos].mean=mean;
			occupied[pos]=1;
			link[pos]=-1;

		}
		else
		{
					int i=0,pos=j;
					while(i<max && occupied[j]==1)
					{
						i++;
						j=(j+1)%max;
					}
					if(i==max)
					{
						cout<<"Table is full \n";
						return ;
					}
					p[j].word=word;
					p[j].mean=mean;
					occupied[j]=1;
					link[j]=-1;
					while(link[pos]!=-1)
					{
						pos=link[pos];
					}
					link[pos]=j	;

		}
		cout<<"Do you want to add another word (y/n)? :";
		cin>>ch;
	}
}
int main()
{

	hash h;
	h.with_replacement();
	h.display();
	h.search_word();
	char ch='y';



	return 0;

}





