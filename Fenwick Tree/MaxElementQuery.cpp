#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int BIT[100000];


// Indexing-1 for BIT

void build(int N){

    for(int j=1;j<=N;j++){
        int inc= arr[j];
        int i=j;
        while(i<=N){
            BIT[i]=max(BIT[i],inc);
            i+= (i&(-i));
        }
    }
}

// sum till the ith index
int query(int i){
    int ans=0;
    while(i>0){
        ans=max(BIT[i],ans);
        i-=(i&(-i));
    }
    return ans;
}


int main(){
    int n; cin>>n;

    memset(BIT,0,sizeof(BIT));

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(n);
    for(int i=1;i<=n;i++){
        cout<<BIT[i]<<" ";
    }


    cout<<endl;
    int q; cin>>q;
    while(q--){
        int qs;
        cin>>qs;
        cout<<query(qs)<<endl;
    }

}

