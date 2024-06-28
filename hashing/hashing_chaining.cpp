#include<iostream>
using namespace std;
class Hashing
{
	private:
		int hashtable[20][2];
		int size=0;
		int tempdata=0;
	public:
		Hashing()
		{
			cout<<"Enter the size of Hash Table ::";
			cin>>size;
			hashtable[size][2];
			for(int i=0;i<size;i++)
			{
				hashtable[i][0]=0;
				hashtable[i][1]=-1;
			}
		}
		int hashFunction(int value)
		{
			return value%size;
		}
		void createHash()
		{
			int k;
			for(int i=0;i<size;i++)
			{
				cout<<"Enter the data ::";
				cin>>tempdata;
				int key=hashFunction(tempdata);
				 k=key;
				if(hashtable[key][0]==0)
				{
					hashtable[key][0]=tempdata;				
				}
				else
				{
					while(hashtable[k][0]!=0)
					{
						k=(k+1)%size;
					}		
						hashtable[k][0]=tempdata;
						hashtable[key][1]=k;
										
				}				
			}
		}
		void showHashTable()
		{
			for(int i=0;i<size;i++)
			{
				for(int j=0;j<2;j++)
				{
					cout<<hashtable[i][j]<<" ";
				}
				cout<<endl;
			}
		}	
};
int main()
{
	Hashing H1;
	H1.createHash();
	H1.showHashTable();
	return 0;
}