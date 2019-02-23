#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int a[10];

    node *child[10];

    node(){
        for(int i=0;i<10;i++){
            a[i]=0;
            child[i]=NULL;
        }

    }
};
node *Root=NULL;

void insert(node *root,string s,int n, int i=0){
    if(i==n){
        return ;
    }

    int digit= s[i]-'0';

    //cout<<digit<<" "<<endl;
    root->a[digit]++;


    for(int i=0;i<10;i++){
        cout<<root->a[i]<<" ";
    }
    cout<<endl;

    if(root->child[digit] ==NULL){
        node *ptr=new node;
        root->child[digit]=ptr;
    }

    insert(root->child[digit],s,n,i+1);

}
int ans=0;
double query(node *Root){

    // will later do prefix sum
    for(int i=0;i<9;i++){
        sum+=root->a[digit];
    }

    if(sum&1){
        int x=0;
        for(int i=0;i<9;i++){
            x+=root->a[digit];
            if(x> sum/2){
                ans
            }
        }

    // recursively call on that root->child[digit]
    else
    {


    }

}


int main(){

    int n; cin>>n;

    node *Root=new node;

    while(n--){
        string s; cin>>s;
        int x=s.length();
        insert(Root,s,x);
        cout<<query(Root)<<endl;
    }




}
