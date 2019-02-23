
#include<bits/stdc++.h>
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

/*

    You are given an array A of N elements and Q queries.
    Each query consists of 3 integers L R K.
    For each query, you have to find the number of elements
     Ax1, Ax2,….,Axj>=K, where L<=x1, x2,…xj<=R.

*/

void BuildTree(long *arr,long *tree,int s,int e,int index){

    if(s==e){
        if(arr[s]>=0){
            tree[index]=1;
        }
        else{
            tree[index]=0;
        }
        return;
    }

    int mid= (s+e)>>1;
    int left= index<<1;
    BuildTree(arr,tree,s,mid,left);
    BuildTree(arr,tree,mid+1,e,left+1);

    tree[index]=tree[left]+tree[left+1];

}


int query(long *tree,int s,int e,int index,int qs, int qe){



    if(qe < s or qs > e){
        return 0;
    }
    if(qs<=s and qe >=e){
        return tree[index];
    }

    int mid=(s+e)>>1;
    int left=index<<1;

    int leftans= query(tree,s,mid,left,qs,qe);
    int rightans= query(tree,mid+1,e,left+1,qs,qe);

    return leftans+rightans;

}

void updateRange(long *arr,long *tree,int s,int e,int index,int l,int r,int inc){

    if(r <s or l>e){
        return ;
    }

    if(s==e){
        arr[s]+=inc;
        if(arr[s]>=0)
            tree[index]=1;
        else
            tree[index]=0;
        return ;
    }

    int mid=(s+e)>>1;
    int left=(index)<<1;

    updateRange(arr,tree,s,mid,left,l,r,inc);
    updateRange(arr,tree,mid+1,e,left+1,l,r,inc);

    tree[index]=tree[left]+tree[left+1];

}


int main(){

    int n; cin>>n;

    long arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long *tree= new long[4*n+1];
    BuildTree(arr,tree,0,n-1,1);

    int q; cin>>q;
    while(q--){

        int l,r; cin>>l>>r;
        l--; r--;
        long k; cin>>k;

        updateRange(arr,tree,0,n-1,1,l,r,-k);
        cout<<query(tree,0,n-1,1,l,r)<<endl;
        updateRange(arr,tree,0,n-1,1,l,r,k);
    }


}
