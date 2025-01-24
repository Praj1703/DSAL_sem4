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
	void findMin(Node *root);
	void displaymin();
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
int BST::findMin(Node* root){
	if (root == nullptr) {
        throw "Tree is empty";
    }

    Node* current = root;
    while (current->lc != nullptr) {
        current = current->lc;
    }
    return current->data;
}
void BST::displaymin(){
	cout<<"Display the minimum Value "<<endl;
	findMin(Node* root);
}

void BST::dis()
{
	cout<<"*********************************************"<<endl;
		cout<<"Pre-Order Traversal :"<<endl;
		rec_preorder(root);
		cout<<"\n";
		cout<<"Inorder Traversal: "<<endl;
		rec_inorder(root);
		cout<<"\n";
		cout<<"Postorder Traversal: "<<endl;
		rec_postorder(root);
		cout<<"\n\n";
	cout<<"*********************************************"<<endl;
}

void BST::rec_preorder(Node *t)
{
	if(t!=NULL)
	{
		cout<<"\t"<<t->data;
		rec_preorder(t->lc);
		rec_preorder(t->rc);

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
void BST::rec_postorder(Node *t)
{
	if(t!=NULL)
	{
		rec_postorder(t->lc);
		rec_postorder(t->rc);
		cout<<"\t"<<t->data;
	}
}
int main()
{
	int choice; 
	BST tree;

	while(true){
		cout<<"x-----------MENU-----------x"<<endl;
		cout<<"|1. create BST             |"<<endl;
		cout<<"|2. Display BST            |"<<endl;
		cout<<"|3. Find Minimum           |"<<endl;
		cout<<"|4. Exit                   |"<<endl;
		cout<<"x--------------------------x"<<endl;
		cout<<"Enter Your Choice : ";
		cin>>choice;
		cout<<"\n"<<endl;
		
		switch(choice){
		case 1 :
			tree.create();
			break;
		case 2 :
			tree.dis();
			break;
		case 3 :
 			tree.displaymin();	
		case 4 :
			cout<<"Thank You for using the program"<<endl;
			exit(0);
		default:
			cout<<"Invalid Input"<<endl;
			break;
	}
	}
	
	return 0;
}
