#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin>>t;
    int arr[]={2,3,5,7,11,13,17,19};
    int n= sizeof(arr)/sizeof(int);
    int N= 1<<n;

    while(t--){
        ll ans=0;
        ll num; cin>>num;
        for(int i=1;i<N;i++){

            int b= __builtin_popcount(i);
            int mask=i;
            ll temp=1;
            int p=0;
            while(mask){
                if(mask  & 1){
                    temp*= arr[p];
                }
                mask=mask>>1;
                p++;
            }

            if(b&1){
                ans+= num/ temp;
               // if(num/temp !=0)
                 //   cout<<"\n mask : "<<i<<"  added : " <<num/temp;
            }
            else{
                ans-= num/temp;
                //if(num/temp !=0)
                //cout<<"\n mask : "<<i<<"  subtracted :" <<num/temp;
            }

        }
        cout<<ans<<endl;

    }



}
