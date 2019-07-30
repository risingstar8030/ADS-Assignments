#include<iostream>
using namespace std;
class heap
{
	int *arr1,*arr2,num;
public:
	void max_heap(int item,int n);
	void min_heap(int item,int n);
	void display();
	void getdata();

	heap()
	{
		cout<<"Enter the no of students :";
		cin>>num;
		arr2=new int [num];
		arr1=new int [num];
	}
};
void heap::max_heap(int item,int n)
{
	int ptr=n;
	while(ptr>0)
	{
		int par=(ptr-1)/2;

		if(item <= arr1[par])
		{
			arr1[ptr]=item;
			return;
		}
		arr1[ptr]=arr1[par];
		ptr=par;
	}
	arr1[ptr]=item;
	return;
}
void heap::min_heap(int item,int n)
{
	int ptr=n;
	while(ptr>0)
	{
		int par=(ptr-1)/2;

		if(item >= arr2[par])
		{
			arr2[ptr]=item;
			return;
		}
		arr2[ptr]=arr2[par];
		ptr=par;
	}
	arr2[ptr]=item;
	return;
}
void heap::display()
{
	for (int i = 0; i < num; i++)
	{
		cout<<arr1[i]<<" ";
	}
	cout<<"\n";
	for (int i = 0; i < num; i++)
	{
		cout<<arr2[i]<<" ";
	}
}
void heap::getdata()
{
	int data;

	cout<<"Enter the marks of students :";

	for (int i = 0; i < num; i++)
	{
		cin>>data;
		max_heap(data,i);
		min_heap(data,i);
	}
	display();
}
int main()
{
	heap h;
	
	h.getdata();


	return 0;

}