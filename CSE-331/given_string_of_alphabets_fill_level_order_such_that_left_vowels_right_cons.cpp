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

void levelOrderInsert(node *root,int data){

	node *n=createNode(data);

	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *ptr= q.front();
		q.pop();
		if(ptr->left==NULL){
			ptr->left=n;
			return ;
		}
		else{
			q.push(ptr->left);
		}
		if(ptr->right==NULL){
			ptr->right=n;
			return;
		}
		else{
			q.push(ptr->right);
		}
	}

}


void printlevelOrder(node *root){
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

int a[]={2,1,0,3,4,5,6,7,1,9,8,1,10,12,14};

	node *root=createNode(-1);
	for(auto i:a){
		if(i&1){
			if(root->left==NULL)
				root->left=createNode(i);
			else
				levelOrderInsert(root->left,i);
		}
		else{
			if(root->right==NULL)
				root->right=createNode(i);
			else
			levelOrderInsert(root->right,i);
		}
	}

	printlevelOrder(root);
	// list<int> v;
}