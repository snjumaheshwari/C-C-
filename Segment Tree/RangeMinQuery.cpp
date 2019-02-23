#include<bits/stdc++.h>
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
const int inf= int(1e9);
const int MOD= int(1e9 +7);


void BuildTree(int *arr, int *tree, int s,int e,int index){

    // Base case
    if(s==e){
        tree[index]=arr[s];
        return ;
    }

    int mid= (s+e)>>1;

    int left= index<<1;

    BuildTree(arr,tree,s,mid,left);
    BuildTree(arr,tree,mid+1,e,left+1);

    tree[index]= min(tree[left],tree[left+1]);

}

int query(int *tree, int s,int e, int index, int qs,int qe){

    //complete overlap -- return ans to that index
    if(s>=qs and qe >=e){
        return tree[index];
    }

    // No overlap -- return inf
    if(s>qe or qs> e){
        return inf;
    }

    // partial overlap --- call on both side
    int mid= (s+e)>>1;
    int left= index<<1;

    int leftans=query(tree,s,mid,left,qs,qe);
    int rightans=query(tree,mid+1,e,left+1,qs,qe);

    return min(leftans,rightans);
}


void update(int *tree, int s,int e, int index, int i,int inc){

    if(s==e){
        tree[index]+=inc;
        return ;
    }

    int mid=(s+e)>>1;
    int left= index<<1;


    if(i<=mid){
        update(tree,s,mid,left,i,inc);
    }
    else{
        update(tree,mid+1,e,left+1,i,inc);
    }
    tree[index]= min(tree[left], tree[left+1]);
    return;

}

void updateRange(int *tree,int s,int e,int index,int l,int r,int inc){

    if(s>r or l>e){
        return ;
    }

    if(s==e){
        tree[index]+=inc;
        return ;
    }

    int mid=(s+e)>>1;
    int left=(index)<<1;

    updateRange(tree,s,mid,left,l,r,inc);
    updateRange(tree,mid+1,e,left+1,l,r,inc);

    tree[index]= min(tree[left],tree[left+1]);
    return ;

}


int lazy[100000]={0};
void updateRangeLazy(int *tree,int s,int e,int index,int l,int r,int inc){


    if(lazy[index]!=0){
        tree[index]+=lazy[index];

        if(s!=e){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }

    if(s > r or e <l){
        return ;
    }

    if(l<=s and r>=e){
        tree[index]+=inc;
        if(s!=e){
            lazy[2*index]+=inc;
            lazy[2*index+1]+=inc;
            }
        return ;
    }

    int mid=(s+e)>>1;
    int left= (index)<<1;
    updateRangeLazy(tree,s,mid,left,l,r,inc);
    updateRangeLazy(tree,mid+1,e,left+1,l,r,inc);

    tree[index]=min(tree[left],tree[left+1]);
    return ;
}

int  queryLazy(int *tree,int s,int e,int index,int qs,int qe){

    // New Query --> Old Query + resolve lazy values in the branches

    // first step => to resolve lazy value

    if(lazy[index]!=0){
        tree[index]+=lazy[index];
        if(s!=e){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }


    //complete overlap -- return ans to that index
    if(s>=qs and qe >=e){
        return tree[index];
    }

    // No overlap -- return inf
    if(s>qe or qs> e){
        return inf;
    }

    // partial overlap --- call on both side
    int mid= (s+e)>>1;
    int left= index<<1;

    int leftans=queryLazy(tree,s,mid,left,qs,qe);
    int rightans=queryLazy(tree,mid+1,e,left+1,qs,qe);

    return min(leftans,rightans);

}
int main(){

    // solve range minimum query ..

    int arr[]= {1,3,2,-5,6,4};
    int n= sizeof(arr)/sizeof(int);

    int *tree= new int[4*n+1];

    BuildTree(arr,tree,0,n-1,1);


    for(int i=1;i<=4*n;i++){
        cout<<tree[i]<<" ";
    }


    // Query--



    // update--

    update(tree,0,n-1,1,2,10);
    update(tree,0,n-1,1,3,15);


        int q; cin>>q;
    while(q--){
            int l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,1,l,r)<<endl;
    }



    // update range--




    // lazy Update--




    return 0;
}
