/*CREATING A BINARY SEARCH TREE AND PERFORMING THE FOLLOWING OPERATION ON IT ::
	> FINDING A MINIMUM ELEMENT IN THE TREE
	> FINDING A MAXIMUM ELEMENT IN THE TREE
	> SEARCHING A PARTICULAR ELEMENT IN THE TREE
	> DISPLAYING THE TREE
	> DISPLAYING THE LEAFNODES IN THE TREE
	> DISPLAYING ALL THE NODES HAVING DEGREE 1
*/

#include<iostream>
using namespace std;
class Treenode
{
	public:
		Treenode *left,*right;
		int data;
		Treenode()
		{
			left = NULL;
			right = NULL;
			data = 0;	
		}
		
		friend class Binarysearchtree;	
};	

class Binarysearchtree
{
	public:
		Treenode *root,*temp;
		Binarysearchtree()
		{
			root = NULL;
		}
		void create()
		{
			Treenode *root,*temp,*nnode;
			cout<<"Enter the element ::";
			nnode=new Treenode;
			cin>>nnode->data; 
			do
			{
				if(nnode->data == -1)
				{
					break;
				}
				if(root == NULL)
				{
					root=nnode;
					temp=root;
				}	
				
				else
				{
					while(true)
					{
						if(nnode->data < temp->data)
						{
							temp=temp->left;
							if(temp == NULL)
							{
								
							}
						}
					}
					
						
				}
			}
			while(1);
			
		}
};

int main()
{
	Binarysearchtree b1;
	b1.create();
	return 0;
}