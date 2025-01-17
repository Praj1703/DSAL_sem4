#include<iostream>
using namespace std;

class BST
{
	private:
		struct Node
		{
			int data;
			Node *lc,*rc;
		}*root;
	public:
	BST()
	{
		root=NULL;
	}
	void dis();
	void rec_preorder(Node *root);
	void rec_inorder(Node *root);
	void rec_postorder(Node *root);
	void create()
	{
		Node *temp,*curr;
		int ch;
		do
		{
			
			temp=new Node;
			cout<<"Enter data: ";
			cin>>temp->data;
			temp->lc=NULL;
			temp->rc=NULL;
			if(root==NULL)
			{
				root=temp;
			}
			else
			{
				
				curr=root;
				while(1)
				{
					if(temp->data< curr->data)
					{
						if(curr->lc==NULL)
						{
							curr->lc=temp;
							break;
						}
						else
							curr=curr->lc;
					}
					
					if(temp->data > curr->data)
					{
						if(curr->rc==NULL)
						{
							curr->rc=temp;
							break;
						}
						else
							curr=curr->rc;
					}
				}
				
			}
		cout<<"Do you want to add more?YES(enter 1) and NO(enter 2)"<<endl;
		cin>>ch;
	}while(ch==1);
}

};


void BST::dis()
{
	rec_preorder(root);
	cout<<"Inorder Traversal: "<<endl;
	rec_inorder(root);
	cout<<"Postorder Traversal: "<<endl;
	rec_postorder(root);
}

void BST::rec_preorder(Node *t)
{
	if(t!=NULL)
	{
		cout<<"\t"<<t->data;
		rec_preorder(t->lc);
		rec_preorder(t->rc);
		cout<<""<<endl;
	}
}
void BST::rec_inorder(Node *t)
{
	if(t!=NULL)
	{
		rec_inorder(t->lc);
		cout<<"\t"<<t->data;
		
		rec_inorder(t->rc);

	}
}
int main()
{
	BST tree;
	tree.create();
	cout<<"Pre-Order Traversal :"<<endl;
	tree.dis();	
	cout<<""<<endl;
	return 0;
}
