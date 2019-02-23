#include<bits/stdc++.h>
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

/*

You are given an array A of n elements and Q queries.
Each query can be of following types:

    1 L R: Print the minimum value in AL, AL+1, AL+2….,AR.
    2 X Y: Update the value of Ax with Y.

*/

void BuildTree(long *arr,long *tree,int s,int e,int index){

    if(s==e){
        tree[index]=arr[s];
        return;
    }
    int mid=(s+e)>>1;
    int left= (index)<<1;

    BuildTree(arr,tree,s,mid,left);
    BuildTree(arr,tree,mid+1,e,left+1);

    tree[index]= min(tree[left],tree[left+1]);

}


int query(long *tree,int s,int e,int index, int qs,int qe){
    // No overlap

    if(qs >e or qe< s){
        return LONG_MAX;
    }

    if(qs<=s and qe>=e){
        return tree[index];
    }

    int mid= (s+e)>>1;
    int left= index<<1;

    long leftans= query(tree,s,mid,left,qs,qe);
    long rightans= query(tree,mid+1,e,left+1,qs,qe);

    return min(leftans, rightans);

}


void update(long *tree,int s,int e,int index,int i,long value){

   if(s==e){
        tree[index]=value;
        return ;
    }

    int mid=(s+e)>>1;
    int left= index<<1;


    if(i<=mid){
        update(tree,s,mid,left,i,value);
    }
    else{
        update(tree,mid+1,e,left+1,i,value);
    }
    tree[index]= min(tree[left], tree[left+1]);
    return;


}


int main(){

    int n,q; cin>>n>>q;

    long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long *tree= new long[4*n+1];

    BuildTree(arr,tree,0,n-1,1);


    while(q--){
        int x; cin>>x;
        if(x==1){
            int y,z; cin>>y>>z;
            y--; z--;
            cout<<query(tree,0,n-1,1,y,z)<<"\n";
        }
        else{
            int y;long z; cin>>y>>z;
            y--;
            update(tree,0,n-1,1,y,z);
        }
    }
    return 0;
}
