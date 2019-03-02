
#include<bits/stdc++.h>
using namespace std;


int main(){

    int n; cin>>n;

    int arr[n];
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans= ans ^arr[i];
    }


    int p = ans &(-ans) ;  // last set bit 000100

    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(arr[i] & p){
            x=x^arr[i];
        }
        else{
            y=y^arr[i];
        }
    }

    if(x >y){
        x= x^y;
        y=x^y;
        x=x^y;
    }
    cout<<x<<" "<<y<<endl;


}
