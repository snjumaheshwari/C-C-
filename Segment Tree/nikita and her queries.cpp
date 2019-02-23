#include<iostream>
using namespace std;


int main(){

    int t; cin>>t;
    while(t--){

        int n,q; cin>>n>>q;

        int arr[n];

        int x=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            x=x xor arr[i];
        }

        int prefix_xor[n+1];
        prefix_xor[0]=0;

        for(int i=0;i<n;i++){
            prefix_xor[i+1]=arr[i] xor prefix_xor[i];
        }

        while(q--){
            int l,r; cin>>l>>r;

            int ans=(prefix_xor[r] ^ prefix_xor[l-1])^x;

            cout<<ans<<endl;
        }

    }
    return 0;
}
