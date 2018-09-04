#include<bits/stdc++.h>
#define ll long long
#define INF 10000000000
using namespace std;

int main()
{
    ll test,x,y;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        ll ans=0;

        for(ll i=1;i<=n;i++)
        {
            cin>>x>>y;
            ans^=i;
        }

        cout<<ans<<"\n";
    }

}

