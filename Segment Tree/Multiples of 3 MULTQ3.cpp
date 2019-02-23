
#include<bits/stdc++.h>
#define TLE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N=100002;


int Tree[400002][3];
int Lazy[400002];

void BuildTree(int index,int s,int e){

    if(s==e){

        Tree[index][0]=1;
        return;
    }
    int mid=(s+e)>>1;

    int left=index<<1;
    BuildTree(left,s,mid);
    BuildTree(left+1,mid+1,e);

    Tree[index][0]= Tree[left][0]+ Tree[left+1][0];
    //Tree[index].ones= Tree[2*index].ones + Tree[2*index+1].ones;
    //Tree[index].twos = Tree[2*index].twos + Tree[2*index+1].twos;

    return ;
}


int query(int index,int s,int e,int qs,int qe){


    int left= index<<1;

    if(Lazy[index]!=0){
        if(s!=e){
            Lazy[left]+= Lazy[index];
            Lazy[left+1]+= Lazy[index];
        }
        int rem= Lazy[index]%3;
        if(rem==1){

            int temp= Tree[index][0];
            Tree[index][0]= Tree[index][2];
            Tree[index][2]= Tree[index][1];
            Tree[index][1]= temp;
        }
        else if(rem==2){
            int temp = Tree[index][0];
            Tree[index][0]=Tree[index][1];
            Tree[index][1]= Tree[index][2];
            Tree[index][2]= temp;
        }
        Lazy[index]=0;
    }


    // No overlap

    if(qe < s or qs >e ){
        return 0;
    }
    if( qs <= s and qe >= e){
        return Tree[index][0];
    }

    int mid=(s+e)>>1;
    return query(left, s,mid,qs,qe)+ query(left+1,mid+1,e,qs,qe);
}


void updateRange(int index,int s,int e,int l, int r){

    int left= index<<1;

    if(Lazy[index]!=0){
        if(s!=e){
            Lazy[left]+= Lazy[index];
            Lazy[left+1]+= Lazy[index];
        }
        int rem= Lazy[index]%3;
        if(rem==1){

            int temp= Tree[index][0];
            Tree[index][0]= Tree[index][2];
            Tree[index][2]= Tree[index][1];
            Tree[index][1]= temp;
        }
        else if(rem==2){
            int temp = Tree[index][0];
            Tree[index][0]=Tree[index][1];
            Tree[index][1]= Tree[index][2];
            Tree[index][2]= temp;
        }
        Lazy[index]=0;
    }


    // No overlap
    if(r < s or l >e ){
        return ;
    }

    // complete overlap

    if( l <= s and r >= e){

            int temp= Tree[index][0];
            Tree[index][0]= Tree[index][2];
            Tree[index][2]= Tree[index][1];
            Tree[index][1]= temp;

            if(s!=e){
                Lazy[left]++;
                Lazy[left+1]++;

            }

            return;
    }


    // else

    int mid=(s+e)>>1;


    updateRange(left, s,mid,l,r);
    updateRange(left+1,mid+1,e,l,r);

    Tree[index][0]=Tree[left][0] + Tree[left+1][0];
    Tree[index][1]=Tree[left][1] + Tree[left+1][1];
    Tree[index][2]=Tree[left][2]+ Tree[left+1][2];

}

void print(){
}
int main(){

    TLE;
    int n,q,x,y,z; cin>>n>>q;
    memset(Lazy,0,sizeof(Lazy));
    memset(Tree,0,sizeof(Tree));

    BuildTree(1,0,n-1);

   // print();

    while(q--){
         cin>>x>>y>>z;
        if(x==1)
         cout<<query(1,0,n-1,y,z)<<"\n";
        else
        updateRange(1,0,n-1,y,z);
    }
    return 0;
}
