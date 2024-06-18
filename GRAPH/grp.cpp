#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
template<typename T>
class Stack
{
	private:
	    std::vector<T> elements;

	public:
	    void push(const T& value) 
		{
	        elements.push_back(value);
	    }
	
	    T pop() 
		{
	        if (elements.empty())
			{
	            throw std::out_of_range("Stack is empty");
	        }
	        T topElement = elements.back();
	        elements.pop_back();
	        return topElement;
	    }
	
	    T top() const
		{
	        if (elements.empty())
			{
	            throw std::out_of_range("Stack is empty");
	        }
	        return elements.back();
	    }
	
	    bool isEmpty() const 
		{
	        return elements.empty();
	    }
	
	    size_t size() const
		{
	        return elements.size();
	    }
};
class grp
{
	Stack <int>s1;
	int vertex,edges;
	int arr[10][10];
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
	void DFS()
	{
		int arr1[10];
		for(int i=0;i<vertex;i++)
		{
			for(int j=0;j<vertex;j++)
			{
				while(arr[i][j] != 0)
				{
					
					for(int k=0;k<10;k++)
					{
						if(arr1[k] != i+1)
						{
							arr1[k]==i+1;
							s1.push(i+1);
							cout<<i+1;
						}
							
					}
					
				}
			}
		}
	}
};
int main()
{
		grp g1;
		g1.create();
		g1.DFS();
		return 0;
}