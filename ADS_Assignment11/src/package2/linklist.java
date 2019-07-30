package package2;
import package1.common;

import java.util.Scanner;
class node
{
	int data;
	node next;
	node()
	{
		next=null;
	}
	
}
public class linklist extends node implements common
{
	
	node head;
	linklist()
	{
		head=null;
	}
	Scanner sc=new Scanner (System.in);
	int count()
	{
		node p=head;
		int c=0;
		while(p!=null)
		{
			c++;
			p=p.next;
		}
		return c;
			
	}
	public void insert()
	{
		node p,q;int pos;
		int value,num;
		System.out.println("Enter the position :");
		pos=sc.nextInt();
		
		System.out.println("Enter the data :");
		value=sc.nextInt();
		num=count();
		if(pos<0 || pos>num+1)
		{
			System.out.println("Invalid Position ");
			return;
		}
		if(pos==1)
		{
			q=new node();
			q.data=value;
			p=head;
			q.next=p;
			head=q;
		}
		else
		{
			p=head;
			for(int i=1;i<pos-1;i++)
			{
				p=p.next;
			}

			q=new node();
			q.data=value;
			q.next=p.next;
			p.next=q;
			
		}
		
		
	}
	public void Delete()
	{
		node p,q;int pos;
		int num;
		System.out.println("Enter the position :");
		pos=sc.nextInt();
		num=count();
		if(pos<0 || pos>num)
		{
			System.out.println("Invalid Position ");
			return;
		}
		if(pos==1)
		{
			p=head;
			head=head.next;
		}
		else
		{
			p=head;
			for(int i=1;i<pos-1;i++)
			{
				p=p.next;
			}
			q=p.next;
			p.next=q.next;
		}
	}
	public void search()
	{
		int value,pos=0;
		node p=head;
		System.out.println("Enter the value to be searched :");
		value=sc.nextInt();
		
		while(p!=null)
		{
			pos++;
			if(p.data==value)
			{
				System.out.print("value has been found at position:"+pos);
				return;
			}
			p=p.next;
		}
	}
	public void create_list()
	{
		int num,value;
		System.out.println("Enter the number of nodes to be created :");
		num=sc.nextInt();
		System.out.println("Enter the values:");
		value=sc.nextInt();
		head=new node();
		head.data=value;
		node p=head;
		for(int i=1;i<num;i++)
		{
			value=sc.nextInt();
			p.next=new node();
			p.next.data=value;
			p=p.next;
		}

	}
	public void display()
	{
		node p=head;
		while(p!=null)
		{
			System.out.print( " " + p.data +" ");
			p=p.next;
		}
	}
	public static void main(String [] args)
	{
		linklist l=new linklist();
		l.create_list();
		int num;
		char ch='y';
		Scanner sc=new Scanner (System.in);

		while (ch=='y' || ch=='Y')
		{
			System.out.println(" 1:Insert Node \n 2: Search \n 3: Delete node \n 4: Display");
			num=sc.nextInt();
			switch(num)
			{
			case 1: l.insert();
					l.display();
				break;
			case 2: l.search();
				break;
			case 3: l.Delete();
					l.display();
				break;
			case 4: l.display();
				break;
			}
			System.out.print("\nDo you want to continue?(y/n) :");
			ch=sc.next().charAt(0);
			
		}
		sc.close();
	}
}