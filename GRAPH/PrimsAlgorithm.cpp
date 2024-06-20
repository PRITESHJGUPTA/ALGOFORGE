#include<iostream>
using namespace std;
class grp
{
	int vertex,edges;
	int arr[10][10];
	int dist[10]={9999};
	int distfrom[10]={0};
	bool visited[10]={false};
		public:
	grp()
	{
		cout<<"Enter the Number of Vertex ::";
		cin>>vertex;
		cout<<"Enter the number of edges ::";
		cin>>edges;
		int arr[vertex][vertex];
	}
	void create()
	{	
		for(int i=0;i<vertex;i++)
		{
			for(int j=0;j<vertex;j++)
			{
				cout<<"Enter the Weight for "<<i+1<<" to "<<j+1<<" :: ";
				cin>>arr[i][j];
			}
		}	
	}
	void prims(int start)
	{
		int index=start-1;
		int min=99999;
		while(!visited[index])
		{
			cout<<start<<"-";
			visited[index]=true;
			for(int i=0;i<vertex;i++)
			{
				if(arr[index][i]!=0)
				{
					if(dist[i]>arr[index][i])
					{
						dist[i]=arr[index][i];
						distfrom[i]=start;
					}
					if(dist[i]<min)
					{
						min=dist[i];
						start=i+1;
					}
				}
			}
			prims(start);
		}		
	}	
};
int main()
{
		grp g1;
		g1.create();
		g1.prims(1);
		return 0;
}