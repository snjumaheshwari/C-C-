#include<bits/stdc++.h>
#define ll long long
using namespace std;



void solve(ll *arr,int n){

    int pos=0;
    int neg=0;
    int zero=0;

    int maxans=0;
    int minans=0;

    for(int i=0;i<n;i++){
        if(arr[i] >0) pos++;
        else if(arr[i]<0) neg++;
        else zero++;
    }
    if(pos==0 && zero==0){
        maxans=minans=neg;
    }
    else if(neg==0 && zero==0){
        maxans=minans=pos;
    }
    else if(pos==0){
        maxans=minans=zero+neg;
    }
    else if(neg==0){
        maxans= minans=zero+pos;
    }
    else if(pos >= neg){
        maxans= pos+zero;
        minans= neg;
    }
    else{
        maxans= neg+zero;
        minans= pos;
    }
    cout<<maxans<<" "<<minans<<endl;


}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        solve(arr,n);
    }


}
