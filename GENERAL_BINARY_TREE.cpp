#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
template<typename T>
class TreeNode
{
	
	public:
		int data;
		TreeNode *left,*right;
		TreeNode()
		{
			data=0;
			left=NULL;
			right=NULL;
		}
		
		friend class GenrealBinaryTree;
};


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
class GeneralBinaryTree
{
	public:
		TreeNode *root,*temp;
		GeneralBinaryTree()
		{
			root=NULL;
		}
		void create()
		{
			TreeNode *nnode;
			char side;
			do
			{
				cout<<"Enter the data :: ";
				nnode=new TreeNode;
				cin>>nnode->data;
					if( nnode->data == -1 )
						break;
				
				if(root==NULL)
				{
					root=nnode;
				}
				else
				{
					temp=root;
						while(1)
						{
							cout<<"Enter the side (l/r) :: "<<temp->data << " : ";
							cin>>side;
							if(side=='l')
							{
								if( temp->left == NULL )
								{
									temp->left = nnode ;
									break;		
								}
								else
									temp = temp->left;		
							}
							else if(side=='r')
							{
								if( temp->right == NULL)
								{
									temp->right = nnode;
									break;		
								}
								else
									temp = temp->right;		
							}		
						}		
				}		
			}
			while(1);	
		}
		//defining with a recursive method
		void inorderdisplay(TreeNode *temp)
		{
			if( temp != NULL )
			{
				inorderdisplay(temp->left);
				cout<<temp->data<<"\t";
				inorderdisplay(temp->right);
			}
		}
		void preorderDisplay(TreeNode *temp)
		{
			if( temp != NULL )
			{
				cout<<temp->data<<"\t";
				preorderDisplay(temp->left);
				preorderDisplay(temp->right);
			}
							
		}
		
		void postorderDisplay(TreeNode *temp)
		{
			if( temp != NULL )
			{
				postorderDisplay(temp->left);
				postorderDisplay(temp->right);
				cout<<temp->data<<"\t";
			}
							
		}
		
		//defining with non-recursive method
		void inorderNonRecurrsive()
		{
			TreeNode *temp=root;
			Stack <TreeNode *>s1;
			while(temp->left != NULL)
			{
				s1.push(temp);
				temp=temp->left;
			}
			s1.push(temp);
			while(!s1.isEmpty())
			{
				temp=s1.pop();
				cout<<temp->data<<"\t";
				if(temp->right != NULL)
				{
					temp=temp->right;
					while(temp != NULL)
					{
						s1.push(temp);
						temp=temp->left;
					}
				}
			}
		}
		
		void preorderNonRecurrsive()
		{
			TreeNode *temp=root;
			Stack<TreeNode *>s2;
			while(temp->left != NULL)
			{
				s2.push(temp);
				cout<<temp->data<<"\t";
				temp=temp->left;
			}
			cout<<temp->data<<"\t";
			while(!s2.isEmpty())
			{	
					
					temp=s2.pop();	
					
					if(temp->right != NULL)
					{
						temp=temp->right;
						if(temp != NULL)
						{
							s2.push(temp);
							cout<<temp->data<<"\t";
						}
					}
				
			}
		}
		
		void postorderNonRecurrsive()
		{
			int flag;
			TreeNode *temp=root;
			Stack<TreeNode *>s3;
			Stack<int>s4;
			while(temp != NULL)
			{
				s3.push(temp);
				s4.push(0);
				temp=temp->left;
			}
			while(!s3.isEmpty())
			{
				flag=s4.pop();
				temp=s3.pop();
					if(flag==1)
					{
						cout<<temp->data<<"\t";
					}
					else
					{
						s3.push(temp);
						s4.push(1);
						if(temp->right != NULL)
						{
							temp=temp->right;
							while(temp != NULL)
							{
								s3.push(temp);
								s4.push(0);
								temp=temp->left;
							}
						}
					}
			}
		}
};

int main()
{
	GeneralBinaryTree G1;
	G1.create();
	
	cout<<"\n\tBY RECURSSION METHOD ::\n"<<endl;
	
	cout<<"INORDER TRAVERSAL OF THE GENERAL BINARY TREE :: \n";
	G1.inorderdisplay(G1.root);
	cout<<"\nPREORDER TRAVERSAL OF THE GENERAL BINARY TREE :: \n";
	G1.preorderDisplay(G1.root);
	cout<<"\nPOSTORDER TRAVERSAL OF THE GENERAL BINARY TREE :: \n";
	G1.postorderDisplay(G1.root);
	
	cout<<"\n\n\tBY NON-RECURSSION METHOD :: "<<endl;
	
	cout<<"\nINORDER TRAVERSAL OF THE GENERAL BINARY TREE :: \n";
	G1.inorderNonRecurrsive();
	cout<<"\nPREORDER TRAVERSAL OF THE GENERAL BINARY TREE :: \n";
	G1.preorderNonRecurrsive();
	cout<<"\nPOSTORDER TRAVERSAL OF THE GENERAL BINARY TREE :: \n";
	G1.postorderNonRecurrsive();
	return 0;
}
