#include<bits/stdc++.h>
#define MAX 1000002
#define ll long long
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


//MAX= pow(10,6)+1

ll spf[MAX+2]={0};
ll arr[100002]={0};
ll Tree[400009]={0};

void BuildTree(int ss,int se,int index){
 
    if(ss==se){
        Tree[index]=spf[arr[ss]];
        return ;
    }
    int mid= (ss+se)>>1;
    int x=index<<1;
    BuildTree(ss,mid,x);
    BuildTree(mid+1,se,x +1);
    Tree[index]= max(Tree[x], Tree[x+1]);
}


void update(int ss,int se,int l,int r,int index){

    if( ss> r ||  l> se )
        return;
    if(Tree[index]==1)
        return ;
    if(ss==se){
        arr[ss]= arr[ss]/spf[arr[ss]];
        Tree[index]= spf[arr[ss]];
        return ;
    }
    int mid= (ss+se)>>1 ;
    int x;
    x=index<<1;
    update(ss,mid,l,r,x );
    update(mid+1,se,l,r,x+1);
    Tree[index]=max(Tree[x], Tree[x+1]);
}


int query(int ss,int se,int qs,int qe,int index){
    if(ss>qe || qs>se)
        return 0;
    else if(ss>=qs && qe>= se){
        return Tree[index];
    }
    if(Tree[index]==1)
        return 1;
    int mid= (ss+se)>>1;
    int x= index<<1 ;
    ll left= query(ss,mid,qs,qe,x);
    ll right= query(mid+1,se,qs,qe,x+1);
    return max(left,right);
}


int main()
{
    Done;
    int limit= 1002;
    for(ll i=1;i<=MAX;i++)
    {
        if(i&1)
            spf[i]=i;
        else
            spf[i]=2;
    }

    for(int i=3;i<=limit;i++)
    {
        if(spf[i]==i)
        {
            for(ll j=i*i ; j<=MAX; j+= 2*i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
/*
    for(int i=1;i<=1000000;i++)
    {
        cout<<i<<" "<<spf[i]<<endl;
    }
    */

    int t; cin>> t; 

    while(t--)
    {
        int N,M;
        cin>>N>>M;
        
        for(int i=0;i<N;i++)
            cin>>arr[i];

        BuildTree(0,N-1,1);
    
        for(int j=0;j<M;j++)
        { 
            int a,L,R; cin>>a>>L>>R;
            L=L-1;
            R=R-1;

            if(a==0)                    // update 
                update(0,N-1,L,R,1);
            else                    //get maximum spf in range [L,R]
                cout<< query(0,N-1,L,R,1) <<" ";
        }
        cout<<"\n";
        
    }
    
    return 0;
}    
            
