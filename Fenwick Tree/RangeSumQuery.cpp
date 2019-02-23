#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int BIT[100000];


// Indexing-1 for BIT

void update(int i,int inc, int N){
    while(i<=N){
        BIT[i]+=inc;
        i+= (i&(-i));
    }
}

// sum till the ith index
int query(int i){
    int ans=0;
    while(i>0){
        ans+=BIT[i];
        i-=(i&(-i));
    }
    return ans;
}


int main(){
    int n; cin>>n;

    memset(BIT,0,sizeof(BIT));

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        update(i,arr[i],n);
    }
    for(int i=1;i<=n;i++){
        cout<<BIT[i]<<" ";
    }

    cout<<endl;
    int q; cin>>q;
    while(q--){
        int qs,qe; cin>>qs>>qe;
        cout<<query(qe)- query(qs-1)<<endl;
    }

}
