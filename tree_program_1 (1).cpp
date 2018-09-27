// binary Search trees... :-traversal.. inserstion .. deletion.. 


#include<iostream>
# define MAXSIZE 100
using namespace std;

struct bstnode{
	int info;
	bstnode* left;
	bstnode* right;
};
struct bstnode* LOC=NULL;
struct bstnode* PAR=NULL;
struct bstnode* ROOT=NULL;




class stack{
	private:
		bstnode* a[MAXSIZE];
		int TOP;
	public:
		stack()
		{
			TOP=-1;
		}
		void add(bstnode* item);
		bstnode* pop();
		void display();
		int isempty()
		{
			if(TOP==-1)
				return 1;
			else
				return 0;
		}
		
};
//int a[MAXSIZE];
//int TOP=-1;


void stack::add(bstnode* item)
{
	if (TOP+1==MAXSIZE)
	{
		cout<<"OVERFLOW "<<endl;
		return; 
	}
	
	a[TOP+1]=item;
	TOP=TOP+1;	

}

bstnode* stack:: pop()
{
	if(TOP==-1)
	{
		cout<<"UNDERFLOW"<<endl;
		return NULL;	
	}	
		bstnode* item=a[TOP];		
		TOP=TOP-1;
		return item;
}


void stack::display()
{
	cout<<endl<<"ELEMENTS ARE :-"<<endl; 
	for (int i=0;i<=TOP;i++)
	{
		cout<<a[i]<<endl;
	}
}

//------------------------------------------------------------


void inorder_traversal_without_recursion()
{
	stack s1;
	bstnode* root=ROOT;
	while(1)
	{
		while(root)
		{
		
			s1.add(root);
			root=root->left;			
		}
		if (s1.isempty())
		{
			break;
		}
		root=s1.pop();
			cout<<root->info<<"  ";
		root=root->right;		
	}
		
}

void inorder(bstnode* root=ROOT)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->info<< "    ";
	inorder(root->right);
}

void preorder(bstnode* root=ROOT)
{
	if(root==NULL)
	{
		return ;
	}
	cout<<root->info<< "  ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(bstnode* root=ROOT)
{
	if(root==NULL)
	{
	return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->info<< "  ";
 } 
 
 void preorder_traversal_without_recursion()
 {
 	stack s1;
 	
 	bstnode * root=ROOT;
 	while(1)
 	{
 		while(root)
 		{
 			cout<<root->info<<"  ";
 			s1.add(root);
 			root=root->left;
		 }
		 
 		if(s1.isempty())
 		{
 			break; // return 
		 }
		 root=s1.pop();
		 root=root->right;
 		
	 }
 	
 }
 
 void postorder_traversal_without_recursion()
 {
 	// nahi aayega..
 	 	
 }
 //--------------------------------------------------------------------
 struct node{
		bstnode* info;
		node *link;
		
};

class queue{
	private:
	node* START;
	node* END;
	
	public:
	queue()
	{
		START=NULL;
		END=NULL;
	 } 
	 void push( bstnode* item);
	 bstnode* pop();
	 void display();
	 int isempty();
	 
};

int queue::isempty()
{
	
	if(START==NULL)
	{
		return 1;
	}
	return 0;
}


void queue::push(bstnode* item)
{
	// inserting at the end of linked list ..
	node * n1=new node;
	n1->info=item;
	n1->link=NULL;
	
	if(START==NULL)
	{
		START=n1;
		END=n1;	
		return;
	}
	
	END->link=n1;
	END=n1;
	
}
bstnode* queue::pop()
{
	// deleteing from the begigning of the linked list..
	
	if(START==NULL)
	{
		cout<<endl<<"UNDERFLOW"<<endl;
		return NULL;	
	}	
	if(START==END)
	{
		bstnode* item=START->info;
		START=NULL;
		END=NULL;
		return item;		
	}
	
		bstnode* item=START->info;
		START=START->link;
		return item;
}

void queue::display()
{
	if(START==NULL)
	{
		cout<<endl<<" EMPTY"<<endl;
		return;
	}
	cout<<endl<<"ELEMENTS ARE :-"<<endl; 
	node *ptr=START;
	while(ptr!=NULL)
	{
		cout<<ptr->info<<" ";
		ptr=ptr->link;
	}
}


int HEIGHT=0; 
 void levelorder(struct bstnode*root=ROOT)
 {

 	struct bstnode* temp;
 	queue q1;
 	if(root==NULL)
 	{
 		return ;
	 }
	 q1.push(root);
	 while(!q1.isempty())
	 {
	
	 	temp=q1.pop();
	 	cout<< temp->info<< "   ";
	 	
	 	if(temp->left or temp->right)
	 		HEIGHT++;
	 		
	 	if(temp->left)
	 		q1.push(temp->left);
	 	if(temp->right)
	 		q1.push(temp->right);
	 }
 	
 }
 
 
 void find(int item,bstnode * ptr=ROOT)
{
	if(ptr==NULL)
	{
		//  NO MORE ITEM TO LOOK INTO..
		return ;
	}
	if(item>ptr->info)
	{
		PAR=ptr;
		find(item,ptr->right)	;
	}
	else if(item<ptr->info)
	{
		PAR=ptr;
		find(item,ptr->left);	
	}
	else
	{
		LOC=ptr;
		return ;
	}

}


void insert(int item)
{
	find(item);
	if(LOC !=NULL)
	{
		cout<<endl<<"ITEM ALREADY EXIST"<<endl;
		return ;		
	}
	
	bstnode *n1=new bstnode;
	n1->info=item;
	n1->left=NULL;
	n1->right=NULL;

	if(PAR==NULL)   // first bstnode CASE..
	{
		ROOT=n1;
		return ;
	}
	//cout<<PAR->info;
	 if(item > (PAR->info))
	{
	PAR->right=n1;
	}
	else   //(item <(PAR->info)
	{
		PAR->left=n1;
	}
	
}


 
int main()
{
	insert(80);
	insert(60);
	insert(90);
	insert(78);
	insert(89);
	insert(98);
	cout<<" display inorder : "<<endl;
	inorder();
	cout<<endl<<" display postorder : "<<endl;
	postorder();
	cout<<endl<<" dispaly preorder : "<<endl;
	preorder();
	
	cout<<endl<<endl<<" display inorder without using recursion : "<< endl<<endl;
	inorder_traversal_without_recursion();
	
	cout<<endl<<endl<<" display preorder without using recursion : "<<endl;
	preorder_traversal_without_recursion();
	

	cout<<endl<<endl<<" display levelorder : "<<endl;
	levelorder();
	
	cout<< "height of tree is : "<<HEIGHT<< endl;
	
	
}
