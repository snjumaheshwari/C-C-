#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;

	node(int data){
		this->data=data;
		left=right=NULL;
	}
};

void PostOrder(node *root)
{
	if(root==NULL){
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

void InOrder(node *root){
	if(root==NULL){
		return;
	}
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);

}
void PreOrder(node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	PreOrder(root->left);
	
	PreOrder(root->right);
}

void Inorder_without_recursion(node* root){
	stack<node*> s;
	node *current= root;
	while(current!=NULL or !s.empty()){
		while(current){
			s.push(current);
			current= current->left;
		}
		if(!s.empty()){
			node *n= s.top();
			s.pop();
			cout<< n-> data<<" ";
			current= n->right;
		}
	}
}

void PreOrder_without_recursion(node *root){



}

void PostOrder_without_recursion(node* root){


}


int main(){
	struct node *root= new node(1);
	root->left=new node(2);
	root->right= new node(3);
	root->left->left= new node(4);
	root->left->right= new node(5);

	InOrder(root);
	Inorder_without_recursion(root);

}