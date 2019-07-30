#include<iostream>
using namespace std;
class node
{
	int data;
	node *left,*right;
	int ht;
	node()
	{
		left=right=NULL;
	}
	friend class tree;
};
class tree
{
	node *root;
public:
	tree()
	{
		root=NULL;
	}
	void insert();
	node* insert_element(node* T,int x);
	node* RR(node* T);
	node* LL(node* T);
	node* RL(node* T);
	node* LR(node* T);
	node* rotate_left(node* x);
	node* rotate_right(node* x);
	int height(node* T);
	int balance_factor(node* T);
	void inorder(node* T);
	void descending(node* T);
	void ascending_order();
	void descending_order();
	void search_element();
	node* search(node *p,int x,int *q);
	
};
void tree::insert()
{
	int num;
	cout<<"Enter the data :";
	cin>>num;
	root=insert_element(root,num);
}
node* tree::insert_element(node* T,int x)
{
	if(T==NULL)
	{
		T=new node;
		T->data=x;
	}
	else
	{
		if(x > T->data)
		{
			T->right=insert_element(T->right,x);
			if(balance_factor(T)==-2)
			{
				if(x > T->right->data)
				{
					T=RR(T);
				}
				else
				{
					T=RL(T);
				}
			}
		}
		else
		{
			T->left=insert_element(T->left,x);
			if(balance_factor(T)==2)
			{
				if(x < T->left->data)
				{
					T=LL(T);
				}
				else
				{
					T=LR(T);
				}
			}
		}
	}
	T->ht=height(T);
	return T;
}
int tree::height(node* T)
{
	int lh,rh;

	if(T==NULL)
	{
		return 0;
	}
	if(T->left==NULL)
	{
		lh=0;
	}
	else
	{
		lh=1+T->left->ht;
	}
	if (T->right==NULL)
	{
		rh=0;
	}
	else
	{
		rh=1+T->right->ht;
	}
	if(lh > rh)
	{
		return lh;
	}
	return rh;
}
int tree::balance_factor(node* T)
{
	int lh,rh;

	if(T==NULL)
	{
		return 0;
	}
	if(T->left==NULL)
	{
		lh=-1;
	}
	else
	{
		lh=T->left->ht;
	}
	if (T->right==NULL)
	{
		rh=-1;
	}
	else
	{
		rh=T->right->ht;
	}
	
	return(lh-rh);
}
node* tree::rotate_right(node* x)
{
	node* y;

	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);

	return y;
}
node* tree::rotate_left (node* x)
{
	node* y;

	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);

	return y;
}
node* tree::RR(node* T)
{
	T=rotate_left(T);
	return T;
}
node* tree::LL(node* T)
{
	T=rotate_right(T);
	return T;
}
node* tree::LR(node* T)
{
	T->left=rotate_left(T->left);
	T=rotate_right(T);
	return T;
}
node* tree::RL(node* T)
{
	T->right=rotate_right(T->right);
	T=rotate_left(T);
	return T;
}
void tree::inorder(node* T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		cout<<T->data<<" ";
		inorder(T->right);
	}
}
void tree::ascending_order()
{
	inorder(root);
}
void tree::descending_order()
{
	descending(root);
}
void tree::descending(node* T)
{
	if(T!=NULL)
	{
		descending(T->right);
		cout<<T->data<<" ";
		descending(T->left);
	}
}
void tree::search_element()
{
	int count=0,x,*t;
	node *ptr;
	t=&count;
	cout<<"\nEnter the no to be searched :";
	cin>>x;

	ptr=search(root,x,&count);
	if(ptr!=NULL)
	{
		cout<<"Number has been found\n";
		cout<<"No of comparisions performed :"<<*t<<"\n";
	}
	else
	{
		cout<<"\nNumber not found";
	}

}
node* tree::search(node *p,int x,int *q)
{
	if(p!=NULL)
	{
		if(x==p->data)
		{
			return p;
		}
		else if(x > p->data)
		{
			*q=*q+1;
			return(search(p->right,x,q));
		}
		else if(x < p->data)
		{
			*q=*q+1;
			return(	search(p->left,x,q));
		}
	}
	else
	{
		return NULL;
	}
}
int main()
{
	char ch='y';
	tree t;

	while(ch=='y' || ch=='Y')
	{
		t.insert();
		cout<<"Do you want to add more ? (y/n) :";
		cin>>ch;
	}
	cout<<"\nAscending order :\n";
	t.ascending_order();
	cout<<"\nDescending order :\n";
	t.descending_order();
	t.search_element();

	return 0;
}
