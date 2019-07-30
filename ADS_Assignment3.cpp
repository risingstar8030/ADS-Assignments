

#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node *left,*right;
	int lflag,rflag;
	node()
	{
		left=right=NULL;
	}
};
class tree
{
public:
	node *root,*dummy;

	void insert(node *root,node *n);
	void create();
	node* in_successor(node *p);
	node* in_predecessor(node *p);
	void inorder();
	void preorder();
	node* pre_successor(node *p);
	void Delete();
	node* delete_leaf(node *root,node *par,node *ptr);
	node* delete_child_one(node *root,node *par,node *ptr);
	node* delete_child_two(node *root,node *par,node *ptr);
	tree()
	{
		root=NULL;
	}
};
void tree::create()
{
	char ch='y';
	
	dummy=new node;
	dummy->lflag=dummy->rflag=0;
	dummy->left=root;

	root=new node;
	cout<<"Enter the data of root :";
	cin>>root->data;
	root->left=NULL;
	root->right=NULL;
	root->lflag=1;
	root->rflag=1;

	dummy->right=dummy;

	while(ch=='y')
	{
		node *n=new node;
		cout<<"\nEnter the data :";
		cin>>n->data;
		insert(root,n);
		cout<<"Wanna Continue ? (y/n) :";
		cin>>ch;
	}

	node *q=root;
	while(q->left!=NULL)
	{
		q=q->left;
	}
	q->left=dummy;

	q=root;
	while(q->right!=NULL)
	{
		q=q->right;
	}
	q->right=dummy;

}
void tree::insert(node *root,node *n)
{


		if(root->data > n->data)
		{
			if(root->lflag==0)
			{
				insert(root->left,n);
			}
			else
			{
				n->left=root->left;
				n->lflag=1;
				n->right=root;
				n->rflag=1;
				root->left=n;
				root->lflag=0;
			}
		}
		if(root->data < n->data)
		{
			if(root->rflag==0)
			{
				insert(root->right,n);
			}
			else
			{
				n->left=root;
				n->lflag=1;
				n->right=root->right;
				n->rflag=1;
				root->right=n;
				root->rflag=0;
			}
		}
}

void tree::inorder()
{
	node *p=root;
	while(p->lflag==0)
	{
		p=p->left;
	}
	while(p!=dummy)
	{
		cout<<p->data<<" ";
		p=in_successor(p);
	}
}
node* tree::in_successor(node *p)
{
	if(p->rflag==1)
	{
		return p->right;
	}
	else
	{
		node* temp=p->right;
		while(temp->lflag==0)
		{
			temp=temp->left;
		}
		return temp;
	}
}
void tree::preorder()
{
	node *p=root;
	while(p!=dummy)
	{
		cout<<p->data<<" ";
		p=pre_successor(p);
	}
}
node* tree::pre_successor(node *p)
{
	if(p->lflag==0)
	{
		return p->left;
	}
	else
	{
		while(p->rflag==1)
		{
			p=p->right;
		}
		return p->right;
	}
}
void tree::Delete()
{
	int x,flag=0;
	cout<<"Enter the value to be deleted :";
	cin>>x;

	node *ptr,*par=NULL;
	ptr=root;
	while(ptr!=NULL)
	{
		if (ptr->data==x)
		{
			flag=1;
			break;
		}
		par=ptr;
		 if(ptr->data > x)
		{
			if(ptr->lflag==0)
			{
				ptr=ptr->left;
			}
			else
			{
				break;
			}
		}
		else 
		{
			if(ptr->rflag==0)
			{
				ptr=ptr->right;
			}
			else
			{
				break;
			}
		}
	}

	if(flag==0)
	{
		cout<<"value not found  :\n";
		return;
	}

	cout<<"value has been found and deleted successfully :\n";
	if(ptr->lflag==1 && ptr->rflag==1)
	{
		root=delete_leaf(root,par,ptr);
	}

	else if(ptr->lflag==0)
	{
		root=delete_child_one(root,par,ptr);
	}

	else if(ptr->rflag==0)
	{
		root=delete_child_one(root,par,ptr);
	}

	else
	{
		root=delete_child_two(root,par,ptr);
	}


}
node* tree::delete_leaf(node *root,node *par,node *ptr)
{
	if(par==NULL)
	{
		root=NULL;
		return NULL;
	}
	else if(ptr==par->left)
	{
		par->lflag=1;
		par->left=ptr->left;
		delete ptr;
		return root;
	}
	else if(ptr==par->right)
	{
		par->rflag=1;
		par->right=ptr->right;
		delete ptr;
		return root;
	}
}
node* tree::delete_child_one(node *root,node *par,node *ptr)
{
	node *m;

	if(ptr->left !=NULL)
	{
		m=ptr->left;
	}
	else
	{
		m=ptr->right;
	}
	if(par==NULL)
	{
		par=m;
	}
	else if(ptr==par->left)
	{
		par->left=m;
	}
	else if(ptr==par->right)
	{
		par->right=m;
	}

	node *s=in_successor(ptr);
	node *p=in_predecessor(ptr);

	if(ptr->lflag==0)
	{
		p->right=s;
	}
	else
	{
		if(ptr->rflag==0)
		{
			s->left=p;
		}
	}

	delete ptr;
	return root;

}
node* tree::delete_child_two(node *root,node *par,node *ptr)
{
	node *parsucc,*succ;

	parsucc=ptr;
	succ=ptr->right;

	 while (succ->left != NULL)
    {
        parsucc = succ;
        succ = succ -> left;
    }

    ptr->data=succ->data;

    if(succ->lflag==1 && succ->rflag==1)
    {
    	root=delete_leaf(root,parsucc,succ);
    }
    else
    {
    	root=delete_child_one(root,parsucc,succ);
    }
    return root;
}
node* tree::in_predecessor(node *p)
{
	if(p->lflag==1)
	{
		return p->left;
	}
	else
	{
		node* temp=p->left;
		while(temp->rflag==0)
		{
			temp=temp->right;
		}
		return temp;
	}
}
int main()
{
	tree t;
	int x;
	char ch='y';
	
	t.create();
	
	while(ch=='y')
	{
		cout<<"Enter the choice :\n1:INORDER TRAVERSAL\n2:PREORDER TRAVERSAL\n3:Delete a node\n";
		cin>>x;
		switch(x)
		{
			case 1: cout<<"\nINORDER TRAVERSAL : ";
					t.inorder();
					cout<<"\n";
					break;
			case 2: cout<<"\nPREORDER TRAVERSAL : ";
					t.preorder();
					cout<<"\n";
					break;
			case 3: t.Delete();
					break;
			default: cout<<"Incorrect option\n";
		}
		cout<<"Wanna Continue? (y/n) :";
		cin>>ch;
	}
	return 0;

}
