#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;

ll memo[10000];

ll fib(int n)
{
    if(n==0 || n==1)
        return n;

    if(memo[n]!=-1)
    {
        return memo[n];
    }

    ll ans= fib(n-1)+fib(n-2);
    memo[n]=ans;
    return ans;
}

int main()
{
    DONE;

    int n;
    cin>>n;

    for(int i=0;i<=n;i++)
        memo[i]=-1;

    ll ans=fib(n);
    cout<<ans;
    
    return 0;
}