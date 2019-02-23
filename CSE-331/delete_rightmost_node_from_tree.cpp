#include<bits/stdc++.h>
using namespace std;

struct node{
    node *left;
    node *right;
    int data;
};
struct node* root=NULL;

node* newNode(int data){
    node *n= new node();
    n->data= data;
    n->left= NULL;
    n->right= NULL;
    return n;
}


void inorder(node *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);

    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(node *root){
    if(root==NULL){
        return ;
    }
    queue<node*> q;

    q.push(root);

    while(!q.empty()){

        node *temp= q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left !=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}

node* search_node(node *root,int item){
    if(root==NULL){
        return NULL;
    }
    queue<node*> q;

    q.push(root);

    while(!q.empty()){

        node *temp= q.front();
        q.pop();

        if(temp->data==item){
            return temp;
        }

        if(temp->left !=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    return NULL;
}
void delete_node(node *root,int item){

   /* // In complete
    node *target= search(root,item);
    if(target==NULL){

        cout<<" Item is not present\n";
    }


    node *ptr=root;
    node  *src= NULL;
    while(ptr!=NULL){
        if(ptr->right !=NULL){
            ptr= ptr-> right;
        }
        else if(ptr->left !=NULL){
            ptr=ptr->left;
        }
        else{
            src=ptr;
            target->data= src;
            ptr-NULL;
        }

    }
    */
}

int main(){

    // 1. binary tree represented using array

   /* int arr[]={-1,1,6,3,4,5,60};
    int n= sizeof(arr)/sizeof(int);
    n--;
    int item; cin>>item;
    int index;
    for(int i=1;i<=n;i++){
        if(arr[i]==item){
            index=i;
        }
    }

    arr[index]=arr[n];
    arr[n]=-1;

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
*/
    // Binary Tree using structure


    node *root=newNode(1);
    root->left= newNode(2);
    root->right= newNode(3);
    root->left->left= newNode(4);
    root->left->right= newNode(5);
    root->right->right= newNode(6);


    cout<<"Inorder Traversal :";
    inorder(root);
    cout<<"\n Preorder Traversal :";
    preorder(root);

    cout<<"\n Postorder traversal :";
    postorder(root);

    cout<<"\n Level order traversal :";
    levelorder(root);










}
