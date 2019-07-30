//Assignment No 5 Prim's and Kruskal's

#include<iostream>
#include<vector>
using namespace std;
#define max 10
#define infinite 999
class graph
{
	public:
	int arr[max][max],arr1[max][max],arr2[max][max];
	int num,visited[max],distance[max],from[max],cost=0;

	void getmat();
	void showmat();
	void prims();
	void show_mst();
};
class kruskal:public graph
{
public:
	void calculate();
};
void graph::getmat()
{
	cout<<"Enter the no of vertices :";
	cin>>num;

	cout<<"Enter the matrix values :";

	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			cin>>arr[i][j];
		}
	}
}
void graph::showmat()
{
	for(int i=0;i<num;i++)
		{
			for(int j=0;j<num;j++)
			{
				cout<<arr[i][j]<<"  ";
			}
			cout<<"\n";
		}
}
void graph::prims()
{
	for(int i=0;i<num;i++)
			{
				for(int j=0;j<num;j++)
				{
					if (arr[i][j]==0)
					{
						arr1[i][j]=infinite;
						arr2[i][j]=0;
					}
					else
					{
						arr1[i][j]=arr[i][j];
						arr2[i][j]=0;
					}
				}

			}
	visited[0]=1;
	distance[0]=0;
	for(int i=1;i<num;i++)
	{
		distance[i]=arr1[0][i];
		from[i]=0;
		visited[i]=0;
	}
	int edges=num-1;
	int min=infinite,u,v;
	while(edges >0)
	{
		for(int i=1;i<num;i++)
		{
			if(visited[i]==0 && distance[i]<min)
			{
				v=i;
				min=distance[i];
			}
		}
		u=from[v];
		visited[v]=1;
		arr2[u][v]=distance[v];
		arr2[v][u]=distance[v];
		edges--;

		for(int i=1;i<num;i++)
		{
			if(visited[i]==0 && arr1[i][v]<distance[i])
			{
				distance[i]=arr1[i][v];
				from[i]=v;
			}
		}
		cost=cost+min;
		min=infinite;
	}
}
void graph::show_mst()
{
	cout<<"\nMinimum cost :"<<cost<<"\n";

	cout<<"\nMinimum Spanning tree :\n";

	for(int i=0;i<num;i++)
			{
				for(int j=0;j<num;j++)
				{
					cout<<arr2[i][j]<<"  ";
				}
				cout<<"\n";
			}
}
void kruskal::calculate()
{
	int count=0;

	for(int i=0;i<num;i++)
	{
		visited[i]=i;

		for(int j=0;j<num;j++)
		{
			arr2[i][j]=0;

			if(arr[i][j]!=0)
			{
				count++;
			}
		}
	}

	vector < vector<int>  > sparse(count, vector<int>(3));
	int k=0,temp,temp1,temp2,count1=0;
	for(int i=0;i<count;i++)
	{
		sparse[k][2]=0;
	}

	static int m=0;
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			if (m==0 && arr[i][j]!=0)
			{
				sparse[k][0]=i;
				sparse[k][1]=j;
				sparse[k][2]=arr[i][j];
				k++;
				m++;count1++;
			}
			else if(arr[i][j]!=0)
			{
				int m=0,flag=0;
				while( sparse[m][2]!=0)
				{
					if(sparse[m][2]==arr[i][j] && sparse[m][0]==j && sparse[m][1]==i)
					{
						flag=1;
						break;
					}
					else
					{
						m++;
					}
				}
				if(flag==0)
				{
					sparse[k][0]=i;
					sparse[k][1]=j;
					sparse[k][2]=arr[i][j];
					k++;count1++;
				}

			}
		}
	}
	for(int i=0;i<count1-1;i++)
	{
		for(int j=0;j<count1-1-i;j++)
		{
			if(sparse[j][2]>sparse[j+1][2])
			{
				temp=sparse[j][2];
				sparse[j][2]=sparse[j+1][2];
				sparse[j+1][2]=temp;

				temp1=sparse[j][0];
				sparse[j][0]=sparse[j+1][0];
				sparse[j+1][0]=temp1;

				temp2=sparse[j][1];
				sparse[j][1]=sparse[j+1][1];
				sparse[j+1][1]=temp2;
			}
		}
	}

	for(int i=0;i<count1;i++)
				{
					for(int j=0;j<3;j++)
					{
						cout<<sparse[i][j]<<"  ";
					}
					cout<<"\n";
				}



	for(int i=0;i<count1;i++)
	{
		if(visited[ sparse[i][0] ] != visited[ sparse[i][1] ])
		{
			arr2[sparse[i][0]][sparse[i][1]]=sparse[i][2];
			arr2[sparse[i][1]][sparse[i][0]]=sparse[i][2];
			cost=cost+sparse[i][2];
			for(int j=0;j<num;j++)
			{
				if(visited[j]==visited[sparse[i][1]])
				{
					visited[j]=visited[sparse[i][0]];
				}
			}
		}
	}

}
int main()
{
	graph g;
	kruskal k;

	cout<<"For Prims's Algorithm :\n";
	g.getmat();
	g.showmat();
	g.prims();
	g.show_mst();

	cout<<"\nFor Kruskal's Algorithm :\n";
	k.getmat();
	k.showmat();
	k.calculate();
	k.show_mst();



	return 0;
}




