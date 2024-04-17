
#include<iostream>
 #include<vector>
 #include<stdexcept>
 using namespace std;
 
 class TreeNode
{
	
	public:
		char data;
		TreeNode *left,*right;
		TreeNode()
		{
			data=0;
			left=NULL;
			right=NULL;
		}
		
		friend class ExperssionTree;
};
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
class ExpressionTree
{
		
		Stack <TreeNode *>s1;
		public:
			TreeNode *nnode,*root;
			void create(char exp[])
			{
				int i=0;
				while(exp[i]!= '\0')
				{
						if(exp[i] == 'A' || exp[i]== 'B' || exp[i] == 'C'|| exp[i]=='D')
						{
							nnode=new TreeNode();
							nnode->data=exp[i];
							s1.push(nnode);	
						}
						else
						{
							nnode= new TreeNode();
							nnode->data=exp[i];
							nnode->right=s1.pop();
							nnode->left=s1.pop();
							s1.push(nnode);
						}
						i++;
				}
				root=s1.pop();
			}
			void inorderdisplay(TreeNode *temp)
			{
			if( temp != NULL )
			{
				inorderdisplay(temp->left);
				cout<<temp->data<<"\t";
				inorderdisplay(temp->right);
			}
			}
};
int main()
{
	ExpressionTree e1;
	char val[20];
	cout<<"enter the expression :: ";
	cin>>val;
	e1.create(val);
	e1.inorderdisplay(e1.root);
	return 0;
}
