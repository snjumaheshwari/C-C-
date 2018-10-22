#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[100001]={0};

int main() {
    
        for(int i=1;i<100000;i++)
            dp[i]=dp[i-1]+i;
            
        int t; cin>>t;
        
        while(t--)
        {
            ll k;cin>>k;
            if(k<0)
                k=-k;
            
            int s= int(sqrt(2*k))-5;

            if(s<0)
                s=0;
            for(int i=s ;i<100000;i++)
            {
                //cout<<" i and dp[i] "<<i<< "  "<< dp[i]<<endl;
                if( (dp[i] ^ k)&1 )
                    continue;
                if(dp[i]>=k){
                    cout<<i<<endl;
                    break;
                }
                
                
            }
            
            
        }
    
}