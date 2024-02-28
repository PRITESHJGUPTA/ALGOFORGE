#include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	public:
		node()
		{
			data=0;
			next=NULL;
		}
		friend class linkedlist;
};
class linkedlist
{
	node *start,*temp;
	public:
		linkedlist()
		{
			start=NULL;
		}
		void add_last()
		{
			node *nnode;
			cout<<"PRESS -1 TO STOP !!"<<endl;
			do
			{
				cout<<"ENTER THE DATA ::";
				nnode=new node;
				cin>>nnode->data;
					if(nnode->data==-1)
					{
						break;
					}
					if(start==NULL)
					{
						start=nnode;
					}
					else
					{
						for(temp=start;temp->next!=NULL;temp=temp->next)
						{
							//traaversal
						}
						temp->next=nnode;
					}
					
			}
			while(1);
			
		}
		void add_first()
		{
			cout<<"ADDING THE DATA IN THE FRONT ::"<<endl;
			node *new_node;
		
					cout<<"Enter the data::";
					new_node=new node;
					cin>>new_node->data;					
						new_node->next=start;
						start=new_node;
		}
		void add_middle(int prevpost)
		{
			node *new_node;
			cout<<"Enter the new element :: ";
			new_node=new node;
			cin>>new_node->data;
			for(temp=start;temp!=NULL;temp=temp->next)
			{
				if(temp->data==prevpost)
				{
					new_node->next=temp->next;
					temp->next=new_node;
				}
				
			}	
		}
		int  delete_first()
		{
			int temp;
			temp=start->data;
			start=start->next;
			return temp;
		}
		int delete_last()
		{
			int ret;
			node *temp=start;
			while(temp->next->next !=NULL)
			{
				temp=temp->next;
			}
			ret=temp->next->data;
			delete temp->next;
			temp->next=NULL;
			return ret;
		}
		int delete_post(int elem)
		{
			int ret;
			node *temp=start;	
			while(temp->next != NULL)
			{
				if(temp->next->next=NULL)
				{
				ret=delete_last();
				return ret; 
				}
				else if(temp->data == elem)
				{
					ret=temp->next->data;
					temp->next=temp->next->next;
				}
				temp=temp->next;
			}
			return ret;
			}
		
void display()
{
	cout<<"DISPLAY::"<<endl;
	for(temp=start;temp!=NULL;temp=temp->next)
	{
		cout<<temp->data<<"\t";
	}
}
};
int main()
{
	
		
	
	int choice,temp;
	linkedlist l1;
	do
	{
	
	
	cout<<"\nHERE ARE THE CHOICES TO PERFORM ::\n1.INSERT LAST\n2.INSERT FIRST\n3.INSERT MIDDLE\n4.DELETE FIRST\n5.DELETE LAST\n6.DELETE MIDDLE\n7.DISPLAY"<<endl;
	cout<<"Enter your choice::";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			
			l1.add_last();
			
			break;
		}
		case 2:
			{
				l1.add_first();
				break;
			}
		case 3:
			{
				int num1;
				cout<<"The the data after which you need to add a new element :";
				cin>>num1;
				l1.add_middle(num1);
				break;
			}
		case 4:
		{
		
			temp=l1.delete_first();
			cout<<"The Deleted element is :"<<temp<<endl;
			break;		
		}	
		case 5:
		{
			temp=l1.delete_last();
			cout<<"The Deleted element is :"<<temp<<endl;
			break;
		}
		case 6:
		{
			int num2;
			cout<<"Enter the element after which to delete :";
			cin>>num2;
			temp=l1.delete_post(num2);
			cout<<"The Deleted element is :"<<temp<<endl;
			break;				
		}	
		case 7:
		{
			l1.display();
			break;
		}	
		default:
		{	
		}
	}
	}
	while(true);
	return 0;	
}