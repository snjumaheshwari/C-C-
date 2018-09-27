#include<bits/stdc++.h>
#define ll long long
#define MeTime ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

ll fn(map<ll,ll> &dp,ll n)
{
    if(n<11)
        return n;
    if(dp[n]!=0)
        return dp[n];
    ll ans= max(n, fn(dp,n/2)+ fn(dp,n/3)+fn(dp,n/4));
    dp[n]=ans;
    return dp[n];

}
int main()
{
    MeTime;
    map<ll,ll> dp;
    for( ll i=0;i<11;i++)
        dp[i]=i;

    ll n;

    while(cin>>n)
    {
        if(n==-1)
            break;
        cout<<fn(dp,n)<<"\n";
    }
}
