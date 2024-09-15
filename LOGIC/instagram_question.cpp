#include<iostream>
using namespace std;
int main()
{
char sym=65;
for(int i=1;i<=9;i++)
{
        for(int k=1;k<=(i<=5?5-i:i-5);k++)
                cout<<" ";
        for(int j=1;j<=(i<=5?i:10-i);j++)
		cout<<((j%2)?"\033[31m":"\033[0m")\
        <<"\033[9m"<<sym++<<"\033[0m"<<" ";
        cout<<"\n";	
}
	return 0;
}
