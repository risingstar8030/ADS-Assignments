#include<iostream>
using namespace std;
class node
{
	public:
	string str1,str2;
	node *left,*right;
	
	node()
	{
		left=right=NULL;
	}
};
class tree
{
	public:
		node *root;
		void insert(string s1,string s2);
		void inorder(node *p);
		void update();
		node* search(node* p,string s1,int *q);
		void ascendind_display();
		void descending_display(node *p);
		void operator =(tree &t);
		node* equ_tree(node *p);
		node* Delete(node* t,string s);
		node* min(node *p);
		tree()
		{
			root=NULL;
		}
};
void tree::insert(string s1,string s2)
{
	node *p,*ptr,*m;
	static int n=1;
	if(n==1)
	{
		root=new node;
		root->str1=s1;
		root->str2=s2;
		n++;
	}
	else
	{
		p=root;

		while(p!=NULL)
		{
			ptr=p;
			if(p->str1 > s1)
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}
		}
		if(ptr->str1 > s1)
		{
			m=new node;
			m->str1=s1;
			m->str2=s2;
			ptr->left=m;
		}
		else
		{
			m=new node;
			m->str1=s1;
			m->str2=s2;
			ptr->right=m;
		}
	}
}
void tree::inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->str1<<"\t\t"<<p->str2<<"\n";
		inorder(p->right);
	}
}
void tree::update()
{
	string str1,str;
	int count=0,*t;
	t=&count;
	cout<<"Enter the word to be searched for :";
	cin>>str1;
	node *ptr=search(root,str1,&count);
	if(ptr!=NULL)
	{
		cout<<"Word has been found :\n";
		cout<<"No of comparisions performed :"<<*t<<"\n";
		cout<<"Enter the new meaning of word :";
		cin>>str;
		ptr->str2=str;
		cout<<"Meaning of word has been updated :\n";
		inorder(root);
	}
	else
	{
		cout<<"Word Not found :";
	}
}
node* tree::search(node *p,string s1,int *q)
{
	if(p!=NULL)
	{
		if(s1==p->str1)
		{+
			return p;
		}
		else if(s1 > p->str1)
		{
			*q=*q+1;
			return(search(p->right,s1,q));
		}
		else if(s1 < p->str1)
		{
			*q=*q+1;
			return(	search(p->left,s1,q));
		}
	}
	else
	{
		return NULL;
	}
}
void tree::ascendind_display()
{
	inorder(root);
}
void tree::descending_display(node *p)
{
	if(p!=NULL)
	{
		descending_display(p->right);
		cout<<p->str1<<"\t\t"<<p->str2<<"\n";
		descending_display(p->left);	
	}
}
void tree::operator =(tree &t)
{
	root=equ_tree(t.root);
	cout<<endl;
	inorder(root);
}
node* tree::equ_tree(node *p)
{
	if(p!=NULL)
	{
		node *q=new node;
		q->str1=p->str1;
		q->str2=p->str2;
		q->left=equ_tree(p->left);
		q->right=equ_tree(p->right);
		return q;
	}
	else
	{
		return NULL;
	}
}
node* tree::Delete(node *t,string s)
{
	if(t==NULL)
	{
		cout<<"Word Not Found :\n";
		return t;
	}
	else if(s < t->str1)
	{
		t->left=Delete(t->left,s);
		return t;
	}
	else if(s > t->str1)
	{
		t->right=Delete(t->right,s);
		return t;
	}
	else
	{
		if(t->left==NULL && t->right==NULL)
		{
			node *p=t;
			delete p;
			return NULL;
		}
		else if(t->left==NULL)
		{
			node *p=t;
			t=t->right;
			delete p;
			return t;	
		}
		else if(t->right==NULL)
		{
			node *p=t;
			t=t->left;
			delete p;
			return t;
		}
		node *p=min(t->right);
		t->str1=p->str1;
		t->str2=p->str2;
		t->right=Delete(t->right,p->str1);
		return t;	
	}
}
node* tree::min(node *p)
{
	while(p->left!=NULL)
	{
		p=p->left;
	}
	return p;
}
int main()
{
	string s1,s2,s3;
	int i;
	char ch='y';
	tree t,t1;
	while(ch=='y')
	{
		cout<<"\nEnter the word :";
		cin>>s1;
		cout<<"Enter the meaning :";
		cin>>s2;
		t.insert(s1,s2);
		cout<<"Wanna Continue? (y/n) :";
		cin>>ch;
	}
	cout<<endl;
	t.inorder(t.root);
	ch='y';
	while(ch=='y')
	{
		cout<<"\n1: Update meaning of word\n2: Ascending order display\n3: Descending order display\n4: Delete a word\n5: Create equal tree\n6: Display tree :";
		cin>>i;	
		switch(i)
		{
			case 1: t.update();
					break;
			case 2: t.ascendind_display();
					break;
			case 3: t.descending_display(t.root);
					break;
			case 4: cout<<"Enter the word to be deleted :";
					cin>>s3;
					t.Delete(t.root,s3);
					break;
			case 5: t1=t;
					break;
			case 6: t.inorder(t.root);
					break;
			default: cout<<"Wrong option:\n";
		}
		cout<<"Wanna Continue? (y/n) :";
		cin>>ch;
	}
}
