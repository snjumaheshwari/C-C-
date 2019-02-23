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

bool checkCousins(node *root,int a,int b){
	queue<node*> q;

	q.push(root);
	q.push(NULL);
	int level=1;

	int alevel=0;
	node *apar=NULL;
	int blevel=0;
	node *bpar=NULL;


	while(!q.empty())  {
		node *ptr= q.front();
		q.pop();

		if(ptr==NULL){
			if(q.empty())
				break;
			level++;
			cout<<endl;
			q.push(ptr);
			continue;
		}
		cout<<ptr->data   ;// <<" "<<level<<" ";
		if(ptr->data==a) {
			alevel=level;
		}
		if(ptr->data==b){
			blevel=level;
		}
		if(ptr->left){
			if(ptr->left->data==a) apar=ptr;
			if(ptr->left->data==b) bpar=ptr;
			q.push(ptr->left);
		}
		if(ptr->right){
			if(ptr->right->data==a) apar=ptr;
			if(ptr->right->data==b) bpar= ptr;
			q.push(ptr->right);
		}

		if(alevel!=0 &&blevel!=0)
			break;
	}

	if(alevel==0 or blevel==0)
		return false;
	if(alevel==blevel && apar!=bpar){
		return true;
	}
	return false;
}

int main(){
	node *root= createNode(1);
	root->left= createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);
	root->left->right->right=createNode(8);

	if(checkCousins(root,4,5)){
		cout<<"\nYes";
	}
	else{
		cout<<"\nNo";
	}
	return 0;
}