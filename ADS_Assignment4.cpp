
#include<iostream>
#include<queue>
using namespace std;
class node
{
	string destination,source1;
	node *next;
	int id1;

public:
	node()
	{
		next=NULL;
	}
	friend class headnode;
	friend class graph;
};
class headnode
{
	string source;
	
	headnode *vnext;
	node *hnext;
	int id;
public:
	headnode()
	{
		vnext=NULL;
		hnext=NULL;
	}
	friend class graph;
};
class graph
{
	headnode *head;
	int x;

public:
	graph()
	{
		cout<<"Enter the no of sources : ";
		cin>>x;
		head=new headnode;
		headnode *p=head;
		for(int i=1;i<x;i++)
		{
			p->vnext=new headnode;
			p=p->vnext;
		}
		
	}
	void create_sources();
	void create_destinations();
	node* info();
	void show();
	void Delete();
	void add_source();
	void add_destination();
	void BFS_traversal();
	int count();
	void outdegree();
	void indegree();
};
void graph::create_sources()
{
	headnode *p=head;
	for(int i=0;i<x;i++)
	{
		cout<<"Enter the name of source "<<i+1<<" :";
		cin>>p->source;
		p->id=i;
		p=p->vnext;
	}
}
node* graph::info()
{
	node *p=new node;
	cout<<"\nEnter the source :";
	cin>>p->source1;
	cout<<"\nEnter the destination :";
	cin>>p->destination;
	return p;
}
void graph::create_destinations()
{
	int flag=0;
	char ch='y';

	cout<<"\nNow,Enter the information of Destination :\n";

	while(ch=='y')
	{
		int indicate=0;
		int num_head=count();
		node *temp=info();
		headnode *m=head;
		while(m!=NULL)
		{
			if (m->source==temp->destination)
			{
				temp->id1=m->id;
				indicate=1;
				break;
			}
			m=m->vnext;
		}
		if(indicate==0)
		{
			temp->id1=num_head;
		}
		m=head;
		flag=0;
		while(flag==0)
		{
			if(m->source == temp->source1)
			{
				if(m->hnext == NULL)
				{
					m->hnext=temp;
					flag=1;
				}
				else
				{
					node *p=m->hnext;
					while(p->next!=NULL)
					{
						p=p->next;
					}
					p->next=temp;
					flag=1;
				}
			}
			else
			{
				m=m->vnext;
			}
		}
		cout<<"Do you want to add more places (y/n) ? :";
		cin>>ch;
	}
}
void graph::show()
{
	headnode *p=head;
	while(p!=NULL)
	{
		cout<<"\n"<<p->source<<":";
		node *q=p->hnext;
		while(q!=NULL)
		{
			cout<<"->"<<q->destination;
			q=q->next;
		}
		p=p->vnext;
	}

}
void graph::Delete()
{
	headnode *p=head;
	string data1,data2;
	int flag1=0,flag=0;
	cout<<"\nEnter the edge to be deleted eg. a -> b (from a to b) :";
	cin>>data1>>data2;
	while(p!=NULL)
	{
		if(p->source==data1)
		{
			node *q=p->hnext;
			if(q->destination==data2)
			{
				node *m=q->next;
				p->hnext=m;
				delete q;
				flag1=1;
			}
			else
			{
					node *prev=q;
					q=q->next;
					while(q!=NULL)
					{
						if(q->destination==data2)
						{
							node *m=q->next;
							prev->next=m;
							delete q;
							flag=1;
							break;
						}
						else
						{
							prev=q;
							q=q->next;
						}
	
					}
			}
		}
		else
		{
			p=p->vnext;
		}
		if(flag==1 || flag1==1)
		{
			break;
		}
	}

}
void graph::add_source()
{
	headnode *p=head,*q;
	q=new headnode;
	cout<<"Enter the name of city :";
	cin>>q->source;
	while(p->vnext!=NULL)
	{
		p=p->vnext;
	}
	p->vnext=q;
	int num_head=count();
	q->id=num_head;
}
void graph::add_destination()
{
	headnode *p=head;
	node *ptr=new node;
	int flag=0;
	
	cout<<"Enter the source and destination :";
	cin>>ptr->source1>>ptr->destination;

		int indicate=0;
		int num_head=count();
		headnode *m=head;
		while(m!=NULL)
		{
			if (m->source==ptr->destination)
			{
				ptr->id1=m->id;
				indicate=1;
				break;
			}
			m=m->vnext;
		}
		if(indicate==0)
		{
			ptr->id1=num_head;
			flag=1;
		}
	
		if(flag==1)
		{
				m=head;
				while(m->vnext!=NULL)
				{
					m=m->vnext;
				}
				m->vnext=new headnode;
				m->vnext->source=ptr->destination;
				m->vnext->id=num_head;
		}

	while(p!=NULL)
	{
		if(p->source==ptr->source1)
		{
			if(p->hnext==NULL)
			{
				p->hnext=ptr;
				break;
			}
			else
			{
				node *m=p->hnext;
				while(m->next!=NULL)
				{
					m=m->next;
				}
				m->next=ptr;
				break;
			}
		}
		else
		{
			p=p->vnext;
		}
	}
}
int graph::count()
{
	headnode *p=head;
	int c=0;
	while(p!=NULL)
	{
		c++;
		p=p->vnext;
	}
	return c;
}
void graph::BFS_traversal()
{
	int num=count(),pos,ptr;
	int visited[num]={0};
	string start;
	queue<node*>q;

	node *new_list=new node[num];
	headnode *p=head;

	for (int i = 0; i < num; ++i)
	{
		new_list[i].destination=p->source;
		new_list[i].id1=p->id;
		new_list[i].next=p->hnext;
		p=p->vnext;
	}

	cout<<"\nEnter the starting name for traversal :";
	cin>>start;

	for (int i = 0; i < num; ++i)
	{
		if (new_list[i].destination==start)
		{
			pos=i;
			break;
		}
	}
	visited[pos]=1;
	q.push(&new_list[pos]);
	while(!q.empty())
	{
		node* temp;
		temp=q.front();
		cout<<temp->destination<<" ";
		q.pop();

		temp=temp->next;
		while(temp!=NULL)
		{
			int x=temp->id1;
			if(visited[x]==0)
			{
				q.push(&new_list[x]);
				visited[x]=1;
			}
			temp=temp->next;
		}

	}

}
void graph::outdegree()
{
	string s;
	int flag=0,count=0;
	cout<<"\nEnter the name of city :";
	cin>>s;

	headnode *p=head;
	while(p!=NULL)
	{
		if(p->source==s)
		{
			node *m=p->hnext;
			while(m!=NULL)
			{
				count++;
				m=m->next;
			}
			break;
		}
		p=p->vnext;
	}

	cout<<"Outdegree of "<<s<<" :"<<count<<"\n";
}
void graph::indegree()
{
	string s;
	int flag=0,count=0;
	cout<<"\nEnter the name of city :";
	cin>>s;

	headnode *p=head;
	while(p!=NULL)
	{
		node *m=p->hnext;
		while(m!=NULL)
		{
			if(m->destination==s)
			{
				count++;
				break;
			}
			else
			{
				m=m->next;
			}
		}
		p=p->vnext;
	}

		cout<<"Intdegree of "<<s<<" :"<<count<<"\n";

}
int main()
{
	graph g;
	char ch='y';
	int i;

	g.create_sources();
	g.create_destinations();
	
	while(ch=='y')
	{
		cout<<"\nEnter your choice :";
		cout<<"\n1:Show the lists\n2:Delete the edge between city\n3:Add source\n4:Add Destination\n5:BFS_traversal\n6:Outdegree\n7:Intdegree ";
		cin>>i;
		switch(i)
		{
			case 1: g.show();
					break;
			case 2: g.Delete();
					break;
			case 3: g.add_source();
					break;
			case 4: g.add_destination();
					break;
			case 5:g.BFS_traversal();
					break;
			case 6:g.outdegree();
					break;
			case 7:g.indegree();
					break;
			default:cout<<"INVALID OPTION\n";
		}
		cout<<"\nDo you want to continue?(y/n) :";
		cin>>ch;
	}

	return 0;
}



