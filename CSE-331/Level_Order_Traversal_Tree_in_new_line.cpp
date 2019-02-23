#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	node *left;
	node *right;
};

node* createNode(int data){
	node *n=new node();
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

void levelOrder(node *root){
	queue<node*> q;

	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node *ptr= q.front();
		q.pop();

		if(ptr==NULL){
			if(q.empty())
				break;
			cout<<endl;
			q.push(ptr);
			continue;
		}
		cout<<ptr->data<<" ";
		if(ptr->left){
			q.push(ptr->left);
		}
		if(ptr->right){
			q.push(ptr->right);
		}
	}
}

int main(){
	node *root= createNode(1);
	root->left= createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->right->right=createNode(5);
	root->right->right->left=createNode(6);

	levelOrder(root);
	return 0;
}