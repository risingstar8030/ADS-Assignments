#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *left,*right;
	
		node()
		{
			left=right=NULL;
		}
		
		
};
class list
{
	public:
		node *snode;
		list *next;
		list()
		{
			next=NULL;
		}
};
class stack
{
	public:
		list *p;
		stack()
		{
			p=NULL;
		}
		void push(node *q)
		{
			if(p==NULL)
			{
				list*  m=new list;
				m->snode=q;
				p=m;
			}
			else
			{
				list *m=new list;
				m->snode=q;
				m->next=p;
				p=m;
			}
		}
		node* pop()
		{
			node *m=p->snode;
			p=p->next;
			return m;
		}
		int isempty()
		{
			if(p==NULL)
			{
				return 1;
			}
			return 0;
		}
};
class tree
{
	
	public:
		node *root;
		void create_tree();
		void create(node *current,int x);
		void delete_tree();
		void del_tree(node *current);
		void mirror_image();
		node* mirror(node *current);
		void equal_tree();
		node* eq_tree(node *current);
		void height_tree();
		int height(node *current);
		void leaf_node();
		int leaf(node *current);
		void internal_node();
		int internal(node *current);
		void inorder(node *p);
		void preorder(node *p);
		void postorder(node *p);
		void non_rec_in(node *root);
		void non_rec_pre(node *root);
		void non_rec_post(node *root);
		tree()
		{
			root=NULL;	
		}
};
void tree::create_tree()
{
	int x;
	char ch='y';
	root=new node;
	cout<<"Enter the root data :";
	cin>>root->data;
	cout<<"\n";
	while(ch=='y')
	{
		cout<<"Enter the data :";
		cin>>x;
		create(root,x);
		cout<<"Wanna continue? (y/n) :";
		cin>>ch;
		cout<<"\n";
	}
}
void tree::create(node *current,int x)
{
	int n;
	cout<<"\nEnter choice 1:Left 2:Right :";
	cin>>n;
	if(n==1)
	{
		if(current->left==NULL)
		{
			current->left=new node;
			current->left->data=x;
		}
		else
		{
			cout<<"Node is not empty";
			create(current->left,x);
		}
	}
	if(n==2)
	{
		if(current->right==NULL)
		{
			current->right=new node;
			current->right->data=x;
		}
		else
		{
			cout<<"Node is not empty";
			create(current->right,x);
		}
	}
}
void tree::delete_tree()
{
	del_tree(root);
	root=NULL;
}
void tree::del_tree(node *current)
{
	if(current==NULL)
	{
		return;
	}
	else
	{
		del_tree(current->left);
		del_tree(current->right);
		cout<<"Node deleted :"<<current->data<<"\n";
		delete current;
	}
}
void tree::mirror_image()
{
	node *newroot;
	newroot=mirror(root);
	cout<<"\nMirror Image :";
	inorder(newroot);
}
node* tree::mirror(node *current)
{
	if(current!=NULL)
	{
		node *p=new node;
		p->data=current->data;
		p->left=mirror(current->right);
		p->right=mirror(current->left);
		return p;
	}
	else
	{
		return NULL;
	}
}
void tree::equal_tree()
{
	node *newroot;
	newroot=eq_tree(root);
	cout<<"\nEqual Tree :";
	inorder(newroot);
}
node* tree::eq_tree(node *current)
{
	if(current!=NULL)
	{
		node *p=new node;
		p->data=current->data;
		p->left=eq_tree(current->left);
		p->right=eq_tree(current->right);
		return p;
	}
	else
	{
		return NULL;
	}
}
void tree::height_tree()
{
	int x=height(root);
	cout<<"\nHeight of tree :"<<x;
}
int tree::height(node *current)
{
	if(current==NULL)
	{
		return 0;
	}
	int h1=height(current->left);
	int h2=height(current->right);
	if(h1>=h2)
	{
		return (1+h1);
	}
	else
	{
		return (1+h2);
	}
}
void tree::leaf_node()
{
	int x=leaf(root);
	cout<<"\nNo of leaf Nodes :"<<x;
}
int tree::leaf(node *current)
{
	int i;
	if(current==NULL)
	{
		return 0;
	}
	if(current->left==NULL && current->right==NULL)
	{
		return 1;
	}
	i=leaf(current->left)+leaf(current->right);
	return i;
}
void tree::internal_node()
{
	int x=internal(root);
	cout<<"\nNo of internal nodes :"<<x;
}
int tree::internal(node *current)
{
	int i;
	if(current==NULL)
	{
		return 0;
	}
	if(current->left!=NULL  || current->right!=NULL)
	{
		return 1;
	}
	i=internal(current->left)+internal(current->right);
	return i;
}
void tree::inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}
void tree::postorder(node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->data<<" ";
	}	
}
void tree::preorder(node *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}
void tree::non_rec_in(node *root)
{
	stack s;
	node *p=root;
	while(p!=NULL || !s.isempty())
	{
		if(p!=NULL)
		{
			s.push(p);
			p=p->left;
		}
		else
		{
			p=s.pop();
			cout<<p->data<<" ";
			p=p->right;
		}
	}
}
void tree::non_rec_pre(node *root)
{
	stack s;
	node *p=root;
	while(p!=NULL || !s.isempty())
	{
		if(p!=NULL)
		{
			cout<<p->data<<" ";
			s.push(p);
			p=p->left;
		}
		else
		{
			p=s.pop();
			p=p->right;
		}
	}
}
void tree::non_rec_post(node * root)
{
	stack s1,s2;

	node *p=root;

	if(root==NULL)
	{
		return;
	}
	s1.push(root);
	while(!s1.isempty())
	{
		p=s1.pop();

		s2.push(p);

		if(p->left!=NULL)
		{
			s1.push(p->left);
		}
		if(p->right!=NULL)
		{
			s1.push(p->right);
		}
	}
	while(!s2.isempty())
	{
		node *m=s2.pop();
		cout<<m->data<<" ";
	}
}
int main()
{
	tree t;

	t.create_tree();
	cout<<"Postorder :";
	t.non_rec_post(t.root);
	/*t.height_tree();
	t.internal_node();
	t.leaf_node();
	t.mirror_image();
	t.equal_tree();
	cout<<"\n";
	t.delete_tree();*/
	return 0;
	
}
